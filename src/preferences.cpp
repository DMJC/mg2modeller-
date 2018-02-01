#include "../include/preferences.h"

void preferences::default_preferences(void)
{
	this -> interface_type = 1;
	this -> grid_resolution = 32;
	this -> draw_axes = TRUE;
	this -> draw_ground_plane = FALSE;
	this -> background_color[0] = 0.6;
	this -> background_color[1] = 0.6;
	this -> background_color[2] = 0.6;
	this -> grid_color[0] = 0.7;
	this -> grid_color[1] = 0.7;
	this -> grid_color[2] = 0.7;
	this -> highlight_color[0] = 0.0;
	this -> highlight_color[1] = 1.0;
	this -> highlight_color[2] = 0.0;
	this -> pesel_color[0] = 1.0;
	this -> pesel_color[1] = 1.0;
	this -> pesel_color[2] = 1.0;
	this -> selected_color[0] = 1.0;
	this -> selected_color[1] = 1.0;
	this -> selected_color[2] = 1.0;
	this -> unselected_color[0] = 0.75;
	this -> unselected_color[1] = 0.75;
	this -> unselected_color[2] = 0.75;
	this -> light_color[0] = 0.9;
	this -> light_color[1] = 0.9;
	this -> light_color[2] = 0.9;
	this -> camera_color[0] = 0.9;
	this -> camera_color[1] = 0.9;
	this -> camera_color[2] = 1.0;
	this -> plane_resolution = 1;
	this -> cube_resolution = 1;
	this -> geosphere_resolution = 1;
	this -> sphere_latitude = 8;
	this -> sphere_longitude = 16;
	this -> cone_latitude = 1;
	this -> cone_longitude = 16;
	this -> cylinder_latitude = 1;
	this -> cylinder_longitude = 16;
	this -> cylinder_top_radius = 1.0;
	this -> torus_latitude = 16;
	this -> torus_longitude = 16;
	this -> torus_inner_radius = 0.04;
	this -> rounded_cube_latitude = 8;
	this -> rounded_cube_longitude = 4;
	this -> rounded_cylinder_latitude = 4;
	this -> rounded_cylinder_longitude = 16;
}

void preferences::load_preferences(string filename)
{
	string line;
	ifstream pref_file (filename);

	if (pref_file.is_open())
	{
        pref_file.close();
	}
	cout << "Loaded Preferences\n" << endl;
};

void preferences::save_preferences(string filename){
  	ofstream prefs;
  	prefs.open (filename);
	prefs << this -> interface_type << endl;
	prefs << this -> grid_resolution << endl;
	prefs << this -> draw_axes << endl;
	prefs << this -> draw_ground_plane << endl;
	prefs << this -> background_color[0] << endl;
	prefs << this -> background_color[1] << endl;
	prefs << this -> background_color[2] << endl;
	prefs << this -> grid_color[0] << endl;
	prefs << this -> grid_color[1] << endl;
	prefs << this -> grid_color[2] << endl;
	prefs << this -> highlight_color[0] << endl;
	prefs << this -> highlight_color[1] << endl;
	prefs << this -> highlight_color[2] << endl;
	prefs << this -> pesel_color[0] << endl;
	prefs << this -> pesel_color[1] << endl;
	prefs << this -> pesel_color[2] << endl;
	prefs << this -> selected_color[0] << endl;
	prefs << this -> selected_color[1] << endl;
	prefs << this -> selected_color[2] << endl;
	prefs << this -> unselected_color[0] << endl;
	prefs << this -> unselected_color[1] << endl;
	prefs << this -> unselected_color[2] << endl;
	prefs << this -> light_color[0] << endl;
	prefs << this -> light_color[1] << endl;
	prefs << this -> light_color[2] << endl;
	prefs << this -> camera_color[0] << endl;
	prefs << this -> camera_color[1] << endl;
	prefs << this -> camera_color[2] << endl;
	prefs << this -> plane_resolution << endl;
	prefs << this -> cube_resolution << endl;
	prefs << this -> geosphere_resolution << endl;
	prefs << this -> sphere_latitude << endl;
	prefs << this -> sphere_longitude << endl;
	prefs << this -> cone_latitude << endl;
	prefs << this -> cone_longitude << endl;
	prefs << this -> cylinder_latitude << endl;
	prefs << this -> cylinder_longitude << endl;
	prefs << this -> cylinder_top_radius << endl;
	prefs << this -> torus_latitude << endl;
	prefs << this -> torus_longitude << endl;
	prefs << this -> torus_inner_radius << endl;
	prefs << this -> rounded_cube_latitude << endl;
	prefs << this -> rounded_cube_longitude << endl;
	prefs << this -> rounded_cylinder_latitude << endl;
	prefs << this -> rounded_cylinder_longitude << endl;
 	prefs.close();
};

int preferences::get_interface_type(){
	return interface_type;
};

bool preferences::get_draw_ground_plane(void){
	return draw_ground_plane;
};

int preferences::get_grid_resolution(){
	return grid_resolution;
};

bool preferences::get_draw_axes(){
	return draw_axes;
};

