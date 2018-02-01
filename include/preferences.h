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
		float background_color[3] = { 0.6, 0.6, 0.6 };
		float grid_color[3] = { 0.7, 0.7, 0.7 };
		float highlight_color[3] = { 0.0, 1.0, 0.0 };
		float pesel_color[3] = { 1.0, 1.0, 1.0 };
		float selected_color[3] = { 1.0, 1.0, 1.0 };
		float unselected_color[3] = { 0.75, 0.75, 0.75 };
		float light_color[3] = { 1.0, 1.0, 1.0 };
		float camera_color[3] = { 1.0, 1.0, 1.0 };
		int plane_resolution = 1;
    	int cube_resolution = 1;
		int geosphere_resolution = 1;
    	int sphere_latitude = 8;
		int sphere_longitude = 16;
		int cone_latitude = 1;
		int cone_longitude = 16;
		int cylinder_latitude = 1;
		int cylinder_longitude = 16;
		float cylinder_top_radius = 1.0;
        int torus_latitude = 16;
        int torus_longitude = 16;
        float torus_inner_radius = 0.04;
		int rounded_cube_latitude = 8;
		int rounded_cube_longitude = 4;
		int rounded_cylinder_latitude = 4;
		int rounded_cylinder_longitude = 16;
		
    public:
		void default_preferences(void);
		void load_preferences(string filename);
		void save_preferences(string filename);
		int get_interface_type(void);
		int get_grid_resolution(void);
		bool get_draw_ground_plane(void);
		bool get_draw_axes(void);
		float *get_background_color(void);
		float *get_grid_color(void);
		float *get_highlight_color(void);
		float *get_pesel_color(void);
		float *get_selected_color(void);
		float *get_unselected_color(void);
		float *get_light_color(void);
		float *get_camera_color(void);
		int get_plane_resolution(void);
    	int get_cube_resolution(void);
		int get_geosphere_resolution(void);
    	int get_sphere_latitude(void);
		int get_sphere_longitude(void);
		int get_cone_latitude(void);
		int get_cone_longitude(void);
		int get_cylinder_latitude(void);
		int get_cylinder_longitude(void);
		float get_cylinder_top_radius(void);
        int get_torus_latitude(void);
        int get_torus_longitude(void);
        float get_torus_inner_radius(void);
		int get_rounded_cube_latitude(void);
		int get_rounded_cube_longitude(void);
		int get_rounded_cylinder_latitude(void);
		int get_rounded_cylinder_longitude(void);
		void set_interface_type(int);
		void set_grid_resolution(int);
		void set_draw_axes(bool);
		void set_draw_ground_plane(bool);
		void set_background_color( float Red, float green, float Blue );
		void set_grid_color( float Red, float green, float Blue );
		void set_highlight_color( float Red, float green, float Blue );
		void set_pesel_color( float Red, float green, float Blue );
		void set_selected_color( float Red, float green, float Blue );
		void set_unselected_color( float Red, float green, float Blue );
		void set_light_color( float Red, float green, float Blue );
		void set_camera_color( float Red, float green, float Blue );
		void set_plane_resolution(int);
		void set_cube_resolution(int);
		void set_geosphere_resolution(int);
		void set_sphere_latitude(int);
		void set_sphere_longitude(int);
		void set_cone_latitude(int);
		void set_cone_longitude(int);
		void set_cylinder_latitude(int);
		void set_cylinder_longitude(int);
		void set_cylinder_top_radius(float);
		void set_torus_latitude(int);
		void set_torus_longitude(int);
		void set_torus_inner_radius(float);
		void set_rounded_cube_latitude(int);
		void set_rounded_cube_longitude(int);
		void set_rounded_cylinder_latitude(int);
		void set_rounded_cylinder_longitude(int);
};
#endif // PREFERENCES_H
