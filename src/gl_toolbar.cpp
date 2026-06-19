#include "../include/gl_toolbar.h"
#include "../include/tools.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <cstring>
#include <cstdlib>

static const char* icon_vert_src = R"(
#version 330 core
layout(location = 0) in vec2 aPos;
layout(location = 1) in vec2 aTexCoord;
out vec2 TexCoord;
void main() {
    gl_Position = vec4(aPos, 0.0, 1.0);
    TexCoord = aTexCoord;
}
)";

static const char* icon_frag_src = R"(
#version 330 core
in vec2 TexCoord;
uniform sampler2D iconTex;
out vec4 FragColor;
void main() {
    FragColor = texture(iconTex, TexCoord);
}
)";

static unsigned int parseHexColor(const std::string& hex) {
    unsigned int r = 0, g = 0, b = 0;
    if (hex.size() == 7 && hex[0] == '#') {
        r = std::strtoul(hex.substr(1, 2).c_str(), nullptr, 16);
        g = std::strtoul(hex.substr(3, 2).c_str(), nullptr, 16);
        b = std::strtoul(hex.substr(5, 2).c_str(), nullptr, 16);
    }
    return (r) | (g << 8) | (b << 16) | (0xFF << 24);
}

static GLuint generatePlaceholderTexture(int w, int h) {
    std::vector<unsigned int> pixels(w * h);
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            bool checker = ((x / 4 + y / 4) % 2 == 0);
            pixels[y * w + x] = checker ? 0xFF666666 : 0xFF999999;
        }
    }
    GLuint tex;
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels.data());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glBindTexture(GL_TEXTURE_2D, 0);
    return tex;
}

GLuint GLToolbar::loadXpmTexture(const std::string& filename, int& out_w, int& out_h) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Cannot open XPM: " << filename << ", using placeholder" << std::endl;
        out_w = ICON_W;
        out_h = ICON_H;
        return generatePlaceholderTexture(ICON_W, ICON_H);
    }

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line)) {
        size_t q1 = line.find('"');
        if (q1 == std::string::npos) continue;
        size_t q2 = line.rfind('"');
        if (q2 <= q1) continue;
        lines.push_back(line.substr(q1 + 1, q2 - q1 - 1));
    }

    if (lines.empty()) return 0;

    int width, height, ncolors, cpp;
    std::istringstream hdr(lines[0]);
    hdr >> width >> height >> ncolors >> cpp;
    out_w = width;
    out_h = height;

    std::unordered_map<std::string, unsigned int> colormap;
    for (int i = 1; i <= ncolors && i < (int)lines.size(); i++) {
        std::string key = lines[i].substr(0, cpp);
        size_t cpos = lines[i].find("\tc ");
        if (cpos == std::string::npos) cpos = lines[i].find(" c ");
        if (cpos == std::string::npos) continue;
        std::string colorstr = lines[i].substr(cpos + 3);
        while (!colorstr.empty() && colorstr.back() == ' ') colorstr.pop_back();

        if (colorstr == "None" || colorstr == "none") {
            colormap[key] = 0x00000000;
        } else {
            colormap[key] = parseHexColor(colorstr);
        }
    }

    std::vector<unsigned int> pixels(width * height, 0xFF969696);
    for (int y = 0; y < height && (1 + ncolors + y) < (int)lines.size(); y++) {
        const std::string& row = lines[1 + ncolors + y];
        for (int x = 0; x < width; x++) {
            int offset = x * cpp;
            if (offset + cpp > (int)row.size()) break;
            std::string key = row.substr(offset, cpp);
            auto it = colormap.find(key);
            if (it != colormap.end()) {
                pixels[y * width + x] = it->second;
            }
        }
    }

    GLuint tex;
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels.data());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glBindTexture(GL_TEXTURE_2D, 0);
    return tex;
}