float *preferences::get_background_color(void){
    return this -> background_color;
}
float *preferences::get_grid_color(void){
    return this -> grid_color;
}
float *preferences::get_highlight_color(void){
    return this -> highlight_color;
}
float *preferences::get_pesel_color(void){
    return this -> pesel_color;
}
float *preferences::get_selected_color(void){
    return this -> selected_color;
}
float *preferences::get_unselected_color(void){
    return this -> unselected_color;
}
float *preferences::get_light_color(void){
    return this -> light_color;
}
float *preferences::get_camera_color(void){
    return this -> camera_color;
}
int preferences::get_plane_resolution(void){
    return this -> plane_resolution;
}
int preferences::get_cube_resolution(void){
    return this -> cube_resolution;
}
int preferences::get_geosphere_resolution(void){
    return this -> geosphere_resolution;
}
int preferences::get_sphere_latitude(void){
    return this -> sphere_latitude;
}
int preferences::get_sphere_longitude(void){
    return this -> sphere_longitude;
}
int preferences::get_cone_latitude(void){
    return this -> cone_latitude;
}
int preferences::get_cone_longitude(void){
    return this -> cone_longitude;
}
int preferences::get_cylinder_latitude(void){
    return this -> cylinder_latitude;
}
int preferences::get_cylinder_longitude(void){
    return this -> cylinder_longitude;
}
float preferences::get_cylinder_top_radius(void){
    return this -> cylinder_top_radius;
}
int preferences::get_torus_latitude(void){
    return this -> torus_latitude;
}
int preferences::get_torus_longitude(void){
    return this -> torus_longitude;
}
float preferences::get_torus_inner_radius(void){
    return this -> torus_inner_radius;
}
int preferences::get_rounded_cube_latitude(void){
    return this -> rounded_cube_latitude;
}
int preferences::get_rounded_cube_longitude(void){
    return this -> rounded_cube_longitude;
}
int preferences::get_rounded_cylinder_latitude(void){
    return this -> rounded_cylinder_latitude;
}
int preferences::get_rounded_cylinder_longitude(void){
    return this -> rounded_cylinder_longitude;
}

void preferences::set_interface_type(int interface_type){
	this ->	interface_type = interface_type;
};

void preferences::set_grid_resolution(int grid_resolution){
	this ->	grid_resolution = grid_resolution;
};
void preferences::set_draw_ground_plane(bool draw_ground_plane){
	this ->	draw_ground_plane = draw_ground_plane;
};

void preferences::set_draw_axes(bool draw_axes){
	this -> draw_axes = draw_axes;
};

void preferences::set_background_color( float red, float green, float blue ){

}
void preferences::set_grid_color( float red, float green, float blue ){

}
void preferences::set_highlight_color( float red, float green, float blue ){

}
void preferences::set_pesel_color( float red, float green, float blue ){

}
void preferences::set_selected_color( float red, float green, float blue ){
	this -> selected_color[0] = red;
	this -> selected_color[1]= green;
	this -> selected_color[2]= blue;
}
void preferences::set_unselected_color( float red, float green, float blue ){
	this -> unselected_color[0] = red;
	this -> unselected_color[1] = green;
	this -> unselected_color[2] = blue;
}
void preferences::set_light_color( float red, float green, float blue ){
	this -> light_color[0] = red;
	this -> light_color[1] = green;
	this -> light_color[2] = blue;
}
void preferences::set_camera_color( float red, float green, float blue ){
	this -> camera_color[0] = red;
	this -> camera_color[1] = green;
	this -> camera_color[2] = blue;
}
void preferences::set_plane_resolution(int resolution){
	this -> plane_resolution = resolution;

}
void preferences::set_cube_resolution(int resolution){
	this -> cube_resolution = resolution;
}
void preferences::set_geosphere_resolution(int resolution){
	this -> geosphere_resolution = resolution;
}
void preferences::set_sphere_latitude(int latitude){
	this -> sphere_latitude = latitude;
}
void preferences::set_sphere_longitude(int longitude){
	this -> sphere_longitude = longitude;
}
void preferences::set_cone_latitude(int latitude){
	this -> cone_latitude = latitude;
}
void preferences::set_cone_longitude(int longitude){
	this -> cone_longitude = longitude;
}
void preferences::set_cylinder_latitude(int latitude){
	this -> cylinder_latitude = latitude;
}
void preferences::set_cylinder_longitude(int longitude){
	this -> cylinder_longitude = longitude;
}
void preferences::set_cylinder_top_radius(float radius){
	this -> cylinder_top_radius = radius;
}
void preferences::set_torus_latitude(int latitude){
	this -> torus_latitude = latitude;
}
void preferences::set_torus_longitude(int longitude){
	this -> torus_longitude = longitude;
}
void preferences::set_torus_inner_radius(float latitude){
	this -> torus_inner_radius = latitude;
}
void preferences::set_rounded_cube_latitude(int latitude){
	this -> rounded_cube_latitude = latitude;
}
void preferences::set_rounded_cube_longitude(int longitude){
	this -> rounded_cube_longitude = longitude;
}
void preferences::set_rounded_cylinder_latitude(int latitude){
	this -> rounded_cylinder_latitude = latitude;
}
void preferences::set_rounded_cylinder_longitude(int longitude){
	this -> rounded_cylinder_longitude = longitude;
}
