#include "../../include/gui/tsgui.h"

void ts_gui::make_gui(preferences &prefs, scene &scene)
{
	Gtk::Window* main_window = nullptr;
	Gtk::Window* boolean_window = nullptr;
	Gtk::Window* cone_window = nullptr;
	Gtk::Window* copy_tool_window = nullptr;
	Gtk::Window* cube_window = nullptr;
	Gtk::Window* cylinder_window = nullptr;
	Gtk::Window* deformation_window = nullptr;
	Gtk::Window* edit_window = nullptr;
	Gtk::Window* edit_window_expanded = nullptr;
	Gtk::Window* geosphere_window = nullptr;
	Gtk::Window* lights_window = nullptr;
	Gtk::Window* mirror_options_window = nullptr;
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
	Gtk::Window* skin_options_window = nullptr;
	Gtk::Window* sphere_window = nullptr;
	Gtk::Window* taper_window = nullptr;
	Gtk::Window* torus_window = nullptr;
	Gtk::Window* undo_options_window = nullptr;
	Gtk::Grid* view_grid = nullptr;
	Gtk::ImageMenuItem* ts_quit_button = nullptr;


		/*TS Style UI*/
	this -> builder->get_widget("ts_main_window", main_window);
	this -> builder->get_widget("edit_window", edit_window);
	this -> builder->get_widget("boolean_window", boolean_window);
	this -> builder->get_widget("cone_window", cone_window);
	this -> builder->get_widget("copy_tool_window", copy_tool_window);
	this -> builder->get_widget("cube_window", cube_window);
	this -> builder->get_widget("cylinder_window", cylinder_window);
	this -> builder->get_widget("deformation_window", deformation_window);
	this -> builder->get_widget("edit_window", edit_window);
	this -> builder->get_widget("geosphere_window", geosphere_window);
	this -> builder->get_widget("lights_window", lights_window);
	this -> builder->get_widget("mirror_options_window", mirror_options_window);
	this -> builder->get_widget("object_info_window", object_info_window);
	this -> builder->get_widget("object_movie_window", object_movie_window);
	this -> builder->get_widget("object_render_options_window", object_render_options_window);
	this -> builder->get_widget("ogl_setting_window", ogl_setting_window);
	this -> builder->get_widget("pan_movie_window", pan_movie_window);
	this -> builder->get_widget("panoramic_camera_window", panoramic_camera_window);
	this -> builder->get_widget("plane_window", plane_window);
	this -> builder->get_widget("point_edit_window", point_edit_window);
	this -> builder->get_widget("polygon_reduction_tool_window", polygon_reduction_tool_window);
	this -> builder->get_widget("preferences_window", preferences_window);
	this -> builder->get_widget("primitive_parameters_window", primitive_parameters_window);
	this -> builder->get_widget("primitive_shape_window", primitive_shape_window);
	this -> builder->get_widget("rounded_cube_window", rounded_cube_window);
	this -> builder->get_widget("rounded_cylinder_window", rounded_cylinder_window);
	this -> builder->get_widget("scene_editor_preferences_window", scene_editor_preferences_window);
	this -> builder->get_widget("selection_window", selection_window);
	this -> builder->get_widget("set_keyframe_window", set_keyframe_window);
	this -> builder->get_widget("shell_properties_window", shell_properties_window);
	this -> builder->get_widget("skin_options_window", skin_options_window);
	this -> builder->get_widget("sphere_window", sphere_window);
	this -> builder->get_widget("taper_window", taper_window);
	this -> builder->get_widget("torus_window", torus_window);
	this -> builder->get_widget("undo_options_window", undo_options_window);
	this -> builder->get_widget("ts_view_grid", view_grid);
	this -> builder->get_widget("ts_quit_button", ts_quit_button);
    gtk_builder_connect_signals (this->builder->gobj(), NULL);

	int num_views = 1;

	main_window->show();
	view_grid->show();

	view view3d_4(LEFT_VIEW, WIREFRAME_VIEW, scene );
	view view3d_3(TOP_VIEW, WIREFRAME_VIEW, scene );
	view view3d_2(FRONT_VIEW, WIREFRAME_VIEW, scene );
	view view3d_1(PERSPECTIVE_VIEW, WIREFRAME_VIEW, scene );

	switch (num_views){
	case 4:
//		view view3d_4(LEFT_VIEW, WIREFRAME_VIEW, scene );
		view_grid->attach(view3d_4, 1, 1, 1, 1);
	case 3:
//		view view3d_3(TOP_VIEW, WIREFRAME_VIEW, scene );
		if (num_views == 4){
			cout << "There are 4 views" << endl;
			view_grid->attach(view3d_3, 0, 1, 1, 1);
		}
		else{
			view_grid->attach(view3d_3, 1, 1, 2, 1);
		}
	case 2:
//		view view3d_2(FRONT_VIEW, WIREFRAME_VIEW, scene );
		view_grid->attach(view3d_2, 1, 0, 1, 1);
	default:
//		view view3d_1(PERSPECTIVE_VIEW, WIREFRAME_VIEW, scene );
		view_grid->attach(view3d_1, 0, 0, 1, 1);
	break;
	}
		cout << "Displays Added to Grid" << endl;
		view_grid->show_all();
		object_info_window->show();

	list<tool> view_move_tool_list = {{ "Eye Move", "Move View Around Scene", "pix/view_move.xpm", view_move, nullptr, nullptr, nullptr }};
	list<tool> view_rotate_tool_list = {{ "Eye Rotate", "Rotate View Around Scene", "pix/view_rotate.xpm", view_rotate, nullptr, nullptr, nullptr }};
	list<tool> view_zoom_tool_list = {{ "Zoom", "Zoom View of Scene", "pix/view_zoom.xpm", view_zoom, nullptr, nullptr, nullptr }};
	list<tool> object_move_tool_list = {{ "Object Move", "Move Object Around Scene", "pix/object_move.xpm", object_move, nullptr, nullptr, nullptr }};
	list<tool> object_rotate_tool_list = {{ "Object Rotate", "Rotate Object Within Scene", "pix/object_rotate.xpm", object_rotate, nullptr, nullptr, nullptr }};
	list<tool> object_scale_tool_list = {{ "Object Scale", "Scale Object in Relation to Scene", "pix/object_scale.xpm", object_scale, nullptr, nullptr, nullptr }};
	list<tool> object_hierarchy_up_tool_list = {{ "Move Up in Hierarchy","Move Up in Hierarchy: Use Arrow Keys to move within hierarchy", "pix/hierarchy_up.xpm", hierarchy_up, nullptr, nullptr, nullptr }};
	list<tool> object_hierarchy_down_tool_list = {{ "Move Down in Hierarchy","Move Down in Hierarchy: Use Arrow Keys to move within hierarchy", "pix/hierarchy_down.xpm", hierarchy_down, nullptr, nullptr, nullptr }};

	ToolButton view_move_tool = ToolButton(view_move_tool_list);
	ToolButton view_rotate_tool = ToolButton(view_rotate_tool_list);
	ToolButton view_zoom_tool = ToolButton(view_zoom_tool_list);
	ToolButton object_move_tool = ToolButton(object_move_tool_list);
	ToolButton object_rotate_tool = ToolButton(object_rotate_tool_list);
	ToolButton object_scale_tool = ToolButton(object_scale_tool_list);
	ToolButton object_hierarchy_up_tool = ToolButton(object_hierarchy_up_tool_list);
	ToolButton object_hierarchy_down_tool = ToolButton(object_hierarchy_down_tool_list);

	Gtk::Window view_object_tool_window;
	Gtk::Box view_object_tool_grid;
	view_object_tool_window.set_default_size(32, 24);
	view_object_tool_window.set_decorated(false);
	view_object_tool_grid.add(view_move_tool);
	view_object_tool_grid.add(view_rotate_tool);
	view_object_tool_grid.add(view_zoom_tool);
	view_object_tool_grid.add(object_move_tool);
	view_object_tool_grid.add(object_rotate_tool);
	view_object_tool_grid.add(object_scale_tool);
	view_object_tool_grid.add(object_hierarchy_up_tool);
	view_object_tool_grid.add(object_hierarchy_down_tool);
	view_object_tool_grid.show();
	view_object_tool_window.add(view_object_tool_grid);
	view_object_tool_window.show();

	list<tool> polygon_tool_list = {
		{"Plane", "Create a Plane Object", "pix/poly_plane.xpm", create_plane, nullptr, nullptr, nullptr }, 
		{"Cube", "Create a Cube Object", "pix/poly_cube.xpm", create_cube, nullptr, nullptr, nullptr }, 
		{"Cylinder", "Create a Cylinder Object", "pix/poly_cylinder.xpm", create_cylinder, nullptr, nullptr, nullptr }, 
		{"Cone", "Create a Cone Object", "pix/poly_cone.xpm", create_cone, nullptr, nullptr, nullptr }, 
		{"Sphere", "Create a Sphere Object", "pix/poly_sphere.xpm", create_sphere, nullptr, nullptr, nullptr }, 
		{"GeoSphere", "Create a GeoSphere Object", "pix/poly_geosphere.xpm", create_geosphere, nullptr, nullptr, nullptr }, 
		{"Rounded Cylinder", "Create a Rounded Cylinder Object", "pix/poly_rounded_cylinder.xpm", create_rounded_cylinder, nullptr, nullptr, nullptr }, 
		{"Rounded Cube", "Create a Rounded Cube Object", "pix/poly_rounded_cube.xpm", create_rounded_cube, nullptr, nullptr, nullptr }, 
		{"Torus", "Create a Torus Object", "pix/poly_torus.xpm", create_torus, nullptr, nullptr, nullptr }
	};
	ToolButton polgon_tools = ToolButton(polygon_tool_list);

	list<tool> nurbs_tool_list = {
		{"NURBS Plane", "Create a NURBS Plane", "pix/nurbs_plane.xpm", create_nurbs_plane, nullptr, nullptr, nullptr }, 
		{"NURBS Cylinder (half)", "Create a NURBS Cylinder Half Pipe", "pix/nurbs_halfpipe.xpm", create_nurbs_halfpipe, nullptr, nullptr, nullptr }, 
		{"NURBS Saddle", "Create a NURBS Saddle", "pix/nurbs_saddle.xpm", create_nurbs_saddle, nullptr, nullptr, nullptr }, 
		{"NURBS Cube", "Create a NURBS Cube", "pix/nurbs_cube.xpm", create_nurbs_cube, nullptr, nullptr, nullptr }, 
		{"NURBS Cylinder", "Create a NURBS Cylinder", "pix/nurbs_cylinder.xpm", create_nurbs_cylinder, nullptr, nullptr, nullptr }, 
		{"NURBS Cone", "Create a NURBS Cone", "pix/nurbs_cone.xpm", create_nurbs_cone, nullptr, nullptr, nullptr }, 
		{"NURBS Sphere", "Create a NURBS Sphere", "pix/nurbs_sphere.xpm", create_nurbs_sphere, nullptr, nullptr, nullptr }, 
		{"NURBS Torus", "Create a NURBS Torus", "pix/nurbs_torus.xpm", create_nurbs_torus, nullptr, nullptr, nullptr }
	};
	ToolButton nurbs_tools = ToolButton(nurbs_tool_list);

	list<tool> metaball_tool_list = {
		{ "Metaball Cube", "Create a Metaball Cube", "pix/metaball_cube.xpm", create_metaball_cube, nullptr, nullptr, nullptr }, 
		{ "Metaball Cylinder", "Create a Metaball Cylinder", "pix/metaball_cylinder.xpm", create_metaball_cylinder, nullptr, nullptr, nullptr }, 
		{ "Metaball Sphere", "Create a Metaball Sphere", "pix/metaball_sphere.xpm", create_metaball_sphere, nullptr, nullptr, nullptr }, 
		{ "Metaball Rounded Cylinder", "Create a Metaball Rounded Cylinder", "pix/metaball_rounded_cylinder.xpm", create_metaball_rounded_cylinder, nullptr, nullptr, nullptr }, 
		{ "Metaball Rounded Cube", "Create a Metaball Rounded Cube", "pix/metaball_rounded_cube.xpm", create_metaball_rounded_cube, nullptr, nullptr, nullptr }, 
		{ "Metaball Metamuscle", "Create a Metaball Metamuscle", "pix/metaball_muscle.xpm", create_metaball_metamuscle, nullptr, nullptr, nullptr }
	};
	ToolButton metaball_tools = ToolButton(metaball_tool_list);
	
	list<tool> light_tool_list = {
		{ "Image Based Light", "Create an Image Based Light", "pix/image_light.xpm", create_image_light, nullptr, nullptr, nullptr }, 
		{ "Spot Light", "Create a Spot Light", "pix/spot_light.xpm", create_spot_light, nullptr, nullptr, nullptr }, 
		{ "Local Light", "Create a Local Light", "pix/local_light.xpm", create_local_light, nullptr, nullptr, nullptr }, 
		{ "Infinite Light", "Create an Infinite Light", "pix/infinite_light.xpm", create_infinite_light, nullptr, nullptr, nullptr }, 
		{ "Projector Light", "Create a Projector Light", "pix/projector_light.xpm", create_projector_light, nullptr, nullptr, nullptr }, 
		{ "Sky Light", "Create a Sky Light", "pix/sky_light.xpm", create_sky_light, nullptr, nullptr, nullptr }, 
		{ "Goniometric Light", "Create a Goniometric Light", "pix/goniometric_light.xpm", create_goniometric_light, nullptr, nullptr, nullptr }, 
		{ "Area Light", "Create an Area Light", "pix/area_light.xpm", create_area_light, nullptr, nullptr, nullptr }
	};
	ToolButton light_tools = ToolButton(light_tool_list);

	list<tool> camera_tool_list = {
		{ "Camera", "Create a Camera", "pix/camera.xpm", create_camera, nullptr, nullptr, nullptr }, 
		{ "Panoramic Camera", "Create a Camera", "pix/panoramic_camera.xpm", create_panoramic_camera, nullptr, nullptr, nullptr }, 
		{ "Global Physical Wind", "Create a Global Physical Wind", "pix/global_wind.xpm", create_global_physical_wind, nullptr, nullptr, nullptr }, 
		{ "Local Physical Wind", "Create a Local Physical Wind", "pix/local_wind.xpm", create_local_physical_wind, nullptr, nullptr, nullptr }, 
		{ "Standalone Deformation Plane", "Create a Standalone Deformation Plane", "pix/deformation_plane.xpm", deformation_plane, nullptr, nullptr, nullptr }, 
		{ "Standalone Deformation Pipe", "Create a Standalone Deformation Pipe", "pix/deformation_pipe.xpm", deformation_pipe, nullptr, nullptr, nullptr }, 
		{ "Standalone Deformation Object", "Create a Standalone Deformation Object", "pix/deformation_object.xpm", deformation_object, nullptr, nullptr, nullptr }
	};
	ToolButton camera_tools = ToolButton(camera_tool_list);

	list<tool> sweep_tool_list = {
		{ "Sweep", "Sweep", "pix/sweep.xpm", sweep, nullptr, nullptr, nullptr }, 
		{ "Fillet Tool", "Fillet", "pix/fillet.xpm", fillet, nullptr, nullptr, nullptr }, 
		{ "Chamfer Tool", "Chamfer", "pix/chamfer.xpm", chamfer, nullptr, nullptr, nullptr }, 
		{ "Bevel", "Bevel", "pix/bevel.xpm", bevel, nullptr, nullptr, nullptr }, 
		{ "Macro/Sweep", "Macro/Sweep", "pix/macro_sweep.xpm", macro_sweep, nullptr, nullptr, nullptr }, 
		{ "Lathe", "Lathe", "pix/lathe.xpm", lathe, nullptr, nullptr, nullptr }, 
		{ "Tip", "Tip", "pix/tip.xpm", tip, nullptr, nullptr, nullptr }
	};
	ToolButton sweep_tools = ToolButton(sweep_tool_list);

	list<tool> subdivision_tool_list = {
		{ "Subdivision Object", "Subdivision Object", "pix/subdiv_object.xpm", nullptr, nullptr, nullptr, nullptr }, 
		{ "Plastiform", "Plastiform", "pix/plastiform.xpm", nullptr, nullptr, nullptr, nullptr }
	};
	ToolButton subdivision_tools = ToolButton(subdivision_tool_list);

	list<tool> boolean_tool_list = {
		{ "Object Shell", "Object Shell", "pix/object_shell.xpm", nullptr, nullptr, nullptr, nullptr }, 
		{ "Object Subtraction", "Object Subtraction", "pix/object_subtraction.xpm", nullptr, nullptr, nullptr, nullptr }, 
		{ "Object Intersection", "Object Intersection", "pix/object_intersection.xpm", nullptr, nullptr, nullptr, nullptr }, 
		{ "Object Union", "Object Union", "pix/object_union.xpm", nullptr, nullptr, nullptr, nullptr }
	};
	ToolButton boolean_tools = ToolButton(boolean_tool_list);

	list<tool> deformation_tool_list = {
		{ "Taper Current Object", "Taper Current Object", "pix/object_taper.xpm", nullptr, nullptr, nullptr, nullptr }, 
		{ "Deform", "Deform", "pix/deform.xpm", nullptr, nullptr, nullptr, nullptr }, 
		{ "Sculpt", "Sculpt", "pix/sculpt.xpm", nullptr, nullptr, nullptr, nullptr }, 
		{ "Skew Current Object", "Skew Current Object", "pix/object_skew.xpm", nullptr, nullptr, nullptr, nullptr }, 
		{ "Bend Current Object", "Bend Current Object", "pix/object_bend.xpm", nullptr, nullptr, nullptr, nullptr }
	};
	ToolButton deformation_tools = ToolButton(deformation_tool_list);

	list<tool> array_tool_list = {
		{ "Create Grid Array of Objects", "Create Grid Array of Objects", "pix/grid_objects.xpm", create_object_grid, nullptr, nullptr, nullptr }, 
		{ "Create Spline Array of Objects", "Create Spline Array of Objects", "pix/spline_array.xpm", create_object_spline, nullptr, nullptr, nullptr }, 
		{ "Create Radial Array of Objects", "Create Radial Array of Objects", "pix/radial_array.xpm", create_object_radial, nullptr, nullptr, nullptr }, 
		{ "Convert Array to Group of Objects", "Convert Array to Group of Objects", "pix/array_group.xpm", array_to_group, nullptr, nullptr, nullptr }
	};
	ToolButton array_tools = ToolButton(array_tool_list);
	
	list<tool> draw_panel_tool_list = {
		{ "Draw Panel Tool", "Draw Panel Tool", "pix/draw_panel.xpm", draw_panel, nullptr, nullptr, nullptr }
	};
	ToolButton draw_panel_tools = ToolButton(draw_panel_tool_list);

	list<tool> curve_tool_list = {
		{ "Add Freehand Curve", "Add Freehand Curve", "pix/freehand_curve.xpm", freehand_curve, nullptr, nullptr, nullptr }
	};
	ToolButton curve_tools = ToolButton(curve_tool_list);

	list<tool> material_tool_list = {
		{ "Material Editor", "Material Editor", "pix/material_editor.xpm", material_editor, nullptr, nullptr, nullptr }
	};
	ToolButton material_tools = ToolButton(material_tool_list);

	list<tool> threed_paint_tool_list = {
		{ "3d Paint Tool", "3d Paint Tool", "pix/3d_paint.xpm", threed_paint, nullptr, nullptr, nullptr }
	};
	ToolButton threed_paint_tools = ToolButton(threed_paint_tool_list);

	list<tool> uv_mapping_tool_list = {
		{ "UV Mapping Editor", "UV Mapping Editor", "pix/uv_editor.xpm", uv_editor, nullptr, nullptr, nullptr }, 
		{ "Material Rectangle", "Material Rectangle", "pix/material_rectangle.xpm", material_rectangle, nullptr, nullptr, nullptr }
	};
	ToolButton uv_mapping_tools = ToolButton(uv_mapping_tool_list);

	list<tool> uv_projection_tool_list = {
		{ "Planar UV Projection", "Planar UV Projection", "pix/planar_uv.xpm", planar_uv, nullptr, nullptr, nullptr }, 
		{ "Cubic UV Projection", "Cubic UV Projection", "pix/cubic_uv.xpm", cubic_uv, nullptr, nullptr, nullptr }, 
		{ "Spherical UV Projection", "Spherical UV Projection", "pix/spherical_uv.xpm", spherical_uv, nullptr, nullptr, nullptr }, 
		{ "Cylindrical UV Projection", "Cylindrical UV Projection", "pix/cylindrical_uv.xpm", cylindrical_uv, nullptr, nullptr, nullptr }, 
		{ "UV Unwrapper", "UV Unwrapper", "pix/uv_unwrap.xpm", uv_unwrap, nullptr, nullptr, nullptr }, 
		{ "UV Slice", "UV Slice", "pix/uv_slice.xpm", uv_slice, nullptr, nullptr, nullptr }, 
		{ "Shrink-Wrap UV Computation", "Shrink-Wrap UV Computation", "pix/shrinkwrap_uv.xpm", shrinkwrap_uv, nullptr, nullptr, nullptr }
	};
	ToolButton uv_projection_tools = ToolButton(uv_projection_tool_list);

	list<tool> normalisation_tool_list = {
		{ "Normalise Location", "Normalise Location", "pix/normalise_location.xpm", normalise_location, nullptr, nullptr, nullptr }, 
		{ "Normalise Rotation", "Normalise Rotation", "pix/normalise_rotation.xpm", normalise_rotation, nullptr, nullptr, nullptr }, 
		{ "Normalise Scale", "Normalise Scale", "pix/normalise_scale.xpm", normalise_scale, nullptr, nullptr, nullptr }, 
		{ "Move Axes to Center of Object", "Move Axes to Center of Object", "pix/center_axes.xpm", center_axes, nullptr, nullptr, nullptr }, 
		{ "Axes", "Show Object Axes", "pix/show_axes.xpm", show_axes, nullptr, nullptr, nullptr }
	};
	ToolButton normalisation_tools = ToolButton(normalisation_tool_list);

	Gtk::Window main_tool_window;
	Gtk::Box main_tool_grid;
	main_tool_window.set_default_size(32, 24);
	main_tool_window.set_decorated(false);
	main_tool_grid.add(polgon_tools);
	main_tool_grid.add(nurbs_tools);
	main_tool_grid.add(metaball_tools);
	main_tool_grid.add(light_tools);
	main_tool_grid.add(camera_tools);
	main_tool_grid.add(sweep_tools);
	main_tool_grid.add(subdivision_tools);
	main_tool_grid.add(boolean_tools);
	main_tool_grid.add(deformation_tools);
	main_tool_grid.add(array_tools);
	main_tool_grid.add(draw_panel_tools);
	main_tool_grid.add(curve_tools);
	main_tool_grid.add(material_tools);
	main_tool_grid.add(threed_paint_tools);
	main_tool_grid.add(uv_mapping_tools);
	main_tool_grid.add(uv_projection_tools);
	main_tool_grid.add(normalisation_tools);
	main_tool_grid.show();
	main_tool_window.add(main_tool_grid);
	main_tool_window.show();



	list<tool> select_tool_list = {
		{ "Select", "Selection Tool", "pix/select.xpm", select_object, nullptr, nullptr, nullptr }, 
		{ "Global Panel", "Global Panel", "pix/normalise_rotation.xpm", global_panel, nullptr, nullptr, nullptr }, 
		{ "Unhide All Objects", "Unhide All Objects in Scene", "pix/normalise_scale.xpm", unhide_objects, nullptr, nullptr, nullptr }, 
		{ "Object Notes", "Open Object Notes Editor", "pix/center_axes.xpm", object_notes, nullptr, nullptr, nullptr }, 
	};
	ToolButton select_tools = ToolButton(select_tool_list);

	list<tool> edit_tool_list = {
		{ "Point Edit Context", "Point Edit Context", "pix/select_context.xpm", select_context, nullptr, nullptr, nullptr }, 
		{ "Point Edit Vertices", "Point Edit Vertices", "pix/select_vertices.xpm", select_vertices, nullptr, nullptr, nullptr }, 
		{ "Point Edit Edges", "Point Edit Edges", "pix/select_edges.xpm", select_edges, nullptr, nullptr, nullptr }, 
		{ "Point Edit Faces", "Point Edit Faces", "pix/select_faces.xpm", select_faces, nullptr, nullptr, nullptr }, 
		{ "Named Selection", "Named Selection", "pix/named_selection.xpm", named_selection, nullptr, nullptr, nullptr }, 
		{ "Select Using Lasso", "Select Using Lasso", "pix/lasso_selection.xpm", lasso_selection, nullptr, nullptr, nullptr }, 
		{ "Select Using Rectangle", "Select Using Rectangle", "pix/rectangle_selection.xpm", rectangle_selection, nullptr, nullptr, nullptr }, 
		{ "Select Using Freehand", "Select Using Freehand", "pix/freehand_selection.xpm", freehand_selection, nullptr, nullptr, nullptr } 
	};
	ToolButton edit_tools = ToolButton(edit_tool_list);

	list<tool> grid_tool_list = {
		{ "Toggle Grid Mode", "Toggle Grid Mode", "pix/toggle_grid.xpm", toggle_grid, nullptr, nullptr, nullptr }, 
		{ "Snap Vertex to Vertex", "Snap Vertex to Vertex", "pix/snap_vertex.xpm", snap_vertex, nullptr, nullptr, nullptr }, 
		{ "Snap Vertex to Edge", "Snap Vertex to Edge", "pix/snap_edge.xpm", snap_edge, nullptr, nullptr, nullptr }, 
		{ "Snap Vertex to Face", "Snap Vertex to Face", "pix/snap_face.xpm", snap_face, nullptr, nullptr, nullptr }, 
		{ "Magnetic Tool", "Magnetic Tool", "pix/magnetic_tool.xpm", magnetic_tool, nullptr, nullptr, nullptr }, 
		{ "Collision Disabled", "Collision Disabled", "pix/collision_disabled.xpm", collision_disabled, nullptr, nullptr, nullptr }, 
		{ "Collision With Ground", "Collision With Ground", "pix/collision_ground.xpm", collision_ground, nullptr, nullptr, nullptr }, 
		{ "Collision With Peers", "Collision With Peers", "pix/collision_peers.xpm", collision_peers, nullptr, nullptr, nullptr } 
	};
	ToolButton grid_tools = ToolButton(grid_tool_list);

	list<tool> new_scene_tool_list = {
		{ "New Scene", "Create New Scene", "pix/new_scene.xpm", new_scene, nullptr, nullptr, nullptr } 
	};
	ToolButton new_scene_tools = ToolButton(new_scene_tool_list);

	list<tool> undo_tool_list = {
		{ "Undo", "Undo", "pix/undo.xpm", undo, nullptr, nullptr, nullptr }, 
		{ "Redo", "Redo", "pix/redo.xpm", redo, nullptr, nullptr, nullptr } 
	};
	ToolButton undo_tools = ToolButton(undo_tool_list);

	list<tool> object_tool_list = {
		{ "Copy Object", "Ctrl C | Copy", "pix/object_copy.xpm", object_copy, nullptr, nullptr, nullptr }, 
		{ "Glue Object as Child", "Glue Object as Child", "pix/object_glue_child.xpm", glue_object_as_child, nullptr, nullptr, nullptr }, 
		{ "Glue Object as Sibling", "Glue Object as Sibling", "pix/object_glue_sibling.xpm", glue_object_as_sibling, nullptr, nullptr, nullptr }, 
		{ "Unglue Object", "Ctrl C | Copy", "pix/object_unglue.xpm", object_unglue, nullptr, nullptr, nullptr }, 
		{ "Group Objects as LOD", "Group Objects as LOD", "pix/object_group.xpm", object_group, nullptr, nullptr, nullptr }, 
		{ "UnGroup Objects as LOD", "UnGroup Objects as LOD", "pix/object_ungroup.xpm", object_ungroup, nullptr, nullptr, nullptr }, 
		{ "Delete Object", "Delete | Erase", "pix/object_erase.xpm", object_erase, nullptr, nullptr, nullptr } 
	};
	ToolButton object_tools = ToolButton(object_tool_list);

	list<tool> play_tool_list = {
		{ "Undo", "Undo", "pix/undo.xpm", undo, nullptr, nullptr, nullptr }, 
		{ "Undo", "Undo", "pix/undo.xpm", undo, nullptr, nullptr, nullptr }, 
		{ "Undo", "Undo", "pix/undo.xpm", undo, nullptr, nullptr, nullptr }, 
		{ "Undo", "Undo", "pix/undo.xpm", undo, nullptr, nullptr, nullptr }, 
		{ "Undo", "Undo", "pix/undo.xpm", undo, nullptr, nullptr, nullptr }, 
		{ "Undo", "Undo", "pix/undo.xpm", undo, nullptr, nullptr, nullptr }, 
		{ "Undo", "Undo", "pix/undo.xpm", undo, nullptr, nullptr, nullptr }, 
		{ "Undo", "Undo", "pix/undo.xpm", undo, nullptr, nullptr, nullptr }, 
		{ "Undo", "Undo", "pix/undo.xpm", undo, nullptr, nullptr, nullptr }, 
		{ "Redo", "Redo", "pix/redo.xpm", redo, nullptr, nullptr, nullptr } 
	};
	ToolButton play_tools = ToolButton(play_tool_list);
	
	list<tool> button_finder_tool_list = {
		{ "Button Finder", "Button Finder", "pix/button_finder.xpm", button_finder, nullptr, nullptr, nullptr }, 
		{ "Undo", "Undo", "pix/undo.xpm", undo, nullptr, nullptr, nullptr }, 
		{ "Undo", "Undo", "pix/undo.xpm", undo, nullptr, nullptr, nullptr }, 
		{ "Undo", "Undo", "pix/undo.xpm", undo, nullptr, nullptr, nullptr }, 
		{ "Undo", "Undo", "pix/undo.xpm", undo, nullptr, nullptr, nullptr }, 
		{ "Undo", "Undo", "pix/undo.xpm", undo, nullptr, nullptr, nullptr }, 
		{ "Redo", "Redo", "pix/redo.xpm", redo, nullptr, nullptr, nullptr } 
	};
	ToolButton button_finder_tools = ToolButton(button_finder_tool_list);

	Gtk::Window object_tool_window;
	Gtk::Box object_tool_grid;
	object_tool_window.set_default_size(32, 24);
	object_tool_window.set_decorated(false);
	object_tool_grid.add(select_tools);
	object_tool_grid.add(edit_tools);
	object_tool_grid.add(grid_tools);
	object_tool_grid.add(new_scene_tools);
	object_tool_grid.add(undo_tools);
	object_tool_grid.add(object_tools);
	object_tool_grid.add(play_tools);
	object_tool_grid.add(button_finder_tools);
	object_tool_grid.show();
	object_tool_window.add(object_tool_grid);
	object_tool_window.show();
		
	main_window->maximize();Gtk::Builder::create_from_file("src/gui.gtkbuilder");
	this -> app->run(*main_window);
}
