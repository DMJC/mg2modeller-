#include "../include/tools.h"
#include "../include/scene.h"
#include "../include/primitive.h"
#include "../include/gui/tsgui.h"
void light_parameters (scene &curr_scene){
	curr_scene.curr_gui->show_lights_window(curr_scene);
}

void primitive_parameters (scene &curr_scene){
	curr_scene.curr_gui->show_primitive_parameters_window(curr_scene);
    curr_scene.curr_gui->show_primitive_shape_window(curr_scene);
}

void plane_parameters (scene &curr_scene){
    cout << "Current Tool is: " << curr_scene.Get_Current_Tool() << endl;
	if (curr_scene.Get_Current_Tool() == 50 ){
		curr_scene.curr_gui->show_primitive_parameters_window(curr_scene);
		curr_scene.curr_gui->show_primitive_shape_window(curr_scene);
	}else{
		curr_scene.curr_gui->show_plane_window(curr_scene);
	}
}

void cube_parameters (scene &curr_scene){
	cout << "Current Tool is: " << curr_scene.Get_Current_Tool() << endl;
	if (curr_scene.Get_Current_Tool() == 51 ){
		curr_scene.curr_gui->show_primitive_parameters_window(curr_scene);
		curr_scene.curr_gui->show_primitive_shape_window(curr_scene);
	}else{
		curr_scene.curr_gui->show_cube_window(curr_scene);
	}
}


void sphere_parameters (scene &curr_scene){
	cout << "Current Tool is: " << curr_scene.Get_Current_Tool() << endl;
	if (curr_scene.Get_Current_Tool() == 54 ){
		curr_scene.curr_gui->show_primitive_parameters_window(curr_scene);
		curr_scene.curr_gui->show_primitive_shape_window(curr_scene);
	}else{
		curr_scene.curr_gui->show_sphere_window(curr_scene);
	}
}

void geosphere_parameters (scene &curr_scene){
    curr_scene.curr_gui->show_geosphere_window(curr_scene);
}

void cylinder_parameters (scene &curr_scene){
	cout << "Current Tool is: " << curr_scene.Get_Current_Tool() << endl;
	if (curr_scene.Get_Current_Tool() == 52 ){
		curr_scene.curr_gui->show_primitive_parameters_window(curr_scene);
		curr_scene.curr_gui->show_primitive_shape_window(curr_scene);
	}else{
		curr_scene.curr_gui->show_cylinder_window(curr_scene);
	}
}


void cone_parameters (scene &curr_scene){
	cout << "Current Tool is: " << curr_scene.Get_Current_Tool() << endl;
	if (curr_scene.Get_Current_Tool() == 53 ){
		curr_scene.curr_gui->show_primitive_parameters_window(curr_scene);
		curr_scene.curr_gui->show_primitive_shape_window(curr_scene);
	}else{
		curr_scene.curr_gui->show_cone_window(curr_scene);
	}
}

void torus_parameters (scene &curr_scene){
		cout << "Current Tool is: " << curr_scene.Get_Current_Tool() << endl;
	if (curr_scene.Get_Current_Tool() == 58 ){
		curr_scene.curr_gui->show_primitive_parameters_window(curr_scene);
		curr_scene.curr_gui->show_primitive_shape_window(curr_scene);
	}else{
		curr_scene.curr_gui->show_torus_window(curr_scene);
	}
}

void rounded_cube_parameters (scene &curr_scene){
		cout << "Current Tool is: " << curr_scene.Get_Current_Tool() << endl;
	if (curr_scene.Get_Current_Tool() == 57 ){
		curr_scene.curr_gui->show_primitive_parameters_window(curr_scene);
		curr_scene.curr_gui->show_primitive_shape_window(curr_scene);
	}else{
		curr_scene.curr_gui->show_rounded_cube_window(curr_scene);
	}
}

void rounded_cylinder_parameters (scene &curr_scene){
		cout << "Current Tool is: " << curr_scene.Get_Current_Tool() << endl;
	if (curr_scene.Get_Current_Tool() == 56 ){
		curr_scene.curr_gui->show_primitive_parameters_window(curr_scene);
		curr_scene.curr_gui->show_primitive_shape_window(curr_scene);
	}else{
		curr_scene.curr_gui->show_rounded_cylinder_window(curr_scene);
	}
}

void metaball_parameters (scene &curr_scene){
	cout << "Current Tool is: " << curr_scene.Get_Current_Tool() << endl;
	curr_scene.curr_gui->show_metaball_window(curr_scene);
}

