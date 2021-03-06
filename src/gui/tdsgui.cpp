#include "../../include/gui/tdsgui.h"

void tds_gui::make_gui(preferences &prefs, scene &scene)
{
	/*3DS Style UI*/
	this -> builder->get_widget("tds_main_window", main_window);
	this -> builder->get_widget("tds_view_grid", view_grid);
	this -> builder->get_widget("material_editor_window", material_editor_window);
	this -> builder->get_widget("rendering_editor_window", rendering_editor_window);
	this -> builder->get_widget("tds_quit_button", tds_quit_button);
	this -> builder->get_widget("standard_primitive_button_grid", standard_primitive_button_grid);
	this -> builder->get_widget("extended_primitive_button_grid", extended_primitive_button_grid);
	this -> builder->get_widget("compound_object_button_grid", compound_object_button_grid);
	this -> builder->get_widget("nurbs_button_grid",nurbs_button_grid);
	this -> builder->get_widget("particle_button_grid",particle_button_grid);
	this -> builder->get_widget("patch_button_grid",patch_button_grid);
	this -> builder->get_widget("doors_button_grid",doors_button_grid);
	this -> builder->get_widget("windows_button_grid",windows_button_grid);
	this -> builder->get_widget("dynamics_button_grid",dynamics_button_grid);
	this -> builder->get_widget("object_type_combo", object_type_combo);
	this -> builder->get_widget("object_expander", object_expander);
	gtk_builder_connect_signals (this->builder->gobj(), NULL);

//        tds_quit_button->signal_activate().connect(sigc::ptr_fun(&quit_cb));
	this->object_type_combo->signal_changed().connect(sigc::mem_fun(this, &tds_gui::object_droplist_callback), false);
	this->object_expander->add(*this->standard_primitive_button_grid);
	
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

void tds_gui::object_droplist_callback(){
	cout << this -> object_type_combo -> get_active_id() << " " << this -> object_type_combo -> get_active_text() << endl;
	this -> object_expander -> remove();
	
	switch (this -> object_type_combo -> get_active_row_number())
	{
	case 0:
		this -> object_expander -> add(*this->standard_primitive_button_grid);
	break;
	case 1:
		this -> object_expander -> add(*this->extended_primitive_button_grid);
	break;
	case 2:
		this -> object_expander -> add(*this->compound_object_button_grid);
	break;
	case 3:
		this -> object_expander -> add(*this->particle_button_grid);
	break;
	case 4:
		this -> object_expander -> add(*this->patch_button_grid);
	break;
	case 5:
		this -> object_expander -> add(*this->nurbs_button_grid);
	break;
	case 7:
		this -> object_expander -> add(*this->dynamics_button_grid);
	break;
	case 8:
		this -> object_expander -> add(*this->windows_button_grid);
	break;
	case 9:
		this -> object_expander -> add(*this->doors_button_grid);
	break;
	default:
		this -> object_expander -> add(*this->extended_primitive_button_grid);
	break;
	}
	this -> object_expander->show_all();
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
