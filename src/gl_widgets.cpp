#include "../include/gl_widgets.h"
#include "../include/gl_window_manager.h"
#include "../include/gl_expr.h"
#include <gdk/gdkkeysyms.h>
#include <gdk/gdk.h>
#include <cstdio>
#include <cmath>
#include <cstring>

static const char* LABEL_FONT = "Sans 11";
static const char* TITLE_FONT = "Sans Bold 12";
static const char* INPUT_FONT = "Sans 11";

// ============================================================
// GLWidget
// ============================================================

void GLWidget::setBounds(float x_, float y_, float w, float h) {
    x = x_; y = y_; width = w; height = h;
}

bool GLWidget::containsPoint(float mx, float my, float px, float py) const {
    float ax = px + x, ay = py + y;
    return mx >= ax && mx < ax + width && my >= ay && my < ay + height;
}

// ============================================================
// GLLabel
// ============================================================

GLLabel::GLLabel(const std::string& t) : text(t) {}

void GLLabel::setText(const std::string& t) {
    if (t != text) { text = t; dirty = true; }
}

void GLLabel::render(GLTextRenderer& tr, float px, float py, int vp_w, int vp_h) {
    if (!visible || text.empty()) return;
    if (dirty || !tex.texture) {
        if (tex.texture) tr.freeTexture(tex);
        tex = tr.renderUncached(text, LABEL_FONT, 0.9f, 0.9f, 0.9f);
        dirty = false;
    }
    float ax = px + x, ay = py + y;
    GLWindowManager::renderTexQuad(ax, ay + (height - tex.height) * 0.5f,
                                   tex.width, tex.height, tex.texture, vp_w, vp_h);
}

// ============================================================
// GLButton
// ============================================================

GLButton::GLButton(const std::string& l, std::function<void()> cb)
    : label(l), on_click(cb) {}

void GLButton::render(GLTextRenderer& tr, float px, float py, int vp_w, int vp_h) {
    if (!visible) return;
    float ax = px + x, ay = py + y;
    GLWindowManager::renderRect(ax, ay, width, height, 0.35f, 0.35f, 0.35f, 1.0f, vp_w, vp_h);
    if (dirty || !tex.texture) {
        if (tex.texture) tr.freeTexture(tex);
        tex = tr.renderUncached(label, LABEL_FONT, 0.9f, 0.9f, 0.9f);
        dirty = false;
    }
    float tx = ax + (width - tex.width) * 0.5f;
    float ty = ay + (height - tex.height) * 0.5f;
    GLWindowManager::renderTexQuad(tx, ty, tex.width, tex.height, tex.texture, vp_w, vp_h);
}

bool GLButton::onRelease(float mx, float my, int button) {
    if (button == 1 && on_click) { on_click(); return true; }
    return false;
}

// ============================================================
// GLCheckBox
// ============================================================

GLCheckBox::GLCheckBox(const std::string& l, std::function<void(bool)> cb)
    : label(l), on_change(cb) {}

void GLCheckBox::setChecked(bool c) { checked = c; }

void GLCheckBox::render(GLTextRenderer& tr, float px, float py, int vp_w, int vp_h) {
    if (!visible) return;
    float ax = px + x, ay = py + y;
    float box_size = height - 4;
    float bx = ax + 2, by = ay + 2;
    GLWindowManager::renderRect(bx, by, box_size, box_size, 0.20f, 0.20f, 0.20f, 1.0f, vp_w, vp_h);
    if (checked) {
        float m = 3;
        GLWindowManager::renderRect(bx + m, by + m, box_size - m * 2, box_size - m * 2,
                                    0.9f, 0.9f, 0.9f, 1.0f, vp_w, vp_h);
    }
    if (dirty || !tex.texture) {
        if (tex.texture) tr.freeTexture(tex);
        tex = tr.renderUncached(label, LABEL_FONT, 0.9f, 0.9f, 0.9f);
        dirty = false;
    }
    float tx = ax + height + 2;
    float ty = ay + (height - tex.height) * 0.5f;
    GLWindowManager::renderTexQuad(tx, ty, tex.width, tex.height, tex.texture, vp_w, vp_h);
}