void GLToolbar::generateHandleTexture(GLuint& tex, bool expanded_style, bool vertical) {
    int w, h;
    if (vertical) { w = ICON_W; h = HANDLE_W; }
    else          { w = HANDLE_W; h = HANDLE_H; }

    std::vector<unsigned int> pixels(w * h);
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            bool border = vertical ? (y == 0) : (x == 0);
            if (border) {
                pixels[y * w + x] = 0xFF505050;
            } else if (expanded_style) {
                bool is_plus = false;
                if (vertical) {
                    for (int p = 0; p < 3; p++) {
                        int cx = 4 + p * 9;
                        int cy = h / 2;
                        if ((y == cy && x >= cx - 2 && x <= cx + 2) ||
                            (x == cx && y >= cy - 2 && y <= cy + 2))
                            is_plus = true;
                    }
                } else {
                    for (int p = 0; p < 3; p++) {
                        int cy = 4 + p * 7;
                        int cx = w / 2;
                        if ((x == cx && y >= cy - 2 && y <= cy + 2) ||
                            (y == cy && x >= cx - 2 && x <= cx + 2))
                            is_plus = true;
                    }
                }
                pixels[y * w + x] = is_plus ? 0xFFFFFFFF : 0xFF808080;
            } else {
                bool dot = vertical ? ((x % 3 == 1) && (y % 3 == 1))
                                    : ((x % 3 == 1) && (y % 3 == 1));
                pixels[y * w + x] = dot ? 0xFFCCCCCC : 0xFF808080;
            }
        }
    }
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels.data());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void GLToolbar::initGL() {
    if (gl_ready) return;

    icon_shader.build(icon_vert_src, icon_frag_src);

    float quad[] = {
        0.0f, 0.0f,  0.0f, 1.0f,
        1.0f, 0.0f,  1.0f, 1.0f,
        1.0f, 1.0f,  1.0f, 0.0f,
        0.0f, 0.0f,  0.0f, 1.0f,
        1.0f, 1.0f,  1.0f, 0.0f,
        0.0f, 1.0f,  0.0f, 0.0f,
    };

    glGenVertexArrays(1, &quad_vao);
    glGenBuffers(1, &quad_vbo);
    glBindVertexArray(quad_vao);
    glBindBuffer(GL_ARRAY_BUFFER, quad_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(quad), quad, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
    glBindVertexArray(0);

    generateHandleTexture(handle_h_texture, false, false);
    generateHandleTexture(handle_h_expanded_texture, true, false);
    generateHandleTexture(handle_v_texture, false, true);
    generateHandleTexture(handle_v_expanded_texture, true, true);

    gl_ready = true;
}

void GLToolbar::ensureGroupTextures() {
    for (auto& g : groups) {
        if (g.load_attempted) continue;
        g.load_attempted = true;
        auto it = g.tools->begin();
        std::advance(it, g.active_index);
        g.texture = loadXpmTexture(it->image_filename, g.tex_w, g.tex_h);
    }
}

void GLToolbar::ensureAllTextures() {
    for (auto& g : groups) {
        if (!g.alt_textures.empty()) continue;
        for (auto& t : *g.tools) {
            int tw, th;
            GLuint tex = loadXpmTexture(t.image_filename, tw, th);
            g.alt_textures.push_back(tex);
        }
    }
}

int GLToolbar::maxGroupSize() const {
    int mx = 0;
    for (auto& g : groups) {
        int n = (int)g.tools->size();
        if (n > mx) mx = n;
    }
    return mx;
}

void GLToolbar::renderQuad(float x, float y, float w, float h, GLuint texture, int vp_w, int vp_h) {
    float nx = (x / vp_w) * 2.0f - 1.0f;
    float ny = 1.0f - ((y + h) / vp_h) * 2.0f;
    float nx2 = ((x + w) / vp_w) * 2.0f - 1.0f;
    float ny2 = 1.0f - (y / vp_h) * 2.0f;

    float verts[] = {
        nx,  ny,   0.0f, 1.0f,
        nx2, ny,   1.0f, 1.0f,
        nx2, ny2,  1.0f, 0.0f,
        nx,  ny,   0.0f, 1.0f,
        nx2, ny2,  1.0f, 0.0f,
        nx,  ny2,  0.0f, 0.0f,
    };

    glBindBuffer(GL_ARRAY_BUFFER, quad_vbo);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(verts), verts);
    glBindTexture(GL_TEXTURE_2D, texture);
    glDrawArrays(GL_TRIANGLES, 0, 6);
}

int GLToolbar::totalWidth() const {
    if (orientation == HORIZONTAL) {
        return (int)groups.size() * ICON_W + HANDLE_W;
    } else {
        if (expanded)
            return maxGroupSize() * ICON_W;
        return ICON_W;
    }
}

int GLToolbar::totalHeight() const {
    if (orientation == HORIZONTAL) {
        if (expanded)
            return maxGroupSize() * ICON_H;
        return ICON_H;
    } else {
        return (int)groups.size() * ICON_H + HANDLE_W;
    }
}

int GLToolbar::expandedOriginY(int vp_h) const {
    if (orientation == HORIZONTAL) {
        int grid_h = maxGroupSize() * ICON_H;
        return (int)pos_y + ICON_H - grid_h;
    }
    return (int)pos_y;
}

int GLToolbar::expandedOriginX() const {
    if (orientation == VERTICAL) {
        int grid_w = maxGroupSize() * ICON_W;
        return (int)pos_x + ICON_W - grid_w;
    }
    return (int)pos_x;
}