void nurbs_plane_parameters (scene &curr_scene){
	curr_scene.curr_gui->show_nurbs_plane_window(curr_scene);
}

void nurbs_saddle_parameters (scene &curr_scene){
	curr_scene.curr_gui->show_nurbs_saddle_window(curr_scene);
}

void nurbs_cube_parameters (scene &curr_scene){
	curr_scene.curr_gui->show_nurbs_cube_window(curr_scene);
}

void nurbs_cylinder_parameters (scene &curr_scene){
	curr_scene.curr_gui->show_nurbs_cylinder_window(curr_scene);
}

void nurbs_cone_parameters (scene &curr_scene){
	curr_scene.curr_gui->show_nurbs_cone_window(curr_scene);
}
void nurbs_sphere_parameters (scene &curr_scene){
	curr_scene.curr_gui->show_nurbs_sphere_window(curr_scene);
}

void nurbs_torus_parameters (scene &curr_scene){
	curr_scene.curr_gui->show_nurbs_torus_window(curr_scene);
}

void view_move (scene &curr_scene){
}
void view_rotate (scene &curr_scene){
}
void view_zoom (scene &curr_scene){
}
void object_move (scene &curr_scene){
}
void object_rotate (scene &curr_scene){
}
void object_scale (scene &curr_scene){
}
void hierarchy_up (scene &curr_scene){
}
void hierarchy_down (scene &curr_scene){
}
void create_plane (scene &curr_scene){
	curr_scene.Set_Current_Tool(50);
	cout << "Current Tool is: " << curr_scene.Get_Current_Tool() << endl;
    plane(curr_scene.prefs.get_plane_resolution(), curr_scene);
}
void create_cube (scene &curr_scene){
	curr_scene.Set_Current_Tool(51);
	cout << "Current Tool is: " << curr_scene.Get_Current_Tool() << endl;
    cube(curr_scene.prefs.get_cube_resolution(), curr_scene);
}
void create_cylinder (scene &curr_scene){
	curr_scene.Set_Current_Tool(52);
	cout << "Current Tool is: " << curr_scene.Get_Current_Tool() << endl;
    cylinder(curr_scene.prefs.get_cylinder_latitude(),curr_scene.prefs.get_cylinder_longitude(),curr_scene.prefs.get_cylinder_top_radius(), curr_scene);
}
void create_cone (scene &curr_scene){
	curr_scene.Set_Current_Tool(53);
	cout << "Current Tool is: " << curr_scene.Get_Current_Tool() << endl;
    cone(curr_scene.prefs.get_cone_latitude(), curr_scene.prefs.get_cone_longitude(), curr_scene);
}
void create_sphere (scene &curr_scene){
	curr_scene.Set_Current_Tool(54);
	cout << "Current Tool is: " << curr_scene.Get_Current_Tool() << endl;
    sphere(curr_scene.prefs.get_sphere_latitude(), curr_scene.prefs.get_sphere_longitude(), curr_scene);
}
void create_geosphere (scene &curr_scene){
	curr_scene.Set_Current_Tool(55);
	cout << "Current Tool is: " << curr_scene.Get_Current_Tool() << endl;
    cube(curr_scene.prefs.get_geosphere_resolution(), curr_scene);
}
void create_rounded_cylinder (scene &curr_scene){
	curr_scene.Set_Current_Tool(56);
	cout << "Current Tool is: " << curr_scene.Get_Current_Tool() << endl;
    rounded_cylinder(curr_scene.prefs.get_rounded_cylinder_latitude(), curr_scene.prefs.get_rounded_cylinder_longitude(), curr_scene);
}
void create_rounded_cube (scene &curr_scene){
	curr_scene.Set_Current_Tool(57);
	cout << "Current Tool is: " << curr_scene.Get_Current_Tool() << endl;
    rounded_cube(curr_scene.prefs.get_rounded_cube_longitude(), curr_scene.prefs.get_rounded_cube_latitude(), curr_scene);
}
void create_torus (scene &curr_scene){
	curr_scene.Set_Current_Tool(58);
	cout << "Current Tool is: " << curr_scene.Get_Current_Tool() << endl;
    torus(curr_scene.prefs.get_torus_longitude(), curr_scene.prefs.get_torus_latitude(), curr_scene.prefs.get_torus_inner_radius(), curr_scene);
}



