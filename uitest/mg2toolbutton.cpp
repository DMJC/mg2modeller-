#include "mg2toolbutton.h"

ToolButton::ToolButton(std::list<tool>& tool_list)
{
    std::cout << "Initialised" << std::endl;
    this->start_time = 0;
    this->signal_button_press_event().connect(sigc::mem_fun(this, &ToolButton::mg2_button_press), false);
    this->signal_button_release_event().connect(sigc::mem_fun(this, &ToolButton::mg2_button_release), false);
    this->name = tool_list.front().name;
    this->tooltip = tool_list.front().tooltip;
    this->image_filename = tool_list.front().image_filename;
    void (*left_click_callback)(void) = tool_list.front().left_click_callback;
    void (*right_click_callback)(void) = tool_list.front().right_click_callback;
    void (*long_left_click_callback)(void) = tool_list.front().long_left_click_callback;
    void (*long_right_click_callback)(void) = tool_list.front().long_right_click_callback;
    this->set_size_request(32, 24);
    this->buttonimage = new Gtk::Image( this->image_filename );
    this->set_image(*this->buttonimage);
    this->show();
}

void ToolButton::set_button(std::list<tool>& tool_list, int position){
    this->left_click_callback = tool_list.front().left_click_callback;
    this->right_click_callback = tool_list.front().right_click_callback;
    this->long_left_click_callback = tool_list.front().long_left_click_callback;
    this->long_right_click_callback = tool_list.front().long_right_click_callback;
    
    this->image_filename = tool_list.front().image_filename;
    this->buttonimage = new Gtk::Image( this->image_filename );
    this->set_image(*this->buttonimage);
};


unsigned int ToolButton::mg2_button_press(GdkEventButton * event){
    std::cout << "Button Pressed at: " << event->time << std::endl;
    this->start_time = event->time;
}

unsigned int ToolButton::mg2_button_release(GdkEventButton * event){
    std::cout << "Button Released at: " << event->time << std::endl;
    unsigned int finish_time = 0;
    finish_time = event->time;
	std::cout << "Finish Time: " << finish_time << std::endl;

	switch (event->button){

	case 3:
	    if ((finish_time - this->start_time) >= 200){
		    std::cout << "Menu click" << std::endl;

	    } else {
		    std::cout << "short right click" << std::endl;

	    }
	break;
	default:
	    if ((finish_time - this->start_time) >= 200){
		    std::cout << "Menu click" << std::endl;

	    } else {
		    std::cout << "short left click" << std::endl;

	    }
	}
	std::cout << "Click Took: " << finish_time - this->start_time << std::endl;
}

