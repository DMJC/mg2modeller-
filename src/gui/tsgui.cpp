#include "../../include/gui/tsgui.h"

void ts_gui::make_gui(preferences &prefs, scene &curr_scene)
{
		/*TS Style UI*/
	this -> builder->get_widget("main_window_tools_grid", this->main_window_tools_grid);
	this -> builder->get_widget("ts_main_window", this->main_window);
	this -> builder->get_widget("bevel_window", this->bevel_window);
	this -> builder->get_widget("boolean_window", this->boolean_window);
	this -> builder->get_widget("chamfer_window", this->chamfer_window);
	this -> builder->get_widget("coords_window", this->coords_window);
	this -> builder->get_widget("cone_window", this->cone_window);
	this -> builder->get_widget("copy_tool_window", this->copy_tool_window);
	this -> builder->get_widget("cube_window", this->cube_window);
	this -> builder->get_widget("cylinder_window", this->cylinder_window);
	this -> builder->get_widget("deformation_window", this->deformation_window);
	this -> builder->get_widget("edit_window", this->edit_window);
	this -> builder->get_widget("fillet_window", this->fillet_window);
	this -> builder->get_widget("geosphere_window", this->geosphere_window);
	this -> builder->get_widget("lathe_window", this->lathe_window);
	this -> builder->get_widget("lights_window", this->lights_window);
	this -> builder->get_widget("macro_window", this->macro_window);
	this -> builder->get_widget("metaball_options_window", this->metaball_options_window);
	this -> builder->get_widget("mirror_options_window", this->mirror_options_window);
	this -> builder->get_widget("nurbs_plane_window", this->nurbs_plane_window);
	this -> builder->get_widget("nurbs_saddle_window", this->nurbs_saddle_window);
	this -> builder->get_widget("nurbs_cube_window", this->nurbs_cube_window);
	this -> builder->get_widget("nurbs_cone_window", this->nurbs_cone_window);
	this -> builder->get_widget("nurbs_cylinder_window", this->nurbs_cylinder_window);
	this -> builder->get_widget("nurbs_sphere_window", this->nurbs_sphere_window);
	this -> builder->get_widget("nurbs_torus_window", this->nurbs_torus_window);
	this -> builder->get_widget("object_info_window", this->object_info_window);
	this -> builder->get_widget("object_movie_window", this->object_movie_window);
	this -> builder->get_widget("object_render_options_window", this->object_render_options_window);
	this -> builder->get_widget("ogl_setting_window", this->ogl_setting_window);
	this -> builder->get_widget("pan_movie_window", this->pan_movie_window);
	this -> builder->get_widget("panoramic_camera_window", this->panoramic_camera_window);
	this -> builder->get_widget("plane_window", this->plane_window);
	this -> builder->get_widget("point_edit_window", this->point_edit_window);
	this -> builder->get_widget("polygon_reduction_tool_window", this->polygon_reduction_tool_window);
	this -> builder->get_widget("preferences_window", this->preferences_window);
	this -> builder->get_widget("primitive_parameters_window", this->primitive_parameters_window);
	this -> builder->get_widget("primitive_shape_window", this->primitive_shape_window);
	this -> builder->get_widget("rounded_cube_window", this->rounded_cube_window);
	this -> builder->get_widget("rounded_cylinder_window", this->rounded_cylinder_window);
	this -> builder->get_widget("scene_editor_preferences_window", this->scene_editor_preferences_window);
	this -> builder->get_widget("selection_window", this->selection_window);
	this -> builder->get_widget("set_keyframe_window", this->set_keyframe_window);
	this -> builder->get_widget("shell_properties_window", this->shell_properties_window);
	this -> builder->get_widget("skin_options_window", this->skin_options_window);
	this -> builder->get_widget("smooth_quad_window", this->smooth_quad_window);
	this -> builder->get_widget("sphere_window", this->sphere_window);
	this -> builder->get_widget("sweep_tip_window", this->sweep_tip_window);
	this -> builder->get_widget("taper_window", this->taper_window);
	this -> builder->get_widget("torus_window", this->torus_window);
	this -> builder->get_widget("undo_options_window", this->undo_options_window);
	this -> builder->get_widget("wind_window", this->wind_window);
	this -> builder->get_widget("ts_view_grid", this->view_grid);
	this -> builder->get_widget("ts_quit_button", this->ts_quit_button);
	this -> builder->get_widget("ts_save_layout_menuitem", this->ts_save_layout_menuitem);

	// Object Info entry widgets
	this -> builder->get_widget("obj_info_name_entry", this->obj_info_name);
	this -> builder->get_widget("entry2", this->obj_info_loc_x);
	this -> builder->get_widget("entry3", this->obj_info_loc_y);
	this -> builder->get_widget("entry4", this->obj_info_loc_z);
	this -> builder->get_widget("entry5", this->obj_info_rot_x);
	this -> builder->get_widget("entry6", this->obj_info_rot_y);
	this -> builder->get_widget("entry7", this->obj_info_rot_z);
	this -> builder->get_widget("entry8", this->obj_info_sca_x);
	this -> builder->get_widget("entry9", this->obj_info_sca_y);
	this -> builder->get_widget("entry10", this->obj_info_sca_z);
	this -> builder->get_widget("label18", this->obj_info_verts);
	this -> builder->get_widget("label20", this->obj_info_faces);

	// Shape parameter spin buttons
	this -> builder->get_widget("plane_resolution_spinbutton", this->plane_resolution_spin);
	this -> builder->get_widget("spinbutton16", this->cube_resolution_spin);
	this -> builder->get_widget("spinbutton21", this->cone_lat_spin);
	this -> builder->get_widget("spinbutton22", this->cone_long_spin);
	this -> builder->get_widget("spinbutton18", this->cylinder_lat_spin);
	this -> builder->get_widget("spinbutton19", this->cylinder_long_spin);
	this -> builder->get_widget("spinbutton20", this->cylinder_top_radius_spin);
	this -> builder->get_widget("spinbutton23", this->sphere_lat_spin);
	this -> builder->get_widget("spinbutton24", this->sphere_long_spin);
	this -> builder->get_widget("spinbutton25", this->geosphere_resolution_spin);
	this -> builder->get_widget("spinbutton26", this->rounded_cylinder_lat_spin);
	this -> builder->get_widget("spinbutton27", this->rounded_cylinder_long_spin);
	this -> builder->get_widget("spinbutton28", this->rounded_cube_lat_spin);
	this -> builder->get_widget("spinbutton29", this->rounded_cube_long_spin);
	this -> builder->get_widget("spinbutton30", this->torus_lat_spin);
	this -> builder->get_widget("spinbutton31", this->torus_long_spin);
	this -> builder->get_widget("spinbutton32", this->torus_inner_radius_spin);

	curr_scene.SetGui(this);

	// Connect Entry activate signals to apply edits on Enter key
	auto connect_entry = [&](Gtk::Entry* e) {
		if (e) e->signal_activate().connect(sigc::bind(sigc::mem_fun(*this, &ts_gui::on_object_info_entry_changed), &curr_scene));
	};
	connect_entry(obj_info_name);
	connect_entry(obj_info_loc_x); connect_entry(obj_info_loc_y); connect_entry(obj_info_loc_z);
	connect_entry(obj_info_rot_x); connect_entry(obj_info_rot_y); connect_entry(obj_info_rot_z);
	connect_entry(obj_info_sca_x); connect_entry(obj_info_sca_y); connect_entry(obj_info_sca_z);

	// Connect shape parameter spin button activate signals to update defaults on Enter
	auto connect_spin = [&](Gtk::SpinButton* s, void (ts_gui::*handler)(scene*)) {
		if (s) s->signal_activate().connect(sigc::bind(sigc::mem_fun(*this, handler), &curr_scene));
	};
	connect_spin(plane_resolution_spin, &ts_gui::on_plane_param_activated);
	connect_spin(cube_resolution_spin, &ts_gui::on_cube_param_activated);
	connect_spin(cone_lat_spin, &ts_gui::on_cone_param_activated);
	connect_spin(cone_long_spin, &ts_gui::on_cone_param_activated);
	connect_spin(cylinder_lat_spin, &ts_gui::on_cylinder_param_activated);
	connect_spin(cylinder_long_spin, &ts_gui::on_cylinder_param_activated);
	connect_spin(cylinder_top_radius_spin, &ts_gui::on_cylinder_param_activated);
	connect_spin(sphere_lat_spin, &ts_gui::on_sphere_param_activated);
	connect_spin(sphere_long_spin, &ts_gui::on_sphere_param_activated);
	connect_spin(geosphere_resolution_spin, &ts_gui::on_geosphere_param_activated);
	connect_spin(rounded_cube_lat_spin, &ts_gui::on_rounded_cube_param_activated);
	connect_spin(rounded_cube_long_spin, &ts_gui::on_rounded_cube_param_activated);
	connect_spin(rounded_cylinder_lat_spin, &ts_gui::on_rounded_cylinder_param_activated);
	connect_spin(rounded_cylinder_long_spin, &ts_gui::on_rounded_cylinder_param_activated);
	connect_spin(torus_lat_spin, &ts_gui::on_torus_param_activated);
	connect_spin(torus_long_spin, &ts_gui::on_torus_param_activated);
	connect_spin(torus_inner_radius_spin, &ts_gui::on_torus_param_activated);

	if (ts_save_layout_menuitem)
		ts_save_layout_menuitem->signal_activate().connect(sigc::bind(sigc::mem_fun(*this, &ts_gui::on_save_layout), &curr_scene));

	edit_window->set_keep_above(TRUE);
	object_info_window->set_keep_above(TRUE);
	int h_loc = 0;
	int w_loc = 0;
	int s_width = 0;
	int s_height = 0;

	Glib::RefPtr <Gdk::Screen> cur_screen = Gdk::Screen::get_default();
    cur_screen = main_window->get_screen();
    s_width =  cur_screen->get_width();
    s_height = cur_screen->get_height();
    std::cout << "Resolution is: " << s_width <<" x "<< s_height << std::endl;
	
    w_loc = (s_width - 300);
    h_loc = (s_height - 32);

    object_info_window->move(w_loc, h_loc/2);

	
    	gtk_builder_connect_signals (this->builder->gobj(), NULL);

	list<tool> render_list = {
		{ "Render Current Object", "Render Current Object", "pix/render_object.xpm", 1, nullptr, nullptr, nullptr, nullptr, curr_scene },
		{ "Render Portion of Screen", "Render Portion of Screen", "pix/render_selection.xpm", 2, nullptr, nullptr, nullptr, nullptr, curr_scene },
		{ "Render Scene", "Render Scene", "pix/render_scene.xpm", 3, nullptr, nullptr, nullptr, nullptr, curr_scene },
		{ "Render Scene to File", "Render Scene to File", "pix/render_to_file.xpm", 4, nullptr, nullptr, nullptr, nullptr, curr_scene },
		{ "Compute Textures from Illumination", "Compute Textures from Illumination", "pix/compute_textures.xpm", 5, nullptr, nullptr, nullptr, nullptr, curr_scene }
	};
	ToolButton render_tools = ToolButton(render_list);

	list<tool> draw_mode_list = {
		{ "Draw Objects as Wireframe", "Draw Objects as Wireframe", "pix/draw_wireframe.xpm", 6, draw_as_wireframe, nullptr, nullptr, nullptr, curr_scene },
		{ "Draw Objects as Transparent Outline", "Draw Objects as Transparent Outline", "pix/draw_transparent_wire.xpm", 7, draw_as_transparent_wireframe, nullptr, nullptr, nullptr, curr_scene },
		{ "Draw Objects as Solid Outline", "Draw Objects as Solid Outline", "pix/draw_solid_wire.xpm", 8, draw_as_solid_wireframe, nullptr, nullptr, nullptr, curr_scene },
		{ "Draw Objects as Transparent", "Draw Objects as Transparent", "pix/draw_transparent.xpm", 9, draw_as_transparent, nullptr, nullptr, nullptr, curr_scene },
		{ "Draw Objects as Solid", "Draw Objects as Solid", "pix/draw_solid.xpm", 10, draw_as_solid, nullptr, nullptr, nullptr, curr_scene },
		{ "Draw Objects as Radiosity", "Draw Objects as Radiosity", "pix/draw_radiosity.xpm", 11, draw_as_radiosity, nullptr, nullptr, nullptr, curr_scene }
	};
	ToolButton draw_mode_tools = ToolButton(draw_mode_list);
	
	list<tool> splitscreen_list = {
		{ "Quad View", "Quad View", "pix/view_quad.xpm", 12, nullptr, nullptr, nullptr, nullptr, curr_scene },
		{ "Triple View", "Triple View", "pix/view_triple.xpm", 13, nullptr, nullptr, nullptr, nullptr, curr_scene },
		{ "Split View", "Split View", "pix/view_double.xpm", 14, nullptr, nullptr, nullptr, nullptr, curr_scene },
		{ "Single View", "Single View", "pix/view_single.xpm", 15, nullptr, nullptr, nullptr, nullptr, curr_scene }
	};
	ToolButton splitscreen_tools = ToolButton(splitscreen_list);

	list<tool> view_list = {
		{ "Perspective View", "Perspective View", "pix/view_perspective.xpm", 16, nullptr, nullptr, nullptr, nullptr, curr_scene },
		{ "Front View", "Front View", "pix/view_front.xpm", 17, nullptr, nullptr, nullptr, nullptr, curr_scene },
		{ "Left View", "Left View", "pix/view_left.xpm", 18, nullptr, nullptr, nullptr, nullptr, curr_scene },
		{ "Top View", "Top View", "pix/view_top.xpm", 19, nullptr, nullptr, nullptr, nullptr, curr_scene },
		{ "Back View", "Back View", "pix/view_back.xpm", 20, nullptr, nullptr, nullptr, nullptr, curr_scene },
		{ "Right View", "Right View", "pix/view_right.xpm", 21, nullptr, nullptr, nullptr, nullptr, curr_scene },
		{ "Bottom View", "Bottom View", "pix/view_bottom.xpm", 22, nullptr, nullptr, nullptr, nullptr, curr_scene },
		{ "Camera View", "Camera View", "pix/view_camera.xpm", 23, nullptr, nullptr, nullptr, nullptr, curr_scene }
	};
	ToolButton view_tools = ToolButton(view_list);

	list<tool> new_view_list = {
		{ "New Perspective View", "New Perspective View", "pix/new_view_perspective.xpm", 24, nullptr, nullptr, nullptr, nullptr, curr_scene },
		{ "New Front View", "New Front View", "pix/new_view_front.xpm", 25, nullptr, nullptr, nullptr, nullptr, curr_scene },
		{ "New Left View", "New Left View", "pix/new_view_left.xpm", 26, nullptr, nullptr, nullptr, nullptr, curr_scene },
		{ "New Top View", "New Top View", "pix/new_view_top.xpm", 27, nullptr, nullptr, nullptr, nullptr, curr_scene },
		{ "New Back View", "New Back View", "pix/new_view_back.xpm", 28, nullptr, nullptr, nullptr, nullptr, curr_scene },
		{ "New Right View", "New Right View", "pix/new_view_right.xpm", 29, nullptr, nullptr, nullptr, nullptr, curr_scene },
		{ "New Bottom View", "New Bottom View", "pix/new_view_bottom.xpm", 30, nullptr, nullptr, nullptr, nullptr, curr_scene },
		{ "New Camera View", "New Camera View", "pix/new_view_camera.xpm", 31, nullptr, nullptr, nullptr, nullptr, curr_scene }
	};
	ToolButton new_view_tools = ToolButton(new_view_list);

	list<tool> coordinates_list = {
		{ "World Coordinates", "Use World Coordinates", "pix/coords_world.xpm", 32, nullptr, nullptr, nullptr, nullptr, curr_scene },
		{ "Screen Coordinates", "Use Screen Coordinates", "pix/coords_screen.xpm", 33, nullptr, nullptr, nullptr, nullptr, curr_scene },
		{ "Object Coordinates", "Use Object Coordinates", "pix/coords_object.xpm", 34, nullptr, nullptr, nullptr, nullptr, curr_scene }
	};
	ToolButton coordinates_tools = ToolButton(coordinates_list);

	list<tool> renderer_list = {
		{ "OpenGL Renderer", "Use OpenGL Renderer", "pix/opengl.xpm", 35, nullptr, nullptr, nullptr, nullptr, curr_scene },
		{ "Vulkan Renderer", "Use Vulkan Renderer", "pix/vulkan.xpm", 36, nullptr, nullptr, nullptr, nullptr, curr_scene }
	};
	ToolButton renderer_tools = ToolButton(renderer_list);

	main_window_tools_grid->attach(render_tools,0,1,1,1);
	main_window_tools_grid->attach(draw_mode_tools,1,1,1,1);
	main_window_tools_grid->attach(splitscreen_tools,2,1,1,1);
	main_window_tools_grid->attach(view_tools,3,1,1,1);
	main_window_tools_grid->attach(new_view_tools,4,1,1,1);
	main_window_tools_grid->attach(coordinates_tools,5,1,1,1);
	main_window_tools_grid->attach(renderer_tools,6,1,1,1);
	main_window_tools_grid->show();
	main_window->show();
	int num_views = 1;
	view_grid->show();

	view view3d_4(LEFT_VIEW, WIREFRAME_VIEW, curr_scene );
	view view3d_3(TOP_VIEW, WIREFRAME_VIEW, curr_scene );
	view view3d_2(FRONT_VIEW, WIREFRAME_VIEW, curr_scene );
	view view3d_1(PERSPECTIVE_VIEW, WIREFRAME_VIEW, curr_scene );

	switch (num_views){
	case 4:
//		view view3d_4(LEFT_VIEW, WIREFRAME_VIEW, curr_scene );
		view_grid->attach(view3d_4, 1, 1, 1, 1);
	case 3:
//		view view3d_3(TOP_VIEW, WIREFRAME_VIEW, curr_scene );
		if (num_views == 4){
			cout << "There are 4 views" << endl;
			view_grid->attach(view3d_3, 0, 1, 1, 1);
		}
		else{
			view_grid->attach(view3d_3, 1, 1, 2, 1);
		}
	case 2:
//		view view3d_2(FRONT_VIEW, WIREFRAME_VIEW, curr_scene );
		view_grid->attach(view3d_2, 1, 0, 1, 1);
	default:
//		view view3d_1(PERSPECTIVE_VIEW, WIREFRAME_VIEW, curr_scene );
		view_grid->attach(view3d_1, 0, 0, 1, 1);
	break;
	}
		cout << "Displays Added to Grid" << endl;
		view_grid->show_all();
		object_info_window->show();

	auto* vo1 = new list<tool>({{ "Eye Move", "Move View Around Scene", "pix/view_move.xpm", 37, view_move, coords_parameters, nullptr, nullptr, curr_scene }});
	auto* vo2 = new list<tool>({{ "Eye Rotate", "Rotate View Around Scene", "pix/view_rotate.xpm", 38, &view_rotate, coords_parameters, nullptr, nullptr, curr_scene }});
	auto* vo3 = new list<tool>({{ "Zoom", "Zoom View of Scene", "pix/view_zoom.xpm", 39, &view_zoom, nullptr, nullptr, nullptr, curr_scene }});
	auto* vo4 = new list<tool>({{ "Object Move", "Move Object Around Scene", "pix/object_move.xpm", 40, &object_move, coords_parameters, nullptr, nullptr, curr_scene }});
	auto* vo5 = new list<tool>({{ "Object Rotate", "Rotate Object Within Scene", "pix/object_rotate.xpm", 41, &object_rotate, coords_parameters, nullptr, nullptr, curr_scene }});
	auto* vo6 = new list<tool>({{ "Object Scale", "Scale Object in Relation to Scene", "pix/object_scale.xpm", 42, &object_scale, coords_parameters, nullptr, nullptr, curr_scene }});
	auto* vo7 = new list<tool>({{ "Move Up in Hierarchy","Move Up in Hierarchy: Use Arrow Keys to move within hierarchy", "pix/hierarchy_up.xpm", 43, &hierarchy_up, nullptr, nullptr, nullptr, curr_scene }});
	auto* vo8 = new list<tool>({{ "Move Down in Hierarchy","Move Down in Hierarchy: Use Arrow Keys to move within hierarchy", "pix/hierarchy_down.xpm", 44, &hierarchy_down, nullptr, nullptr, nullptr, curr_scene }});
	{ float tx, ty; int to; bool te;
	  curr_scene.prefs.get_toolbar_layout(0, tx, ty, to, te);
	  curr_scene.view_object_toolbar.setOrientation(to ? GLToolbar::VERTICAL : GLToolbar::HORIZONTAL);
	  curr_scene.view_object_toolbar.setPosition(tx, ty);
	  curr_scene.view_object_toolbar.setExpanded(te); }
	curr_scene.view_object_toolbar.reserve(8);
	curr_scene.view_object_toolbar.addGroup(vo1);
	curr_scene.view_object_toolbar.addGroup(vo2);
	curr_scene.view_object_toolbar.addGroup(vo3);
	curr_scene.view_object_toolbar.addGroup(vo4);
	curr_scene.view_object_toolbar.addGroup(vo5);
	curr_scene.view_object_toolbar.addGroup(vo6);
	curr_scene.view_object_toolbar.addGroup(vo7);
	curr_scene.view_object_toolbar.addGroup(vo8);
	curr_scene.owned_tool_lists.insert(curr_scene.owned_tool_lists.end(), {vo1,vo2,vo3,vo4,vo5,vo6,vo7,vo8});

	auto* polygon_tool_list = new list<tool>({
		{ "Plane", "Create a Plane Object", "pix/poly_plane.xpm", 50, create_plane, plane_parameters, nullptr, nullptr, curr_scene },
		{ "Cube", "Create a Cube Object", "pix/poly_cube.xpm", 51, create_cube, cube_parameters, nullptr, nullptr, curr_scene },
		{ "Cylinder", "Create a Cylinder Object", "pix/poly_cylinder.xpm", 52, create_cylinder, cylinder_parameters, nullptr, nullptr, curr_scene },
		{ "Cone", "Create a Cone Object", "pix/poly_cone.xpm", 53, create_cone, cone_parameters, nullptr, nullptr, curr_scene },
		{ "Sphere", "Create a Sphere Object", "pix/poly_sphere.xpm", 54, create_sphere, sphere_parameters, nullptr, nullptr, curr_scene },
		{ "GeoSphere", "Create a GeoSphere Object", "pix/poly_geosphere.xpm", 55, create_geosphere, geosphere_parameters, nullptr, nullptr, curr_scene },
		{ "Rounded Cylinder", "Create a Rounded Cylinder Object", "pix/poly_rounded_cylinder.xpm", 56, create_rounded_cylinder, rounded_cylinder_parameters, nullptr, nullptr, curr_scene },
		{ "Rounded Cube", "Create a Rounded Cube Object", "pix/poly_rounded_cube.xpm", 57, create_rounded_cube, rounded_cube_parameters, nullptr, nullptr, curr_scene },
		{ "Torus", "Create a Torus Object", "pix/poly_torus.xpm", 58, create_torus, torus_parameters, nullptr, nullptr, curr_scene }
	});

	auto* nurbs_tool_list = new list<tool>({ { "NURBS Plane", "Create a NURBS Plane", "pix/nurbs_plane.xpm", 60, create_nurbs_plane, nurbs_plane_parameters, nullptr, nullptr, curr_scene }, { "NURBS Cylinder (half)", "Create a NURBS Cylinder Half Pipe", "pix/nurbs_halfpipe.xpm", 61, create_nurbs_halfpipe, nullptr, nullptr, nullptr, curr_scene }, { "NURBS Saddle", "Create a NURBS Saddle", "pix/nurbs_saddle.xpm", 62, create_nurbs_saddle, nurbs_saddle_parameters, nullptr, nullptr, curr_scene }, { "NURBS Cube", "Create a NURBS Cube", "pix/nurbs_cube.xpm", 63, create_nurbs_cube, nurbs_cube_parameters, nullptr, nullptr, curr_scene }, { "NURBS Cylinder", "Create a NURBS Cylinder", "pix/nurbs_cylinder.xpm", 64, create_nurbs_cylinder, nurbs_cylinder_parameters, nullptr, nullptr, curr_scene }, { "NURBS Cone", "Create a NURBS Cone", "pix/nurbs_cone.xpm", 65, create_nurbs_cone, nurbs_cone_parameters, nullptr, nullptr, curr_scene }, { "NURBS Sphere", "Create a NURBS Sphere", "pix/nurbs_sphere.xpm", 66, create_nurbs_sphere, nurbs_sphere_parameters, nullptr, nullptr, curr_scene }, { "NURBS Torus", "Create a NURBS Torus", "pix/nurbs_torus.xpm", 67, create_nurbs_torus, nurbs_torus_parameters, nullptr, nullptr, curr_scene } });
	auto* metaball_tool_list = new list<tool>({ { "Metaball Cube", "Create a Metaball Cube", "pix/metaball_cube.xpm", 70, create_metaball_cube, metaball_parameters, nullptr, nullptr, curr_scene }, { "Metaball Cylinder", "Create a Metaball Cylinder", "pix/metaball_cylinder.xpm", 71, create_metaball_cylinder, metaball_parameters, nullptr, nullptr, curr_scene }, { "Metaball Sphere", "Create a Metaball Sphere", "pix/metaball_sphere.xpm", 72, create_metaball_sphere, metaball_parameters, nullptr, nullptr, curr_scene }, { "Metaball Rounded Cylinder", "Create a Metaball Rounded Cylinder", "pix/metaball_rounded_cylinder.xpm", 73, create_metaball_rounded_cylinder, metaball_parameters, nullptr, nullptr, curr_scene }, { "Metaball Rounded Cube", "Create a Metaball Rounded Cube", "pix/metaball_rounded_cube.xpm", 74, create_metaball_rounded_cube, metaball_parameters, nullptr, nullptr, curr_scene }, { "Metaball Metamuscle", "Create a Metaball Metamuscle", "pix/metaball_muscle.xpm", 75, create_metaball_metamuscle, metaball_parameters, nullptr, nullptr, curr_scene } });
	auto* light_tool_list = new list<tool>({ { "Image Based Light", "Create an Image Based Light", "pix/image_light.xpm", 90, create_image_light, light_parameters, nullptr, nullptr, curr_scene }, { "Spot Light", "Create a Spot Light", "pix/spot_light.xpm", 91, create_spot_light, light_parameters, nullptr, nullptr, curr_scene }, { "Local Light", "Create a Local Light", "pix/local_light.xpm", 92, create_local_light, light_parameters, nullptr, nullptr, curr_scene }, { "Infinite Light", "Create an Infinite Light", "pix/infinite_light.xpm", 93, create_infinite_light, light_parameters, nullptr, nullptr, curr_scene }, { "Projector Light", "Create a Projector Light", "pix/projector_light.xpm", 94, create_projector_light, light_parameters, nullptr, nullptr, curr_scene }, { "Sky Light", "Create a Sky Light", "pix/sky_light.xpm", 95, create_sky_light, light_parameters, nullptr, nullptr, curr_scene }, { "Goniometric Light", "Create a Goniometric Light", "pix/goniometric_light.xpm", 96, create_goniometric_light, light_parameters, nullptr, nullptr, curr_scene }, { "Area Light", "Create an Area Light", "pix/area_light.xpm", 97, create_area_light, light_parameters, nullptr, nullptr, curr_scene } });
	auto* camera_tool_list = new list<tool>({ { "Camera", "Create a Camera", "pix/camera.xpm", 100, create_camera, nullptr, nullptr, nullptr, curr_scene }, { "Panoramic Camera", "Create a Camera", "pix/panoramic_camera.xpm", 101, create_panoramic_camera, nullptr, nullptr, nullptr, curr_scene }, { "Global Physical Wind", "Create a Global Physical Wind", "pix/global_wind.xpm", 102, create_global_physical_wind, wind_parameters, nullptr, nullptr, curr_scene }, { "Local Physical Wind", "Create a Local Physical Wind", "pix/local_wind.xpm", 103, create_local_physical_wind, wind_parameters, nullptr, nullptr, curr_scene }, { "Standalone Deformation Plane", "Create a Standalone Deformation Plane", "pix/deformation_plane.xpm", 104, deformation_plane, nullptr, nullptr, nullptr, curr_scene }, { "Standalone Deformation Pipe", "Create a Standalone Deformation Pipe", "pix/deformation_pipe.xpm", 105, deformation_pipe, nullptr, nullptr, nullptr, curr_scene }, { "Standalone Deformation Object", "Create a Standalone Deformation Object", "pix/deformation_object.xpm", 106, deformation_object, nullptr, nullptr, nullptr, curr_scene } });
	auto* sweep_tool_list = new list<tool>({ { "Sweep", "Sweep", "pix/sweep.xpm", 110, sweep, sweep_tip_parameters, nullptr, nullptr, curr_scene }, { "Fillet Tool", "Fillet", "pix/fillet.xpm", 111, fillet, fillet_parameters, nullptr, nullptr, curr_scene }, { "Chamfer Tool", "Chamfer", "pix/chamfer.xpm", 112, chamfer, chamfer_parameters, nullptr, nullptr, curr_scene }, { "Bevel", "Bevel", "pix/bevel.xpm", 113, bevel, bevel_parameters, nullptr, nullptr, curr_scene }, { "Macro/Sweep", "Macro/Sweep", "pix/macro_sweep.xpm", 114, macro_sweep, macro_parameters, nullptr, nullptr, curr_scene }, { "Lathe", "Lathe", "pix/lathe.xpm", 115, lathe, lathe_parameters, nullptr, nullptr, curr_scene }, { "Tip", "Tip", "pix/tip.xpm", 116, tip, sweep_tip_parameters, nullptr, nullptr, curr_scene } });
	auto* subdivision_tool_list = new list<tool>({ { "Subdivision Object", "Subdivision Object", "pix/subdivision_object.xpm", 120, nullptr, nullptr, nullptr, nullptr, curr_scene }, { "Plastiform", "Plastiform", "pix/plastiform.xpm", 121, nullptr, nullptr, nullptr, nullptr, curr_scene } });
	auto* boolean_tool_list = new list<tool>({ { "Object Shell", "Object Shell", "pix/object_shell.xpm", 130, nullptr, shell_parameters, nullptr, nullptr, curr_scene }, { "Object Subtraction", "Object Subtraction", "pix/object_subtraction.xpm", 131, boolean_subtract, boolean_parameters, nullptr, nullptr, curr_scene }, { "Object Intersection", "Object Intersection", "pix/object_intersection.xpm", 132, boolean_intersect, boolean_parameters, nullptr, nullptr, curr_scene }, { "Object Union", "Object Union", "pix/object_union.xpm", 133, boolean_union, boolean_parameters, nullptr, nullptr, curr_scene } });
	auto* deformation_tool_list = new list<tool>({ { "Taper Current Object", "Taper Current Object", "pix/taper_object.xpm", 140, nullptr, nullptr, nullptr, nullptr, curr_scene }, { "Deform", "Deform", "pix/deform_object.xpm", 141, nullptr, nullptr, nullptr, nullptr, curr_scene }, { "Sculpt", "Sculpt", "pix/sculpt_surface.xpm", 142, nullptr, nullptr, nullptr, nullptr, curr_scene }, { "Skew Current Object", "Skew Current Object", "pix/skew_object.xpm", 143, nullptr, nullptr, nullptr, nullptr, curr_scene }, { "Bend Current Object", "Bend Current Object", "pix/bend_object.xpm", 144, nullptr, nullptr, nullptr, nullptr, curr_scene }, { "Standalone Deformation Object", "Standalone Deformation Object", "pix/standalone_deformation.xpm", 145, nullptr, nullptr, nullptr, nullptr, curr_scene }, { "Delete Deformation Object", "Delete Deformation Object", "pix/delete_deformation.xpm", 146, nullptr, nullptr, nullptr, nullptr, curr_scene } });
	auto* array_tool_list = new list<tool>({ { "Create Grid Array of Objects", "Create Grid Array of Objects", "pix/grid_objects.xpm", 150, create_object_grid, nullptr, nullptr, nullptr, curr_scene }, { "Create Spline Array of Objects", "Create Spline Array of Objects", "pix/spline_array.xpm", 151, create_object_spline, nullptr, nullptr, nullptr, curr_scene }, { "Create Radial Array of Objects", "Create Radial Array of Objects", "pix/radial_array.xpm", 152, create_object_radial, nullptr, nullptr, nullptr, curr_scene }, { "Convert Array to Group of Objects", "Convert Array to Group of Objects", "pix/array_group.xpm", 153, array_to_group, nullptr, nullptr, nullptr, curr_scene } });
	auto* draw_panel_tool_list = new list<tool>({ { "Draw Panel Tool", "Draw Panel Tool", "pix/draw_panel.xpm", 160, draw_panel, nullptr, nullptr, nullptr, curr_scene } });
	auto* curve_tool_list = new list<tool>({ { "Add Freehand Curve", "Add Freehand Curve", "pix/freehand_curve.xpm", 161, freehand_curve, nullptr, nullptr, nullptr, curr_scene }, { "Add Curve", "Add Curve", "pix/curve.xpm", 162, freehand_curve, nullptr, nullptr, nullptr, curr_scene }, { "Add Polyline", "Add Polyline", "pix/polyline.xpm", 163, freehand_curve, nullptr, nullptr, nullptr, curr_scene }, { "Add Circular Arc Drawn by Center and two Points", "Add Circular Arc Drawn by Center and two Points", "pix/circular_arc_center_two_points.xpm", 164, freehand_curve, nullptr, nullptr, nullptr, curr_scene }, { "Add Circular Arc", "Add Circular Arc", "pix/circular_arc_three_points.xpm", 165, freehand_curve, nullptr, nullptr, nullptr, curr_scene }, { "Add Elliptical Arc", "Add Elliptical Arc", "pix/elliptical_arc_center_vertex_point.xpm", 166, freehand_curve, nullptr, nullptr, nullptr, curr_scene }, { "Add Elliptical Arc", "Add Elliptical Arc", "pix/elliptical_arc_center_three_points.xpm", 167, freehand_curve, nullptr, nullptr, nullptr, curr_scene }, { "Circle Drawn by Center and Point", "Circle Drawn by Center and Point", "pix/circle_point.xpm", 168, nullptr, nullptr, nullptr, nullptr, curr_scene }, { "Circle Drawn by Two Points", "Circle Drawn by Two Points", "pix/circle_two_points.xpm", 169, nullptr, nullptr, nullptr, nullptr, curr_scene }, { "Circle Drawn by Three Points", "Circle Drawn by Three Points", "pix/circle_three_points.xpm", 170, nullptr, nullptr, nullptr, nullptr, curr_scene }, { "Add Regular Polygon", "Add Regular Polygon", "pix/regular_polygon.xpm", 171, nullptr, nullptr, nullptr, nullptr, curr_scene }, { "Ellipse Drawn by Center and Point", "Ellipse Drawn by Center and Point", "pix/ellipse_point.xpm", 172, freehand_curve, nullptr, nullptr, nullptr, curr_scene }, { "Ellipse Drawn by Center, Vertex Point", "Ellipse Drawn by Center, Vertex Point", "pix/ellipse_center_vertex_point.xpm", 173, freehand_curve, nullptr, nullptr, nullptr, curr_scene }, { "Ellipse Drawn by Center, two Focuses and Point", "Ellipse Drawn by Center, two Focuses and Point", "pix/ellipse_two_focus_point.xpm", 174, freehand_curve, nullptr, nullptr, nullptr, curr_scene }, { "Ellipse Drawn by two Vertices and Point", "Ellipse Drawn by two Vertices and Point", "pix/ellipse_two_vertex_point.xpm", 175, freehand_curve, nullptr, nullptr, nullptr, curr_scene }, { "Add Vertical Text", "Add Vertical Text, Right Click scene to select Font", "pix/text.xpm", 176, nullptr, nullptr, nullptr, nullptr, curr_scene }, { "Add Horizontal Text", "Add Horizontal Text, Right Click scene to select Font", "pix/horizontal_text.xpm", 177, nullptr, nullptr, nullptr, nullptr, curr_scene } });
	auto* skin_tool_list = new list<tool>({ { "Material Editor", "Material Editor", "pix/material_editor.xpm", 180, material_editor, nullptr, nullptr, nullptr, curr_scene }, { "Material Editor", "Material Editor", "pix/material_editor.xpm", 181, material_editor, nullptr, nullptr, nullptr, curr_scene }, { "Material Editor", "Material Editor", "pix/material_editor.xpm", 182, material_editor, nullptr, nullptr, nullptr, curr_scene }, { "Material Editor", "Material Editor", "pix/material_editor.xpm", 183, material_editor, nullptr, nullptr, nullptr, curr_scene }, { "Material Editor", "Material Editor", "pix/material_editor.xpm", 184, material_editor, nullptr, nullptr, nullptr, curr_scene }, { "Material Editor", "Material Editor", "pix/material_editor.xpm", 185, material_editor, nullptr, nullptr, nullptr, curr_scene }, { "Material Editor", "Material Editor", "pix/material_editor.xpm", 186, material_editor, nullptr, nullptr, nullptr, curr_scene }, { "Material Editor", "Material Editor", "pix/material_editor.xpm", 187, material_editor, nullptr, nullptr, nullptr, curr_scene }, { "Material Editor", "Material Editor", "pix/material_editor.xpm", 188, material_editor, nullptr, nullptr, nullptr, curr_scene }, { "Material Editor", "Material Editor", "pix/material_editor.xpm", 189, material_editor, nullptr, nullptr, nullptr, curr_scene } });
	auto* material_tool_list = new list<tool>({ { "Material Editor", "Material Editor", "pix/material_editor.xpm", 190, material_editor, nullptr, nullptr, nullptr, curr_scene } });
	auto* threed_paint_tool_list = new list<tool>({ { "3d Paint Tool", "3d Paint Tool", "pix/3d_paint.xpm", 191, threed_paint, nullptr, nullptr, nullptr, curr_scene } });
	auto* uv_mapping_tool_list = new list<tool>({ { "UV Mapping Editor", "UV Mapping Editor", "pix/uv_editor.xpm", 192, uv_editor, nullptr, nullptr, nullptr, curr_scene }, { "Material Rectangle", "Material Rectangle", "pix/material_rectangle.xpm", 193, material_rectangle, nullptr, nullptr, nullptr, curr_scene } });
	auto* uv_projection_tool_list = new list<tool>({ { "Planar UV Projection", "Planar UV Projection", "pix/planar_uv.xpm", 194, planar_uv, nullptr, nullptr, nullptr, curr_scene }, { "Cubic UV Projection", "Cubic UV Projection", "pix/cubic_uv.xpm", 195, cubic_uv, nullptr, nullptr, nullptr, curr_scene }, { "Spherical UV Projection", "Spherical UV Projection", "pix/spherical_uv.xpm", 196, spherical_uv, nullptr, nullptr, nullptr, curr_scene }, { "Cylindrical UV Projection", "Cylindrical UV Projection", "pix/cylindrical_uv.xpm", 197, cylindrical_uv, nullptr, nullptr, nullptr, curr_scene }, { "UV Unwrapper", "UV Unwrapper", "pix/uv_unwrap.xpm", 198, uv_unwrap, nullptr, nullptr, nullptr, curr_scene }, { "UV Slice", "UV Slice", "pix/uv_slice.xpm", 199, uv_slice, nullptr, nullptr, nullptr, curr_scene }, { "Shrink-Wrap UV Computation", "Shrink-Wrap UV Computation", "pix/shrinkwrap_uv.xpm", 200, shrinkwrap_uv, nullptr, nullptr, nullptr, curr_scene } });
	auto* normalisation_tool_list = new list<tool>({ { "Normalise Location", "Normalise Location", "pix/normalise_location.xpm", 201, normalise_location, nullptr, nullptr, nullptr, curr_scene }, { "Normalise Rotation", "Normalise Rotation", "pix/normalise_rotation.xpm", 202, normalise_rotation, nullptr, nullptr, nullptr, curr_scene }, { "Normalise Scale", "Normalise Scale", "pix/normalise_scale.xpm", 203, normalise_scale, nullptr, nullptr, nullptr, curr_scene }, { "Move Axes to Center of Object", "Move Axes to Center of Object", "pix/center_axes.xpm", 204, center_axes, nullptr, nullptr, nullptr, curr_scene }, { "Axes", "Show Object Axes", "pix/show_axes.xpm", 205, show_axes, nullptr, nullptr, nullptr, curr_scene } });
	auto* geometry_tool_list = new list<tool>({ { "Polygon Reduction Tool", "Polygon Reduction Tool", "pix/lod.xpm", 210, nullptr, polygon_reduction_parameters, nullptr, nullptr, curr_scene }, { "Dimensioning Tool", "Dimensioning Tool", "pix/dimensioning.xpm", 211, nullptr, nullptr, nullptr, nullptr, curr_scene }, { "Mirror Modelling", "Mirror Modelling", "pix/mirror.xpm", 212, nullptr, mirror_options_parameters, nullptr, nullptr, curr_scene }, { "Split Hierarchy", "Split hierarchy into polyhedra and IK linked branches", "pix/split_hierarchy.xpm", 213, nullptr, nullptr, nullptr, nullptr, curr_scene }, { "Decompose Object", "Decompose into objects", "pix/decompose.xpm", 214, nullptr, nullptr, nullptr, nullptr, curr_scene }, { "Flip Normals", "Flip all normals", "pix/flip_normals.xpm", 215, nullptr, nullptr, nullptr, nullptr, curr_scene }, { "Flip Object Faces", "Select object and flip faces", "pix/flip_object_faces.xpm", 216, nullptr, nullptr, nullptr, nullptr, curr_scene }, { "Fix Geometry", "Try to fix bad geometry", "pix/fix_geometry.xpm", 217, nullptr, nullptr, nullptr, nullptr, curr_scene }, { "Quad Divide", "Quad Divide", "pix/quad_divide.xpm", 218, nullptr, nullptr, nullptr, nullptr, curr_scene }, { "Smooth Quad Divide", "Smooth Quad Divide", "pix/smooth_quad_divide.xpm", 219, nullptr, smooth_quad_parameters, nullptr, nullptr, curr_scene }, { "Triangulate", "Triangulate", "pix/triangulate.xpm", 220, nullptr, nullptr, nullptr, nullptr, curr_scene } });
	auto* plugin_tool_list = new list<tool>({ { "Add Plugin", "Add Plugin", "pix/plugin.xpm", 230, nullptr, nullptr, nullptr, nullptr, curr_scene } });

	{ float tx, ty; int to; bool te;
	  curr_scene.prefs.get_toolbar_layout(1, tx, ty, to, te);
	  curr_scene.main_toolbar.setOrientation(to ? GLToolbar::VERTICAL : GLToolbar::HORIZONTAL);
	  curr_scene.main_toolbar.setPosition(tx, ty);
	  curr_scene.main_toolbar.setExpanded(te); }
	curr_scene.main_toolbar.reserve(20);
	curr_scene.main_toolbar.addGroup(polygon_tool_list);
	curr_scene.main_toolbar.addGroup(nurbs_tool_list);
	curr_scene.main_toolbar.addGroup(metaball_tool_list);
	curr_scene.main_toolbar.addGroup(light_tool_list);
	curr_scene.main_toolbar.addGroup(camera_tool_list);
	curr_scene.main_toolbar.addGroup(sweep_tool_list);
	curr_scene.main_toolbar.addGroup(subdivision_tool_list);
	curr_scene.main_toolbar.addGroup(boolean_tool_list);
	curr_scene.main_toolbar.addGroup(deformation_tool_list);
	curr_scene.main_toolbar.addGroup(array_tool_list);
	curr_scene.main_toolbar.addGroup(draw_panel_tool_list);
	curr_scene.main_toolbar.addGroup(curve_tool_list);
	curr_scene.main_toolbar.addGroup(skin_tool_list);
	curr_scene.main_toolbar.addGroup(material_tool_list);
	curr_scene.main_toolbar.addGroup(threed_paint_tool_list);
	curr_scene.main_toolbar.addGroup(uv_mapping_tool_list);
	curr_scene.main_toolbar.addGroup(uv_projection_tool_list);
	curr_scene.main_toolbar.addGroup(normalisation_tool_list);
	curr_scene.main_toolbar.addGroup(geometry_tool_list);
	curr_scene.main_toolbar.addGroup(plugin_tool_list);
	curr_scene.owned_tool_lists.insert(curr_scene.owned_tool_lists.end(), {polygon_tool_list, nurbs_tool_list, metaball_tool_list, light_tool_list, camera_tool_list, sweep_tool_list, subdivision_tool_list, boolean_tool_list, deformation_tool_list, array_tool_list, draw_panel_tool_list, curve_tool_list, skin_tool_list, material_tool_list, threed_paint_tool_list, uv_mapping_tool_list, uv_projection_tool_list, normalisation_tool_list, geometry_tool_list, plugin_tool_list});
	cout << "Main Tool Toolbar Ready" << endl;

	auto* select_tool_list = new list<tool>({ { "Select", "Selection Tool", "pix/select.xpm", 0, select_object, show_object_info, nullptr, nullptr, curr_scene }, { "Global Panel", "Global Panel", "pix/normalise_rotation.xpm", 241, global_panel, nullptr, nullptr, nullptr, curr_scene }, { "Unhide All Objects", "Unhide All Objects in Scene", "pix/normalise_scale.xpm", 242, unhide_objects, nullptr, nullptr, nullptr, curr_scene }, { "Object Notes", "Open Object Notes Editor", "pix/center_axes.xpm", 243, object_notes, nullptr, nullptr, nullptr, curr_scene } });
	auto* edit_tool_list = new list<tool>({ { "Point Edit Context", "Point Edit Context", "pix/select_context.xpm", 250, select_context, nullptr, nullptr, nullptr, curr_scene }, { "Point Edit Vertices", "Point Edit Vertices", "pix/select_vertices.xpm", 251, select_vertices, nullptr, nullptr, nullptr, curr_scene }, { "Point Edit Edges", "Point Edit Edges", "pix/select_edges.xpm", 252, select_edges, nullptr, nullptr, nullptr, curr_scene }, { "Point Edit Faces", "Point Edit Faces", "pix/select_faces.xpm", 253, select_faces, nullptr, nullptr, nullptr, curr_scene }, { "Named Selection", "Named Selection", "pix/select_named.xpm", 254, named_selection, nullptr, nullptr, nullptr, curr_scene }, { "Select Using Lasso", "Select Using Lasso", "pix/select_lasso.xpm", 255, lasso_selection, nullptr, nullptr, nullptr, curr_scene }, { "Select Using Rectangle", "Select Using Rectangle", "pix/select_rectangle.xpm", 256, rectangle_selection, nullptr, nullptr, nullptr, curr_scene }, { "Select Using Freehand", "Select Using Freehand", "pix/select_freehand.xpm", 257, freehand_selection, nullptr, nullptr, nullptr, curr_scene } });
	auto* grid_tool_list = new list<tool>({ { "Toggle Grid Mode", "Toggle Grid Mode", "pix/toggle_grid.xpm", 260, toggle_grid, nullptr, nullptr, nullptr, curr_scene }, { "Snap Vertex to Vertex", "Snap Vertex to Vertex", "pix/snap_vertex.xpm", 261, snap_vertex, nullptr, nullptr, nullptr, curr_scene }, { "Snap Vertex to Edge", "Snap Vertex to Edge", "pix/snap_edge.xpm", 262, snap_edge, nullptr, nullptr, nullptr, curr_scene }, { "Snap Vertex to Face", "Snap Vertex to Face", "pix/snap_face.xpm", 263, snap_face, nullptr, nullptr, nullptr, curr_scene }, { "Magnetic Tool", "Magnetic Tool", "pix/magnetic_tool.xpm", 264, magnetic_tool, nullptr, nullptr, nullptr, curr_scene }, { "Collision Disabled", "Collision Disabled", "pix/collision_disabled.xpm", 265, collision_disabled, nullptr, nullptr, nullptr, curr_scene }, { "Collision With Ground", "Collision With Ground", "pix/collision_ground.xpm", 266, collision_ground, nullptr, nullptr, nullptr, curr_scene }, { "Collision With Peers", "Collision With Peers", "pix/collision_peers.xpm", 267, collision_peers, nullptr, nullptr, nullptr, curr_scene } });
	auto* new_scene_tool_list = new list<tool>({ { "New Scene", "Create New Scene", "pix/new_scene.xpm", 270, new_scene, nullptr, nullptr, nullptr, curr_scene } });
	auto* undo_tool_list = new list<tool>({ { "Undo", "Undo", "pix/undo.xpm", 280, undo, nullptr, nullptr, nullptr, curr_scene }, { "Redo", "Redo", "pix/redo.xpm", 281, redo, nullptr, nullptr, nullptr, curr_scene } });
	auto* object_tool_list = new list<tool>({ { "Copy Object", "Ctrl C | Copy", "pix/object_copy.xpm", 290, object_copy, nullptr, nullptr, nullptr, curr_scene }, { "Glue Object as Child", "Glue Object as Child", "pix/object_glue_child.xpm", 291, glue_object_as_child, nullptr, nullptr, nullptr, curr_scene }, { "Glue Object as Sibling", "Glue Object as Sibling", "pix/object_glue_sibling.xpm", 292, glue_object_as_sibling, nullptr, nullptr, nullptr, curr_scene }, { "Unglue Object", "Ctrl C | Copy", "pix/object_unglue.xpm", 293, object_unglue, nullptr, nullptr, nullptr, curr_scene }, { "Group Objects as LOD", "Group Objects as LOD", "pix/object_group.xpm", 294, object_group, nullptr, nullptr, nullptr, curr_scene }, { "UnGroup Objects as LOD", "UnGroup Objects as LOD", "pix/object_ungroup.xpm", 295, object_ungroup, nullptr, nullptr, nullptr, curr_scene }, { "Delete Object", "Delete | Erase", "pix/object_erase.xpm", 296, object_erase, nullptr, nullptr, nullptr, curr_scene } });
	auto* play_tool_list = new list<tool>({ { "Undo", "Undo", "pix/undo.xpm", 300, undo, nullptr, nullptr, nullptr, curr_scene }, { "Undo", "Undo", "pix/undo.xpm", 301, undo, nullptr, nullptr, nullptr, curr_scene }, { "Undo", "Undo", "pix/undo.xpm", 302, undo, nullptr, nullptr, nullptr, curr_scene }, { "Undo", "Undo", "pix/undo.xpm", 303, undo, nullptr, nullptr, nullptr, curr_scene }, { "Undo", "Undo", "pix/undo.xpm", 304, undo, nullptr, nullptr, nullptr, curr_scene }, { "Undo", "Undo", "pix/undo.xpm", 305, undo, nullptr, nullptr, nullptr, curr_scene }, { "Undo", "Undo", "pix/undo.xpm", 306, undo, nullptr, nullptr, nullptr, curr_scene }, { "Undo", "Undo", "pix/undo.xpm", 307, undo, nullptr, nullptr, nullptr, curr_scene }, { "Undo", "Undo", "pix/undo.xpm", 308, undo, nullptr, nullptr, nullptr, curr_scene }, { "Redo", "Redo", "pix/redo.xpm", 309, redo, nullptr, nullptr, nullptr, curr_scene } });
	auto* button_finder_tool_list = new list<tool>({ { "Button Finder", "Button Finder", "pix/button_finder.xpm", 310, button_finder, nullptr, nullptr, nullptr, curr_scene }, { "Undo", "Undo", "pix/undo.xpm", 311, undo, nullptr, nullptr, nullptr, curr_scene }, { "Undo", "Undo", "pix/undo.xpm", 312, undo, nullptr, nullptr, nullptr, curr_scene }, { "Undo", "Undo", "pix/undo.xpm", 313, undo, nullptr, nullptr, nullptr, curr_scene }, { "Undo", "Undo", "pix/undo.xpm", 314, undo, nullptr, nullptr, nullptr, curr_scene }, { "Undo", "Undo", "pix/undo.xpm", 315, undo, nullptr, nullptr, nullptr, curr_scene }, { "Redo", "Redo", "pix/redo.xpm", 316, redo, nullptr, nullptr, nullptr, curr_scene } });

	{ float tx, ty; int to; bool te;
	  curr_scene.prefs.get_toolbar_layout(2, tx, ty, to, te);
	  curr_scene.object_toolbar.setOrientation(to ? GLToolbar::VERTICAL : GLToolbar::HORIZONTAL);
	  curr_scene.object_toolbar.setPosition(tx, ty);
	  curr_scene.object_toolbar.setExpanded(te); }
	curr_scene.object_toolbar.reserve(8);
	curr_scene.object_toolbar.addGroup(select_tool_list);
	curr_scene.object_toolbar.addGroup(edit_tool_list);
	curr_scene.object_toolbar.addGroup(grid_tool_list);
	curr_scene.object_toolbar.addGroup(new_scene_tool_list);
	curr_scene.object_toolbar.addGroup(undo_tool_list);
	curr_scene.object_toolbar.addGroup(object_tool_list);
	curr_scene.object_toolbar.addGroup(play_tool_list);
	curr_scene.object_toolbar.addGroup(button_finder_tool_list);
	curr_scene.owned_tool_lists.insert(curr_scene.owned_tool_lists.end(), {select_tool_list, edit_tool_list, grid_tool_list, new_scene_tool_list, undo_tool_list, object_tool_list, play_tool_list, button_finder_tool_list});

		
	main_window->maximize();Gtk::Builder::create_from_file("src/gui.gtkbuilder");
	this -> app->run(*main_window);

}

