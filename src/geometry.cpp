#include "../include/geometry.h"

float* edge::GetLocation()
{
	return this -> location;
}

void edge::SetLocation(float X, float Y, float Z)
{
	this -> location[0] = X;
	this -> location[1] = Y;
	this -> location[2]	= Z;
}

float* vertex::GetLocation()
{
	return this -> location;
}

void vertex::SetLocation(float X, float Y, float Z)
{
	this -> location[0] = X;
	this -> location[1] = Y;
	this -> location[2]	= Z;
}


void face::AddVertexToFace(vertex selected_vertex)
{
//	this -> vector.add
}

void face::AddEdgeToFace()
{
	
}

void face::DelVertexFromFace(face selected_face)
{
	
}

void face::DelEdgeFromFace(face selected_face)
{
	
}

void face::SetNumVertices(int num_vertices)
{
	this -> num_vertices = num_vertices;
}

void face::SetNumEdges(int num_edges)
{
	this -> num_edges = num_edges;
}

int face::GetNumVertices(void)
{
	return this -> num_vertices;
}

int face::GetNumEdges(void)
{
	return this -> num_edges;
}

void face::SetLocation(float X, float Y, float Z)
{
	this -> location[0] = X;
	this -> location[1] = Y;
	this -> location[2] = Z;
}

float* face::GetLocation()
{
	return this -> location;
}

void face::SetRotation(float X, float Y, float Z){
	this -> rotation[0] = X;
	this -> rotation[1] = Y;
	this -> rotation[2] = Z;
}

float* face::GetRotation()
{
	return this -> rotation;
}

void face::SetSize(float X, float Y, float Z)
{
	this -> size[0] = X;
	this -> size[1] = Y;
	this -> size[2] = Z;
}

float* face::GetSize()
{
	return this -> size;
}