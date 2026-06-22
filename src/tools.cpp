#include "../include/tools.h"
#include "../include/scene.h"
#include "../include/primitive.h"
#include "../include/gui/tsgui.h"
#include "../include/gl_tool_windows.h"
#include "../include/math3d.h"
#include <algorithm>

void boolean_parameters(scene &curr_scene){
	curr_scene.curr_gui->show_boolean_window(curr_scene);
}

void light_parameters (scene &curr_scene){
	curr_scene.curr_gui->show_lights_window(curr_scene);
}

void mirror_options_parameters (scene &curr_scene){
	curr_scene.curr_gui->show_mirror_options_window(curr_scene);
}

void smooth_quad_parameters (scene &curr_scene){
	curr_scene.curr_gui->show_smooth_quad_window(curr_scene);
}

void polygon_reduction_parameters (scene &curr_scene){
	curr_scene.curr_gui->show_polygon_reduction_tool_window(curr_scene);
}

void coords_parameters (scene &curr_scene){
	curr_scene.curr_gui->show_coords_window(curr_scene);
}

void primitive_parameters (scene &curr_scene){
	curr_scene.curr_gui->show_primitive_parameters_window(curr_scene);
    curr_scene.curr_gui->show_primitive_shape_window(curr_scene);
}

void plane_parameters (scene &curr_scene){
	if (curr_scene.Get_Current_Tool() == 50) {
		curr_scene.curr_gui->show_primitive_parameters_window(curr_scene);
		curr_scene.curr_gui->show_primitive_shape_window(curr_scene);
	} else {
		show_gl_plane_window(curr_scene);
	}
}

void cube_parameters (scene &curr_scene){
	if (curr_scene.Get_Current_Tool() == 51) {
		curr_scene.curr_gui->show_primitive_parameters_window(curr_scene);
		curr_scene.curr_gui->show_primitive_shape_window(curr_scene);
	} else {
		show_gl_cube_window(curr_scene);
	}
}

void sphere_parameters (scene &curr_scene){
	if (curr_scene.Get_Current_Tool() == 54) {
		curr_scene.curr_gui->show_primitive_parameters_window(curr_scene);
		curr_scene.curr_gui->show_primitive_shape_window(curr_scene);
	} else {
		show_gl_sphere_window(curr_scene);
	}
}

void geosphere_parameters (scene &curr_scene){
	show_gl_geosphere_window(curr_scene);
}

void cylinder_parameters (scene &curr_scene){
	if (curr_scene.Get_Current_Tool() == 52) {
		curr_scene.curr_gui->show_primitive_parameters_window(curr_scene);
		curr_scene.curr_gui->show_primitive_shape_window(curr_scene);
	} else {
		show_gl_cylinder_window(curr_scene);
	}
}

void cone_parameters (scene &curr_scene){
	if (curr_scene.Get_Current_Tool() == 53) {
		curr_scene.curr_gui->show_primitive_parameters_window(curr_scene);
		curr_scene.curr_gui->show_primitive_shape_window(curr_scene);
	} else {
		show_gl_cone_window(curr_scene);
	}
}

void torus_parameters (scene &curr_scene){
	if (curr_scene.Get_Current_Tool() == 58) {
		curr_scene.curr_gui->show_primitive_parameters_window(curr_scene);
		curr_scene.curr_gui->show_primitive_shape_window(curr_scene);
	} else {
		show_gl_torus_window(curr_scene);
	}
}

void rounded_cube_parameters (scene &curr_scene){
	if (curr_scene.Get_Current_Tool() == 57) {
		curr_scene.curr_gui->show_primitive_parameters_window(curr_scene);
		curr_scene.curr_gui->show_primitive_shape_window(curr_scene);
	} else {
		show_gl_rounded_cube_window(curr_scene);
	}
}