void ts_gui::show_bevel_window(scene &curr_scene){
	this->bevel_window->show();
}

void ts_gui::show_boolean_window(scene &curr_scene){
	this->boolean_window->show();
}

void ts_gui::show_chamfer_window(scene &curr_scene){
	this->chamfer_window->show();
}

void ts_gui::show_coords_window(scene &curr_scene){
	this->coords_window->show();
}

void ts_gui::show_cone_window(scene &curr_scene){
	if (cone_lat_spin) cone_lat_spin->set_value(curr_scene.prefs.get_cone_latitude());
	if (cone_long_spin) cone_long_spin->set_value(curr_scene.prefs.get_cone_longitude());
	this->cone_window->show();
}

void ts_gui::show_copy_tool_window(scene &curr_scene){
	this->copy_tool_window->show();
}

void ts_gui::show_cube_window(scene &curr_scene){
	if (cube_resolution_spin) cube_resolution_spin->set_value(curr_scene.prefs.get_cube_resolution());
	this->cube_window->show();
}

void ts_gui::show_metaball_window(scene &curr_scene){
	this->metaball_options_window->show();
}

void ts_gui::show_cylinder_window(scene &curr_scene){
	if (cylinder_lat_spin) cylinder_lat_spin->set_value(curr_scene.prefs.get_cylinder_latitude());
	if (cylinder_long_spin) cylinder_long_spin->set_value(curr_scene.prefs.get_cylinder_longitude());
	if (cylinder_top_radius_spin) cylinder_top_radius_spin->set_value(curr_scene.prefs.get_cylinder_top_radius());
	this->cylinder_window->show();
}

