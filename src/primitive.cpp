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
				//	horizontal_subdiv, vertical_subdiv, conic_subdiv, spherical_long_subdiv, spherical_lat_subdiv, x_rotation, angle, top_radius, bottom_radius, radius, 0, 0, height, rot_subdiv,
	shape new_shape(0, 0, 0, 0, 0, 45, 0, 1, 1, 1, 0, 0, 0, 4, curr_scene);
}
plane::plane(int horizontal_subdiv, int vertical_subdiv, int conic_subdiv, int spherical_long_subdiv, int spherical_lat_subdiv, int x_rotation, int torus_angle, int top_radius, int bot_radius, int radius, int spherical_radius, int conic_angle, int height, int rot_subdiv, scene curr_scene){
	cout << "Making Plane for real" << endl;
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
/*int rounded_cube_horizontal_subdiv
int rounded_cube_vertical_subdiv
int rounded_cube_conic_subdiv
int rounded_cube_spherical_long_subdiv
int rounded_cube_spherical_lat_subdiv
int rounded_cube_x_rotation
int rounded_cube_torus_angle

int rounded_cube_top_radius
int rounded_cube_bot_radius
int rounded_cube_radius
int rounded_cube_spherical_radius
int rounded_cube_conic_angle
int rounded_cube_height
int rounded_cube_rot_subdiv

	//float rotation = 45.0;
	x = r * cos(a); y = r * sin(a); z = 0.0;
	x = r * cos(a); y = r * sin(a); z = 2.0;*/
}

rounded_cylinder::rounded_cylinder(int horizontal_subdiv, int vertical_subdiv, scene curr_scene){
        
}
rounded_cylinder::rounded_cylinder(int rounded_cylinder_horizontal_subdiv, int rounded_cylinder_vertical_subdiv, int rounded_cylinder_conic_subdiv, int rounded_cylinder_spherical_long_subdiv, int rounded_cylinder_spherical_lat_subdiv, int rounded_cylinder_x_rotation, int rounded_cylinder_torus_angle, int rounded_cylinder_top_radius, int rounded_cylinder_bot_radius, int rounded_cylinder_radius, int rounded_cylinder_spherical_radius, int rounded_cylinder_conic_angle, int rounded_cylinder_height, int rounded_cylinder_rot_subdiv, scene curr_scene){
	
}

shape::shape(int horizontal_subdiv, int vertical_subdiv, int conic_subdiv, int spherical_long_subdiv, int spherical_lat_subdiv, int x_rotation, int angle, float top_radius, float bottom_radius, float radius, int spherical_radius, float conic_angle, float height, int rot_subdiv, scene curr_scene){
	vertical_subdiv = vertical_subdiv + 1;
	float radius_step = 0;
	radius_step = (top_radius - bottom_radius) / (vertical_subdiv -1);
	float vertical_step = 0;
	vertical_step = height / (vertical_subdiv -1);
	int tmp_rot_subdiv = 0;
	float degree = 360 / rot_subdiv;
	float deg_count = 0;
	float X = 0.0;
	float Y = 0.0;
	float Z = 0.0;
	radius = bottom_radius;

	if (conic_angle != 0){
		//add bottom centre vertex here
		//X = 0; Y = 0, Z = height - 1/conic_angle;
	}
	while (vertical_subdiv != 0){
		cout << vertical_subdiv << endl;
		tmp_rot_subdiv = rot_subdiv;
		deg_count = 0;
		while (tmp_rot_subdiv != 0){
			float Xin = 0;
			Xin = (deg_count * (M_PI/180));
			float Yin = 0;
			Yin = (deg_count * (M_PI/180));
			X = cosf(Xin);
			Y = sinf(Yin);
			X = fabs(X);
			Y = fabs(Y);
			float diff = fmod(X, 1.0f);
			if(abs(diff < 0.001f))
			X -= diff;
			float diff2 = fmod(Y, 1.0f);
			if(abs(diff2 < 0.001f))
			Y -= diff2;
			if (deg_count > 180){
				Y = -Y;
			}
			if (deg_count > 90 && deg_count < 270){
				X = -X;
			}
			if(radius == 0){
				X = 0; Y = 0;
			}else{
				X = X * radius;
				Y = Y * radius;
			}
			cout << "vertex" << tmp_rot_subdiv << " Radius: " << radius << " degree " << deg_count << " X: " << X << " Y: " 				<< Y << " Z: " << Z << endl;
			deg_count = deg_count + degree;
			tmp_rot_subdiv--;
		}
	radius = radius + radius_step;
	Z = Z + vertical_step;
	vertical_subdiv--;
	}
	if (conic_angle != 0){
		//add top vertex here
		//X = 0; Y = 0, Z = height + 1/conic_angle;
	}
}
