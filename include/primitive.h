#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include "object.h"
#include "geometry.h"
#include "scene.h"

enum primitive_edit_mode { CREATE_MODE, EDIT_MODE, RENDER_MODE };

class primitive: public object
{
    protected:
		int num_faces;
		int num_verts;
	    primitive_edit_mode edit_mode;
    public:
        primitive();
        virtual ~primitive();
        void set_edit_mode(primitive_edit_mode);
        primitive_edit_mode get_edit_mode(void);
};
class plane : primitive {
	private:
	
    public:
        plane(int resolution, scene curr_scene);
        plane(int horizontal_subdiv, int vertical_subdiv, int conic_subdiv, int spherical_long_subdiv, int spherical_lat_subdiv, int x_rotation, int torus_angle, int top_radius, int bot_radius, int radius, int spherical_radius, int conic_angle, int height, int rot_subdiv, scene curr_scene);
};

class cube : primitive{
	private:
	
    public:
        cube(int resolution, scene curr_scene);
        cube(int horizontal_subdiv, int vertical_subdiv, int conic_subdiv, int spherical_long_subdiv, int spherical_lat_subdiv, int x_rotation, int torus_angle, int top_radius, int bot_radius, int radius, int spherical_radius, int conic_angle, int height, int rot_subdiv);
};

class cone : primitive{
    private:

    public:
        cone(int horizontal_subdiv, int vertical_subdiv, scene curr_scene);
        cone(int horizontal_subdiv, int vertical_subdiv, int conic_subdiv, int spherical_long_subdiv, int spherical_lat_subdiv, int x_rotation, int torus_angle, int top_radius, int bot_radius, int radius, int spherical_radius, int conic_angle, int height, int rot_subdiv);

};

class cylinder : primitive{
    private:

    public:
        cylinder(int horizontal_subdiv, int vertical_subdiv, int top_radius, scene curr_scene);
        cylinder(int horizontal_subdiv, int vertical_subdiv, int conic_subdiv, int spherical_long_subdiv, int spherical_lat_subdiv, int x_rotation, int torus_angle, int top_radius, int bot_radius, int radius, int spherical_radius, int conic_angle, int height, int rot_subdiv);

};

class sphere : primitive{
    private:

    public:
        sphere(int horizontal_subdiv, int vertical_subdiv, scene curr_scene);
        sphere(int horizontal_subdiv, int vertical_subdiv, int conic_subdiv, int spherical_long_subdiv, int spherical_lat_subdiv, int x_rotation, int torus_angle, int top_radius, int bot_radius, int radius, int spherical_radius, int conic_angle, int height, int rot_subdiv);

};

class geosphere : primitive{
    private:

    public:
        geosphere(int resolution, scene curr_scene);
};

class torus : primitive{
    private:

    public:
        torus(int horizontal_subdiv, int vertical_subdiv, float radius, scene curr_scene);
        torus(int horizontal_subdiv, int vertical_subdiv, int conic_subdiv, int spherical_long_subdiv, int spherical_lat_subdiv, int x_rotation, int torus_angle, int top_radius, int bot_radius, int radius, int spherical_radius, int conic_angle, int height, int rot_subdiv);

};

class rounded_cube : primitive{
    private:

    public:
        rounded_cube(int horizontal_subdiv, int vertical_subdiv, scene curr_scene);
        rounded_cube(int horizontal_subdiv, int vertical_subdiv, int conic_subdiv, int spherical_long_subdiv, int spherical_lat_subdiv, int x_rotation, int torus_angle, int top_radius, int bot_radius, int radius, int spherical_radius, int conic_angle, int height, int rot_subdiv);

};

class rounded_cylinder : primitive{
    private:

    public:
        rounded_cylinder(int horizontal_subdiv, int vertical_subdiv, scene curr_scene);
        rounded_cylinder(int horizontal_subdiv, int vertical_subdiv, int conic_subdiv, int spherical_long_subdiv, int spherical_lat_subdiv, int x_rotation, int torus_angle, int top_radius, int bot_radius, int radius, int spherical_radius, int conic_angle, int height, int rot_subdiv);

};

#endif // PRIMITIVE_H