void rounded_cylinder_parameters (scene &curr_scene){
	if (curr_scene.Get_Current_Tool() == 56) {
		curr_scene.curr_gui->show_primitive_parameters_window(curr_scene);
		curr_scene.curr_gui->show_primitive_shape_window(curr_scene);
	} else {
		show_gl_rounded_cylinder_window(curr_scene);
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
	curr_scene.Set_Current_Tool(37);
	cout << "Tool: View Move" << endl;
}
void view_rotate (scene &curr_scene){
	curr_scene.Set_Current_Tool(38);
	cout << "Tool: View Rotate" << endl;
}
void view_zoom (scene &curr_scene){
	curr_scene.Set_Current_Tool(39);
	cout << "Tool: View Zoom" << endl;
}
void object_move (scene &curr_scene){
	curr_scene.Set_Current_Tool(40);
	cout << "Tool: Object Move" << endl;
}
void object_rotate (scene &curr_scene){
	curr_scene.Set_Current_Tool(41);
	cout << "Tool: Object Rotate" << endl;
}
void object_scale (scene &curr_scene){
	curr_scene.Set_Current_Tool(42);
	cout << "Tool: Object Scale" << endl;
}
void hierarchy_up (scene &curr_scene){
	if (curr_scene.hierarchy_level <= 0) {
		curr_scene.hierarchy_level = 0;
		return;
	}
	curr_scene.hierarchy_level = 0;
	auto obj = curr_scene.GetCurrentObject();
	if (!obj) return;
	auto root = curr_scene.GetGroupRoot(obj);
	curr_scene.SelectObject(root, false);
	cout << "Hierarchy Up: group level (" << root->get_name() << ")" << endl;
	if (curr_scene.curr_gui)
		curr_scene.curr_gui->update_object_info(curr_scene);
}
void hierarchy_down (scene &curr_scene){
	auto obj = curr_scene.GetCurrentObject();
	if (!obj) return;
	bool is_grouped = (obj->get_parent() ||
					   !obj->get_children().empty() ||
					   !obj->get_siblings().empty());
	if (!is_grouped) return;
	curr_scene.hierarchy_level = 1;
	curr_scene.selected_objects.clear();
	curr_scene.selected_objects.insert(obj);
	cout << "Hierarchy Down: individual level (" << obj->get_name() << ")" << endl;
	if (curr_scene.curr_gui)
		curr_scene.curr_gui->update_object_info(curr_scene);
}
void create_plane (scene &curr_scene){
	curr_scene.Set_Current_Tool(50);
	cout << "Tool: Plane" << endl;
}
void create_cube (scene &curr_scene){
	curr_scene.Set_Current_Tool(51);
	cout << "Tool: Cube" << endl;
}
void create_cylinder (scene &curr_scene){
	curr_scene.Set_Current_Tool(52);
	cout << "Tool: Cylinder" << endl;
}
void create_cone (scene &curr_scene){
	curr_scene.Set_Current_Tool(53);
	cout << "Tool: Cone" << endl;
}
void create_sphere (scene &curr_scene){
	curr_scene.Set_Current_Tool(54);
	cout << "Tool: Sphere" << endl;
}
void create_geosphere (scene &curr_scene){
	curr_scene.Set_Current_Tool(55);
	cout << "Tool: GeoSphere" << endl;
}
void create_rounded_cylinder (scene &curr_scene){
	curr_scene.Set_Current_Tool(56);
	cout << "Tool: Rounded Cylinder" << endl;
}
void create_rounded_cube (scene &curr_scene){
	curr_scene.Set_Current_Tool(57);
	cout << "Tool: Rounded Cube" << endl;
}
void create_torus (scene &curr_scene){
	curr_scene.Set_Current_Tool(58);
	cout << "Tool: Torus" << endl;
}

void spawn_primitive(scene &curr_scene){
	int tool = curr_scene.Get_Current_Tool();
	switch (tool) {
		case 50:
			plane(curr_scene.prefs.get_plane_resolution(), curr_scene);
			break;
		case 51:
			cube(curr_scene.prefs.get_cube_resolution(), curr_scene);
			break;
		case 52:
			cylinder(curr_scene.prefs.get_cylinder_longitude(), curr_scene.prefs.get_cylinder_latitude(), curr_scene.prefs.get_cylinder_top_radius(), curr_scene);
			break;
		case 53:
			cone(curr_scene.prefs.get_cone_longitude(), curr_scene.prefs.get_cone_latitude(), curr_scene);
			break;
		case 54:
			sphere(curr_scene.prefs.get_sphere_longitude(), curr_scene.prefs.get_sphere_latitude(), curr_scene);
			break;
		case 55:
			geosphere(curr_scene.prefs.get_geosphere_resolution(), curr_scene);
			break;
		case 56:
			rounded_cylinder(curr_scene.prefs.get_rounded_cylinder_longitude(), curr_scene.prefs.get_rounded_cylinder_latitude(), curr_scene);
			break;
		case 57:
			rounded_cube(curr_scene.prefs.get_rounded_cube_longitude(), curr_scene.prefs.get_rounded_cube_latitude(), curr_scene);
			break;
		case 58:
			torus(curr_scene.prefs.get_torus_longitude(), curr_scene.prefs.get_torus_latitude(), curr_scene.prefs.get_torus_inner_radius(), curr_scene);
			break;
	}
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

void bevel_parameters (scene &curr_scene){
	curr_scene.curr_gui->show_bevel_window(curr_scene);
}

void chamfer_parameters (scene &curr_scene){
	curr_scene.curr_gui->show_chamfer_window(curr_scene);
}

void fillet_parameters (scene &curr_scene){
	curr_scene.curr_gui->show_fillet_window(curr_scene);
}

void lathe_parameters (scene &curr_scene){
	curr_scene.curr_gui->show_lathe_window(curr_scene);
}

void macro_parameters (scene &curr_scene){
	curr_scene.curr_gui->show_macro_window(curr_scene);
}

void sweep_tip_parameters (scene &curr_scene){
	curr_scene.curr_gui->show_sweep_tip_window(curr_scene);
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
	auto obj = curr_scene.GetCurrentObject();
	if (obj) {
		bool current = obj->get_show_axes();
		obj->enable_axes(!current);
		cout << "Object axes: " << (!current ? "on" : "off") << endl;
	}
}
void select_object (scene &curr_scene){
	if (curr_scene.Get_Current_Tool() == 0 && curr_scene.selected_objects.empty()) {
		auto prev = curr_scene.GetPrevObject();
		if (prev) {
			for (auto& obj : curr_scene.object_list) {
				if (obj == prev) {
					curr_scene.SelectObject(prev, false);
					if (curr_scene.curr_gui)
						curr_scene.curr_gui->update_object_info(curr_scene);
					return;
				}
			}
		}
	}
	auto save_prev = curr_scene.current_object;
	if (save_prev && save_prev->getSelectedFaces().size() +
		save_prev->getSelectedEdges().size() +
		save_prev->getSelectedVertices().size() > 0)
		save_prev->clearSubSelection();
	curr_scene.ClearSelection();
	curr_scene.SetPrevObject(save_prev);
	curr_scene.Set_Current_Tool(0);
	curr_scene.Set_Edit_Mode(0);
	curr_scene.editing_toolbar_visible = false;
	if (curr_scene.curr_gui)
		curr_scene.curr_gui->update_object_info(curr_scene);
}
void clear_selection (scene &curr_scene){
	curr_scene.Set_Current_Tool(0);
}

void show_object_info(scene &curr_scene){
	show_gl_object_info_window(curr_scene);
}

void global_panel (scene &curr_scene){
}
void unhide_objects (scene &curr_scene){
}
void object_notes (scene &curr_scene){
}
void select_context (scene &curr_scene){
	curr_scene.Set_Current_Tool(250);
	curr_scene.Set_Edit_Mode(0);
	curr_scene.editing_toolbar_visible = true;
	cout << "Edit Mode: Context" << endl;
}
void select_vertices (scene &curr_scene){
	curr_scene.Set_Current_Tool(251);
	curr_scene.Set_Edit_Mode(1);
	curr_scene.editing_toolbar_visible = true;
	cout << "Edit Mode: Vertex" << endl;
}
void select_edges (scene &curr_scene){
	curr_scene.Set_Current_Tool(252);
	curr_scene.Set_Edit_Mode(2);
	curr_scene.editing_toolbar_visible = true;
	cout << "Edit Mode: Edge" << endl;
}
void select_faces (scene &curr_scene){
	curr_scene.Set_Current_Tool(253);
	curr_scene.Set_Edit_Mode(3);
	curr_scene.editing_toolbar_visible = true;
	cout << "Edit Mode: Face" << endl;
}
void select_objects (scene &curr_scene){
	curr_scene.Set_Current_Tool(254);
	curr_scene.Set_Edit_Mode(4);
	curr_scene.editing_toolbar_visible = false;
	cout << "Edit Mode: Object" << endl;
}

void shell_parameters(scene &curr_scene){
	curr_scene.curr_gui->show_shell_properties_window(curr_scene);
}

void named_selection (scene &curr_scene){
	curr_scene.editing_toolbar_visible = true;
}
void lasso_selection (scene &curr_scene){
	curr_scene.editing_toolbar_visible = true;
}
void rectangle_selection (scene &curr_scene){
	curr_scene.editing_toolbar_visible = true;
}
void freehand_selection (scene &curr_scene){
	curr_scene.editing_toolbar_visible = true;
}
void slice_object (scene &curr_scene){}
void separate_object (scene &curr_scene){}
void flip_all_faces (scene &curr_scene){}
void delete_face (scene &curr_scene){}
void add_face (scene &curr_scene){}
void weld_vertices (scene &curr_scene){}
void erase_vertices (scene &curr_scene){}
void polygon_draw (scene &curr_scene){}
void polygon_slice (scene &curr_scene){}
void polygon_bevel (scene &curr_scene){}
void add_vertex (scene &curr_scene){}
void add_edges (scene &curr_scene){}
void polygon_copy (scene &curr_scene){}
void delete_subdivision (scene &curr_scene){}
void add_subdivision (scene &curr_scene){}
void smooth_quad_divide (scene &curr_scene){}
void quad_divide (scene &curr_scene){}
void face_to_hole (scene &curr_scene){}
void hole_to_face (scene &curr_scene){}
void point_move (scene &curr_scene){
	curr_scene.Set_Current_Tool(40);
}
void point_rotate (scene &curr_scene){
	curr_scene.Set_Current_Tool(41);
}
void point_scale (scene &curr_scene){
	curr_scene.Set_Current_Tool(42);
}
void add_to_selection (scene &curr_scene){}
void select_subset (scene &curr_scene){}
void remove_from_selection (scene &curr_scene){}
void toggle_grid (scene &curr_scene){
	bool current = curr_scene.prefs.get_draw_ground_plane();
	curr_scene.prefs.set_draw_ground_plane(!current);
	cout << "Grid: " << (!current ? "on" : "off") << endl;
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
	auto obj = curr_scene.GetCurrentObject();
	if (!obj) return;
	auto copy = obj->clone();
	double* loc = copy->get_location();
	copy->set_location(loc[0] + 0.5, loc[1], loc[2] + 0.5);
	curr_scene.AddObject(copy);
	cout << "Copied: " << obj->get_name() << " -> " << copy->get_name() << endl;
}
void glue_object_as_child (scene &curr_scene){
	auto child = curr_scene.GetCurrentObject();
	auto parent = curr_scene.GetPrevObject();
	if (!child || !parent || child == parent) return;
	if (child->get_parent()) {
		cout << "Object already glued, unglue first" << endl;
		return;
	}
	parent->add_child(child);
	cout << "Glued " << child->get_name() << " as child of " << parent->get_name() << endl;
}
void glue_object_as_sibling (scene &curr_scene){
	auto sib = curr_scene.GetCurrentObject();
	auto target = curr_scene.GetPrevObject();
	if (!sib || !target || sib == target) return;
	if (sib->get_parent()) {
		cout << "Object already glued, unglue first" << endl;
		return;
	}
	target->add_sibling(sib);
	cout << "Glued " << sib->get_name() << " as sibling of " << target->get_name() << endl;
}
void object_unglue (scene &curr_scene){
	auto obj = curr_scene.GetCurrentObject();
	if (!obj) return;
	object* par = obj->get_parent();
	if (!par) {
		cout << "Object is not glued" << endl;
		return;
	}
	// Try to remove from parent's children list
	for (auto it = par->get_children().begin(); it != par->get_children().end(); ++it) {
		if (it->get() == obj.get()) {
			par->get_children().erase(it);
			obj->set_parent(nullptr);
			cout << "Unglued " << obj->get_name() << " from " << par->get_name() << " (child)" << endl;
			return;
		}
	}
	// Try to remove from sibling lists in the scene
	for (auto& scene_obj : curr_scene.object_list) {
		for (auto it = scene_obj->get_siblings().begin(); it != scene_obj->get_siblings().end(); ++it) {
			if (it->get() == obj.get()) {
				scene_obj->get_siblings().erase(it);
				obj->set_parent(nullptr);
				cout << "Unglued " << obj->get_name() << " (sibling)" << endl;
				return;
			}
		}
	}
	obj->set_parent(nullptr);
	cout << "Unglued " << obj->get_name() << endl;
}
void object_group (scene &curr_scene){
	if (curr_scene.selected_objects.size() < 2) {
		cout << "Select at least 2 objects to create an LOD group" << endl;
		return;
	}
	for (auto& obj : curr_scene.selected_objects) {
		if (curr_scene.FindLodGroup(obj)) {
			cout << obj->get_name() << " is already in an LOD group, ungroup first" << endl;
			return;
		}
	}
	lod_group grp;
	grp.name = "LOD_" + to_string(curr_scene.lod_groups.size() + 1);
	for (auto& obj : curr_scene.selected_objects) {
		grp.members.push_back(obj);
	}
	curr_scene.lod_groups.push_back(grp);
	cout << "Created LOD group '" << grp.name << "' with " << grp.members.size() << " objects" << endl;
}
void object_ungroup (scene &curr_scene){
	if (curr_scene.selected_objects.empty()) {
		cout << "No objects selected" << endl;
		return;
	}
	for (auto& obj : curr_scene.selected_objects) {
		lod_group* grp = curr_scene.FindLodGroup(obj);
		if (grp) {
			grp->members.remove(obj);
			cout << "Removed " << obj->get_name() << " from LOD group '" << grp->name << "'" << endl;
			if (grp->members.empty()) {
				cout << "LOD group '" << grp->name << "' is now empty, removing" << endl;
				curr_scene.lod_groups.remove_if([grp](const lod_group& g){ return &g == grp; });
			}
		} else {
			cout << obj->get_name() << " is not in an LOD group" << endl;
		}
	}
}
void object_erase (scene &curr_scene){
	if (curr_scene.selected_objects.empty()) return;
	auto to_delete = curr_scene.selected_objects;
	for (auto& obj : to_delete) {
		if (obj) {
			cout << "Object deleted: " << obj->get_name() << endl;
			curr_scene.DeleteObject(obj);
		}
	}
	if (curr_scene.curr_gui)
		curr_scene.curr_gui->update_object_info(curr_scene);
}
void button_finder (scene &curr_scene){
}
void draw_as_wireframe(scene &curr_scene){
	curr_scene.current_draw_mode = 1;
	cout << "Draw Mode: Wireframe" << endl;
}
void draw_as_transparent_wireframe(scene &curr_scene){
	curr_scene.current_draw_mode = 3;
	cout << "Draw Mode: Transparent Wireframe" << endl;
}
void draw_as_solid_wireframe(scene &curr_scene){
	curr_scene.current_draw_mode = 4;
	cout << "Draw Mode: Solid + Wireframe" << endl;
}
void draw_as_transparent(scene &curr_scene){
	curr_scene.current_draw_mode = 2;
	cout << "Draw Mode: Transparent Solid" << endl;
}
void draw_as_solid(scene &curr_scene){
	curr_scene.current_draw_mode = 0;
	cout << "Draw Mode: Solid" << endl;
}
void draw_as_radiosity(scene &curr_scene){
	curr_scene.current_draw_mode = 5;
	cout << "Draw Mode: Radiosity" << endl;
}
void display_options(scene &curr_scene){
}

void wind_parameters(scene &curr_scene){
	curr_scene.curr_gui->show_wind_window(curr_scene);
}

static shared_ptr<object> merge_meshes(shared_ptr<object> a, shared_ptr<object> b, const string& result_name, scene &curr_scene) {
	Mesh& ma = a->getMesh();
	Mesh& mb = b->getMesh();
	if (!ma.hasData()) a->generateMesh();
	if (!mb.hasData()) b->generateMesh();
	if (ma.isDirty()) ma.uploadToGPU();
	if (mb.isDirty()) mb.uploadToGPU();

	auto result = make_shared<object>();
	result->set_name(result_name);
	result->set_object_type(a->get_object_type());

	double* loc_a = a->get_location();
	double* loc_b = b->get_location();
	double cx = (loc_a[0] + loc_b[0]) * 0.5;
	double cy = (loc_a[1] + loc_b[1]) * 0.5;
	double cz = (loc_a[2] + loc_b[2]) * 0.5;
	result->set_location(cx, cy, cz);

	Mesh& mr = result->getMesh();

	float model_a[16], model_b[16];
	a->buildModelMatrix(model_a);
	b->buildModelMatrix(model_b);

	float inv_result[16];
	IdentityMatrix(inv_result);
	TranslateMatrix((float)-cx, (float)-cy, (float)-cz, inv_result);

	int vert_count_a = ma.vertex_data.size() / 6;
	for (int i = 0; i < vert_count_a; i++) {
		float x = ma.vertex_data[i * 6 + 0];
		float y = ma.vertex_data[i * 6 + 1];
		float z = ma.vertex_data[i * 6 + 2];
		float nx = ma.vertex_data[i * 6 + 3];
		float ny = ma.vertex_data[i * 6 + 4];
		float nz = ma.vertex_data[i * 6 + 5];
		float wx = model_a[0]*x + model_a[4]*y + model_a[8]*z + model_a[12];
		float wy = model_a[1]*x + model_a[5]*y + model_a[9]*z + model_a[13];
		float wz = model_a[2]*x + model_a[6]*y + model_a[10]*z + model_a[14];
		mr.vertex_data.push_back(wx - (float)cx);
		mr.vertex_data.push_back(wy - (float)cy);
		mr.vertex_data.push_back(wz - (float)cz);
		mr.vertex_data.push_back(nx);
		mr.vertex_data.push_back(ny);
		mr.vertex_data.push_back(nz);
	}

	int vert_count_b = mb.vertex_data.size() / 6;
	int offset = vert_count_a;
	for (int i = 0; i < vert_count_b; i++) {
		float x = mb.vertex_data[i * 6 + 0];
		float y = mb.vertex_data[i * 6 + 1];
		float z = mb.vertex_data[i * 6 + 2];
		float nx = mb.vertex_data[i * 6 + 3];
		float ny = mb.vertex_data[i * 6 + 4];
		float nz = mb.vertex_data[i * 6 + 5];
		float wx = model_b[0]*x + model_b[4]*y + model_b[8]*z + model_b[12];
		float wy = model_b[1]*x + model_b[5]*y + model_b[9]*z + model_b[13];
		float wz = model_b[2]*x + model_b[6]*y + model_b[10]*z + model_b[14];
		mr.vertex_data.push_back(wx - (float)cx);
		mr.vertex_data.push_back(wy - (float)cy);
		mr.vertex_data.push_back(wz - (float)cz);
		mr.vertex_data.push_back(nx);
		mr.vertex_data.push_back(ny);
		mr.vertex_data.push_back(nz);
	}

	for (auto idx : ma.triangle_indices)
		mr.triangle_indices.push_back(idx);
	for (auto idx : mb.triangle_indices)
		mr.triangle_indices.push_back(idx + offset);

	for (auto idx : ma.line_indices)
		mr.line_indices.push_back(idx);
	for (auto idx : mb.line_indices)
		mr.line_indices.push_back(idx + offset);

	mr.triangle_face_map = ma.triangle_face_map;
	int face_offset = ma.logical_face_count;
	for (auto f : mb.triangle_face_map)
		mr.triangle_face_map.push_back(f + face_offset);
	mr.logical_face_count = ma.logical_face_count + mb.logical_face_count;

	result->set_num_vertices(vert_count_a + vert_count_b);
	result->set_num_faces(mr.logical_face_count);
	mr.markDirty();
	return result;
}

void boolean_union(scene &curr_scene) {
	auto obj_a = curr_scene.GetPrevObject();
	auto obj_b = curr_scene.GetCurrentObject();
	if (!obj_a || !obj_b || obj_a == obj_b) {
		cout << "Boolean Union: select two different objects" << endl;
		return;
	}
	string name = obj_a->get_name() + " + " + obj_b->get_name();
	auto result = merge_meshes(obj_a, obj_b, name, curr_scene);
	curr_scene.DeleteObject(obj_a);
	curr_scene.DeleteObject(obj_b);
	curr_scene.AddObject(result);
	cout << "Boolean Union: " << name << endl;
}

void boolean_subtract(scene &curr_scene) {
	auto obj_a = curr_scene.GetPrevObject();
	auto obj_b = curr_scene.GetCurrentObject();
	if (!obj_a || !obj_b || obj_a == obj_b) {
		cout << "Boolean Subtract: select two different objects (select target first, then drill)" << endl;
		return;
	}

	Mesh& ma = obj_a->getMesh();
	Mesh& mb = obj_b->getMesh();
	if (!ma.hasData()) obj_a->generateMesh();
	if (!mb.hasData()) obj_b->generateMesh();

	float model_b[16];
	obj_b->buildModelMatrix(model_b);

	double* loc_a = obj_a->get_location();

	float bmin[3] = { 1e30f, 1e30f, 1e30f };
	float bmax[3] = { -1e30f, -1e30f, -1e30f };
	int vcount_b = mb.vertex_data.size() / 6;
	for (int i = 0; i < vcount_b; i++) {
		float x = mb.vertex_data[i*6+0];
		float y = mb.vertex_data[i*6+1];
		float z = mb.vertex_data[i*6+2];
		float wx = model_b[0]*x + model_b[4]*y + model_b[8]*z + model_b[12] - (float)loc_a[0];
		float wy = model_b[1]*x + model_b[5]*y + model_b[9]*z + model_b[13] - (float)loc_a[1];
		float wz = model_b[2]*x + model_b[6]*y + model_b[10]*z + model_b[14] - (float)loc_a[2];
		if (wx < bmin[0]) bmin[0] = wx;
		if (wx > bmax[0]) bmax[0] = wx;
		if (wy < bmin[1]) bmin[1] = wy;
		if (wy > bmax[1]) bmax[1] = wy;
		if (wz < bmin[2]) bmin[2] = wz;
		if (wz > bmax[2]) bmax[2] = wz;
	}

	auto result = obj_a->clone();
	result->set_name(obj_a->get_name() + " - " + obj_b->get_name());
	Mesh& mr = result->getMesh();

	std::vector<unsigned int> new_tris;
	std::vector<int> new_face_map;
	int tri_count = mr.triangle_indices.size() / 3;
	for (int t = 0; t < tri_count; t++) {
		unsigned int i0 = mr.triangle_indices[t*3+0];
		unsigned int i1 = mr.triangle_indices[t*3+1];
		unsigned int i2 = mr.triangle_indices[t*3+2];
		float cx = (mr.vertex_data[i0*6+0] + mr.vertex_data[i1*6+0] + mr.vertex_data[i2*6+0]) / 3.0f;
		float cy = (mr.vertex_data[i0*6+1] + mr.vertex_data[i1*6+1] + mr.vertex_data[i2*6+1]) / 3.0f;
		float cz = (mr.vertex_data[i0*6+2] + mr.vertex_data[i1*6+2] + mr.vertex_data[i2*6+2]) / 3.0f;

		bool inside = (cx >= bmin[0] && cx <= bmax[0] &&
					   cy >= bmin[1] && cy <= bmax[1] &&
					   cz >= bmin[2] && cz <= bmax[2]);
		if (!inside) {
			new_tris.push_back(i0);
			new_tris.push_back(i1);
			new_tris.push_back(i2);
			if (t < (int)mr.triangle_face_map.size())
				new_face_map.push_back(mr.triangle_face_map[t]);
		}
	}
	mr.triangle_indices = new_tris;
	mr.triangle_face_map = new_face_map;
	result->set_num_faces(mr.triangle_face_map.empty() ? 0 : *max_element(mr.triangle_face_map.begin(), mr.triangle_face_map.end()) + 1);
	mr.markDirty();

	curr_scene.DeleteObject(obj_a);
	curr_scene.DeleteObject(obj_b);
	curr_scene.AddObject(result);
	cout << "Boolean Subtract: " << result->get_name() << endl;
}

void boolean_intersect(scene &curr_scene) {
	auto obj_a = curr_scene.GetPrevObject();
	auto obj_b = curr_scene.GetCurrentObject();
	if (!obj_a || !obj_b || obj_a == obj_b) {
		cout << "Boolean Intersect: select two different objects" << endl;
		return;
	}

	Mesh& ma = obj_a->getMesh();
	Mesh& mb = obj_b->getMesh();
	if (!ma.hasData()) obj_a->generateMesh();
	if (!mb.hasData()) obj_b->generateMesh();

	float model_b[16];
	obj_b->buildModelMatrix(model_b);

	double* loc_a = obj_a->get_location();

	float bmin[3] = { 1e30f, 1e30f, 1e30f };
	float bmax[3] = { -1e30f, -1e30f, -1e30f };
	int vcount_b = mb.vertex_data.size() / 6;
	for (int i = 0; i < vcount_b; i++) {
		float x = mb.vertex_data[i*6+0];
		float y = mb.vertex_data[i*6+1];
		float z = mb.vertex_data[i*6+2];
		float wx = model_b[0]*x + model_b[4]*y + model_b[8]*z + model_b[12] - (float)loc_a[0];
		float wy = model_b[1]*x + model_b[5]*y + model_b[9]*z + model_b[13] - (float)loc_a[1];
		float wz = model_b[2]*x + model_b[6]*y + model_b[10]*z + model_b[14] - (float)loc_a[2];
		if (wx < bmin[0]) bmin[0] = wx;
		if (wx > bmax[0]) bmax[0] = wx;
		if (wy < bmin[1]) bmin[1] = wy;
		if (wy > bmax[1]) bmax[1] = wy;
		if (wz < bmin[2]) bmin[2] = wz;
		if (wz > bmax[2]) bmax[2] = wz;
	}

	auto result = obj_a->clone();
	result->set_name(obj_a->get_name() + " & " + obj_b->get_name());
	Mesh& mr = result->getMesh();

	std::vector<unsigned int> new_tris;
	std::vector<int> new_face_map;
	int tri_count = mr.triangle_indices.size() / 3;
	for (int t = 0; t < tri_count; t++) {
		unsigned int i0 = mr.triangle_indices[t*3+0];
		unsigned int i1 = mr.triangle_indices[t*3+1];
		unsigned int i2 = mr.triangle_indices[t*3+2];
		float cx = (mr.vertex_data[i0*6+0] + mr.vertex_data[i1*6+0] + mr.vertex_data[i2*6+0]) / 3.0f;
		float cy = (mr.vertex_data[i0*6+1] + mr.vertex_data[i1*6+1] + mr.vertex_data[i2*6+1]) / 3.0f;
		float cz = (mr.vertex_data[i0*6+2] + mr.vertex_data[i1*6+2] + mr.vertex_data[i2*6+2]) / 3.0f;

		bool inside = (cx >= bmin[0] && cx <= bmax[0] &&
					   cy >= bmin[1] && cy <= bmax[1] &&
					   cz >= bmin[2] && cz <= bmax[2]);
		if (inside) {
			new_tris.push_back(i0);
			new_tris.push_back(i1);
			new_tris.push_back(i2);
			if (t < (int)mr.triangle_face_map.size())
				new_face_map.push_back(mr.triangle_face_map[t]);
		}
	}
	mr.triangle_indices = new_tris;
	mr.triangle_face_map = new_face_map;
	result->set_num_faces(mr.triangle_face_map.empty() ? 0 : *max_element(mr.triangle_face_map.begin(), mr.triangle_face_map.end()) + 1);
	mr.markDirty();

	curr_scene.DeleteObject(obj_a);
	curr_scene.DeleteObject(obj_b);
	curr_scene.AddObject(result);
	cout << "Boolean Intersect: " << result->get_name() << endl;
}
