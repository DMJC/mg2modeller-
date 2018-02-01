#include "../include/primitive.h"

primitive::primitive(){

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
	cout << this->get_name() << endl;
	cout << "faces: " << this->get_num_faces() << endl;
	cout << "verts: " << this->get_num_vertices() << endl;
	
}
plane::plane(int horizontal_subdiv, int vertical_subdiv, int conic_subdiv, int spherical_long_subdiv, int spherical_lat_subdiv, int x_rotation, int torus_angle, int top_radius, int bot_radius, int radius, int spherical_radius, int conic_angle, int height, int rot_subdiv, scene curr_scene){
	cout << "Making Plane for real" << endl;
}

cube::cube(int resolution, scene curr_scene){
	cout << "Making a cube" << endl;
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

cube::cube(int horizontal_subdiv, int vertical_subdiv, int conic_subdiv, int spherical_long_subdiv, int spherical_lat_subdiv, int x_rotation, int torus_angle, int top_radius, int bot_radius, int radius, int spherical_radius, int conic_angle, int height, int rot_subdiv){
	
}

sphere::sphere(int horizontal_subdiv, int vertical_subdiv, scene curr_scene){

}

sphere::sphere(int horizontal_subdiv, int vertical_subdiv, int conic_subdiv, int spherical_long_subdiv, int spherical_lat_subdiv, int x_rotation, int torus_angle, int top_radius, int bot_radius, int radius, int spherical_radius, int conic_angle, int height, int rot_subdiv){
	
}

cone::cone(int horizontal_subdiv, int vertical_subdiv, scene curr_scene){

}

cone::cone(int horizontal_subdiv, int vertical_subdiv, int conic_subdiv, int spherical_long_subdiv, int spherical_lat_subdiv, int x_rotation, int torus_angle, int top_radius, int bot_radius, int radius, int spherical_radius, int conic_angle, int height, int rot_subdiv){
	
}

cylinder::cylinder(int horizontal_subdiv, int vertical_subdiv, int top_radius, scene curr_scene){

}

cylinder::cylinder(int horizontal_subdiv, int vertical_subdiv, int conic_subdiv, int spherical_long_subdiv, int spherical_lat_subdiv, int x_rotation, int torus_angle, int top_radius, int bot_radius, int radius, int spherical_radius, int conic_angle, int height, int rot_subdiv){
	
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
torus::torus(int horizontal_subdiv, int vertical_subdiv, int conic_subdiv, int spherical_long_subdiv, int spherical_lat_subdiv, int x_rotation, int torus_angle, int top_radius, int bot_radius, int radius, int spherical_radius, int conic_angle, int height, int rot_subdiv){
	
}

rounded_cube::rounded_cube(int horizontal_subdiv, int vertical_subdiv, scene curr_scene){

}
rounded_cube::rounded_cube(int horizontal_subdiv, int vertical_subdiv, int conic_subdiv, int spherical_long_subdiv, int spherical_lat_subdiv, int x_rotation, int torus_angle, int top_radius, int bot_radius, int radius, int spherical_radius, int conic_angle, int height, int rot_subdiv){
	
}

rounded_cylinder::rounded_cylinder(int horizontal_subdiv, int vertical_subdiv, scene curr_scene){
        
}
rounded_cylinder::rounded_cylinder(int horizontal_subdiv, int vertical_subdiv, int conic_subdiv, int spherical_long_subdiv, int spherical_lat_subdiv, int x_rotation, int torus_angle, int top_radius, int bot_radius, int radius, int spherical_radius, int conic_angle, int height, int rot_subdiv){
	
}
