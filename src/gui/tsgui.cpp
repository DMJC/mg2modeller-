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
	Gtk::Window* object_tool_window = nullptr;
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
	this -> builder->get_widget("object_tool_window", object_tool_window);
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
		object_tool_window->show();

		main_window->maximize();Gtk::Builder::create_from_file("src/gui.gtkbuilder");
		this -> app->run(*main_window);
}