bool GLCheckBox::onRelease(float mx, float my, int button) {
    if (button == 1) {
        checked = !checked;
        if (on_change) on_change(checked);
        return true;
    }
    return false;
}

// ============================================================
// GLTextInput
// ============================================================

GLTextInput::GLTextInput(std::function<void(const std::string&)> cb)
    : on_activate(cb) { height = 22; }

void GLTextInput::setText(const std::string& t) {
    text = t;
    prev_text = t;
    cursor_pos = (int)t.size();
    clearSelection();
    text_dirty = true;
}

void GLTextInput::setFocus(bool f) {
    focused = f;
    if (f) {
        prev_text = text;
        selectAll();
    } else {
        clearSelection();
        if (text != prev_text) commitValue();
    }
    blink_counter = 0;
}

bool GLTextInput::hasSelection() const { return sel_start >= 0 && sel_end >= 0 && sel_start != sel_end; }
int GLTextInput::selMin() const { return sel_start < sel_end ? sel_start : sel_end; }
int GLTextInput::selMax() const { return sel_start > sel_end ? sel_start : sel_end; }
void GLTextInput::clearSelection() { sel_start = sel_end = -1; }
void GLTextInput::selectAll() { sel_start = 0; sel_end = (int)text.size(); cursor_pos = sel_end; }

void GLTextInput::deleteSelection() {
    if (!hasSelection()) return;
    int lo = selMin(), hi = selMax();
    text.erase(lo, hi - lo);
    cursor_pos = lo;
    clearSelection();
    text_dirty = true;
}

void GLTextInput::deleteChar() {
    if (hasSelection()) { deleteSelection(); return; }
    if (cursor_pos < (int)text.size()) {
        text.erase(cursor_pos, 1);
        text_dirty = true;
    }
}

void GLTextInput::backspaceChar() {
    if (hasSelection()) { deleteSelection(); return; }
    if (cursor_pos > 0) {
        cursor_pos--;
        text.erase(cursor_pos, 1);
        text_dirty = true;
    }
}

void GLTextInput::moveCursorLeft(bool shift) {
    if (shift) {
        if (sel_start < 0) { sel_start = cursor_pos; sel_end = cursor_pos; }
        if (cursor_pos > 0) cursor_pos--;
        sel_end = cursor_pos;
    } else {
        if (hasSelection()) { cursor_pos = selMin(); clearSelection(); }
        else if (cursor_pos > 0) cursor_pos--;
    }
}

void GLTextInput::moveCursorRight(bool shift) {
    if (shift) {
        if (sel_start < 0) { sel_start = cursor_pos; sel_end = cursor_pos; }
        if (cursor_pos < (int)text.size()) cursor_pos++;
        sel_end = cursor_pos;
    } else {
        if (hasSelection()) { cursor_pos = selMax(); clearSelection(); }
        else if (cursor_pos < (int)text.size()) cursor_pos++;
    }
}

void GLTextInput::commitValue() {
    clearSelection();
    double result;
    if (GLExpr::evaluate(text, result)) {
        char buf[64];
        snprintf(buf, sizeof(buf), "%g", result);
        text = buf;
        cursor_pos = (int)text.size();
        text_dirty = true;
    }
    prev_text = text;
    if (on_activate) on_activate(text);
}

void GLTextInput::renderSelectionAndCursor(GLTextRenderer& tr, float ax, float ay, int vp_w, int vp_h) {
    if (!focused) return;

    if (hasSelection()) {
        int lo = selMin(), hi = selMax();
        float sel_x1 = ax + 3;
        float sel_x2 = ax + 3;
        if (lo > 0) {
            TextTexture m = tr.renderUncached(text.substr(0, lo), INPUT_FONT, 1.0f, 1.0f, 1.0f);
            sel_x1 = ax + 3 + m.width;
            tr.freeTexture(m);
        }
        if (hi > 0) {
            TextTexture m = tr.renderUncached(text.substr(0, hi), INPUT_FONT, 1.0f, 1.0f, 1.0f);
            sel_x2 = ax + 3 + m.width;
            tr.freeTexture(m);
        }
        float sel_w = sel_x2 - sel_x1;
        if (sel_w > 0)
            GLWindowManager::renderRect(sel_x1, ay + 2, sel_w, height - 4,
                                        1.0f, 0.0f, 0.0f, 0.5f, vp_w, vp_h);
    }

    blink_counter++;
    if ((blink_counter / 30) % 2 == 0) {
        float cursor_x = ax + 3;
        if (cursor_pos > 0 && !text.empty()) {
            TextTexture m = tr.renderUncached(text.substr(0, cursor_pos), INPUT_FONT, 1.0f, 1.0f, 1.0f);
            cursor_x = ax + 3 + m.width;
            tr.freeTexture(m);
        }
        GLWindowManager::renderRect(cursor_x, ay + 3, 1, height - 6,
                                    1.0f, 1.0f, 1.0f, 1.0f, vp_w, vp_h);
    }
}

