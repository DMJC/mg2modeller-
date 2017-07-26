#ifndef ANIMATION_H
#define ANIMATION_H
class frame {
	public:
	    bool is_keyframe;
		float rotate[16] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
		float translate[3] = { 0.0, 0.0, 0.0 }; // translate data...
		float scale[3] = { 0.0, 0.0, 0.0 }; // etc...

		bool look_at_point = false;
		float lookat[3] = { 0.0, 0.0, 0.0 };

		void set_look_at_point(bool look_at_point, int X, int Y, int Z);
		void unset_look_at_point(bool look_at_point);
		void set_rotation(float rotation[16]);
		void set_translation(int X, int Y, int Z);
		void set_scale(int X, int Y, int Z);
		float* get_rotate(void);
		float* get_translate(void);
		float* get_scale(void);
};
#endif