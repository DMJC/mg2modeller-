#include "../include/primitive.h"

primitive::primitive(){
/*	this -> location[0] = 0.0;
	this -> location[1] = 0.0;
	this -> location[2] = 0.0;
	this -> location[0] = 0.0;
	this -> location[1] = 0.0;
	this -> location[2] = 0.0;
	this -> scale[0] = 1.0;
	this -> scale[1] = 1.0;
	this -> scale[2] = 1.0;*/
}

primitive::~primitive(){

}

plane::plane(int resolution, scene curr_scene){
	cout << "Making a Plane" << endl;
	this->set_name("plane");
	this->set_location(0.0, 0.0, 0.0);
	this->set_rotation(0.0, 0.0, 0.0);
	this->set_scale(1.0, 1.0, 1.0);
	this->set_num_vertices(((resolution + 1) * (resolution + 1)));
	this->set_num_faces((resolution * resolution));
	//cout << this -> get_name() << endl;
	cout << "faces: " << this->get_num_faces() << endl;
	cout << "verts: " << this->get_num_vertices() << endl;
	
	float iter_amount = 0.0;
	float next = 0.0;
	int count = 0;
	/*
	iter_amount = (1 / resolution) *2;
	while ( count !=0 )
	{
		count = resolution -1;
		for (){
			for (){
			
			}	
		}
		
	}*/
/*
	if (resolution > 1){
		
	}
	else {
		/*make_vertex( 1, -1, 0 );
		make_vertex( 1, 1, 0 );
		make_vertex( -1, -1, 0 );
		make_vertex( -1, 1, 0 );
	} */
	
//	cout << "location X: " << this -> location[0] << " location Y: " << this -> location[1] << " location Z: " << this -> location[2] << endl;
}
plane::plane(int horizontal_subdiv, int vertical_subdiv, int conic_subdiv, int spherical_long_subdiv, int spherical_lat_subdiv, int x_rotation, int torus_angle, int top_radius, int bot_radius, int radius, int spherical_radius, int conic_angle, int height, int rot_subdiv, scene curr_scene){
	cout << "Making Plane for real" << endl;
//	cout << "location X: " << this -> location[0] << " location Y: " << this -> location[1] << " location Z: " << this -> location[2] << endl;
}

cube::cube(int resolution, scene curr_scene){
	cout << "Making a cube" << endl;
/*	Cube
	Radius = 1;
	Diameter = 2;
	Location = 0, 0, 1;
	Angle = 45;*/
	this->set_name("cube");
	this->set_location(0.0, 0.0, 0.0);
	this->set_rotation(0.0, 0.0, 0.0);
	this->set_scale(1.0, 1.0, 1.0);
	this->set_num_vertices(((resolution + 1) * (resolution + 1) * (resolution + 1)));
	this->set_num_faces(((resolution * resolution) * 6));
	cout << this->get_name() << endl;
	cout << "faces: " << this->get_num_faces() << endl;
	cout << "verts: " << this->get_num_vertices() << endl;
}

cube::cube(int cube_horizontal_subdiv, int cube_vertical_subdiv, int cube_conic_subdiv, int cube_spherical_long_subdiv, int cube_spherical_lat_subdiv, int cube_x_rotation, int cube_torus_angle, int cube_top_radius, int cube_bot_radius, int cube_radius, int cube_spherical_radius, int cube_conic_angle, int cube_height, int cube_rot_subdiv, scene curr_scene){
	
}

sphere::sphere(int horizontal_subdiv, int vertical_subdiv, scene curr_scene){
	/*Sphere
	Radius = 1;
	Diameter = 2;
	Location = 0, 0, 1;
	Angle = 0;*/
}

sphere::sphere(int horizontal_subdiv, int vertical_subdiv, int conic_subdiv, int spherical_long_subdiv, int spherical_lat_subdiv, int x_rotation, int torus_angle, int top_radius, int bot_radius, int radius, int spherical_radius, int conic_angle, int height, int rot_subdiv){
	
}

cone::cone(int horizontal_subdiv, int vertical_subdiv, scene curr_scene){
	cout << "Making a cone" << endl;
	this->set_name("cone");
	this->set_location(0.0, 0.0, 0.0);
	this->set_rotation(0.0, 0.0, 0.0);
	this->set_scale(1.0, 1.0, 1.0);
	this->set_num_vertices(horizontal_subdiv * 2 * vertical_subdiv);
	this->set_num_faces(horizontal_subdiv * vertical_subdiv + 2);  
	cout << this->get_name() << endl;
	cout << "faces: " << this->get_num_faces() << endl;
	cout << "verts: " << this->get_num_vertices() << endl;
	int horizontal_increment = 0;
	int vertical_increment = 0;
	int horizontal_step = 0;
	horizontal_increment = 360/horizontal_subdiv;
	vertical_increment = 1 / vertical_subdiv;
	horizontal_step = horizontal_increment;
	
	float horizontal_count = 0.0;
	int vertical_count = 0;
	horizontal_count = horizontal_subdiv + 1;

	while (horizontal_count != 0)
		{
			horizontal_count--;
			vertical_count = vertical_subdiv;
			while (vertical_count != 0)
			{
				cout << cos(horizontal_step) << ", " << sin(horizontal_step) << ", " << horizontal_count << endl;
				horizontal_step = horizontal_step + horizontal_increment;
				vertical_count--;
			}

		}
	cout << "finished" << endl;
}