void GLTextInput::render(GLTextRenderer& tr, float px, float py, int vp_w, int vp_h) {
    if (!visible) return;
    float ax = px + x, ay = py + y;
    if (focused) {
        GLWindowManager::renderRect(ax - 1, ay - 1, width + 2, height + 2,
                                    0.4f, 0.6f, 1.0f, 1.0f, vp_w, vp_h);
    }
    GLWindowManager::renderRect(ax, ay, width, height, 0.20f, 0.20f, 0.20f, 1.0f, vp_w, vp_h);

    if (text_dirty || !tex.texture) {
        if (tex.texture) tr.freeTexture(tex);
        if (!text.empty())
            tex = tr.renderUncached(text, INPUT_FONT, 1.0f, 1.0f, 1.0f);
        else
            tex = {};
        text_dirty = false;
    }

    renderSelectionAndCursor(tr, ax, ay, vp_w, vp_h);

    if (tex.texture) {
        float ty = ay + (height - tex.height) * 0.5f;
        GLWindowManager::renderTexQuad(ax + 3, ty, tex.width, tex.height, tex.texture, vp_w, vp_h);
    }
}

bool GLTextInput::onPress(float mx, float my, int button) {
    clearSelection();
    return true;
}

bool GLTextInput::onKeyPress(unsigned int keyval, unsigned int state) {
    bool shift = (state & GDK_SHIFT_MASK) != 0;
    bool ctrl = (state & GDK_CONTROL_MASK) != 0;

    if (ctrl && (keyval == GDK_KEY_a || keyval == GDK_KEY_A)) {
        selectAll();
        return true;
    }

    switch (keyval) {
        case GDK_KEY_Return: case GDK_KEY_KP_Enter:
            commitValue();
            return true;
        case GDK_KEY_Escape:
            text = prev_text;
            text_dirty = true;
            cursor_pos = (int)text.size();
            clearSelection();
            return true;
        case GDK_KEY_BackSpace:
            backspaceChar();
            return true;
        case GDK_KEY_Delete: case GDK_KEY_KP_Delete:
            deleteChar();
            return true;
        case GDK_KEY_Left: case GDK_KEY_KP_Left:
            moveCursorLeft(shift);
            return true;
        case GDK_KEY_Right: case GDK_KEY_KP_Right:
            moveCursorRight(shift);
            return true;
        case GDK_KEY_Home:
            if (shift) {
                if (sel_start < 0) { sel_start = cursor_pos; sel_end = cursor_pos; }
                cursor_pos = 0; sel_end = 0;
            } else { cursor_pos = 0; clearSelection(); }
            return true;
        case GDK_KEY_End:
            if (shift) {
                if (sel_start < 0) { sel_start = cursor_pos; sel_end = cursor_pos; }
                cursor_pos = (int)text.size(); sel_end = cursor_pos;
            } else { cursor_pos = (int)text.size(); clearSelection(); }
            return true;
    }
    return false;
}

bool GLTextInput::onTextInput(const char* input) {
    if (!input) return false;
    if (hasSelection()) deleteSelection();
    text.insert(cursor_pos, input);
    cursor_pos += strlen(input);
    text_dirty = true;
    return true;
}

// ============================================================
// GLSpinButton
// ============================================================