GLToolbar::GLToolbar() {}

void GLToolbar::setOrientation(Orientation o) { orientation = o; }
void GLToolbar::setPosition(float x, float y) { pos_x = x; pos_y = y; }

void GLToolbar::reserve(int n) {
    groups.reserve(n);
}

void GLToolbar::addGroup(std::list<tool>* tools) {
    groups.emplace_back();
    auto& g = groups.back();
    g.tools = tools;
    g.active_index = 0;
    g.texture = 0;
}

void GLToolbar::render(int vp_w, int vp_h) {
    if (groups.empty()) return;
    initGL();
    ensureGroupTextures();

    int tw, th;
    if (orientation == HORIZONTAL) {
        tw = (int)groups.size() * ICON_W + HANDLE_W;
        th = ICON_H;
    } else {
        tw = ICON_W;
        th = (int)groups.size() * ICON_H + HANDLE_W;
    }

    if (pos_x + tw > vp_w) pos_x = vp_w - tw;
    if (pos_y + th > vp_h) pos_y = vp_h - th;

    if (expanded && orientation == HORIZONTAL) {
        int grid_h = maxGroupSize() * ICON_H;
        if (pos_y - (grid_h - ICON_H) < 0) pos_y = grid_h - ICON_H;
    }
    if (expanded && orientation == VERTICAL) {
        int grid_w = maxGroupSize() * ICON_W;
        if (pos_x - (grid_w - ICON_W) < 0) pos_x = grid_w - ICON_W;
    }

    if (pos_x < 0) pos_x = 0;
    if (pos_y < 0) pos_y = 0;

    icon_shader.use();
    glBindVertexArray(quad_vao);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    if (expanded) {
        ensureAllTextures();
        for (int i = 0; i < (int)groups.size(); i++) {
            auto& g = groups[i];
            int n = (int)g.tools->size();
            for (int j = 0; j < n; j++) {
                float ix, iy;
                if (orientation == HORIZONTAL) {
                    ix = pos_x + i * ICON_W;
                    iy = pos_y - (n - 1 - j) * ICON_H;
                } else {
                    ix = pos_x - (n - 1 - j) * ICON_W;
                    iy = pos_y + i * ICON_H;
                }
                if (j < (int)g.alt_textures.size() && g.alt_textures[j])
                    renderQuad(ix, iy, ICON_W, ICON_H, g.alt_textures[j], vp_w, vp_h);
            }
        }
    } else {
        for (int i = 0; i < (int)groups.size(); i++) {
            float ix, iy;
            if (orientation == HORIZONTAL) {
                ix = pos_x + i * ICON_W;
                iy = pos_y;
            } else {
                ix = pos_x;
                iy = pos_y + i * ICON_H;
            }
            if (groups[i].texture)
                renderQuad(ix, iy, ICON_W, ICON_H, groups[i].texture, vp_w, vp_h);
        }
    }

    float hx, hy;
    float hw, hh;
    GLuint htex;
    if (orientation == HORIZONTAL) {
        hx = pos_x + (int)groups.size() * ICON_W;
        hy = pos_y;
        hw = HANDLE_W;
        hh = ICON_H;
        htex = expanded ? handle_h_expanded_texture : handle_h_texture;
    } else {
        hx = pos_x;
        hy = pos_y + (int)groups.size() * ICON_H;
        hw = ICON_W;
        hh = HANDLE_W;
        htex = expanded ? handle_v_expanded_texture : handle_v_texture;
    }
    if (htex)
        renderQuad(hx, hy, hw, hh, htex, vp_w, vp_h);

    if (!expanded && submenu_group >= 0 && submenu_group < (int)groups.size()) {
        auto& g = groups[submenu_group];
        int n = (int)g.tools->size();
        if (n > 1) {
            if (g.alt_textures.empty()) {
                for (auto& t : *g.tools) {
                    int tw, th;
                    GLuint tex = loadXpmTexture(t.image_filename, tw, th);
                    g.alt_textures.push_back(tex);
                }
            }
            float bx, by;
            if (orientation == HORIZONTAL) {
                bx = pos_x + submenu_group * ICON_W;
                by = pos_y - n * ICON_H;
            } else {
                bx = pos_x + ICON_W;
                by = pos_y + submenu_group * ICON_H;
            }
            for (int j = 0; j < n; j++) {
                float sx, sy;
                if (orientation == HORIZONTAL) {
                    sx = bx;
                    sy = by + j * ICON_H;
                } else {
                    sx = bx + j * ICON_W;
                    sy = by;
                }
                if (j < (int)g.alt_textures.size() && g.alt_textures[j])
                    renderQuad(sx, sy, ICON_W, ICON_H, g.alt_textures[j], vp_w, vp_h);
            }
        }
    }

    glDisable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);
    glBindVertexArray(0);
    glUseProgram(0);
}