void ts_gui::show_deformation_window(scene &curr_scene){
	this->deformation_window->show();
}

void ts_gui::show_edit_window(scene &curr_scene){
	this->edit_window->show();
}

void ts_gui::show_edit_window_expanded(scene &curr_scene){
	this->edit_window_expanded->show();
}

void ts_gui::show_fillet_window(scene &curr_scene){
	this->fillet_window->show();
}

void ts_gui::show_geosphere_window(scene &curr_scene){
	if (geosphere_resolution_spin) geosphere_resolution_spin->set_value(curr_scene.prefs.get_geosphere_resolution());
	this->geosphere_window->show();
}

void ts_gui::show_lathe_window(scene &curr_scene){
	this->lathe_window->show();
}

void ts_gui::show_lights_window(scene &curr_scene){
	this->lights_window->show();
}

void ts_gui::show_macro_window(scene &curr_scene){
	this->macro_window->show();
}

void ts_gui::show_mirror_options_window(scene &curr_scene){
	this->mirror_options_window->show();
}

void ts_gui::show_nurbs_plane_window(scene &curr_scene){
	this->nurbs_plane_window->show();
}

void ts_gui::show_nurbs_saddle_window(scene &curr_scene){
	this->nurbs_saddle_window->show();
}

void ts_gui::show_nurbs_cube_window(scene &curr_scene){
	this->nurbs_cube_window->show();
}