GLSpinButton::GLSpinButton(double mn, double mx, double st, int dig,
                           std::function<void(double)> cb)
    : min_val(mn), max_val(mx), step(st), digits(dig), on_value_changed(cb) {
    height = 22;
    on_activate = [this](const std::string&) { updateValueFromText(); };
}

void GLSpinButton::setValue(double v) {
    if (v < min_val) v = min_val;
    if (v > max_val) v = max_val;
    value = v;
    updateTextFromValue();
}

void GLSpinButton::updateTextFromValue() {
    char buf[64];
    snprintf(buf, sizeof(buf), "%.*f", digits, value);
    text = buf;
    cursor_pos = (int)text.size();
    text_dirty = true;
}

void GLSpinButton::updateValueFromText() {
    double result;
    if (GLExpr::evaluate(text, result)) {
        if (result < min_val) result = min_val;
        if (result > max_val) result = max_val;
        value = result;
        if (on_value_changed) on_value_changed(value);
    }
    updateTextFromValue();
}

void GLSpinButton::increment(double delta) {
    setValue(value + delta);
    if (on_value_changed) on_value_changed(value);
}

void GLSpinButton::render(GLTextRenderer& tr, float px, float py, int vp_w, int vp_h) {
    if (!visible) return;
    float ax = px + x, ay = py + y;
    float arrow_w = 14;
    float input_w = width - arrow_w;

    GLWindowManager::renderRect(ax, ay, input_w, height, 0.20f, 0.20f, 0.20f, 1.0f, vp_w, vp_h);

    if (text_dirty || !tex.texture) {
        if (tex.texture) tr.freeTexture(tex);
        if (!text.empty())
            tex = tr.renderUncached(text, INPUT_FONT, 1.0f, 1.0f, 1.0f);
        else
            tex = {};
        text_dirty = false;
    }

    renderSelectionAndCursor(tr, ax, ay, vp_w, vp_h);

    if (tex.texture) {
        float ty = ay + (height - tex.height) * 0.5f;
        GLWindowManager::renderTexQuad(ax + 3, ty, tex.width, tex.height, tex.texture, vp_w, vp_h);
    }

    // Up/down arrow buttons
    float half_h = height * 0.5f;
    float arx = ax + input_w;
    GLWindowManager::renderRect(arx, ay, arrow_w, half_h, 0.35f, 0.35f, 0.35f, 1.0f, vp_w, vp_h);
    GLWindowManager::renderRect(arx, ay + half_h, arrow_w, half_h, 0.30f, 0.30f, 0.30f, 1.0f, vp_w, vp_h);

    // Up triangle
    float tcx = arx + arrow_w * 0.5f, tcy = ay + half_h * 0.35f;
    GLWindowManager::renderRect(tcx - 1, tcy, 3, 2, 0.9f, 0.9f, 0.9f, 1.0f, vp_w, vp_h);
    GLWindowManager::renderRect(tcx, tcy + 2, 1, 2, 0.9f, 0.9f, 0.9f, 1.0f, vp_w, vp_h);
    // Down triangle
    float tdy = ay + half_h + half_h * 0.35f;
    GLWindowManager::renderRect(tcx, tdy, 1, 2, 0.9f, 0.9f, 0.9f, 1.0f, vp_w, vp_h);
    GLWindowManager::renderRect(tcx - 1, tdy + 2, 3, 2, 0.9f, 0.9f, 0.9f, 1.0f, vp_w, vp_h);
}

bool GLSpinButton::onPress(float mx, float my, int button) {
    float ax = x;
    float arrow_w = 14;
    float input_w = width - arrow_w;
    float local_x = mx - ax;
    if (local_x >= input_w) {
        float half_h = height * 0.5f;
        float local_y = my - y;
        if (local_y < half_h)
            increment(step);
        else
            increment(-step);
        return true;
    }
    return GLTextInput::onPress(mx, my, button);
}

bool GLSpinButton::onKeyPress(unsigned int keyval, unsigned int state) {
    if (keyval == GDK_KEY_Up || keyval == GDK_KEY_KP_Up) {
        increment(step);
        return true;
    }
    if (keyval == GDK_KEY_Down || keyval == GDK_KEY_KP_Down) {
        increment(-step);
        return true;
    }
    return GLTextInput::onKeyPress(keyval, state);
}