int GLToolbar::groupAt(int mx, int my, int vp_w, int vp_h) {
    if (expanded) return -1;
    for (int i = 0; i < (int)groups.size(); i++) {
        float ix, iy;
        if (orientation == HORIZONTAL) {
            ix = pos_x + i * ICON_W;
            iy = pos_y;
        } else {
            ix = pos_x;
            iy = pos_y + i * ICON_H;
        }
        if (mx >= ix && mx < ix + ICON_W && my >= iy && my < iy + ICON_H)
            return i;
    }
    return -1;
}

int GLToolbar::expandedToolAt(int mx, int my, int vp_w, int vp_h, int& out_group) {
    if (!expanded) return -1;
    for (int i = 0; i < (int)groups.size(); i++) {
        int n = (int)groups[i].tools->size();
        for (int j = 0; j < n; j++) {
            float ix, iy;
            if (orientation == HORIZONTAL) {
                ix = pos_x + i * ICON_W;
                iy = pos_y - (n - 1 - j) * ICON_H;
            } else {
                ix = pos_x - (n - 1 - j) * ICON_W;
                iy = pos_y + i * ICON_H;
            }
            if (mx >= ix && mx < ix + ICON_W && my >= iy && my < iy + ICON_H) {
                out_group = i;
                return j;
            }
        }
    }
    return -1;
}

bool GLToolbar::handleHit(int mx, int my, int vp_w, int vp_h) {
    float hx, hy, hw, hh;
    if (orientation == HORIZONTAL) {
        hx = pos_x + (int)groups.size() * ICON_W;
        hy = pos_y;
        hw = HANDLE_W;
        hh = ICON_H;
    } else {
        hx = pos_x;
        hy = pos_y + (int)groups.size() * ICON_H;
        hw = ICON_W;
        hh = HANDLE_W;
    }
    return (mx >= hx && mx < hx + hw && my >= hy && my < hy + hh);
}

int GLToolbar::submenuItemAt(int mx, int my, int vp_w, int vp_h) {
    if (submenu_group < 0 || submenu_group >= (int)groups.size()) return -1;
    int n = (int)groups[submenu_group].tools->size();
    if (n <= 1) return -1;

    float bx, by;
    if (orientation == HORIZONTAL) {
        bx = pos_x + submenu_group * ICON_W;
        by = pos_y - n * ICON_H;
        for (int j = 0; j < n; j++) {
            float sy = by + j * ICON_H;
            if (mx >= bx && mx < bx + ICON_W && my >= sy && my < sy + ICON_H)
                return j;
        }
    } else {
        bx = pos_x + ICON_W;
        by = pos_y + submenu_group * ICON_H;
        for (int j = 0; j < n; j++) {
            float sx = bx + j * ICON_W;
            if (mx >= sx && mx < sx + ICON_W && my >= by && my < by + ICON_H)
                return j;
        }
    }
    return -1;
}

bool GLToolbar::hitTest(int mx, int my, int vp_w, int vp_h) {
    if (handleHit(mx, my, vp_w, vp_h)) return true;
    if (expanded) {
        int grp;
        if (expandedToolAt(mx, my, vp_w, vp_h, grp) >= 0) return true;
    } else {
        if (groupAt(mx, my, vp_w, vp_h) >= 0) return true;
        if (submenu_group >= 0 && submenuItemAt(mx, my, vp_w, vp_h) >= 0) return true;
    }
    return false;
}

bool GLToolbar::onPress(int mx, int my, int button, unsigned int time, int vp_w, int vp_h) {
    if (handleHit(mx, my, vp_w, vp_h)) {
        handle_dragging = true;
        handle_drag_moved = false;
        handle_press_button = button;
        drag_offset_x = mx - pos_x;
        drag_offset_y = my - pos_y;
        press_time = time;
        return true;
    }

    if (submenu_group >= 0) {
        int item = submenuItemAt(mx, my, vp_w, vp_h);
        if (item >= 0) {
            press_group = -2;
            return true;
        }
        submenu_group = -1;
        return true;
    }

    if (expanded) {
        int grp;
        int tool_idx = expandedToolAt(mx, my, vp_w, vp_h, grp);
        if (tool_idx >= 0) {
            press_group = -3;
            press_button = button;
            press_time = time;
            submenu_group = grp;
            return true;
        }
    }

    int g = groupAt(mx, my, vp_w, vp_h);
    if (g >= 0) {
        press_group = g;
        press_button = button;
        press_time = time;
        return true;
    }
    return false;
}

