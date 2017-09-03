#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include "object.h"
#include "scene.h"


class primitive: public object
{
    protected:
		int num_faces;
		int num_verts;
	
    public:
        primitive();
        virtual ~primitive();

};

class plane : primitive{
    private:

    public:
        void make_plane(int horizontal_subdiv, int vertical_subdiv, int conic_subdiv, int spherical_long_subdiv, int spherical_lat_subdiv, int x_rotation, int torus_angle, int top_radius, int bot_radius, int radius, int spherical_radius, int conic_angle, int height, int rot_subdiv);

};

class cube : primitive{
	private:
	
    public:
		void make_cube(int horizontal_subdiv, int vertical_subdiv, int conic_subdiv, int spherical_long_subdiv, int spherical_lat_subdiv, int x_rotation, int torus_angle, int top_radius, int bot_radius, int radius, int spherical_radius, int conic_angle, int height, int rot_subdiv);
};

class cone : primitive{
    private:

    public:
        void make_cone(int horizontal_subdiv, int vertical_subdiv, int conic_subdiv, int spherical_long_subdiv, int spherical_lat_subdiv, int x_rotation, int torus_angle, int top_radius, int bot_radius, int radius, int spherical_radius, int conic_angle, int height, int rot_subdiv);

};

class cylinder : primitive{
    private:

    public:
        void make_cylinder(int horizontal_subdiv, int vertical_subdiv, int conic_subdiv, int spherical_long_subdiv, int spherical_lat_subdiv, int x_rotation, int torus_angle, int top_radius, int bot_radius, int radius, int spherical_radius, int conic_angle, int height, int rot_subdiv);

};

class sphere : primitive{
    private:

    public:
        void make_sphere(int horizontal_subdiv, int vertical_subdiv, int conic_subdiv, int spherical_long_subdiv, int spherical_lat_subdiv, int x_rotation, int torus_angle, int top_radius, int bot_radius, int radius, int spherical_radius, int conic_angle, int height, int rot_subdiv);

};

class geosphere : primitive{
    private:

    public:
        void make_geosphere(int resolution);

};

class torus : primitive{
    private:

    public:
        void make_torus(int horizontal_subdiv, int vertical_subdiv, int conic_subdiv, int spherical_long_subdiv, int spherical_lat_subdiv, int x_rotation, int torus_angle, int top_radius, int bot_radius, int radius, int spherical_radius, int conic_angle, int height, int rot_subdiv);

};

class rounded_cube : primitive{
    private:

    public:
        void make_rounded_cube(int horizontal_subdiv, int vertical_subdiv, int conic_subdiv, int spherical_long_subdiv, int spherical_lat_subdiv, int x_rotation, int torus_angle, int top_radius, int bot_radius, int radius, int spherical_radius, int conic_angle, int height, int rot_subdiv);

};

class rounded_cylinder : primitive{
    private:

    public:
        void make_rounded_cylinder(int horizontal_subdiv, int vertical_subdiv, int conic_subdiv, int spherical_long_subdiv, int spherical_lat_subdiv, int x_rotation, int torus_angle, int top_radius, int bot_radius, int radius, int spherical_radius, int conic_angle, int height, int rot_subdiv);

};

#endif // PRIMITIVE_H
