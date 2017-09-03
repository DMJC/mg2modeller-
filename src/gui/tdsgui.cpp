#include "../../include/gui/tdsgui.h"

void tds_gui::make_gui(preferences &prefs, scene &scene)
{
	Gtk::Window* main_window = nullptr;
	Gtk::Window*material_editor_window = nullptr;
	Gtk::Window*rendering_editor_window = nullptr;
	Gtk::Grid* view_grid = nullptr;
	Gtk::ImageMenuItem* tds_quit_button = nullptr;


	/*3DS Style UI*/
	this -> builder->get_widget("tds_main_window", main_window);
	this -> builder->get_widget("tds_view_grid", view_grid);
	this -> builder->get_widget("material_editor_window", material_editor_window);
	this -> builder->get_widget("rendering_editor_window", rendering_editor_window);
	this -> builder->get_widget("tds_quit_button", tds_quit_button);

	gtk_builder_connect_signals (this->builder->gobj(), NULL);

//        tds_quit_button->signal_activate().connect(sigc::ptr_fun(&quit_cb));


	int num_views = 4;
	view_grid->set_hexpand();
	view_grid->set_vexpand();
	view_grid->show();
	main_window->show();

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
		main_window->maximize();
		view_grid->show_all();
		this -> app->run(*main_window);
}



void show_material_win(preferences &prefs, scene &scene);

void show_rendering_win(preferences &prefs, scene &scene);

/*void tds_gui::set_object_properties(object_type object_ui){
	Gtk::Grid* object_grid = nullptr;
	this->builder->get_widget("object_grid", object_grid);
	this->builder->get_widget("name_color_expander", name_color_expander);
	switch (object_ui){
		case TORUS:
			this->builder->get_widget("torus_grid", object_properties);
		case TEAPOT:
			this->builder->get_widget("teapot_grid", object_properties);
		case TUBE:
			this->builder->get_widget("tube_grid", object_properties);
		case SPHERE:
			this->builder->get_widget("sphere_grid", object_properties);
		case PYRAMID:
			this->builder->get_widget("pyramid_grid", object_properties);
		case PLANE:
			this->builder->get_widget("plane_grid", object_properties);
		case GEOSPHERE:
			this->builder->get_widget("geosphere_grid", object_properties);
		case CYLINDER:
			this->builder->get_widget("cylinder_grid", object_properties);
		case CUBE:
			this->builder->get_widget("cube_grid", object_properties);
		case CONE:
			this->builder->get_widget("cone_grid", object_properties);
			break;
		}
		object_grid->add(this->object_properties);
		object_grid->attach_next_to(this->object_properties, this->name_color_expander, Gtk::POS_BOTTOM, 1, 1);
}

void tds_gui::unset_object_properties(void){
		this->builder->get_widget("torus_grid", object_grid);
		this->object_grid.remove(object_properties);
}*/
