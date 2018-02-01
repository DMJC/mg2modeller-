#ifndef CAMERA_H
#define CAMERA_H

#include "../include/object.h"

enum camera_type { CAMERA, PANORAMIC };

class camera : public object
{
		string name;
		int type;
		
	public:
		camera();
        void SetCameraType(int camera_type);
		void SetCameraName(string camera_name);

        virtual ~camera();

};

class panoramic_camera : public camera{
	private:
		bool mode;
		float quality;
		int pan_frames;
		int pan_min;
		int pan_max;
		int pan_init;
		int tilt_frames;
		int tilt_min;
		int tilt_max;
		int tilt_init;
	public:
		panoramic_camera();
		void set_mode(bool);
		void set_quality(float);
		void set_pan_frames(int);
		void set_pan_min(int);
		void set_pan_max(int);
		void set_pan_init(int);
		void set_tilt_frames(int);
		void set_tilt_min(int);
		void set_tilt_max(int);
		void set_tilt_init(int);
		bool get_mode(void);
		float get_quality(void);
		int get_pan_frames(void);
		int get_pan_min(void);
		int get_pan_max(void);
		int get_pan_init(void);
		int get_tilt_frames(void);
		int get_tilt_min(void);
		int get_tilt_max(void);
		int get_tilt_init(void);
};

#endif // CAMERA_H
