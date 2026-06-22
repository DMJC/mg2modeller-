#ifndef TS_GUI_H
#define TS_GUI_H
#include "../gui.h"
#include "../scene.h"
#include <set>
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
	Gtk::Window* selection_window = nullptr;
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
	Gtk::MenuItem* ts_save_layout_menuitem = nullptr;
	Gtk::MenuItem* ts_display_options_menuitem = nullptr;
	Gtk::MenuItem* ts_preferences_menuitem = nullptr;

	// Object Info widgets
	Gtk::Entry* obj_info_name = nullptr;
	Gtk::Entry* obj_info_loc_x = nullptr;
	Gtk::Entry* obj_info_loc_y = nullptr;
	Gtk::Entry* obj_info_loc_z = nullptr;
	Gtk::Entry* obj_info_rot_x = nullptr;
	Gtk::Entry* obj_info_rot_y = nullptr;
	Gtk::Entry* obj_info_rot_z = nullptr;
	Gtk::Entry* obj_info_sca_x = nullptr;
	Gtk::Entry* obj_info_sca_y = nullptr;
	Gtk::Entry* obj_info_sca_z = nullptr;
	Gtk::Label* obj_info_verts = nullptr;
	Gtk::Label* obj_info_faces = nullptr;

	// Shape parameter spin buttons
	Gtk::SpinButton* plane_resolution_spin = nullptr;
	Gtk::SpinButton* cube_resolution_spin = nullptr;
	Gtk::SpinButton* cone_lat_spin = nullptr;
	Gtk::SpinButton* cone_long_spin = nullptr;
	Gtk::SpinButton* cylinder_lat_spin = nullptr;
	Gtk::SpinButton* cylinder_long_spin = nullptr;
	Gtk::SpinButton* cylinder_top_radius_spin = nullptr;
	Gtk::SpinButton* sphere_lat_spin = nullptr;
	Gtk::SpinButton* sphere_long_spin = nullptr;
	Gtk::SpinButton* geosphere_resolution_spin = nullptr;
	Gtk::SpinButton* rounded_cube_lat_spin = nullptr;
	Gtk::SpinButton* rounded_cube_long_spin = nullptr;
	Gtk::SpinButton* rounded_cylinder_lat_spin = nullptr;
	Gtk::SpinButton* rounded_cylinder_long_spin = nullptr;
	Gtk::SpinButton* torus_lat_spin = nullptr;
	Gtk::SpinButton* torus_long_spin = nullptr;
	Gtk::SpinButton* torus_inner_radius_spin = nullptr;

	// Sub-element edit state
	int info_edit_mode = 0;
	float info_center[3] = {0, 0, 0};

	// Multi-object selection state
	int info_multi_count = 0;
	double multi_obj_center[3] = {0, 0, 0};

	void collectSelectedVertexIndices(scene &curr_scene, std::set<int>& out_indices);
	void computeVertexCenter(scene &curr_scene, const std::set<int>& indices, float* center);

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
	void update_object_info(scene &curr_scene);
	void on_object_info_entry_changed(scene *curr_scene);
	void on_plane_param_activated(scene *curr_scene);
	void on_cube_param_activated(scene *curr_scene);
	void on_cone_param_activated(scene *curr_scene);
	void on_cylinder_param_activated(scene *curr_scene);
	void on_sphere_param_activated(scene *curr_scene);
	void on_geosphere_param_activated(scene *curr_scene);
	void on_rounded_cube_param_activated(scene *curr_scene);
	void on_rounded_cylinder_param_activated(scene *curr_scene);
	void on_torus_param_activated(scene *curr_scene);
	void on_save_layout(scene *curr_scene);
};
#endif //TSGUI_H
