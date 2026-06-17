#ifndef METABALL_H
#define METABALL_H
#include "object.h"
#include <vector>

enum metaball_type { METABALL_CUBE, METABALL_CYLINDER, METABALL_SPHERE, METABALL_ROUNDED_CYLINDER, METABALL_ROUND_CUBE, METABALL_MUSCLE };

class metaball : public object
{
protected:
	float threshold = 1.0f;
	float grid_resolution = 0.1f;

public:
	void generateMesh() override;
	void polygonize(float threshold, float resolution);
};

class metaball_cube : public metaball {};
class metaball_cylinder : public metaball {};
class metaball_sphere : public metaball {};
class metaball_rounded_cylinder : public metaball {};
class metaball_rounded_cube : public metaball {};
class metaball_muscle : public metaball {};

#endif //METABALL_H
