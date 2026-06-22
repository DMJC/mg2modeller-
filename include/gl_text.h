#ifndef GL_TEXT_H
#define GL_TEXT_H

#include <epoxy/gl.h>
#include <string>
#include <unordered_map>

struct TextTexture {
    GLuint texture = 0;
    int width = 0;
    int height = 0;
};

class GLTextRenderer {
private:
    std::unordered_map<std::string, TextTexture> cache;
    static std::string makeKey(const std::string& text, const std::string& font,
                               float r, float g, float b);
    static int scale_factor;

public:
    static void setScaleFactor(int s) { scale_factor = s > 0 ? s : 1; }
    static int getScaleFactor() { return scale_factor; }

    TextTexture render(const std::string& text, const std::string& font,
                       float r, float g, float b);
    TextTexture renderUncached(const std::string& text, const std::string& font,
                               float r, float g, float b);
    void invalidate(const std::string& text, const std::string& font,
                    float r, float g, float b);
    void clearCache();
    void freeTexture(TextTexture& tt);
};

#endif // GL_TEXT_H