void ts_gui::show_nurbs_cone_window(scene &curr_scene){
	this->nurbs_cone_window->show();
}

void ts_gui::show_nurbs_cylinder_window(scene &curr_scene){
	this->nurbs_cylinder_window->show();
}

void ts_gui::show_nurbs_sphere_window(scene &curr_scene){
	this->nurbs_sphere_window->show();
}

void ts_gui::show_nurbs_torus_window(scene &curr_scene){
	this->nurbs_torus_window->show();
}

void ts_gui::show_object_info_window(scene &curr_scene){
	this->object_info_window->show();
}

void ts_gui::show_object_movie_window(scene &curr_scene){
	this->object_movie_window->show();
}

void ts_gui::show_object_render_options_window(scene &curr_scene){
	this->object_render_options_window->show();
}

void ts_gui::show_ogl_setting_window(scene &curr_scene){
	this->ogl_setting_window->show();
}

void ts_gui::show_pan_movie_window(scene &curr_scene){
	this->pan_movie_window->show();
}

void ts_gui::show_panoramic_camera_window(scene &curr_scene){
	this->panoramic_camera_window->show();
}

void ts_gui::show_plane_window(scene &curr_scene){
	if (plane_resolution_spin) plane_resolution_spin->set_value(curr_scene.prefs.get_plane_resolution());
	this->plane_window->show();
}

