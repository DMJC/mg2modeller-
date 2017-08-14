#include "../../include/gui/mg2toolbutton.h"


ToolButton::ToolButton(std::list<tool>& tool_list)
{
    std::cout << "Initialised" << std::endl;
    this->start_time = 0;
    this->signal_button_press_event().connect(sigc::mem_fun(this, &ToolButton::mg2_button_press), false);
    this->signal_button_release_event().connect(sigc::mem_fun(this, &ToolButton::mg2_button_release), false);
    this->name = tool_list.front().name;
    this->tooltip = tool_list.front().tooltip;
    this->image_filename = tool_list.front().image_filename;
    this->left_click_callback = tool_list.front().left_click_callback;
    this->right_click_callback = tool_list.front().right_click_callback;
    this->long_left_click_callback = tool_list.front().long_left_click_callback;
    this->long_right_click_callback = tool_list.front().long_right_click_callback;
    this->tool_list = &tool_list;
    this->set_size_request(32, 24);
	this->Set_Gravity( Gdk::GRAVITY_NORTH, Gdk::GRAVITY_SOUTH );
    this->buttonimage = new Gtk::Image( this->image_filename );
    this->set_image(*this->buttonimage);
    this->show();
}

void ToolButton::set_button(std::list<tool>& tool_list, int position){
    std::list<tool>::iterator it = tool_list.begin();
    std::advance(it, position);
    std::cout << "moving item: " << position << " to front of the list." << std::endl;
    this->image_filename = it->image_filename;
    this->buttonimage = new Gtk::Image( this->image_filename );
    this->set_image(*this->buttonimage);
    this->left_click_callback = it->left_click_callback;
    this->right_click_callback = it->right_click_callback;
    this->long_left_click_callback = it->long_left_click_callback;
    this->long_right_click_callback = it->long_right_click_callback;
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
	    if ((finish_time - this->start_time) >= 200 && this->tool_list->size() > 1){
		    std::cout << "Menu click" << std::endl;
			this->Trigger_Menu(*this->tool_list, event);
	    } else {
		    std::cout << "short right click" << std::endl;
			if(this->right_click_callback != nullptr){
			    this->right_click_callback();
			}else{
			    std::cout << "No Right Click Action" << std::endl;
			}
	    }
	break;
	default:
	    if ((finish_time - this->start_time) >= 200 && this->tool_list->size() > 1){
		    std::cout << "Menu click" << std::endl;
			this->Trigger_Menu(*this->tool_list, event);
	    } else {
		    std::cout << "short left click" << std::endl;
			if(this->left_click_callback != nullptr){
			    this->left_click_callback();
			}else{
			    std::cout << "No Left Click Action" << std::endl;
			}
	    }
	}
	std::cout << "Click Took: " << finish_time - this->start_time << std::endl;
}

void ToolButton::Trigger_Menu(std::list<tool>& tool_list, GdkEventButton * event){
    std::cout << "Opening Menu" << std::endl;
    int list_size = 0;
    list_size = tool_list.size();
    list<string>::const_iterator current_tool;
    std::cout << "list is: " << list_size << " elements long" <<std::endl;
    Gtk::Menu *Menu;
    Menu = Gtk::manage(new Gtk::Menu);
    int i = 0;
    for(list<tool>::const_iterator current_tool = tool_list.begin(); current_tool != tool_list.end(); current_tool++){
        std::cout << (*current_tool).name << std::endl;
    	Gtk::Image *ButtonImage = Gtk::manage(new Gtk::Image((*current_tool).image_filename));
        Gtk::MenuItem *MenuItem = Gtk::manage(new Gtk::MenuItem(*ButtonImage));
	MenuItem->set_size_request(32, 24);
        MenuItem->signal_activate().connect(sigc::bind(sigc::mem_fun(*this, &ToolButton::set_button), tool_list, i));
        std::cout << (*current_tool).tooltip << std::endl;
    	std::cout << (*current_tool).image_filename << std::endl;
    	Menu->attach(*MenuItem,0,1,i,i+1);
        i++;
    }
//    Menu->set_size_request(32, 24);
    Menu->set_reserve_toggle_size(FALSE);
	Menu->popup_at_widget(this, this->Gravity_Menu, this->Gravity_Button, nullptr);
	Menu->show_all();
    std::cout << "Showing Tools" << std::endl;
}

void ToolButton::Set_Gravity(Gdk::Gravity Gravity_Menu, Gdk::Gravity Gravity_Button){
		this->Gravity_Menu = Gravity_Menu;
		this->Gravity_Button = Gravity_Button;
}

Gdk::Gravity ToolButton::Get_Gravity_Menu(void){
	return this->Gravity_Menu;
}

Gdk::Gravity ToolButton::Get_Gravity_Button(void){
	return this->Gravity_Button;
}