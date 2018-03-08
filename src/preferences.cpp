#include "../include/preferences.h"

void preferences::default_preferences(void)
{
	this -> interface_type = 1;
	this -> grid_resolution = 32;
	this -> draw_axes = TRUE;
	this -> draw_ground_plane = TRUE;
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
	fstream inputfile;
	string buffer;
    cout << "Loading Preferences" << endl;
    inputfile.open(filename, fstream::in);
	string token;
	string token2;
	string discard;
    int quit = 0;
    	while ( !inputfile.eof()){
			getline (inputfile, buffer);
    		size_t pos = 0;
    		string delimiter = " = ";
    			while ((pos = buffer.find(delimiter)) != string::npos) {
    			    token = buffer.substr(0, pos);
    			    token2 = buffer.substr(pos+3, string::npos);
    			    token2 = token2.erase(token2.length()-1);
	    		    cout << token << " " << token2 << endl;
	    		    buffer.erase(0, pos + delimiter.length());
	    		}

	        map<string,int>	m1;
				m1.insert(pair<string, int>("interface type", 1));
				m1.insert(pair<string, int>("grid resolution", 2));
				m1.insert(pair<string, int>("draw axes", 3));
				m1.insert(pair<string, int>("draw ground plane", 4));
				m1.insert(pair<string, int>("background color red", 5));
				m1.insert(pair<string, int>("background color green", 6));
				m1.insert(pair<string, int>("background color blue", 7));
				m1.insert(pair<string, int>("grid color red", 8));
				m1.insert(pair<string, int>("grid color green", 9));
				m1.insert(pair<string, int>("grid color blue", 10));
				m1.insert(pair<string, int>("highlight color red", 11));
				m1.insert(pair<string, int>("highlight color green", 12));
				m1.insert(pair<string, int>("highlight color blue", 13));
				m1.insert(pair<string, int>("pesel color red", 14));
				m1.insert(pair<string, int>("pesel color green", 15));
				m1.insert(pair<string, int>("pesel color blue", 16));
				m1.insert(pair<string, int>("selected color red", 17));
				m1.insert(pair<string, int>("selected color green", 18));
				m1.insert(pair<string, int>("selected color blue", 19));
				m1.insert(pair<string, int>("unselected color red", 20));
				m1.insert(pair<string, int>("unselected color green", 21));
				m1.insert(pair<string, int>("unselected color blue", 22));
				m1.insert(pair<string, int>("light color red", 23));
				m1.insert(pair<string, int>("light color green", 24));
				m1.insert(pair<string, int>("light color blue", 25));
				m1.insert(pair<string, int>("camera color red", 26));
				m1.insert(pair<string, int>("camera color green", 27));
				m1.insert(pair<string, int>("camera color blue", 28));
				m1.insert(pair<string, int>("plane resolution", 29));
				m1.insert(pair<string, int>("cube resolution", 30));
				m1.insert(pair<string, int>("geosphere resolution", 31));
				m1.insert(pair<string, int>("sphere latitude", 32));
				m1.insert(pair<string, int>("sphere longitude", 33));
				m1.insert(pair<string, int>("cone latitude", 34));
				m1.insert(pair<string, int>("cone longitude", 35));
				m1.insert(pair<string, int>("cylinder latitude", 36));
				m1.insert(pair<string, int>("cylinder longitude", 37));
				m1.insert(pair<string, int>("cylinder top radius", 38));
				m1.insert(pair<string, int>("torus latitude", 39));
				m1.insert(pair<string, int>("torus longitude", 40));
				m1.insert(pair<string, int>("torus inner radius", 41));
				m1.insert(pair<string, int>("rounded cube latitude", 42));
				m1.insert(pair<string, int>("rounded cube longitude", 43));
				m1.insert(pair<string, int>("rounded cylinder latitude", 44));
				m1.insert(pair<string, int>("rounded cylinder longitude", 45));

	   	switch (m1[token]){
			case 1 :
				this->interface_type = atoi(token2.c_str());
			break;
			case 2 :
				this -> grid_resolution = atoi(token2.c_str());
			break;
			case 3 :
				this -> draw_axes = TRUE;
			break;
			case 4 :
				this -> draw_ground_plane = TRUE;
			break;
			case 5 :
				this -> background_color[0] = strtof(token2.c_str(), nullptr);
			break;
			case 6 :
				this -> background_color[1] = strtof(token2.c_str(), nullptr);
			break;
			case 7 :
				this -> background_color[2] = strtof(token2.c_str(), nullptr);
			break;
			case 8 :
				this -> grid_color[0] = strtof(token2.c_str(), nullptr);
			break;
			case 9 :
				this -> grid_color[1] = strtof(token2.c_str(), nullptr);
			break;
			case 10 :
				this -> grid_color[2] = strtof(token2.c_str(), nullptr);
			break;
			case 11 :
				this -> highlight_color[0] = strtof(token2.c_str(), nullptr);
			break;
			case 12 :
				this -> highlight_color[1] = strtof(token2.c_str(), nullptr);
			break;
			case 13 :
				this -> highlight_color[2] = strtof(token2.c_str(), nullptr);
			break;
			case 14 :
				this -> pesel_color[0] = strtof(token2.c_str(), nullptr);
			break;
			case 15 :
				this -> pesel_color[1] = strtof(token2.c_str(), nullptr);
			break;
			case 16 :
				this -> pesel_color[2] = strtof(token2.c_str(), nullptr);
			break;
			case 17 :
				this -> selected_color[0] = strtof(token2.c_str(), nullptr);
			break;
			case 18 :
				this -> selected_color[1] = strtof(token2.c_str(), nullptr);
			break;
			case 19 :
				this -> selected_color[2] = strtof(token2.c_str(), nullptr);
			break;
			case 20 :
				this -> unselected_color[0] = strtof(token2.c_str(), nullptr);
			break;
			case 21 :
				this -> unselected_color[1] = strtof(token2.c_str(), nullptr);
			break;
			case 22 :
				this -> unselected_color[2] = strtof(token2.c_str(), nullptr);
			break;
			case 23 :
				this -> light_color[0] = strtof(token2.c_str(), nullptr);
			break;
			case 24 :
				this -> light_color[1] = strtof(token2.c_str(), nullptr);
			break;
			case 25 :
				this -> light_color[2] = strtof(token2.c_str(), nullptr);
			break;
			case 26 :
				this -> camera_color[0] = strtof(token2.c_str(), nullptr);
			break;
			case 27 :
				this -> camera_color[1] = strtof(token2.c_str(), nullptr);
			break;
			case 28 :
				this -> camera_color[2] = strtof(token2.c_str(), nullptr);
			break;
			case 29 :
				this -> plane_resolution = atoi(token2.c_str());
			break;
			case 30 :
				this -> cube_resolution = atoi(token2.c_str());
			break;
			case 31 :
				this -> geosphere_resolution = atoi(token2.c_str());
			break;
			case 32 :
				this -> sphere_latitude = atoi(token2.c_str());
			break;
			case 33 :
				this -> sphere_longitude = atoi(token2.c_str());
			break;
			case 34 :
				this -> cone_latitude = atoi(token2.c_str());
			break;
			case 35 :
				this -> cone_longitude = atoi(token2.c_str());
			break;
			case 36 :
				this -> cylinder_latitude = atoi(token2.c_str());
			break;
			case 37 :
				this -> cylinder_longitude = atoi(token2.c_str());
			break;
			case 38 :
				this -> cylinder_top_radius = strtof(token2.c_str(), nullptr);
			break;
			case 39 :
				this -> torus_latitude = atoi(token2.c_str());
			break;
			case 40 :
				this -> torus_longitude = atoi(token2.c_str());
			break;
			case 41 :
				this -> torus_inner_radius = strtof(token2.c_str(), nullptr);
			break;
			case 42 :
				this -> rounded_cube_latitude = atoi(token2.c_str());
			break;
			case 43 :
				this -> rounded_cube_longitude = atoi(token2.c_str());
			break;
			case 44 :
				this -> rounded_cylinder_latitude = atoi(token2.c_str());
			break;
			case 45 :
				this -> rounded_cylinder_longitude = atoi(token2.c_str());
			break;
		}
	}
	cout << "Loaded Preferences" << endl;
	inputfile.close();
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
