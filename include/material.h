#ifndef MATERIAL_H
#define MATERIAL_H
#include <string>
using namespace std;
class material
{
	protected:
		bool use_image = false;
		string image;
		float image_U_repeats = 1.00;
		float image_V_repeats = 1.00;
		float image_U_offset = 1.00;
		float image_V_offset = 1.00;
		int color[3] = { 255, 255, 255 };
		bool use_transparency = false;
		bool use_transparency_map = false;
		string transparency_map;
		float trans_map_U_repeats = 1.00;
		float trans_map_V_repeats = 1.00;
		float trans_map_U_offset = 1.00;
		float trans_map_V_offset = 1.00;
		
		bool use_bump = false;
		string bump;
		//shader[]; //Need to design what to put here.
		int luminance = 0;
		int diffusion = 100;
		int shininess = 0;
		int specular = 0;
		int specular_color[3] = { 255, 255, 255 };
		bool use_material_light = false;
		int intensity = 50;
		bool cast_shadow = false;
		
		bool shadow_transparency = false;
		//enum light_falloff { INFINITE, LINEAR, CURVED };
		float min = 0.50; //0.01 - 1.00
		float max = 0.10; //0.01 - 1.00
	public:
		void set_use_image(bool use_image);
		void set_image(string image);
		void set_image_U_repeats(float u_repeats);
		void set_image_V_repeats(float u_repeats);
		void set_image_U_offset(float u_offset);
		void set_image_V_offset(float u_offset);
		void set_color( int R, int G, int B );
		void set_use_transparency(bool use_trans);
		void set_use_transparency_map(bool use_trans_map);
		void set_transparency_map(string trans_map);
		void set_trans_map_U_repeats (float trans_map_U_repeats);
		void set_trans_map_V_repeats (float trans_map_V_repeats);
		void set_trans_map_U_offset (float trans_map_U_offset);
		void set_trans_map_V_offset (float trans_map_V_offset);
		
		void set_use_bump(bool);
		void set_bump(string);
		//shader[]; //Need to design what to put here.
		void set_luminance(int lum);
		void set_diffusion(int diff);
		void set_shininess(int shin);
		void set_specular(int spec);
		void set_specular_color(int R, int G, int B);
		void set_use_material_light(bool);
		void set_intensity(int);
		void set_cast_shadow(bool);
		
		void set_shadow_transparency(bool);
		//enum light_falloff { INFINITE, LINEAR, CURVED };
		void set_shadow_min(float); //0.01 - 1.00
		void set_shadow_max(float); //0.01 - 1.00
};
#endif
		