#ifndef GL_WINDOW_MANAGER_H
#define GL_WINDOW_MANAGER_H

#include "gl_widgets.h"
#include "gl_text.h"
#include "shader.h"
#include <vector>
#include <string>

class GLWindowManager {
private:
    std::vector<GLWindow*> windows;
    GLWidget* focused_widget = nullptr;
    GLWindow* focused_window = nullptr;
    GLWindow* dragging_window = nullptr;

    ShaderProgram tex_shader;
    ShaderProgram flat_shader;
    GLuint quad_vao = 0, quad_vbo = 0;
    bool gl_ready = false;

    GLTextRenderer text_renderer;

    void initGL();

public:
    GLWindowManager();
    ~GLWindowManager();

    void addWindow(GLWindow* win);
    GLWindow* findWindow(const std::string& name);
    void removeWindow(const std::string& name);
    void showWindow(const std::string& name);
    void hideWindow(const std::string& name);

    void render(int vp_w, int vp_h);
    bool onPress(int mx, int my, int button, unsigned int time);
    bool onRelease(int mx, int my, int button, unsigned int time);
    bool onMotion(int mx, int my, int vp_w, int vp_h);
    bool onKeyPress(unsigned int keyval, unsigned int state);
    bool onTextInput(const char* text);
    bool hitTest(int mx, int my);
    bool hasFocus() const { return focused_widget != nullptr; }

    void clearFocus();
    void cleanup();

    static void renderRect(float x, float y, float w, float h,
                           float r, float g, float b, float a,
                           int vp_w, int vp_h);
    static void renderTexQuad(float x, float y, float w, float h,
                              GLuint texture, int vp_w, int vp_h);

    static ShaderProgram* s_tex_shader;
    static ShaderProgram* s_flat_shader;
    static GLuint s_quad_vao;
    static GLuint s_quad_vbo;
    static int s_vp_w, s_vp_h;
};

#endif // GL_WINDOW_MANAGER_H
