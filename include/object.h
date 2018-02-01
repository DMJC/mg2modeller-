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

//enum object_type { LIGHT, PRIMITIVE, CAMERA };
class object
{
	protected:
		int location[3], rotation[3], scale[3];
		string name;
		float selected_color[3];
		float unselected_color[3];
//		virtual ~object obj_type;
		int num_vertices;
		int num_edges;
		int num_faces;
		int num_frames;
		bool is_parent_only; /* invisible parent object */
	
		object *parent;
		list<object> children;
		list<vertex> vertices; // vertex data
		list<edge> edges; // edge data
		list<face> faces; // surface faces (replace with list)
		list<normal> normals; //unimplemented - DMJC
		/* origin offset */
		float origin[3]; // current offset of object origin
		bool show_axes; // object axes
		object_axes axes; // object axes
		bool show_origin;
		float compensation[16]; // used when offset is changed
		float rot_origin[16]; // rotation of origin

		/////////// Animation

		//frame *curr_frame; // pointer to current frame
		list<frame> frames; // linked list of frames
		
	public:
	    void set_name(string);
	    string get_name(void);
		void set_location(double loc_X, double loc_Y, double loc_Z);
		void set_rotation(double rot_X, double rot_Y, double rot_Z);
		void set_scale(double sca_X, double sca_Y, double sca_Z);
		int* get_location(void);
		int* get_rotation(void);
		int* get_scale(void);
		int get_num_vertices();
		int get_num_faces();
		void set_num_vertices(int num_vertices);
		void set_num_faces(int num_faces);
		void AddChild(object *child);
		void RemoveChild(object *child);
		void EnableAxes(bool show_axes);
		void EnableOrigin(bool show_origin);
		void AddFrame(void);
		void RemoveFrame(frame *frame);
};

#endif // OBJECT_H
