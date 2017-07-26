#ifndef TDSGUI_H
#define TDSGUI_H
#include "../gui.h"
#include "../scene.h"
#include "callbacks.h"
#include "tdsgui_callbacks.h"

enum object_type { TORUS, TEAPOT, TUBE, SPHERE, PYRAMID, PLANE, GEOSPHERE, CYLINDER, CUBE, CONE };

class tds_gui : public gui
{
private:
	Gtk::Widget *object_properties = nullptr;
	Gtk::Widget *name_color_expander = nullptr;
public:
	void make_gui(preferences &prefs, scene &scene);
/*	void unset_object_properties(void);
	void set_object_properties(object_type object_ui);*/
	void show_material_win(preferences &prefs, scene &scene);
	void show_rendering_win(preferences &prefs, scene &scene);

};
#endif //TDSGUI_H
