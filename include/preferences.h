#ifndef PREFERENCES_H
#define PREFERENCES_H
#include "mg2.h"

using namespace std;

class preferences
{
	protected:
		int interface_type = 1;
		int grid_resolution = 32;
		bool draw_axes = TRUE;
		bool draw_ground_plane = FALSE;
		float Background_Color[3] = { 0.6, 0.6, 0.6 };
		float Grid_Color[3] = { 0.7, 0.7, 0.7 };
		float Highlight_Color[3] = { 1.0, 1.0, 1.0 };
		float PeSel_Color[3] = { 1.0, 1.0, 1.0 };
		float Selected_Color[3] = { 1.0, 1.0, 1.0 };
		float Unselected_Color[3] = { 1.0, 1.0, 1.0 };
		float Light_Color[3] = { 1.0, 1.0, 1.0 };
		float Camera_Color[3] = { 1.0, 1.0, 1.0 };
		
    public:
		void default_preferences(void);
		void load_preferences(string filename);
		void save_preferences(string filename);
		void set_interface_type(int interface_type);
		void set_grid_resolution(int grid_resolution);
		void set_draw_ground_plane(bool draw_ground_plane);
		void set_draw_axes(bool draw_axes);
		int get_interface_type();
		int get_grid_resolution();
		int get_draw_ground_plane();
		bool get_draw_axes();
};
#endif // PREFERENCES_H