// ============================================================
// GLComboBox
// ============================================================

GLComboBox::GLComboBox(const std::vector<std::string>& itms,
                       std::function<void(int, const std::string&)> cb)
    : items(itms), on_change(cb) { height = 22; }

void GLComboBox::setItems(const std::vector<std::string>& itms) {
    items = itms;
    items_dirty = true;
    dirty = true;
}

void GLComboBox::setSelectedIndex(int idx) {
    selected_index = idx;
    dirty = true;
}

std::string GLComboBox::getSelectedText() const {
    if (selected_index >= 0 && selected_index < (int)items.size())
        return items[selected_index];
    return "";
}

void GLComboBox::render(GLTextRenderer& tr, float px, float py, int vp_w, int vp_h) {
    if (!visible) return;
    float ax = px + x, ay = py + y;
    if (focused) {
        GLWindowManager::renderRect(ax - 1, ay - 1, width + 2, height + 2,
                                    0.4f, 0.6f, 1.0f, 1.0f, vp_w, vp_h);
    }
    GLWindowManager::renderRect(ax, ay, width, height, 0.20f, 0.20f, 0.20f, 1.0f, vp_w, vp_h);

    // Arrow indicator
    float arrow_w = 14;
    GLWindowManager::renderRect(ax + width - arrow_w, ay, arrow_w, height,
                                0.30f, 0.30f, 0.30f, 1.0f, vp_w, vp_h);
    float acx = ax + width - arrow_w * 0.5f;
    float acy = ay + height * 0.4f;
    GLWindowManager::renderRect(acx - 2, acy, 5, 2, 0.9f, 0.9f, 0.9f, 1.0f, vp_w, vp_h);
    GLWindowManager::renderRect(acx - 1, acy + 2, 3, 2, 0.9f, 0.9f, 0.9f, 1.0f, vp_w, vp_h);

    std::string display = getSelectedText();
    if (!display.empty()) {
        if (dirty || !tex.texture) {
            if (tex.texture) tr.freeTexture(tex);
            tex = tr.renderUncached(display, INPUT_FONT, 1.0f, 1.0f, 1.0f);
            dirty = false;
        }
        float ty = ay + (height - tex.height) * 0.5f;
        GLWindowManager::renderTexQuad(ax + 3, ty, tex.width, tex.height, tex.texture, vp_w, vp_h);
    }

    if (dropdown_open) {
        float dy = ay + height;
        for (int i = 0; i < (int)items.size(); i++) {
            float iy = dy + i * height;
            float bg = (i == selected_index) ? 0.30f : 0.20f;
            GLWindowManager::renderRect(ax, iy, width, height, bg, bg, bg, 1.0f, vp_w, vp_h);

            if (items_dirty || (int)item_textures.size() <= i) {
                TextTexture it = tr.renderUncached(items[i], INPUT_FONT, 1.0f, 1.0f, 1.0f);
                if (i < (int)item_textures.size()) {
                    tr.freeTexture(item_textures[i]);
                    item_textures[i] = it;
                } else {
                    item_textures.push_back(it);
                }
            }
            if (i < (int)item_textures.size() && item_textures[i].texture) {
                float ty = iy + (height - item_textures[i].height) * 0.5f;
                GLWindowManager::renderTexQuad(ax + 3, ty, item_textures[i].width,
                                               item_textures[i].height, item_textures[i].texture, vp_w, vp_h);
            }
        }
        items_dirty = false;
    }
}

bool GLComboBox::onPress(float mx, float my, int button) {
    if (button != 1) return false;
    if (dropdown_open) {
        float ay = y + height;
        float local_y = my - ay;
        if (local_y >= 0) {
            int idx = (int)(local_y / height);
            if (idx >= 0 && idx < (int)items.size()) {
                selected_index = idx;
                dirty = true;
                if (on_change) on_change(selected_index, items[selected_index]);
            }
        }
        dropdown_open = false;
        return true;
    }
    dropdown_open = true;
    return true;
}

bool GLComboBox::onRelease(float mx, float my, int button) {
    return false;
}

void GLComboBox::setFocus(bool f) {
    focused = f;
    if (!f && dropdown_open)
        dropdown_open = false;
}