cone::cone(int cone_horizontal_subdiv, int cone_vertical_subdiv, int cone_conic_subdiv, int cone_spherical_long_subdiv, int cone_spherical_lat_subdiv, int cone_x_rotation, int cone_torus_angle, int cone_top_radius, int cone_bot_radius, int cone_radius, int cone_spherical_radius, int cone_conic_angle, int cone_height, int cone_rot_subdiv, scene curr_scene){

}

cylinder::cylinder(int horizontal_subdiv, int vertical_subdiv, int top_radius, scene curr_scene){
	cout << "Making a cylinder" << endl;
	this->set_name("cylinder");
	this->set_location(0.0, 0.0, 0.0);
	this->set_rotation(0.0, 0.0, 0.0);
	this->set_scale(1.0, 1.0, 1.0);
	this->set_num_vertices(horizontal_subdiv * 2 * vertical_subdiv);
	this->set_num_faces(horizontal_subdiv * vertical_subdiv + 2);  
	cout << this->get_name() << endl;
	cout << "faces: " << this->get_num_faces() << endl;
	cout << "verts: " << this->get_num_vertices() << endl;
	int horizontal_increment = 0;
	int vertical_increment = 0;
	int horizontal_step = 0;
	horizontal_increment = 360/horizontal_subdiv;
	vertical_increment = 1 / vertical_subdiv;
	horizontal_step = horizontal_increment;
	float horizontal_count = 0.0;
	int vertical_count = 0;
	horizontal_count = horizontal_subdiv + 1;

	while (horizontal_count != 0)
		{
			horizontal_count--;
			vertical_count = vertical_subdiv;
			while (vertical_count != 0)
			{
				cout << cos(horizontal_step) << ", " << sin(horizontal_step) << ", " << horizontal_count << endl;
				horizontal_step = horizontal_step + horizontal_increment;
				vertical_count--;
			}

		}
	cout << "finished" << endl;
}

cylinder::cylinder(int cylinder_horizontal_subdiv, int cylinder_vertical_subdiv, int cylinder_conic_subdiv, int cylinder_spherical_long_subdiv, int cylinder_spherical_lat_subdiv, int cylinder_x_rotation, int cylinder_torus_angle, int cylinder_top_radius, int cylinder_bot_radius, int cylinder_radius, int cylinder_spherical_radius, int cylinder_conic_angle, int cylinder_height, int cylinder_rot_subdiv, scene curr_scene){
	
}

geosphere::geosphere(int resolution, scene curr_scene){
	cout << "Making a Geosphere" << endl;
	this->set_name("Geosphere");
	this->set_location(0.0, 0.0, 0.0);
	this->set_rotation(0.0, 0.0, 0.0);
	this->set_scale(1.0, 1.0, 1.0);
	this->set_num_vertices(((resolution + 1) * (resolution + 1)));
	this->set_num_faces((resolution * resolution));
	cout << this->get_name() << endl;
	cout << "faces: " << this->get_num_faces() << endl;
	cout << "verts: " << this->get_num_vertices() << endl;
}

torus::torus(int horizontal_subdiv, int vertical_subdiv, float radius, scene curr_scene){
    
}
torus::torus(int torus_horizontal_subdiv, int torus_vertical_subdiv, int torus_conic_subdiv, int torus_spherical_long_subdiv, int torus_spherical_lat_subdiv, int torus_x_rotation, int torus_angle, int torus_top_radius, int torus_bot_radius, int torus_radius, int torus_spherical_radius, int torus_conic_angle, int torus_height, int torus_rot_subdiv, scene curr_scene){
	
}

rounded_cube::rounded_cube(int horizontal_subdiv, int vertical_subdiv, scene curr_scene){

}
rounded_cube::rounded_cube(int rounded_cube_horizontal_subdiv, int rounded_cube_vertical_subdiv, int rounded_cube_conic_subdiv, int rounded_cube_spherical_long_subdiv, int rounded_cube_spherical_lat_subdiv, int rounded_cube_x_rotation, int rounded_cube_torus_angle, int rounded_cube_top_radius, int rounded_cube_bot_radius, int rounded_cube_radius, int rounded_cube_spherical_radius, int rounded_cube_conic_angle, int rounded_cube_height, int rounded_cube_rot_subdiv, scene curr_scene){
	
}

rounded_cylinder::rounded_cylinder(int horizontal_subdiv, int vertical_subdiv, scene curr_scene){
        
}
rounded_cylinder::rounded_cylinder(int rounded_cylinder_horizontal_subdiv, int rounded_cylinder_vertical_subdiv, int rounded_cylinder_conic_subdiv, int rounded_cylinder_spherical_long_subdiv, int rounded_cylinder_spherical_lat_subdiv, int rounded_cylinder_x_rotation, int rounded_cylinder_torus_angle, int rounded_cylinder_top_radius, int rounded_cylinder_bot_radius, int rounded_cylinder_radius, int rounded_cylinder_spherical_radius, int rounded_cylinder_conic_angle, int rounded_cylinder_height, int rounded_cylinder_rot_subdiv, scene curr_scene){
	
}
