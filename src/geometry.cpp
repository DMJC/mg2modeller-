#include "../include/geometry.h"

float* edge::get_location()
{
	return this -> location;
}

vertex::vertex(float X, float Y, float Z){
    this -> location[0] = X;
    this -> location[1] = Y;
    this -> location[2] = Z;
    this -> color[0] = 1.0;
    this -> color[1] = 1.0;
    this -> color[2] = 1.0;
}

/*edge::edge(vertex vert1, vertex vert2)
{
    this->v1 = vert1;
    this->v2 = vert2;
//    this->set_color(0.0, 0.0, 0.0);
}*/

void edge::set_location(float X, float Y, float Z)
{
	this -> location[0] = X;
	this -> location[1] = Y;
	this -> location[2]	= Z;
}

float* vertex::get_location()
{
	return this -> location;
}

void vertex::set_location(float X, float Y, float Z)
{
	this -> location[0] = X;
	this -> location[1] = Y;
	this -> location[2]	= Z;
}

void face::add_vertex_to_face(vertex selected_vertex, int position)
{
//    this -> vertices.insert (vertex_to_insert);
}
void face::add_vertex_to_face(vertex vertex_to_insert)
{
    this -> vertices.push_back (vertex_to_insert);
}

void face::add_edge_to_face(edge edge_to_insert, int position)
{
	
}

void face::add_edge_to_face(edge edge_to_insert)
{
	
}

void face::del_vertex_from_face(vertex, face)
{
	
}

void face::del_edge_from_face(edge, face)
{
	
}

void face::set_num_vertices(int num_vertices)
{
	this -> num_vertices = num_vertices;
}

void face::set_num_edges(int num_edges)
{
	this -> num_edges = num_edges;
}

int face::get_num_vertices(void)
{
	return this -> num_vertices;
}

int face::get_num_edges(void)
{
	return this -> num_edges;
}

void face::set_location(float X, float Y, float Z)
{
	this -> location[0] = X;
	this -> location[1] = Y;
	this -> location[2] = Z;
}

float* face::get_location()
{
	return this -> location;
}

void face::set_rotation(float X, float Y, float Z){
	this -> rotation[0] = X;
	this -> rotation[1] = Y;
	this -> rotation[2] = Z;
}

float* face::get_rotation()
{
	return this -> rotation;
}

void face::set_scale(float X, float Y, float Z)
{
	this -> scale[0] = X;
	this -> scale[1] = Y;
	this -> scale[2] = Z;
}

float* face::get_scale()
{
	return this -> scale;
}
