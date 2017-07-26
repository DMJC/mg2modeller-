#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "material.h"
#include "texture.h"
#include <vector>
using namespace std;

class face;
class edge;

struct object_axes
{
	float axes[3];
};

class vertex
{
	protected:
		float location[3];
		vector<edge> edges;
		vector<face> faces;
	public:
		void SetLocation(float X, float Y, float Z);
		float* GetLocation();
};

class face
{
	protected:
		float location[3];
		float rotation[3];
		float size[3];
		int num_edges;
		int num_vertices;
		vector<texture> textures;
		vector<vertex> polygons;
		vector<edge> edges;
		
	public:
		void SetNumVertices(int num_vertices);
		void SetNumEdges(int num_edges);
		int GetNumVertices(void);
		int GetNumEdges(void);
		void SetLocation(float X, float Y, float Z);
		float* GetLocation();
		void SetRotation(float X, float Y, float Z);
		float* GetRotation();
		void SetSize(float X, float Y, float Z);
		float* GetSize();
		void AddVertexToFace(vertex);
		void AddEdgeToFace();
		void DelVertexFromFace(face);
		void DelEdgeFromFace(face);
};

class edge
{
	protected:
		vector<face> faces;
		vertex v1;
		vertex v2;
		float location[3];
		float scale[3];
	public:
		float* GetLocation(void);
		void SetLocation(float X, float Y, float Z);
		float* GetScale(void);
		void SetScale(float X, float Y, float Z);
};


#endif