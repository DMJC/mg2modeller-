#include "../include/gl_text.h"
#include <pango/pangocairo.h>
#include <cstring>
#include <sstream>
#include <iostream>
#include <vector>

int GLTextRenderer::scale_factor = 1;

std::string GLTextRenderer::makeKey(const std::string& text, const std::string& font,
                                     float r, float g, float b) {
    std::ostringstream oss;
    oss << text << "|" << font << "|" << r << "," << g << "," << b;
    return oss.str();
}

static TextTexture renderToTexture(const std::string& text, const std::string& font_desc,
                                    float r, float g, float b) {
    TextTexture result;
    if (text.empty()) {
        result.width = 1;
        result.height = 1;
        return result;
    }

    int scale = GLTextRenderer::getScaleFactor();

    cairo_surface_t* tmp_surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, 1, 1);
    cairo_surface_set_device_scale(tmp_surface, scale, scale);
    cairo_t* tmp_cr = cairo_create(tmp_surface);
    PangoLayout* layout = pango_cairo_create_layout(tmp_cr);
    PangoFontDescription* fd = pango_font_description_from_string(font_desc.c_str());
    pango_layout_set_font_description(layout, fd);
    pango_layout_set_text(layout, text.c_str(), -1);

    int pw, ph;
    pango_layout_get_pixel_size(layout, &pw, &ph);
    g_object_unref(layout);
    cairo_destroy(tmp_cr);
    cairo_surface_destroy(tmp_surface);

    if (pw <= 0) pw = 1;
    if (ph <= 0) ph = 1;

    int tex_w = pw * scale;
    int tex_h = ph * scale;

    cairo_surface_t* surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, tex_w, tex_h);
    cairo_surface_set_device_scale(surface, scale, scale);
    cairo_t* cr = cairo_create(surface);

    cairo_set_source_rgba(cr, 0.0, 0.0, 0.0, 0.0);
    cairo_paint(cr);

    layout = pango_cairo_create_layout(cr);
    pango_layout_set_font_description(layout, fd);
    pango_layout_set_text(layout, text.c_str(), -1);

    cairo_set_source_rgba(cr, r, g, b, 1.0);
    pango_cairo_show_layout(cr, layout);

    cairo_surface_flush(surface);
    unsigned char* data = cairo_image_surface_get_data(surface);
    int stride = cairo_image_surface_get_stride(surface);

    std::vector<unsigned char> rgba(tex_w * tex_h * 4);
    for (int y = 0; y < tex_h; y++) {
        for (int x = 0; x < tex_w; x++) {
            unsigned char* src = data + y * stride + x * 4;
            unsigned char* dst = rgba.data() + (y * tex_w + x) * 4;
            dst[0] = src[2];
            dst[1] = src[1];
            dst[2] = src[0];
            dst[3] = src[3];
        }
    }

    GLuint tex;
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, tex_w, tex_h, 0, GL_RGBA, GL_UNSIGNED_BYTE, rgba.data());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glBindTexture(GL_TEXTURE_2D, 0);

    g_object_unref(layout);
    pango_font_description_free(fd);
    cairo_destroy(cr);
    cairo_surface_destroy(surface);

    result.texture = tex;
    result.width = pw;
    result.height = ph;
    return result;
}

TextTexture GLTextRenderer::render(const std::string& text, const std::string& font,
                                    float r, float g, float b) {
    std::string key = makeKey(text, font, r, g, b);
    auto it = cache.find(key);
    if (it != cache.end()) return it->second;

    TextTexture tt = renderToTexture(text, font, r, g, b);
    cache[key] = tt;
    return tt;
}

TextTexture GLTextRenderer::renderUncached(const std::string& text, const std::string& font,
                                            float r, float g, float b) {
    return renderToTexture(text, font, r, g, b);
}

void GLTextRenderer::invalidate(const std::string& text, const std::string& font,
                                 float r, float g, float b) {
    std::string key = makeKey(text, font, r, g, b);
    auto it = cache.find(key);
    if (it != cache.end()) {
        if (it->second.texture) glDeleteTextures(1, &it->second.texture);
        cache.erase(it);
    }
}

void GLTextRenderer::clearCache() {
    for (auto& kv : cache) {
        if (kv.second.texture) glDeleteTextures(1, &kv.second.texture);
    }
    cache.clear();
}

void GLTextRenderer::freeTexture(TextTexture& tt) {
    if (tt.texture) {
        glDeleteTextures(1, &tt.texture);
        tt.texture = 0;
    }
}
