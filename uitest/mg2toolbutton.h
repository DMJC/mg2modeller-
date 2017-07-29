#ifndef MG2TOOLBUTTON_H
#define MG2TOOLBUTTON_H
#include <gtkmm.h>
#include "mg2button.h"
#include "mg2buttonmenu.h"
#include "tool.h"
#include <iostream>
#include <string>

struct pressrelease {
    unsigned int button;
    unsigned int time;
};

class ToolButton : public Gtk::Button
{
protected:
    Gtk::Menu *menu;
    Gtk::Image *buttonimage;

    std::string name;
    std::string tooltip;
    std::string image_filename;
    void (*left_click_callback)(void);
    void (*right_click_callback)(void);
    void (*long_left_click_callback)(void);
    void (*long_right_click_callback)(void);
    int start_time;
public:
    ToolButton(std::list<tool>& tool_list);
    void set_button(std::list<tool>& tool_list, int position);
    unsigned int mg2_button_press(GdkEventButton * event);
    unsigned int mg2_button_release(GdkEventButton * event);
};
#endif //MG2TOOLBUTTON_H
