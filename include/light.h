#ifndef LIGHT_H
#define LIGHT_H

#include "scene.h"
#include "view.h"
#include "object.h"
/*
class image_light : public light
{
	protected:
		string name = "Projector ";
		struct colour { R, G, B };
		int intensity 0-255;
		string image;
		enum units { CANDELA, KILOCANDELA, LUMEN, KILOLUMEN, LUX, KILOLUX, NIT, FOOT_CANDLE, EMPIRICAL };
		int temperature 0-30000;
		bool cast_shadows;
		int falloff;
		int volumentric_effect;
		
		int Resolution 4 -100
		float Fuzzine 0.00 -1.00
		float U repeats 0.01 - 100
		float V Repeats 0.01 - 100
		float 0.00 - 1.00
		float 0.00 - 1.00
		bool show environment
		bool below ground
};

class projector_light : public light
{
	protected:
		string name = "Projector ";
		struct colour { int R, G, B };
		int intensity 0-255;
		string image;
		enum units { CANDELA, KILOCANDELA, LUMEN, KILOLUMEN };
		int temperature 0-30000;
		bool cast_shadows;
		int falloff;
};


spotlight : public light
{
		string image = NULL;
		goniomentric = NULL;
};

local_light : public light
{
		string image = NULL;
		goniomentric = NULL;
};

infinite_light : public light
{
		string image = NULL;
		goniomentric = NULL;
};

skylight : public light
{

};

goniometric_light : public light
{
		string image = NULL;

};

area_light : public light
{

};*/




enum volumetric { VOLUMETRIC, LENS_FLARE, PHYSICALLY_BASED };
enum falloff { NO_FALLOFF, LINEAR_FALLOFF, SQUARED_FALLOFF };
enum light_type { SPOTLIGHT, LOCAL, INFINITE, PROJECTOR, SKYLIGHT, IMAGE, GONIOMETRIC, AREA };

class Light : public object
{
    protected:
        int light_type;
        double color[3];
		
    public:
//        void Light::Select_Light(Light);
        virtual ~Light();

};

class SpotLight : Light{
    protected:
    public:

};

class LocalLight : Light{
    protected:
    public:
};

class InfiniteLight : Light{
    protected:
    public:

};

class ProjectorLight : Light{
    protected:
    public:

};

class SkyLight : Light{
    protected:
    public:
};

class ImageLight : Light{
    protected:
    public:
};

class GoniometricLight : Light{
    protected:
    public:
};

class AreaLight : Light{
	protected:
	public:
};

/*Light Light::Select_Light(Light){

    return self;
}*/

#endif // LIGHT_H
