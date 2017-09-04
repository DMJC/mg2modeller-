#ifndef CAMERA_H
#define CAMERA_H

#include "../include/object.h"

enum camera_type { CAMERA, PANORAMIC };

class camera : public object
{
		string name;
		int type;
		
    public:
        void SetCameraType(int camera_type);
		void SetCameraName(string camera_name);

        virtual ~camera();

};

class panoramic_camera : public camera{

};

#endif // CAMERA_H
