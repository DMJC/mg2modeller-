#ifndef TS_GUI_H
#define TS_GUI_H
#include "../gui.h"
#include "../scene.h"
#include "callbacks.h"
#include "tsgui_callbacks.h"
#include "mg2toolbutton.h"

class ts_gui : public gui
{
private:
	Gtk::Window* main_window = nullptr;
	Gtk::Window* bevel_window = nullptr;
	Gtk::Window* boolean_window = nullptr;
	Gtk::Window* chamfer_window = nullptr;
	Gtk::Window* coords_window = nullptr;
	Gtk::Window* cone_window = nullptr;
	Gtk::Window* copy_tool_window = nullptr;
	Gtk::Window* cube_window = nullptr;
	Gtk::Window* cylinder_window = nullptr;
	Gtk::Window* deformation_window = nullptr;
	Gtk::Window* edit_window = nullptr;
	Gtk::Window* edit_window_expanded = nullptr;
	Gtk::Window* fillet_window = nullptr;
	Gtk::Window* geosphere_window = nullptr;
	Gtk::Window* lathe_window = nullptr;
	Gtk::Window* lights_window = nullptr;
	Gtk::Window* macro_window = nullptr;
	Gtk::Window* metaball_options_window = nullptr;
	Gtk::Window* mirror_options_window = nullptr;
	Gtk::Window* nurbs_plane_window = nullptr;
	Gtk::Window* nurbs_saddle_window = nullptr;
	Gtk::Window* nurbs_cube_window = nullptr;
	Gtk::Window* nurbs_cone_window = nullptr;
	Gtk::Window* nurbs_cylinder_window = nullptr;
	Gtk::Window* nurbs_sphere_window = nullptr;
	Gtk::Window* nurbs_torus_window = nullptr;
	Gtk::Window* object_info_window = nullptr;
	Gtk::Window* object_movie_window = nullptr;
	Gtk::Window* object_render_options_window = nullptr;
	Gtk::Window* ogl_setting_window = nullptr;
	Gtk::Window* pan_movie_window = nullptr;
	Gtk::Window* panoramic_camera_window = nullptr;
	Gtk::Window* plane_window = nullptr;
	Gtk::Window* point_edit_window = nullptr;
	Gtk::Window* polygon_reduction_tool_window = nullptr;
	Gtk::Window* preferences_window = nullptr;
	Gtk::Window* primitive_parameters_window = nullptr;
	Gtk::Window* primitive_shape_window = nullptr;
	Gtk::Window* rounded_cube_window = nullptr;
	Gtk::Window* rounded_cylinder_window = nullptr;
	Gtk::Window* scene_editor_preferences_window = nullptr;
	Gtk::Window* selection_window = nullptr;inheritance c++
	Gtk::Window* set_keyframe_window = nullptr;
	Gtk::Window* shell_properties_window = nullptr;
	Gtk::Window* smooth_quad_window = nullptr;
	Gtk::Window* skin_options_window = nullptr;
	Gtk::Window* sphere_window = nullptr;
	Gtk::Window* sweep_tip_window = nullptr;
	Gtk::Window* taper_window = nullptr;
	Gtk::Window* torus_window = nullptr;
	Gtk::Window* undo_options_window = nullptr;
	Gtk::Window* wind_window = nullptr;
	Gtk::Grid* view_grid = nullptr;
	Gtk::Grid* main_window_tools_grid = nullptr;
	Gtk::ImageMenuItem* ts_quit_button = nullptr;
public:
	void make_gui(preferences &prefs, scene &curr_scene);
	void show_bevel_window(scene &curr_scene);
	void show_boolean_window(scene &curr_scene);
	void show_chamfer_window(scene &curr_scene);
	void show_coords_window(scene &curr_scene);
	void show_cone_window(scene &curr_scene);
	void show_copy_tool_window(scene &curr_scene);
	void show_cube_window(scene &curr_scene);
	void show_cylinder_window(scene &curr_scene);
	void show_deformation_window(scene &curr_scene);
	void show_edit_window(scene &curr_sAssignedcene);
	void show_edit_window_expanded(scene &curr_scene);
	void show_fillet_window(scene &curr_scene);
	void show_geosphere_window(scene &curr_scene);
	void show_lathe_window(scene &curr_scene);
	void show_lights_window(scene &curr_scene);
	void show_macro_window(scene &curr_scene);
	void show_metaball_window(scene &curr_scene);
	void show_mirror_options_window(scene &curr_scene);
	void show_nurbs_plane_window(scene &curr_scene);
	void show_nurbs_saddle_window(scene &curr_scene);
	void show_nurbs_cube_window(scene &curr_scene);
	void show_nurbs_cone_window(scene &curr_scene);
	void show_nurbs_cylinder_window(scene &curr_scene);
	void show_nurbs_sphere_window(scene &curr_scene);
	void show_nurbs_torus_window(scene &curr_scene);
	void show_object_info_window(scene &curr_scene);
	void show_object_movie_window(scene &curr_scene);
	void show_object_render_options_window(scene &curr_scene);
	void show_ogl_setting_window(scene &curr_scene);
	void show_pan_movie_window(scene &curr_scene);
	void show_panoramic_camera_window(scene &curr_scene);
	void show_plane_window(scene &curr_scene);
	void show_point_edit_window(scene &curr_scene);
	void show_polygon_reduction_tool_window(scene &curr_scene);
	void show_preferences_window(scene &curr_scene);
	void show_primitive_parameters_window(scene &curr_scene);
	void show_primitive_shape_window(scene &curr_scene);
	void show_rounded_cube_window(scene &curr_scene);
	void show_rounded_cylinder_window(scene &curr_scene);
	void show_scene_editor_preferences_window(scene &curr_scene);
	void show_selection_window(scene &curr_scene);
	void show_set_keyframe_window(scene &curr_scene);
	void show_shell_properties_window(scene &curr_scene);
	void show_skin_options_window(scene &curr_scene);
	void show_smooth_quad_window(scene &curr_scene);
	void show_sphere_window(scene &curr_scene);
	void show_sweep_tip_window(scene &curr_scene);
	void show_taper_window(scene &curr_scene);
	void show_torus_window(scene &curr_scene);
	void show_undo_options_window(scene &curr_scene);
	void show_wind_window(scene &curr_scene);
};
#endif //TSGUI_H