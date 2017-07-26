#include "../include/preferences.h"

void preferences::default_preferences(void)
{
		this -> interface_type = 0;
		this -> grid_resolution = 32;
		this -> draw_axes = TRUE;
		this -> draw_ground_plane = FALSE;
		this -> Background_Color[0] = 0.6;
		this -> Background_Color[1] = 0.6;
		this -> Background_Color[2] = 0.6;
		this -> Grid_Color[0] = 0.7;
		this -> Grid_Color[1] = 0.7;
		this -> Grid_Color[2] = 0.7;
		this -> Highlight_Color[0] = 1.0;
		this -> Highlight_Color[1] = 1.0;
		this -> Highlight_Color[2] = 1.0;
		this -> PeSel_Color[0] = 1.0;
		this -> PeSel_Color[1] = 1.0;
		this -> PeSel_Color[2] = 1.0;
		this -> Selected_Color[0] = 1.0;
		this -> Selected_Color[1] = 1.0;
		this -> Selected_Color[2] = 1.0;
		this -> Unselected_Color[0] = 1.0;
		this -> Unselected_Color[1] = 1.0;
		this -> Unselected_Color[2] = 1.0;
		this -> Light_Color[0] = 1.0;
		this -> Light_Color[1] = 1.0;
		this -> Light_Color[2] = 1.0;
		this -> Camera_Color[0] = 1.0;
		this -> Camera_Color[1] = 1.0;
		this -> Camera_Color[2] = 1.0;
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
	prefs << this -> Background_Color[0] << endl;
	prefs << this -> Background_Color[1] << endl;
	prefs << this -> Background_Color[2] << endl;
	prefs << this -> Grid_Color[0] << endl;
	prefs << this -> Grid_Color[1] << endl;
	prefs << this -> Grid_Color[2] << endl;
	prefs << this -> Highlight_Color[0] << endl;
	prefs << this -> Highlight_Color[1] << endl;
	prefs << this -> Highlight_Color[2] << endl;
	prefs << this -> PeSel_Color[0] << endl;
	prefs << this -> PeSel_Color[1] << endl;
	prefs << this -> PeSel_Color[2] << endl;
	prefs << this -> Selected_Color[0] << endl;
	prefs << this -> Selected_Color[1] << endl;
	prefs << this -> Selected_Color[2] << endl;
	prefs << this -> Unselected_Color[0] << endl;
	prefs << this -> Unselected_Color[1] << endl;
	prefs << this -> Unselected_Color[2] << endl;
	prefs << this -> Light_Color[0] << endl;
	prefs << this -> Light_Color[1] << endl;
	prefs << this -> Light_Color[2] << endl;
	prefs << this -> Camera_Color[0] << endl;
	prefs << this -> Camera_Color[1] << endl;
	prefs << this -> Camera_Color[2] << endl;
  	prefs.close();
//  return 0;
};

void preferences::set_interface_type(int interface_type){
	this ->	interface_type = interface_type;
};

int preferences::get_interface_type(){
	return interface_type;
};

void preferences::set_grid_resolution(int grid_resolution){
	this ->	grid_resolution = grid_resolution;
};

int preferences::get_grid_resolution(){
	return grid_resolution;
};

void preferences::set_draw_ground_plane(bool draw_ground_plane){
	this ->	draw_ground_plane = draw_ground_plane;
};

int preferences::get_draw_ground_plane(){
	return draw_ground_plane;
};

void preferences::set_draw_axes(bool draw_axes){
	this -> draw_axes = draw_axes;
};

bool preferences::get_draw_axes(){
	return draw_axes;
};