bool GLComboBox::onKeyPress(unsigned int keyval, unsigned int state) {
    if (dropdown_open) {
        switch (keyval) {
            case GDK_KEY_Up: case GDK_KEY_KP_Up:
                if (selected_index > 0) {
                    selected_index--;
                    dirty = true;
                    if (on_change) on_change(selected_index, items[selected_index]);
                }
                return true;
            case GDK_KEY_Down: case GDK_KEY_KP_Down:
                if (selected_index < (int)items.size() - 1) {
                    selected_index++;
                    dirty = true;
                    if (on_change) on_change(selected_index, items[selected_index]);
                }
                return true;
            case GDK_KEY_Return: case GDK_KEY_KP_Enter:
            case GDK_KEY_Escape:
                dropdown_open = false;
                return true;
        }
        return false;
    }

    switch (keyval) {
        case GDK_KEY_Return: case GDK_KEY_KP_Enter:
        case GDK_KEY_space:
            dropdown_open = true;
            return true;
        case GDK_KEY_Up: case GDK_KEY_KP_Up:
            if (selected_index > 0) {
                selected_index--;
                dirty = true;
                if (on_change) on_change(selected_index, items[selected_index]);
            }
            return true;
        case GDK_KEY_Down: case GDK_KEY_KP_Down:
            if (selected_index < (int)items.size() - 1) {
                selected_index++;
                dirty = true;
                if (on_change) on_change(selected_index, items[selected_index]);
            }
            return true;
    }
    return false;
}

// ============================================================
// GLWindow
// ============================================================

GLWindow::GLWindow(const std::string& nm, const std::string& t, float w, float h)
    : title(t), win_width(w), win_height(h), name(nm) {}

GLWindow::~GLWindow() {
    if (title_tex.texture) glDeleteTextures(1, &title_tex.texture);
}

void GLWindow::addWidget(GLWidget* w) {
    w->setParentWindow(this);
    children.emplace_back(w);
}

GLWidget* GLWindow::findWidget(int index) {
    if (index >= 0 && index < (int)children.size())
        return children[index].get();
    return nullptr;
}

void GLWindow::render(GLTextRenderer& tr, int vp_w, int vp_h) {
    if (!visible) return;

    // Title bar
    GLWindowManager::renderRect(pos_x, pos_y, win_width, TITLE_BAR_H,
                                0.24f, 0.24f, 0.24f, 1.0f, vp_w, vp_h);

    // Close button
    float cbx = pos_x + win_width - CLOSE_BTN_SIZE;
    GLWindowManager::renderRect(cbx, pos_y, CLOSE_BTN_SIZE, CLOSE_BTN_SIZE,
                                0.64f, 0.64f, 0.64f, 1.0f, vp_w, vp_h);
    // X lines (approximated with small rects)
    for (int i = 0; i < 10; i++) {
        float t = i / 9.0f;
        GLWindowManager::renderRect(cbx + 5 + t * 12, pos_y + 5 + t * 12, 2, 2,
                                    0.0f, 0.0f, 0.0f, 1.0f, vp_w, vp_h);
        GLWindowManager::renderRect(cbx + 5 + t * 12, pos_y + 5 + (1 - t) * 12, 2, 2,
                                    0.0f, 0.0f, 0.0f, 1.0f, vp_w, vp_h);
    }

    // Title text
    if (title_dirty || !title_tex.texture) {
        if (title_tex.texture) tr.freeTexture(title_tex);
        title_tex = tr.renderUncached(title, TITLE_FONT, 1.0f, 1.0f, 1.0f);
        title_dirty = false;
    }
    if (title_tex.texture) {
        float tx = pos_x + (win_width - CLOSE_BTN_SIZE - title_tex.width) * 0.5f;
        float ty = pos_y + (TITLE_BAR_H - title_tex.height) * 0.5f;
        GLWindowManager::renderTexQuad(tx, ty, title_tex.width, title_tex.height,
                                       title_tex.texture, vp_w, vp_h);
    }

    // Content background
    float cy = pos_y + TITLE_BAR_H;
    GLWindowManager::renderRect(pos_x, cy, win_width, win_height,
                                0.30f, 0.30f, 0.30f, 1.0f, vp_w, vp_h);

    // Children
    for (auto& child : children) {
        child->render(tr, contentX(), contentY(), vp_w, vp_h);
    }
}

