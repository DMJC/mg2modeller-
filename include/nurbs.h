#ifndef NURBS_H
#define NURBS_H
#include "object.h"
#include <vector>

enum nurbs_type { NURBS_PLANE, NURBS_CUBE, NURBS_SPHERE, NURBS_CONE };

class nurbs : public object
{
protected:
	int u_order = 4;
	int v_order = 4;
	int u_points = 4;
	int v_points = 4;
	std::vector<float> knots_u;
	std::vector<float> knots_v;
	int tessellation_resolution = 8;

public:
	void generateMesh() override;
	void tessellate(int resolution);
	void setTessellationResolution(int res);
};

class nurbs_plane : public nurbs {};
class nurbs_cube : public nurbs {};
class nurbs_sphere : public nurbs {};
class nurbs_cone : public nurbs {};

#endif //NURBS_H
