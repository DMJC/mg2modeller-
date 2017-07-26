#ifndef TEXTURE_H
#define TEXTURE_H
#include "material.h"
class texture
{
	protected:
		material mat;
		float coordinates[3];
	public:
		void set_coordinates(float X, float Y, float Z);
		void set_material(material mat);
		float* get_coordinates(void);
		material get_material(void);
};

#endif //TEXTURE_H