bool GLWindow::hitTest(float mx, float my) const {
    return mx >= pos_x && mx < pos_x + win_width &&
           my >= pos_y && my < pos_y + getHeight();
}

bool GLWindow::titleBarHit(float mx, float my) const {
    return mx >= pos_x && mx < pos_x + win_width - CLOSE_BTN_SIZE &&
           my >= pos_y && my < pos_y + TITLE_BAR_H;
}

bool GLWindow::closeButtonHit(float mx, float my) const {
    float cbx = pos_x + win_width - CLOSE_BTN_SIZE;
    return mx >= cbx && mx < cbx + CLOSE_BTN_SIZE &&
           my >= pos_y && my < pos_y + CLOSE_BTN_SIZE;
}

bool GLWindow::onPress(float mx, float my, int button, GLWidget*& out_focused) {
    if (!visible) return false;
    if (closeButtonHit(mx, my)) return true;
    if (titleBarHit(mx, my)) {
        dragging = true;
        drag_off_x = mx - pos_x;
        drag_off_y = my - pos_y;
        return true;
    }

    float cx = contentX(), cy = contentY();
    // Check combobox dropdowns first (they extend beyond normal bounds)
    for (auto& child : children) {
        GLComboBox* combo = dynamic_cast<GLComboBox*>(child.get());
        if (combo && combo->isDropdownOpen()) {
            float ax = cx + combo->x, ay = cy + combo->y + combo->height;
            float dh = combo->dropdownHeight();
            if (mx >= ax && mx < ax + combo->width && my >= ay && my < ay + dh) {
                combo->onPress(mx - cx, my - cy, button);
                out_focused = nullptr;
                return true;
            }
            combo->closeDropdown();
        }
    }

    for (auto& child : children) {
        if (child->isVisible() && child->containsPoint(mx, my, cx, cy)) {
            child->onPress(mx - cx, my - cy, button);
            if (child->wantsKeyboard())
                out_focused = child.get();
            else
                out_focused = nullptr;
            return true;
        }
    }
    out_focused = nullptr;
    return hitTest(mx, my);
}

bool GLWindow::onRelease(float mx, float my, int button) {
    if (dragging) { dragging = false; return true; }
    if (closeButtonHit(mx, my)) { hide(); return true; }

    float cx = contentX(), cy = contentY();
    for (auto& child : children) {
        if (child->isVisible() && child->containsPoint(mx, my, cx, cy)) {
            return child->onRelease(mx - cx, my - cy, button);
        }
    }
    return false;
}

bool GLWindow::onMotion(float mx, float my, int vp_w, int vp_h) {
    if (dragging) {
        pos_x = mx - drag_off_x;
        pos_y = my - drag_off_y;
        if (pos_x < 0) pos_x = 0;
        if (pos_y < 0) pos_y = 0;
        if (pos_x + win_width > vp_w) pos_x = vp_w - win_width;
        if (pos_y + getHeight() > vp_h) pos_y = vp_h - getHeight();
        return true;
    }
    return false;
}

GLWidget* GLWindow::focusNext(GLWidget* current) {
    int start = -1;
    for (int i = 0; i < (int)children.size(); i++) {
        if (children[i].get() == current) { start = i; break; }
    }
    int n = (int)children.size();
    for (int j = 1; j <= n; j++) {
        int idx = (start + j) % n;
        GLWidget* w = children[idx].get();
        if (w->isVisible() && w->wantsKeyboard())
            return w;
    }
    return current;
}

GLWidget* GLWindow::focusPrev(GLWidget* current) {
    int start = -1;
    for (int i = 0; i < (int)children.size(); i++) {
        if (children[i].get() == current) { start = i; break; }
    }
    int n = (int)children.size();
    for (int j = 1; j <= n; j++) {
        int idx = (start - j + n) % n;
        GLWidget* w = children[idx].get();
        if (w->isVisible() && w->wantsKeyboard())
            return w;
    }
    return current;
}