bool GLToolbar::onRelease(int mx, int my, int button, unsigned int time, int vp_w, int vp_h, scene& sc) {
    if (handle_dragging) {
        handle_dragging = false;
        if (!handle_drag_moved) {
            if (handle_press_button == 3) {
                orientation = (orientation == HORIZONTAL) ? VERTICAL : HORIZONTAL;
            } else {
                expanded = !expanded;
                submenu_group = -1;
            }
        }
        return true;
    }

    if (press_group == -3 && expanded) {
        int grp;
        int tool_idx = expandedToolAt(mx, my, vp_w, vp_h, grp);
        if (tool_idx >= 0 && grp >= 0 && grp < (int)groups.size()) {
            auto& g = groups[grp];
            auto it = g.tools->begin();
            std::advance(it, tool_idx);
            if (press_button == 3 || button == 3) {
                if (it->right_click_callback)
                    it->right_click_callback(sc);
            } else {
                g.active_index = tool_idx;
                int tw, th;
                GLuint new_tex = loadXpmTexture(it->image_filename, tw, th);
                if (g.texture) glDeleteTextures(1, &g.texture);
                g.texture = new_tex;
                g.tex_w = tw;
                g.tex_h = th;
                if (it->left_click_callback)
                    it->left_click_callback(sc);
            }
        }
        press_group = -1;
        submenu_group = -1;
        return true;
    }

    if (submenu_group >= 0 && press_group == -2) {
        int item = submenuItemAt(mx, my, vp_w, vp_h);
        if (item >= 0) {
            auto& g = groups[submenu_group];
            g.active_index = item;
            auto it = g.tools->begin();
            std::advance(it, item);
            int tw, th;
            GLuint new_tex = loadXpmTexture(it->image_filename, tw, th);
            if (g.texture) glDeleteTextures(1, &g.texture);
            g.texture = new_tex;
            g.tex_w = tw;
            g.tex_h = th;
            if (it->left_click_callback)
                it->left_click_callback(sc);
        }
        submenu_group = -1;
        press_group = -1;
        return true;
    }

    if (press_group >= 0 && press_group < (int)groups.size()) {
        unsigned int elapsed = time - press_time;
        auto& g = groups[press_group];
        auto it = g.tools->begin();
        std::advance(it, g.active_index);

        if (elapsed >= 200 && (int)g.tools->size() > 1) {
            submenu_group = press_group;
        } else if (button == 3 || press_button == 3) {
            if (it->right_click_callback)
                it->right_click_callback(sc);
        } else {
            if (it->left_click_callback)
                it->left_click_callback(sc);
        }
        press_group = -1;
        return true;
    }

    press_group = -1;
    return false;
}

bool GLToolbar::onMotion(int mx, int my, int vp_w, int vp_h) {
    if (handle_dragging) {
        float new_x = mx - drag_offset_x;
        float new_y = my - drag_offset_y;
        if (new_x != pos_x || new_y != pos_y)
            handle_drag_moved = true;
        pos_x = new_x;
        pos_y = new_y;
        if (pos_x < 0) pos_x = 0;
        if (pos_y < 0) pos_y = 0;
        if (pos_x + totalWidth() > vp_w) pos_x = vp_w - totalWidth();
        if (pos_y + totalHeight() > vp_h) pos_y = vp_h - totalHeight();
        return true;
    }
    return false;
}

void GLToolbar::cleanup() {
    for (auto& g : groups) {
        if (g.texture) { glDeleteTextures(1, &g.texture); g.texture = 0; }
        for (auto t : g.alt_textures)
            if (t) glDeleteTextures(1, &t);
        g.alt_textures.clear();
    }
    if (handle_h_texture) { glDeleteTextures(1, &handle_h_texture); handle_h_texture = 0; }
    if (handle_h_expanded_texture) { glDeleteTextures(1, &handle_h_expanded_texture); handle_h_expanded_texture = 0; }
    if (handle_v_texture) { glDeleteTextures(1, &handle_v_texture); handle_v_texture = 0; }
    if (handle_v_expanded_texture) { glDeleteTextures(1, &handle_v_expanded_texture); handle_v_expanded_texture = 0; }
    if (quad_vao) { glDeleteVertexArrays(1, &quad_vao); quad_vao = 0; }
    if (quad_vbo) { glDeleteBuffers(1, &quad_vbo); quad_vbo = 0; }
    icon_shader.cleanup();
    gl_ready = false;
}