void ts_gui::show_point_edit_window(scene &curr_scene){
	this->point_edit_window->show();
}

void ts_gui::show_polygon_reduction_tool_window(scene &curr_scene){
	this->polygon_reduction_tool_window->show();
}

void ts_gui::show_preferences_window(scene &curr_scene){
	this->preferences_window->show();
}

void ts_gui::show_primitive_parameters_window(scene &curr_scene){
	this->primitive_parameters_window->show();
}

void ts_gui::show_primitive_shape_window(scene &curr_scene){
	this->primitive_shape_window->show();
}

void ts_gui::show_rounded_cube_window(scene &curr_scene){
	if (rounded_cube_lat_spin) rounded_cube_lat_spin->set_value(curr_scene.prefs.get_rounded_cube_latitude());
	if (rounded_cube_long_spin) rounded_cube_long_spin->set_value(curr_scene.prefs.get_rounded_cube_longitude());
	this->rounded_cube_window->show();
}

void ts_gui::show_rounded_cylinder_window(scene &curr_scene){
	if (rounded_cylinder_lat_spin) rounded_cylinder_lat_spin->set_value(curr_scene.prefs.get_rounded_cylinder_latitude());
	if (rounded_cylinder_long_spin) rounded_cylinder_long_spin->set_value(curr_scene.prefs.get_rounded_cylinder_longitude());
	this->rounded_cylinder_window->show();
}

