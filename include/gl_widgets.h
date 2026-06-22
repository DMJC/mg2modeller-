#ifndef GL_WIDGETS_H
#define GL_WIDGETS_H

#include <epoxy/gl.h>
#include <string>
#include <vector>
#include <functional>
#include <memory>
#include "gl_text.h"
#include "shader.h"

class GLWindow;

class GLWidget {
    friend class GLWindow;
protected:
    float x = 0, y = 0;
    float width = 100, height = 24;
    bool visible = true;
    bool enabled = true;
    bool focused = false;
    GLWindow* parent_window = nullptr;

public:
    virtual ~GLWidget() = default;
    void setBounds(float x, float y, float w, float h);
    void setVisible(bool v) { visible = v; }
    bool isVisible() const { return visible; }
    bool isFocused() const { return focused; }
    virtual void setFocus(bool f) { focused = f; }
    virtual bool wantsKeyboard() const { return false; }
    void setParentWindow(GLWindow* w) { parent_window = w; }

    bool containsPoint(float mx, float my, float px, float py) const;

    virtual void render(GLTextRenderer& tr, float px, float py, int vp_w, int vp_h) = 0;
    virtual bool onPress(float mx, float my, int button) { return false; }
    virtual bool onRelease(float mx, float my, int button) { return false; }
    virtual bool onKeyPress(unsigned int keyval, unsigned int state) { return false; }
    virtual bool onTextInput(const char* text) { return false; }
};

class GLLabel : public GLWidget {
    std::string text;
    TextTexture tex = {};
    bool dirty = true;
public:
    GLLabel(const std::string& text);
    void setText(const std::string& t);
    const std::string& getText() const { return text; }
    void render(GLTextRenderer& tr, float px, float py, int vp_w, int vp_h) override;
};

class GLButton : public GLWidget {
    std::string label;
    TextTexture tex = {};
    bool dirty = true;
    std::function<void()> on_click;
public:
    GLButton(const std::string& label, std::function<void()> callback);
    void render(GLTextRenderer& tr, float px, float py, int vp_w, int vp_h) override;
    bool onRelease(float mx, float my, int button) override;
};

class GLCheckBox : public GLWidget {
    std::string label;
    bool checked = false;
    TextTexture tex = {};
    bool dirty = true;
    std::function<void(bool)> on_change;
public:
    GLCheckBox(const std::string& label, std::function<void(bool)> callback = nullptr);
    void setChecked(bool c);
    bool isChecked() const { return checked; }
    void render(GLTextRenderer& tr, float px, float py, int vp_w, int vp_h) override;
    bool onRelease(float mx, float my, int button) override;
};

class GLTextInput : public GLWidget {
protected:
    std::string text;
    std::string prev_text;
    int cursor_pos = 0;
    int sel_start = -1;
    int sel_end = -1;
    TextTexture tex = {};
    bool text_dirty = true;
    int blink_counter = 0;
    std::function<void(const std::string&)> on_activate;

    void deleteSelection();
    void deleteChar();
    void backspaceChar();
    void moveCursorLeft(bool shift);
    void moveCursorRight(bool shift);
    void selectAll();
    void clearSelection();
    bool hasSelection() const;
    int selMin() const;
    int selMax() const;
    void commitValue();
    void renderSelectionAndCursor(GLTextRenderer& tr, float ax, float ay, int vp_w, int vp_h);

public:
    GLTextInput(std::function<void(const std::string&)> callback = nullptr);
    void setText(const std::string& t);
    const std::string& getText() const { return text; }
    void setOnActivate(std::function<void(const std::string&)> cb) { on_activate = cb; }
    bool wantsKeyboard() const override { return true; }
    void setFocus(bool f) override;
    void render(GLTextRenderer& tr, float px, float py, int vp_w, int vp_h) override;
    bool onPress(float mx, float my, int button) override;
    bool onKeyPress(unsigned int keyval, unsigned int state) override;
    bool onTextInput(const char* text) override;
};

