#include "../include/gl_window_manager.h"
#include <gdk/gdkkeysyms.h>
#include <gdk/gdk.h>
#include <algorithm>
#include <iostream>

ShaderProgram* GLWindowManager::s_tex_shader = nullptr;
ShaderProgram* GLWindowManager::s_flat_shader = nullptr;
GLuint GLWindowManager::s_quad_vao = 0;
GLuint GLWindowManager::s_quad_vbo = 0;
int GLWindowManager::s_vp_w = 0;
int GLWindowManager::s_vp_h = 0;

static const char* tex_vert_src = R"(
#version 330 core
layout(location = 0) in vec2 aPos;
layout(location = 1) in vec2 aTexCoord;
out vec2 TexCoord;
void main() {
    gl_Position = vec4(aPos, 0.0, 1.0);
    TexCoord = aTexCoord;
}
)";

static const char* tex_frag_src = R"(
#version 330 core
in vec2 TexCoord;
uniform sampler2D iconTex;
out vec4 FragColor;
void main() {
    FragColor = texture(iconTex, TexCoord);
}
)";

static const char* flat_vert_src = R"(
#version 330 core
layout(location = 0) in vec2 aPos;
void main() {
    gl_Position = vec4(aPos, 0.0, 1.0);
}
)";

static const char* flat_frag_src = R"(
#version 330 core
uniform vec4 uColor;
out vec4 FragColor;
void main() {
    FragColor = uColor;
}
)";

GLWindowManager::GLWindowManager() {}

GLWindowManager::~GLWindowManager() {
    for (auto* w : windows) delete w;
    windows.clear();
}

void GLWindowManager::initGL() {
    if (gl_ready) return;

    tex_shader.build(tex_vert_src, tex_frag_src);
    flat_shader.build(flat_vert_src, flat_frag_src);

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
    glBufferData(GL_ARRAY_BUFFER, sizeof(quad), quad, GL_DYNAMIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
    glBindVertexArray(0);

    s_tex_shader = &tex_shader;
    s_flat_shader = &flat_shader;
    s_quad_vao = quad_vao;
    s_quad_vbo = quad_vbo;

    gl_ready = true;
}

void GLWindowManager::renderRect(float x, float y, float w, float h,
                                  float r, float g, float b, float a,
                                  int vp_w, int vp_h) {
    if (!s_flat_shader || !s_quad_vao) return;

    float nx = (x / vp_w) * 2.0f - 1.0f;
    float ny = 1.0f - ((y + h) / vp_h) * 2.0f;
    float nx2 = ((x + w) / vp_w) * 2.0f - 1.0f;
    float ny2 = 1.0f - (y / vp_h) * 2.0f;

    float verts[] = {
        nx,  ny,   0.0f, 0.0f,
        nx2, ny,   0.0f, 0.0f,
        nx2, ny2,  0.0f, 0.0f,
        nx,  ny,   0.0f, 0.0f,
        nx2, ny2,  0.0f, 0.0f,
        nx,  ny2,  0.0f, 0.0f,
    };

    s_flat_shader->use();
    GLint loc = glGetUniformLocation(s_flat_shader->getId(), "uColor");
    glUniform4f(loc, r, g, b, a);
    glBindVertexArray(s_quad_vao);
    glBindBuffer(GL_ARRAY_BUFFER, s_quad_vbo);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(verts), verts);
    glDrawArrays(GL_TRIANGLES, 0, 6);
}

void GLWindowManager::renderTexQuad(float x, float y, float w, float h,
                                     GLuint texture, int vp_w, int vp_h) {
    if (!s_tex_shader || !s_quad_vao || !texture) return;

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

    s_tex_shader->use();
    glBindVertexArray(s_quad_vao);
    glBindBuffer(GL_ARRAY_BUFFER, s_quad_vbo);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(verts), verts);
    glBindTexture(GL_TEXTURE_2D, texture);
    glDrawArrays(GL_TRIANGLES, 0, 6);
}

void GLWindowManager::addWindow(GLWindow* win) {
    windows.push_back(win);
}

GLWindow* GLWindowManager::findWindow(const std::string& name) {
    for (auto* w : windows)
        if (w->getName() == name) return w;
    return nullptr;
}

void GLWindowManager::removeWindow(const std::string& name) {
    for (auto it = windows.begin(); it != windows.end(); ++it) {
        if ((*it)->getName() == name) {
            if (focused_window == *it) clearFocus();
            if (dragging_window == *it) dragging_window = nullptr;
            delete *it;
            windows.erase(it);
            return;
        }
    }
}