void ts_gui::show_scene_editor_preferences_window(scene &curr_scene){
	this->scene_editor_preferences_window->show();
}

void ts_gui::show_selection_window(scene &curr_scene){
	this->selection_window->show();
}

void ts_gui::show_set_keyframe_window(scene &curr_scene){
	this->set_keyframe_window->show();
}

void ts_gui::show_shell_properties_window(scene &curr_scene){
	this->shell_properties_window->show();
}

void ts_gui::show_skin_options_window(scene &curr_scene){
	this->skin_options_window->show();
}

void ts_gui::show_smooth_quad_window(scene &curr_scene){
	this->smooth_quad_window->show();
}


void ts_gui::show_sphere_window(scene &curr_scene){
	if (sphere_lat_spin) sphere_lat_spin->set_value(curr_scene.prefs.get_sphere_latitude());
	if (sphere_long_spin) sphere_long_spin->set_value(curr_scene.prefs.get_sphere_longitude());
	this->sphere_window->show();
}

void ts_gui::show_sweep_tip_window(scene &curr_scene){
	this->sweep_tip_window->show();
}

void ts_gui::show_taper_window(scene &curr_scene){
	this->taper_window->show();
}

void ts_gui::show_torus_window(scene &curr_scene){
	if (torus_lat_spin) torus_lat_spin->set_value(curr_scene.prefs.get_torus_latitude());
	if (torus_long_spin) torus_long_spin->set_value(curr_scene.prefs.get_torus_longitude());
	if (torus_inner_radius_spin) torus_inner_radius_spin->set_value(curr_scene.prefs.get_torus_inner_radius());
	this->torus_window->show();
}