class GLSpinButton : public GLTextInput {
    double value = 0.0;
    double min_val = 0.0, max_val = 9999.0;
    double step = 1.0;
    int digits = 0;
    std::function<void(double)> on_value_changed;

    void updateTextFromValue();
    void updateValueFromText();
    void increment(double delta);

public:
    GLSpinButton(double min_val, double max_val, double step, int digits = 0,
                 std::function<void(double)> callback = nullptr);
    void setValue(double v);
    double getValue() const { return value; }
    void setRange(double mn, double mx) { min_val = mn; max_val = mx; }
    void render(GLTextRenderer& tr, float px, float py, int vp_w, int vp_h) override;
    bool onPress(float mx, float my, int button) override;
    bool onKeyPress(unsigned int keyval, unsigned int state) override;
};

class GLComboBox : public GLWidget {
    std::vector<std::string> items;
    int selected_index = -1;
    bool dropdown_open = false;
    TextTexture tex = {};
    bool dirty = true;
    std::vector<TextTexture> item_textures;
    bool items_dirty = true;
    std::function<void(int, const std::string&)> on_change;

public:
    GLComboBox(const std::vector<std::string>& items,
               std::function<void(int, const std::string&)> callback = nullptr);
    void setItems(const std::vector<std::string>& items);
    void setSelectedIndex(int idx);
    int getSelectedIndex() const { return selected_index; }
    std::string getSelectedText() const;
    bool isDropdownOpen() const { return dropdown_open; }
    void closeDropdown() { dropdown_open = false; }
    bool wantsKeyboard() const override { return true; }
    void setFocus(bool f) override;
    void render(GLTextRenderer& tr, float px, float py, int vp_w, int vp_h) override;
    bool onPress(float mx, float my, int button) override;
    bool onRelease(float mx, float my, int button) override;
    bool onKeyPress(unsigned int keyval, unsigned int state) override;
    float dropdownHeight() const { return items.size() * height; }
};

class GLWindow {
public:
    static const int TITLE_BAR_H = 22;
    static const int CLOSE_BTN_SIZE = 22;

private:
    std::string title;
    float pos_x = 100, pos_y = 100;
    float win_width = 200, win_height = 150;
    bool visible = false;
    bool dragging = false;
    float drag_off_x = 0, drag_off_y = 0;
    TextTexture title_tex = {};
    bool title_dirty = true;
    std::vector<std::unique_ptr<GLWidget>> children;
    std::string name;

public:
    GLWindow(const std::string& name, const std::string& title, float w, float h);
    ~GLWindow();

    void setPosition(float x, float y) { pos_x = x; pos_y = y; }
    void setSize(float w, float h) { win_width = w; win_height = h; }
    float getX() const { return pos_x; }
    float getY() const { return pos_y; }
    float getWidth() const { return win_width; }
    float getHeight() const { return win_height + TITLE_BAR_H; }
    const std::string& getName() const { return name; }
    const std::string& getTitle() const { return title; }
    void setTitle(const std::string& t) { title = t; title_dirty = true; }

    void show() { visible = true; }
    void hide() { visible = false; }
    bool isVisible() const { return visible; }

    void addWidget(GLWidget* w);
    GLWidget* findWidget(int index);
    int widgetCount() const { return (int)children.size(); }

    void render(GLTextRenderer& tr, int vp_w, int vp_h);
    bool hitTest(float mx, float my) const;
    bool titleBarHit(float mx, float my) const;
    bool closeButtonHit(float mx, float my) const;
    float contentX() const { return pos_x; }
    float contentY() const { return pos_y + TITLE_BAR_H; }

    bool onPress(float mx, float my, int button, GLWidget*& out_focused);
    bool onRelease(float mx, float my, int button);
    bool onMotion(float mx, float my, int vp_w, int vp_h);
    void stopDrag() { dragging = false; }

    GLWidget* focusNext(GLWidget* current);
    GLWidget* focusPrev(GLWidget* current);
};

#endif // GL_WIDGETS_H
