#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include "object.h"
#include "geometry.h"
#include "scene.h"

enum primitive_edit_mode { CREATE_MODE, EDIT_MODE, RENDER_MODE };
enum primitive_type { TORUS, TEAPOT, TUBE, SPHERE, PYRAMID, PLANE, GEOSPHERE, CYLINDER, CUBE, CONE };


class primitive: public object
{
    protected:
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
        plane(int plane_resolution, scene curr_scene);
		plane(int plane_horizontal_subdiv, int plane_vertical_subdiv, int plane_conic_subdiv, int plane_spherical_long_subdiv, int plane_spherical_lat_subdiv, int plane_x_rotation, int plane_torus_angle, int plane_top_radius, int plane_bot_radius, int plane_radius, int plane_spherical_radius, int plane_conic_angle, int plane_height, int plane_rot_subdiv, scene curr_scene);};

class cube : primitive{
	private:
	
    public:
        cube(int cube_resolution, scene curr_scene);
		cube(int cube_horizontal_subdiv, int cube_vertical_subdiv, int cube_conic_subdiv, int cube_spherical_long_subdiv, int cube_spherical_lat_subdiv, int cube_x_rotation, int cube_torus_angle, int cube_top_radius, int cube_bot_radius, int cube_radius, int cube_spherical_radius, int cube_conic_angle, int cube_height, int cube_rot_subdiv, scene curr_scene);
};

class cone : primitive{
    private:

    public:
        cone(int cone_horizontal_subdiv, int cone_vertical_subdiv, scene curr_scene);
		cone(int cone_horizontal_subdiv, int cone_vertical_subdiv, int cone_conic_subdiv, int cone_spherical_long_subdiv, int cone_spherical_lat_subdiv, int cone_x_rotation, int cone_torus_angle, int cone_top_radius, int cone_bot_radius, int cone_radius, int cone_spherical_radius, int cone_conic_angle, int cone_height, int cone_rot_subdiv, scene curr_scene);
};

class cylinder : primitive{
    private:

    public:
        cylinder(int cylinder_horizontal_subdiv, int cylinder_vertical_subdiv, int cylinder_top_radius, scene curr_scene);
		cylinder(int cylinder_horizontal_subdiv, int cylinder_vertical_subdiv, int cylinder_conic_subdiv, int cylinder_spherical_long_subdiv, int cylinder_spherical_lat_subdiv, int cylinder_x_rotation, int cylinder_torus_angle, int cylinder_top_radius, int cylinder_bot_radius, int cylinder_radius, int cylinder_spherical_radius, int cylinder_conic_angle, int cylinder_height, int cylinder_rot_subdiv, scene curr_scene);
};

class sphere : primitive{
    private:

    public:
        sphere(int sphere_horizontal_subdiv, int sphere_vertical_subdiv, scene curr_scene);
        sphere(int sphere_horizontal_subdiv, int sphere_vertical_subdiv, int sphere_conic_subdiv, int sphere_spherical_long_subdiv, int sphere_spherical_lat_subdiv, int sphere_x_rotation, int sphere_torus_angle, int sphere_top_radius, int sphere_bot_radius, int sphere_radius, int sphere_spherical_radius, int sphere_conic_angle, int sphere_height, int sphere_rot_subdiv);

};

class geosphere : primitive{
    private:

    public:
        geosphere(int resolution, scene curr_scene);
};

class torus : primitive{
    private:

    public:
        torus(int torus_horizontal_subdiv, int torus_vertical_subdiv, float torus_radius, scene curr_scene);
		torus(int torus_horizontal_subdiv, int torus_vertical_subdiv, int torus_conic_subdiv, int torus_spherical_long_subdiv, int torus_spherical_lat_subdiv, int torus_x_rotation, int torus_angle, int torus_top_radius, int torus_bot_radius, int torus_radius, int torus_spherical_radius, int torus_conic_angle, int torus_height, int torus_rot_subdiv, scene curr_scene);
};

class rounded_cube : primitive{
    private:

    public:
        rounded_cube(int rounded_cube_horizontal_subdiv, int rounded_cube_vertical_subdiv, scene curr_scene);
        rounded_cube(int rounded_cube_horizontal_subdiv, int rounded_cube_vertical_subdiv, int rounded_cube_conic_subdiv, int rounded_cube_spherical_long_subdiv, int rounded_cube_spherical_lat_subdiv, int rounded_cube_x_rotation, int rounded_cube_torus_angle, int rounded_cube_top_radius, int rounded_cube_bot_radius, int rounded_cube_radius, int rounded_cube_spherical_radius, int rounded_cube_conic_angle, int rounded_cube_height, int rounded_cube_rot_subdiv, scene curr_scene);
};

class rounded_cylinder : primitive{
    private:

    public:
        rounded_cylinder(int rounded_cylinder_horizontal_subdiv, int rounded_cylinder_vertical_subdiv, scene curr_scene);
        rounded_cylinder(int rounded_cylinder_horizontal_subdiv, int rounded_cylinder_vertical_subdiv, int rounded_cylinder_conic_subdiv, int rounded_cylinder_spherical_long_subdiv, int rounded_cylinder_spherical_lat_subdiv, int rounded_cylinder_x_rotation, int rounded_cylinder_torus_angle, int rounded_cylinder_top_radius, int rounded_cylinder_bot_radius, int rounded_cylinder_radius, int rounded_cylinder_spherical_radius, int rounded_cylinder_conic_angle, int rounded_cylinder_height, int rounded_cylinder_rot_subdiv, scene curr_scene);
};


class shape : primitive{
    private:

    public:
		shape(int horizontal_subdiv, int vertical_subdiv, int conic_subdiv, int spherical_long_subdiv, int spherical_lat_subdiv, int x_rotation, int angle, float top_radius, float bottom_radius, float radius, int spherical_radius, float conic_angle, float height, int rot_subdiv, scene curr_scene);
};
#endif // PRIMITIVE_H
