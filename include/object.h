#ifndef OBJECT_H
#define OBJECT_H
#include <string>
#include <list>
#include <set>
#include <memory>
#include <epoxy/gl.h>
#include "animation.h"
#include "geometry.h"
#include "texture.h"
#include "material.h"
#include "mesh.h"

using namespace std;

enum type_of_object { LIGHT, PRIMITIVE, CAMERA, PANORAMIC };

class object
{
	protected:
		double location[3] = { 0.0, 0.0, 0.0 };
		float rotation[3] = { 0.0, 0.0, 0.0 };
		float scale[3] = { 1.0, 1.0, 1.0 };
		string name;
		float selected_color[3] = { 1.0, 1.0, 1.0 };
		float unselected_color[3] = { 0.75, 0.75, 0.75 };
		type_of_object object_type;
		int num_vertices = 0;
		int num_edges = 0;
		int num_faces = 0;
		int num_frames = 0;
		/////////// Hierarcy
		bool is_parent_only = false;
		object *parent = nullptr;
		list<shared_ptr<object>> children;
		list<shared_ptr<object>> sibling;
		/////////// Geometry
		list<vertex> vertices;
		list<edge> edges;
		list<face> faces;
		list<normal> normals;
		float origin[3] = { 0.0, 0.0, 0.0 };
		bool show_axes = false;
		object_axes axes;
		bool show_origin = false;
		float compensation[16];
		float rot_origin[16];
		/////////// Animation
		frame *curr_frame = nullptr;
		list<frame> frames;
		/////////// GPU
		Mesh mesh;
		/////////// Sub-element selection
		std::set<int> selected_vertices;
		std::set<int> selected_edges;
		std::set<int> selected_faces;

	public:
		object();
		virtual ~object();
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
		void add_child(shared_ptr<object> child);
		void remove_child(shared_ptr<object> child);
		void add_sibling(shared_ptr<object> sib);
		void remove_sibling(shared_ptr<object> sib);
		object* get_parent();
		void set_parent(object* p);
		list<shared_ptr<object>>& get_children();
		list<shared_ptr<object>>& get_siblings();
		void enable_axes(bool state);
		bool get_show_axes(void);
		void enable_origin(bool state);
		void add_frame(void);
		void remove_frame(frame *frame);

		virtual shared_ptr<object> clone();
		virtual void generateMesh();
		void buildModelMatrix(float* out);
		Mesh& getMesh();
		list<vertex>& getVertices();
		list<face>& getFaces();
		float* getSelectedColor();
		float* getUnselectedColor();
		void setSelectedColor(float r, float g, float b);
		void setUnselectedColor(float r, float g, float b);

		void clearSubSelection();
		void selectFace(int idx, bool shift);
		void selectEdge(int idx, bool shift);
		void selectVertex(int idx, bool shift);
		const std::set<int>& getSelectedFaces() const;
		const std::set<int>& getSelectedEdges() const;
		const std::set<int>& getSelectedVertices() const;
};

#endif // OBJECT_H
