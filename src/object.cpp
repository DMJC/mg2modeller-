#include "../include/object.h"

GLuint wireframe_object_bo;

void object::set_object_type(type_of_object object_type){
	this -> object_type = object_type;
}

type_of_object object::get_object_type(void){
	return this -> object_type;		
}

void object::object::set_name(string name){
    this -> name = name;
}

string object::get_name(void){
    return this -> name;
}

void object::set_location(double loc_X, double loc_Y, double loc_Z)
{
	this -> location[0] = loc_X;
	this -> location[1] = loc_Y;
	this -> location[2] = loc_Z;
}

void object::set_rotation(float rot_X, float rot_Y, float rot_Z)
{
	this -> rotation[0] = rot_X;
	this -> rotation[1] = rot_Y;
	this -> rotation[2] = rot_Z;
}

void object::set_scale(float sca_X, float sca_Y, float sca_Z)
{
	this -> scale[0] = sca_X;
	this -> scale[1] = sca_Y;
	this -> scale[2] = sca_Z;
}

double* object::get_location()
{
	return this -> location;
}

float* object::get_rotation()
{
	return this -> rotation;
}

float* object::get_scale()
{
	return this -> scale;
}

int object::get_num_vertices()
{
	return this -> num_vertices;
}

int object::get_num_faces()
{
	return this -> num_faces;
}
void object::set_num_vertices(int num_vertices)
{
	this -> num_vertices = num_vertices;
}

void object::set_num_faces(int num_faces)
{
	this -> num_faces = num_faces;
}

void object::add_child(object *child)
{
	
}

void object::remove_child(object *child)
{
	
}

void object::add_sibling(object *sibling)
{
	
}

void object::remove_sibling(object *sibling)
{
	
}

void object::enable_axes(bool state)
{
	this -> show_axes = state;
}

void object::enable_origin(bool state)
{
	this -> show_origin = state;
}

void object::add_frame(void)
{
	
}

void object::remove_frame(frame *frame)
{
	
}
