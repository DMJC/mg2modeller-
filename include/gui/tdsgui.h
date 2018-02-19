#ifndef TDSGUI_H
#define TDSGUI_H
#include "../gui.h"
#include "../scene.h"
#include "callbacks.h"
#include "tdsgui_callbacks.h"

class tds_gui : public gui
{
private:
	Gtk::Widget *object_properties = nullptr;
	Gtk::Widget *name_color_expander = nullptr;
	Gtk::Window* main_window = nullptr;
	Gtk::Window*material_editor_window = nullptr;
	Gtk::Window*rendering_editor_window = nullptr;
	Gtk::Grid* view_grid = nullptr;
	Gtk::ImageMenuItem* tds_quit_button = nullptr;
	Gtk::Widget* standard_primitive_button_grid = nullptr;
	Gtk::Widget* extended_primitive_button_grid = nullptr;
	Gtk::Widget* compound_object_button_grid = nullptr;
	Gtk::Widget* nurbs_button_grid = nullptr;
	Gtk::Widget* particle_button_grid = nullptr;
	Gtk::Widget* patch_button_grid = nullptr;
	Gtk::Widget* doors_button_grid = nullptr;
	Gtk::Widget* windows_button_grid = nullptr;
	Gtk::Widget* dynamics_button_grid = nullptr;
	Gtk::ComboBoxText* object_type_combo = nullptr;
	Gtk::Expander* object_expander = nullptr;
	
	scene* cur_scene;
	preferences* prefs;
public:
	void make_gui(preferences &prefs, scene &scene);
/*	void unset_object_properties(void);
	void set_object_properties(object_type object_ui);*/
	void show_material_win(preferences &prefs, scene &scene);
	void show_rendering_win(preferences &prefs, scene &scene);
	void object_droplist_callback();
};
#endif //TDSGUI_H
