#ifndef OBJECT_H
#define OBJECT_H
#include <string>
#include <list>
#include <GL/glew.h>
#include <GL/gl.h>
#include "animation.h"
#include "geometry.h"
#include "texture.h"
#include "material.h"

using namespace std;

enum type_of_object { LIGHT, PRIMITIVE, CAMERA, PANORAMIC };

class object
{
	protected:
		double location[3] = { 0.0, 0.0, 0.0 };
		float rotation[3], scale[3] = { 0.0, 0.0, 0.0 };
		string name;
		float selected_color[3] = { 0.0, 0.0, 0.0 };
		float unselected_color[3] = { 0.0, 0.0, 0.0 };
		//virtual ~object obj_type;
		type_of_object object_type;
		int num_vertices = 0;
		int num_edges = 0;
		int num_faces = 0;
		int num_frames = 0;
		/////////// Hierarcy
		bool is_parent_only; /* invisible parent object */
		object *parent;
		list<object> children;
		list<object> sibling;
		/////////// Geometry
		list<vertex> vertices; // vertex data
		list<edge> edges; // edge data
		list<face> faces; // surface faces (replace with list)
		list<normal> normals; //unimplemented - DMJC
		float origin[3]; // current offset of object origin
		bool show_axes; // object axes
		object_axes axes; // object axes
		bool show_origin;
		float compensation[16]; // used when offset is changed
		float rot_origin[16]; // rotation of origin
		/////////// Animation
		frame *curr_frame; // pointer to current frame
		list<frame> frames; // linked list of frames
		
	public:
	    void set_name(string);
	    string get_name(void);
		void set_object_type(type_of_object);
		type_of_object get_object_type(void);
		void set_location(double loc_X, double loc_Y, double loc_Z);
		void set_rotation(float rot_X, float rot_Y, float rot_Z);
		void set_scale(float sca_X, float sca_Y, float sca_Z);
		double* get_location(void);
		float* get_rotation(void);
		float* get_scale(void);
		int get_num_vertices(void);
		int get_num_faces(void);
		void set_num_vertices(int num_vertices);
		void set_num_faces(int num_faces);
		void add_child(object *child);
		void remove_child(object *child);
		void add_sibling(object *sibling);
		void remove_sibling(object *sibling);
		void enable_axes(bool state);
		void enable_origin(bool state);
		void add_frame(void);
		void remove_frame(frame *frame);
};

#endif // OBJECT_H