void ts_gui::show_undo_options_window(scene &curr_scene){
	this->undo_options_window->show();
}

void ts_gui::show_wind_window(scene &curr_scene){
	this->wind_window->show();
}

void ts_gui::collectSelectedVertexIndices(scene &curr_scene, std::set<int>& out) {
	auto obj = curr_scene.GetCurrentObject();
	if (!obj) return;
	Mesh& m = obj->getMesh();
	int edit_mode = curr_scene.Get_Edit_Mode();

	if (edit_mode == 1) {
		out = obj->getSelectedVertices();
	} else if (edit_mode == 2) {
		for (int edge_idx : obj->getSelectedEdges()) {
			int v0, v1;
			m.getEdgeVertices(edge_idx, v0, v1);
			out.insert(v0);
			out.insert(v1);
		}
	}
}

void ts_gui::computeVertexCenter(scene &curr_scene, const std::set<int>& indices, float* center) {
	center[0] = center[1] = center[2] = 0.0f;
	if (indices.empty()) return;
	auto obj = curr_scene.GetCurrentObject();
	if (!obj) return;
	Mesh& m = obj->getMesh();
	for (int idx : indices) {
		float x, y, z;
		m.getVertexPosition(idx, x, y, z);
		center[0] += x; center[1] += y; center[2] += z;
	}
	float n = (float)indices.size();
	center[0] /= n; center[1] /= n; center[2] /= n;
}

void ts_gui::update_object_info(scene &curr_scene){
	auto obj = curr_scene.GetCurrentObject();

	auto fmt = [](double v) -> std::string {
		char buf[32];
		snprintf(buf, sizeof(buf), "%.4f", v);
		return std::string(buf);
	};

	int edit_mode = curr_scene.Get_Edit_Mode();
	info_edit_mode = edit_mode;
	info_multi_count = (int)curr_scene.selected_objects.size();

	if (!obj && curr_scene.selected_objects.empty()) {
		info_multi_count = 0;
		if (obj_info_name) obj_info_name->set_text("");
		if (obj_info_loc_x) obj_info_loc_x->set_text("0.0000");
		if (obj_info_loc_y) obj_info_loc_y->set_text("0.0000");
		if (obj_info_loc_z) obj_info_loc_z->set_text("0.0000");
		if (obj_info_rot_x) obj_info_rot_x->set_text("0.0000");
		if (obj_info_rot_y) obj_info_rot_y->set_text("0.0000");
		if (obj_info_rot_z) obj_info_rot_z->set_text("0.0000");
		if (obj_info_sca_x) obj_info_sca_x->set_text("1.0000");
		if (obj_info_sca_y) obj_info_sca_y->set_text("1.0000");
		if (obj_info_sca_z) obj_info_sca_z->set_text("1.0000");
		if (obj_info_verts) obj_info_verts->set_text("0");
		if (obj_info_faces) obj_info_faces->set_text("0");
		return;
	}

	// Multi-object selection
	if (info_multi_count > 1) {
		multi_obj_center[0] = multi_obj_center[1] = multi_obj_center[2] = 0.0;
		int total_verts = 0;
		int total_faces = 0;
		for (auto& sel_obj : curr_scene.selected_objects) {
			if (!sel_obj) continue;
			double* loc = sel_obj->get_location();
			multi_obj_center[0] += loc[0];
			multi_obj_center[1] += loc[1];
			multi_obj_center[2] += loc[2];
			total_verts += sel_obj->get_num_vertices();
			total_faces += sel_obj->get_num_faces();
		}
		double n = (double)info_multi_count;
		multi_obj_center[0] /= n;
		multi_obj_center[1] /= n;
		multi_obj_center[2] /= n;

		std::string label = std::to_string(info_multi_count) + " objects";
		if (obj_info_name) obj_info_name->set_text(label);
		if (obj_info_loc_x) obj_info_loc_x->set_text(fmt(multi_obj_center[0]));
		if (obj_info_loc_y) obj_info_loc_y->set_text(fmt(multi_obj_center[1]));
		if (obj_info_loc_z) obj_info_loc_z->set_text(fmt(multi_obj_center[2]));
		if (obj_info_rot_x) obj_info_rot_x->set_text("0.0000");
		if (obj_info_rot_y) obj_info_rot_y->set_text("0.0000");
		if (obj_info_rot_z) obj_info_rot_z->set_text("0.0000");
		if (obj_info_sca_x) obj_info_sca_x->set_text("1.0000");
		if (obj_info_sca_y) obj_info_sca_y->set_text("1.0000");
		if (obj_info_sca_z) obj_info_sca_z->set_text("1.0000");
		if (obj_info_verts) obj_info_verts->set_text(std::to_string(total_verts));
		if (obj_info_faces) obj_info_faces->set_text(std::to_string(total_faces));
		return;
	}

	if (!obj) return;

	if (edit_mode == 1 || edit_mode == 2) {
		std::set<int> vert_indices;
		collectSelectedVertexIndices(curr_scene, vert_indices);

		if (!vert_indices.empty()) {
			computeVertexCenter(curr_scene, vert_indices, info_center);

			int count = (edit_mode == 1) ? (int)obj->getSelectedVertices().size()
										 : (int)obj->getSelectedEdges().size();
			std::string label = std::to_string(count);
			label += (edit_mode == 1) ? (count == 1 ? " vertex" : " vertices")
									  : (count == 1 ? " edge" : " edges");
			if (obj_info_name) obj_info_name->set_text(label);

			if (obj_info_loc_x) obj_info_loc_x->set_text(fmt(info_center[0]));
			if (obj_info_loc_y) obj_info_loc_y->set_text(fmt(info_center[1]));
			if (obj_info_loc_z) obj_info_loc_z->set_text(fmt(info_center[2]));
			if (obj_info_rot_x) obj_info_rot_x->set_text("0.0000");
			if (obj_info_rot_y) obj_info_rot_y->set_text("0.0000");
			if (obj_info_rot_z) obj_info_rot_z->set_text("0.0000");
			if (obj_info_sca_x) obj_info_sca_x->set_text("1.0000");
			if (obj_info_sca_y) obj_info_sca_y->set_text("1.0000");
			if (obj_info_sca_z) obj_info_sca_z->set_text("1.0000");
		} else {
			if (obj_info_name) obj_info_name->set_text(obj->get_name());
			if (obj_info_loc_x) obj_info_loc_x->set_text("0.0000");
			if (obj_info_loc_y) obj_info_loc_y->set_text("0.0000");
			if (obj_info_loc_z) obj_info_loc_z->set_text("0.0000");
			if (obj_info_rot_x) obj_info_rot_x->set_text("0.0000");
			if (obj_info_rot_y) obj_info_rot_y->set_text("0.0000");
			if (obj_info_rot_z) obj_info_rot_z->set_text("0.0000");
			if (obj_info_sca_x) obj_info_sca_x->set_text("1.0000");
			if (obj_info_sca_y) obj_info_sca_y->set_text("1.0000");
			if (obj_info_sca_z) obj_info_sca_z->set_text("1.0000");
		}
		if (obj_info_verts) obj_info_verts->set_text(std::to_string(obj->get_num_vertices()));
		if (obj_info_faces) obj_info_faces->set_text(std::to_string(obj->get_num_faces()));
		return;
	}

	// Single object mode (edit_mode == 0 or 3/face)
	double* loc = obj->get_location();
	float* rot = obj->get_rotation();
	float* sc = obj->get_scale();

	if (obj_info_name) obj_info_name->set_text(obj->get_name());
	if (obj_info_loc_x) obj_info_loc_x->set_text(fmt(loc[0]));
	if (obj_info_loc_y) obj_info_loc_y->set_text(fmt(loc[1]));
	if (obj_info_loc_z) obj_info_loc_z->set_text(fmt(loc[2]));
	if (obj_info_rot_x) obj_info_rot_x->set_text(fmt(rot[0]));
	if (obj_info_rot_y) obj_info_rot_y->set_text(fmt(rot[1]));
	if (obj_info_rot_z) obj_info_rot_z->set_text(fmt(rot[2]));
	if (obj_info_sca_x) obj_info_sca_x->set_text(fmt(sc[0]));
	if (obj_info_sca_y) obj_info_sca_y->set_text(fmt(sc[1]));
	if (obj_info_sca_z) obj_info_sca_z->set_text(fmt(sc[2]));
	if (obj_info_verts) obj_info_verts->set_text(std::to_string(obj->get_num_vertices()));
	if (obj_info_faces) obj_info_faces->set_text(std::to_string(obj->get_num_faces()));
}

void ts_gui::on_plane_param_activated(scene *curr_scene){
	if (plane_resolution_spin)
		curr_scene->prefs.set_plane_resolution(plane_resolution_spin->get_value_as_int());
}

void ts_gui::on_cube_param_activated(scene *curr_scene){
	if (cube_resolution_spin)
		curr_scene->prefs.set_cube_resolution(cube_resolution_spin->get_value_as_int());
}

void ts_gui::on_cone_param_activated(scene *curr_scene){
	if (cone_lat_spin) curr_scene->prefs.set_cone_latitude(cone_lat_spin->get_value_as_int());
	if (cone_long_spin) curr_scene->prefs.set_cone_longitude(cone_long_spin->get_value_as_int());
}

