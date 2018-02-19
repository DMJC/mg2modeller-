#ifndef TDSGUI_CALLBACKS_H
#define TDSGUI_CALLBACKS_H
#include "../mg2.h"

extern "C" void object_droplist_callback(Gtk::Builder* builder);

void select_sphere_tool(void);
void select_box_tool(void);
void select_cylinder_tool(void);
void select_torus_tool(void);
void select_tube_tool(void);
void select_cone_tool(void);
void select_hedra_tool(void);
void select_teapot_tool(void);
void select_plane_tool(void);
void select_geosphere_tool(void);

void file_new_cb(void);
void file_open_cb(void);
void file_save_cb(string filename);
void file_saveas_cb(void);
#endif //TDSGUI_CALLBACKS_H