void GLWindowManager::showWindow(const std::string& name) {
    GLWindow* w = findWindow(name);
    if (w) {
        w->show();
        auto it = std::find(windows.begin(), windows.end(), w);
        if (it != windows.end()) {
            windows.erase(it);
            windows.push_back(w);
        }
    }
}

void GLWindowManager::hideWindow(const std::string& name) {
    GLWindow* w = findWindow(name);
    if (w) w->hide();
}

void GLWindowManager::render(int vp_w, int vp_h) {
    initGL();
    s_vp_w = vp_w;
    s_vp_h = vp_h;

    glDisable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    for (auto* w : windows) {
        if (w->isVisible())
            w->render(text_renderer, vp_w, vp_h);
    }

    glDisable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);
    glBindVertexArray(0);
    glUseProgram(0);
}

bool GLWindowManager::onPress(int mx, int my, int button, unsigned int time) {
    // Iterate front-to-back (last in vector = frontmost)
    for (int i = (int)windows.size() - 1; i >= 0; i--) {
        GLWindow* w = windows[i];
        if (!w->isVisible()) continue;
        if (!w->hitTest(mx, my)) continue;

        // Bring to front
        if (i < (int)windows.size() - 1) {
            windows.erase(windows.begin() + i);
            windows.push_back(w);
        }

        GLWidget* new_focus = nullptr;
        if (w->onPress(mx, my, button, new_focus)) {
            if (w->titleBarHit(mx, my))
                dragging_window = w;

            if (new_focus != focused_widget) {
                if (focused_widget) focused_widget->setFocus(false);
                focused_widget = new_focus;
                focused_window = w;
                if (focused_widget) focused_widget->setFocus(true);
            }
            return true;
        }
    }

    if (focused_widget) clearFocus();
    return false;
}

bool GLWindowManager::onRelease(int mx, int my, int button, unsigned int time) {
    if (dragging_window) {
        dragging_window->stopDrag();
        dragging_window = nullptr;
        return true;
    }

    for (int i = (int)windows.size() - 1; i >= 0; i--) {
        GLWindow* w = windows[i];
        if (!w->isVisible()) continue;
        if (w->hitTest(mx, my))
            return w->onRelease(mx, my, button);
    }
    return false;
}

bool GLWindowManager::onMotion(int mx, int my, int vp_w, int vp_h) {
    if (dragging_window) {
        return dragging_window->onMotion(mx, my, vp_w, vp_h);
    }
    return false;
}

bool GLWindowManager::onKeyPress(unsigned int keyval, unsigned int state) {
    if (!focused_widget || !focused_window) return false;

    if (keyval == GDK_KEY_Tab || keyval == GDK_KEY_ISO_Left_Tab) {
        bool shift = (state & GDK_SHIFT_MASK) != 0;
        GLWidget* next = shift
            ? focused_window->focusPrev(focused_widget)
            : focused_window->focusNext(focused_widget);
        if (next && next != focused_widget) {
            focused_widget->setFocus(false);
            focused_widget = next;
            focused_widget->setFocus(true);
        }
        return true;
    }

    return focused_widget->onKeyPress(keyval, state);
}

bool GLWindowManager::onTextInput(const char* text) {
    if (!focused_widget) return false;
    return focused_widget->onTextInput(text);
}

bool GLWindowManager::hitTest(int mx, int my) {
    for (int i = (int)windows.size() - 1; i >= 0; i--) {
        if (windows[i]->isVisible() && windows[i]->hitTest(mx, my))
            return true;
    }
    return false;
}

void GLWindowManager::clearFocus() {
    if (focused_widget) {
        focused_widget->setFocus(false);
        focused_widget = nullptr;
    }
    focused_window = nullptr;
}

void GLWindowManager::cleanup() {
    text_renderer.clearCache();
    if (quad_vao) { glDeleteVertexArrays(1, &quad_vao); quad_vao = 0; }
    if (quad_vbo) { glDeleteBuffers(1, &quad_vbo); quad_vbo = 0; }
    tex_shader.cleanup();
    flat_shader.cleanup();
    s_tex_shader = nullptr;
    s_flat_shader = nullptr;
    s_quad_vao = 0;
    s_quad_vbo = 0;
    gl_ready = false;
}
