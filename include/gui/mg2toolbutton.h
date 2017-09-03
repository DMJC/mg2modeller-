#ifndef MG2TOOLBUTTON_H
#define MG2TOOLBUTTON_H
#include <gtkmm.h>
#include "../tools.h"
#include <iostream>
#include <list>
#include <string>

struct pressrelease {
    unsigned int button;
    unsigned int time;
};

class ToolButton : public Gtk::Button
{
protected:
    Gtk::Image *buttonimage;

    std::list<tool> *tool_list;
    std::string name;
    std::string tooltip;
    std::string image_filename;
    callback left_click_callback;
    callback right_click_callback;
    callback long_left_click_callback;
    callback long_right_click_callback;
	scene curr_scene;
    int start_time;
	Gdk::Gravity Gravity_Menu;
	Gdk::Gravity Gravity_Button;
public:
    ToolButton(std::list<tool>& tool_list);
    void set_button(std::list<tool>& tool_list, int position);
    unsigned int mg2_button_press(GdkEventButton * event);
    unsigned int mg2_button_release(GdkEventButton * event);
    void Trigger_Menu(std::list<tool>& tool_list, GdkEventButton * event);
    void Short_Left_Click(void);
    void Short_Right_Click(void);
	void Set_Gravity(Gdk::Gravity Gravity_Menu, Gdk::Gravity Gravity_Button);
	Gdk::Gravity Get_Gravity_Menu(void);
	Gdk::Gravity Get_Gravity_Button(void);
};
#endif //MG2TOOLBUTTON_H
