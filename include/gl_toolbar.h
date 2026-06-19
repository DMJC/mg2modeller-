#ifndef GL_TOOLBAR_H
#define GL_TOOLBAR_H

#include <epoxy/gl.h>
#include <string>
#include <vector>
#include <list>
#include "shader.h"

class scene;
struct tool;

struct GLToolGroup {
    std::list<tool>* tools = nullptr;
    int active_index = 0;
    GLuint texture = 0;
    int tex_w = 0, tex_h = 0;
    bool load_attempted = false;
    std::vector<GLuint> alt_textures;

    GLToolGroup() = default;
    GLToolGroup(const GLToolGroup&) = delete;
    GLToolGroup& operator=(const GLToolGroup&) = delete;
    GLToolGroup(GLToolGroup&& o) noexcept
        : tools(o.tools), active_index(o.active_index), texture(o.texture),
          tex_w(o.tex_w), tex_h(o.tex_h), load_attempted(o.load_attempted),
          alt_textures(std::move(o.alt_textures)) {
        o.texture = 0;
        o.tools = nullptr;
    }
    GLToolGroup& operator=(GLToolGroup&& o) noexcept {
        if (this != &o) {
            tools = o.tools; active_index = o.active_index;
            texture = o.texture; tex_w = o.tex_w; tex_h = o.tex_h;
            load_attempted = o.load_attempted;
            alt_textures = std::move(o.alt_textures);
            o.texture = 0; o.tools = nullptr;
        }
        return *this;
    }
};

class GLToolbar {
public:
    static const int ICON_W = 32;
    static const int ICON_H = 24;
    static const int HANDLE_W = 9;
    static const int HANDLE_H = 24;

    enum Orientation { HORIZONTAL, VERTICAL };

private:
    std::vector<GLToolGroup> groups;
    float pos_x = 0, pos_y = 0;
    Orientation orientation = HORIZONTAL;
    bool gl_ready = false;

    GLuint handle_h_texture = 0;
    GLuint handle_h_expanded_texture = 0;
    GLuint handle_v_texture = 0;
    GLuint handle_v_expanded_texture = 0;
    GLuint quad_vao = 0, quad_vbo = 0;
    ShaderProgram icon_shader;

    bool handle_dragging = false;
    bool handle_drag_moved = false;
    float drag_offset_x = 0, drag_offset_y = 0;
    int handle_press_button = 0;

    bool expanded = false;

    int submenu_group = -1;

    unsigned int press_time = 0;
    int press_group = -1;
    int press_button = 0;

    static GLuint loadXpmTexture(const std::string& filename, int& out_w, int& out_h);
    static void generateHandleTexture(GLuint& tex, bool expanded_style, bool vertical);
    void initGL();
    void ensureGroupTextures();
    void ensureAllTextures();
    void renderQuad(float x, float y, float w, float h, GLuint texture, int vp_w, int vp_h);
    int groupAt(int mx, int my, int vp_w, int vp_h);
    int expandedToolAt(int mx, int my, int vp_w, int vp_h, int& out_group);
    bool handleHit(int mx, int my, int vp_w, int vp_h);
    int submenuItemAt(int mx, int my, int vp_w, int vp_h);
    int maxGroupSize() const;

    int totalWidth() const;
    int totalHeight() const;
    int expandedOriginY(int vp_h) const;
    int expandedOriginX() const;

public:
    GLToolbar();
    void setOrientation(Orientation o);
    void setPosition(float x, float y);
    float getX() const { return pos_x; }
    float getY() const { return pos_y; }
    Orientation getOrientation() const { return orientation; }
    bool getExpanded() const { return expanded; }
    void setExpanded(bool e) { expanded = e; }
    void reserve(int n);
    void addGroup(std::list<tool>* tools);
    void render(int vp_w, int vp_h);
    bool onPress(int mx, int my, int button, unsigned int time, int vp_w, int vp_h);
    bool onRelease(int mx, int my, int button, unsigned int time, int vp_w, int vp_h, scene& sc);
    bool onMotion(int mx, int my, int vp_w, int vp_h);
    bool hitTest(int mx, int my, int vp_w, int vp_h);
    void cleanup();
};

#endif // GL_TOOLBAR_H