void ts_gui::on_cylinder_param_activated(scene *curr_scene){
	if (cylinder_lat_spin) curr_scene->prefs.set_cylinder_latitude(cylinder_lat_spin->get_value_as_int());
	if (cylinder_long_spin) curr_scene->prefs.set_cylinder_longitude(cylinder_long_spin->get_value_as_int());
	if (cylinder_top_radius_spin) curr_scene->prefs.set_cylinder_top_radius(cylinder_top_radius_spin->get_value());
}

void ts_gui::on_sphere_param_activated(scene *curr_scene){
	if (sphere_lat_spin) curr_scene->prefs.set_sphere_latitude(sphere_lat_spin->get_value_as_int());
	if (sphere_long_spin) curr_scene->prefs.set_sphere_longitude(sphere_long_spin->get_value_as_int());
}

void ts_gui::on_geosphere_param_activated(scene *curr_scene){
	if (geosphere_resolution_spin)
		curr_scene->prefs.set_geosphere_resolution(geosphere_resolution_spin->get_value_as_int());
}

void ts_gui::on_rounded_cube_param_activated(scene *curr_scene){
	if (rounded_cube_lat_spin) curr_scene->prefs.set_rounded_cube_latitude(rounded_cube_lat_spin->get_value_as_int());
	if (rounded_cube_long_spin) curr_scene->prefs.set_rounded_cube_longitude(rounded_cube_long_spin->get_value_as_int());
}

void ts_gui::on_rounded_cylinder_param_activated(scene *curr_scene){
	if (rounded_cylinder_lat_spin) curr_scene->prefs.set_rounded_cylinder_latitude(rounded_cylinder_lat_spin->get_value_as_int());
	if (rounded_cylinder_long_spin) curr_scene->prefs.set_rounded_cylinder_longitude(rounded_cylinder_long_spin->get_value_as_int());
}

void ts_gui::on_torus_param_activated(scene *curr_scene){
	if (torus_lat_spin) curr_scene->prefs.set_torus_latitude(torus_lat_spin->get_value_as_int());
	if (torus_long_spin) curr_scene->prefs.set_torus_longitude(torus_long_spin->get_value_as_int());
	if (torus_inner_radius_spin) curr_scene->prefs.set_torus_inner_radius(torus_inner_radius_spin->get_value());
}

void ts_gui::on_object_info_entry_changed(scene *curr_scene){
	auto obj = curr_scene->GetCurrentObject();
	if (!obj && curr_scene->selected_objects.empty()) return;

	auto toFloat = [](Gtk::Entry* e) -> float {
		try { return std::stof(e->get_text()); }
		catch (...) { return 0.0f; }
	};

	auto toDouble = [](Gtk::Entry* e) -> double {
		try { return std::stod(e->get_text()); }
		catch (...) { return 0.0; }
	};

	// Multi-object mode
	if (info_multi_count > 1) {
		double new_cx = toDouble(obj_info_loc_x);
		double new_cy = toDouble(obj_info_loc_y);
		double new_cz = toDouble(obj_info_loc_z);
		double dx = new_cx - multi_obj_center[0];
		double dy = new_cy - multi_obj_center[1];
		double dz = new_cz - multi_obj_center[2];

		float rot_x = toFloat(obj_info_rot_x);
		float rot_y = toFloat(obj_info_rot_y);
		float rot_z = toFloat(obj_info_rot_z);
		bool has_rotation = (rot_x != 0.0f || rot_y != 0.0f || rot_z != 0.0f);

		float sca_x = toFloat(obj_info_sca_x);
		float sca_y = toFloat(obj_info_sca_y);
		float sca_z = toFloat(obj_info_sca_z);
		bool has_scale = (sca_x != 1.0f || sca_y != 1.0f || sca_z != 1.0f);

		for (auto& sel_obj : curr_scene->selected_objects) {
			if (!sel_obj) continue;
			double* loc = sel_obj->get_location();

			double rx = loc[0] - multi_obj_center[0];
			double ry = loc[1] - multi_obj_center[1];
			double rz = loc[2] - multi_obj_center[2];

			if (has_scale) {
				rx *= sca_x;
				ry *= sca_y;
				rz *= sca_z;
				float* sc = sel_obj->get_scale();
				sel_obj->set_scale(sc[0] * sca_x, sc[1] * sca_y, sc[2] * sca_z);
			}

			if (has_rotation) {
				float rad_x = rot_x * M_PI / 180.0f;
				float rad_y = rot_y * M_PI / 180.0f;
				float rad_z = rot_z * M_PI / 180.0f;

				float cx, sx, cz, sz;
				// Y rotation
				cx = cosf(rad_y); float sy = sinf(rad_y);
				double tx = rx * cx + rz * sy;
				double tz = -rx * sy + rz * cx;
				rx = tx; rz = tz;
				// X rotation
				cx = cosf(rad_x); sx = sinf(rad_x);
				double ty = ry * cx - rz * sx;
				tz = ry * sx + rz * cx;
				ry = ty; rz = tz;
				// Z rotation
				cz = cosf(rad_z); sz = sinf(rad_z);
				tx = rx * cz - ry * sz;
				ty = rx * sz + ry * cz;
				rx = tx; ry = ty;

				float* r = sel_obj->get_rotation();
				sel_obj->set_rotation(r[0] + rot_x, r[1] + rot_y, r[2] + rot_z);
			}

			sel_obj->set_location(multi_obj_center[0] + rx + dx,
								  multi_obj_center[1] + ry + dy,
								  multi_obj_center[2] + rz + dz);
			sel_obj->getMesh().markDirty();
		}

		update_object_info(*curr_scene);
		if (this->view_grid) this->view_grid->queue_draw();
		return;
	}

	if (!obj) return;

	if (info_edit_mode == 1 || info_edit_mode == 2) {
		std::set<int> vert_indices;
		collectSelectedVertexIndices(*curr_scene, vert_indices);
		if (vert_indices.empty()) return;

		Mesh& m = obj->getMesh();
		float new_loc[3] = { toFloat(obj_info_loc_x), toFloat(obj_info_loc_y), toFloat(obj_info_loc_z) };
		float new_rot[3] = { toFloat(obj_info_rot_x), toFloat(obj_info_rot_y), toFloat(obj_info_rot_z) };
		float new_sca[3] = { toFloat(obj_info_sca_x), toFloat(obj_info_sca_y), toFloat(obj_info_sca_z) };

		float fdx = new_loc[0] - info_center[0];
		float fdy = new_loc[1] - info_center[1];
		float fdz = new_loc[2] - info_center[2];

		bool has_rotation = (new_rot[0] != 0.0f || new_rot[1] != 0.0f || new_rot[2] != 0.0f);
		bool has_scale = (new_sca[0] != 1.0f || new_sca[1] != 1.0f || new_sca[2] != 1.0f);
		bool is_single_vertex = (info_edit_mode == 1 && vert_indices.size() == 1);

		for (int idx : vert_indices) {
			float vx, vy, vz;
			m.getVertexPosition(idx, vx, vy, vz);

			float rx = vx - info_center[0];
			float ry = vy - info_center[1];
			float rz = vz - info_center[2];

			if (!is_single_vertex && has_scale) {
				rx *= new_sca[0];
				ry *= new_sca[1];
				rz *= new_sca[2];
			}

			if (!is_single_vertex && has_rotation) {
				float rad_x = new_rot[0] * M_PI / 180.0f;
				float rad_y = new_rot[1] * M_PI / 180.0f;
				float rad_z = new_rot[2] * M_PI / 180.0f;

				float cx, cy, cz, sx, sy, sz;
				// Y rotation
				cx = cosf(rad_y); sy = sinf(rad_y);
				float tx = rx * cx + rz * sy;
				float tz = -rx * sy + rz * cx;
				rx = tx; rz = tz;
				// X rotation
				cx = cosf(rad_x); sx = sinf(rad_x);
				float ty = ry * cx - rz * sx;
				tz = ry * sx + rz * cx;
				ry = ty; rz = tz;
				// Z rotation
				cz = cosf(rad_z); sz = sinf(rad_z);
				tx = rx * cz - ry * sz;
				ty = rx * sz + ry * cz;
				rx = tx; ry = ty;
			}

			m.setVertexPosition(idx, info_center[0] + rx + fdx,
									 info_center[1] + ry + fdy,
									 info_center[2] + rz + fdz);
		}

		m.uploadToGPU();
		update_object_info(*curr_scene);
		if (this->view_grid) this->view_grid->queue_draw();
		return;
	}

	// Single object mode
	if (obj_info_name) obj->set_name(obj_info_name->get_text());
	if (obj_info_loc_x && obj_info_loc_y && obj_info_loc_z)
		obj->set_location(toDouble(obj_info_loc_x), toDouble(obj_info_loc_y), toDouble(obj_info_loc_z));
	if (obj_info_rot_x && obj_info_rot_y && obj_info_rot_z)
		obj->set_rotation(toFloat(obj_info_rot_x), toFloat(obj_info_rot_y), toFloat(obj_info_rot_z));
	if (obj_info_sca_x && obj_info_sca_y && obj_info_sca_z)
		obj->set_scale(toFloat(obj_info_sca_x), toFloat(obj_info_sca_y), toFloat(obj_info_sca_z));

	obj->getMesh().markDirty();
	if (this->view_grid) this->view_grid->queue_draw();
}

void ts_gui::on_save_layout(scene *curr_scene){
	curr_scene->prefs.set_toolbar_layout(0,
		curr_scene->view_object_toolbar.getX(),
		curr_scene->view_object_toolbar.getY(),
		curr_scene->view_object_toolbar.getOrientation() == GLToolbar::VERTICAL ? 1 : 0,
		curr_scene->view_object_toolbar.getExpanded());
	curr_scene->prefs.set_toolbar_layout(1,
		curr_scene->main_toolbar.getX(),
		curr_scene->main_toolbar.getY(),
		curr_scene->main_toolbar.getOrientation() == GLToolbar::VERTICAL ? 1 : 0,
		curr_scene->main_toolbar.getExpanded());
	curr_scene->prefs.set_toolbar_layout(2,
		curr_scene->object_toolbar.getX(),
		curr_scene->object_toolbar.getY(),
		curr_scene->object_toolbar.getOrientation() == GLToolbar::VERTICAL ? 1 : 0,
		curr_scene->object_toolbar.getExpanded());
	curr_scene->prefs.save_layout("preferences.ini");
}
