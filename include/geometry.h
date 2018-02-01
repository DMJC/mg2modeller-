#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "material.h"
#include "texture.h"
#include <vector>
class face;
class edge;

struct object_axes
{
	int axes[3];
};



class vertex
{
	protected:
		float location[2];
		float color[2];
	public:
        vertex(float X, float Y, float Z);
		void set_color(float X, float Y, float Z);
		int* get_color();
		void set_location(float X, float Y, float Z);
		float* get_location();
};

class normal 
{
	protected:
	public:
	
};

class edge
{
	protected:
//		vector<face> faces;
		vertex v1;
		vertex v2;
		float location[2];
		float rotation[2];
		float scale[2];
		int color[2];
	public:
	    edge(vertex vert1, vertex vert2);
		void set_color(float X, float Y, float Z);
		int* get_color();
		float* get_location(void);
		void set_location(float X, float Y, float Z);
		float* get_scale(void);
		void set_scale(float X, float Y, float Z);
};

class face
{
	protected:
		int type;					//0 = triangle, 1 = quad, 2 = polygon.
		int num_edges;
		int num_vertices;
		int color[2];
		normal face_normal;
		float location[2];
		float rotation[2];
		float scale[2];
		vector<texture> textures; 	//not sure if vector is correct or if pointer should be used.
		vector<vertex> vertices;
		vector<edge> edges;

	public:
	    face();
		void set_color(int X, int Y, int Z);
		int* get_color();
		void set_num_vertices(int num_vertices);
		void set_num_edges(int num_edges);
		int get_num_vertices(void);
		int get_num_edges(void);
		void set_location(float X, float Y, float Z);
		float* get_location();
		void set_rotation(float X, float Y, float Z);
		float* get_rotation();
		void set_scale(float X, float Y, float Z);
		float* get_scale();
		void add_vertex_to_face(vertex vertex_to_insert, int position);
		void add_vertex_to_face(vertex vertex_to_insert);
		void add_edge_to_face(edge edge_to_insert);
		void add_edge_to_face(edge edge_to_insert, int position);
		void del_vertex_from_face(vertex, face);
		void del_edge_from_face(edge, face);
};

#endif