void create_nurbs_plane (scene &curr_scene){
}
void create_nurbs_halfpipe (scene &curr_scene){
}
void create_nurbs_saddle (scene &curr_scene){
}
void create_nurbs_cube (scene &curr_scene){
}
void create_nurbs_cylinder (scene &curr_scene){
}
void create_nurbs_cone (scene &curr_scene){
}
void create_nurbs_sphere (scene &curr_scene){
}
void create_nurbs_torus (scene &curr_scene){
}
void create_metaball_cube (scene &curr_scene){
}
void create_metaball_cylinder (scene &curr_scene){
}
void create_metaball_sphere (scene &curr_scene){
}
void create_metaball_rounded_cylinder (scene &curr_scene){
}
void create_metaball_rounded_cube (scene &curr_scene){
}
void create_metaball_metamuscle (scene &curr_scene){
}
void create_image_light (scene &curr_scene){
}
void create_spot_light (scene &curr_scene){
}
void create_local_light (scene &curr_scene){
}
void create_infinite_light (scene &curr_scene){
}
void create_projector_light (scene &curr_scene){
}
void create_sky_light (scene &curr_scene){
}
void create_goniometric_light (scene &curr_scene){
}
void create_area_light (scene &curr_scene){
}
void create_camera (scene &curr_scene){
}
void create_panoramic_camera (scene &curr_scene){
}
void create_global_physical_wind (scene &curr_scene){
}
void create_local_physical_wind (scene &curr_scene){
}
void deformation_plane (scene &curr_scene){
}
void deformation_pipe (scene &curr_scene){
}
void deformation_object (scene &curr_scene){
}
void sweep (scene &curr_scene){
}
void fillet (scene &curr_scene){
}
void chamfer (scene &curr_scene){
}
void bevel (scene &curr_scene){
}
void macro_sweep (scene &curr_scene){
}
void lathe (scene &curr_scene){
}
void tip (scene &curr_scene){
}
void create_object_grid (scene &curr_scene){
}
void create_object_spline (scene &curr_scene){
}
void create_object_radial (scene &curr_scene){
}
void array_to_group (scene &curr_scene){
}
void draw_panel (scene &curr_scene){
}
void freehand_curve (scene &curr_scene){
}
void material_editor (scene &curr_scene){
}
void threed_paint (scene &curr_scene){
}
void uv_editor (scene &curr_scene){
}
void material_rectangle (scene &curr_scene){
}
void planar_uv (scene &curr_scene){
}
void cubic_uv (scene &curr_scene){
}
void spherical_uv (scene &curr_scene){
}
void cylindrical_uv (scene &curr_scene){
}
void uv_unwrap (scene &curr_scene){
}
void uv_slice (scene &curr_scene){
}
void shrinkwrap_uv (scene &curr_scene){
}
void normalise_location (scene &curr_scene){
}
void normalise_rotation (scene &curr_scene){
}
void normalise_scale (scene &curr_scene){
}
void center_axes (scene &curr_scene){
}
void show_axes (scene &curr_scene){
}
void select_object (scene &curr_scene){
	curr_scene.Set_Current_Tool(0);
	cout << "Current Tool is: " << curr_scene.Get_Current_Tool() << endl;
}
void clear_selection (scene &curr_scene){
	curr_scene.Set_Current_Tool(0);
}

void show_object_info(scene &curr_scene){
	curr_scene.curr_gui->show_object_info_window(curr_scene);
}

void global_panel (scene &curr_scene){
}
void unhide_objects (scene &curr_scene){
}
void object_notes (scene &curr_scene){
}
void select_context (scene &curr_scene){
}
void select_vertices (scene &curr_scene){
}
void select_edges (scene &curr_scene){
}
void select_faces (scene &curr_scene){
}
void named_selection (scene &curr_scene){
}
void lasso_selection (scene &curr_scene){
}
void rectangle_selection (scene &curr_scene){
}
void freehand_selection (scene &curr_scene){
}
void toggle_grid (scene &curr_scene){
}
void snap_vertex (scene &curr_scene){
}
void snap_edge (scene &curr_scene){
}
void snap_face (scene &curr_scene){
}
void magnetic_tool (scene &curr_scene){
}
void collision_disabled (scene &curr_scene){
}
void collision_ground (scene &curr_scene){
}
void collision_peers (scene &curr_scene){
}
void new_scene (scene &curr_scene){
}
void undo (scene &curr_scene){
}
void redo (scene &curr_scene){
}
void object_copy (scene &curr_scene){
}
void glue_object_as_child (scene &curr_scene){
}
void glue_object_as_sibling (scene &curr_scene){
}
void object_unglue (scene &curr_scene){
}
void object_group (scene &curr_scene){
}
void object_ungroup (scene &curr_scene){
}
void object_erase (scene &curr_scene){
}
void button_finder (scene &curr_scene){
}
void display_options(scene &curr_scene){
}
