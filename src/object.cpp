#include "../include/object.h"

GLuint wireframe_object_bo;

void object::set_name(string name){
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

void object::set_rotation(double rot_X, double rot_Y, double rot_Z)
{
	this -> rotation[0] = rot_X;
	this -> rotation[1] = rot_Y;
	this -> rotation[2] = rot_Z;
}

void object::set_scale(double sca_X, double sca_Y, double sca_Z)
{
	this -> scale[0] = sca_X;
	this -> scale[1] = sca_Y;
	this -> scale[2] = sca_Z;
}

int* object::get_location()
{
	return this -> location;
}

int* object::get_rotation()
{
	return this -> rotation;
}

int* object::get_scale()
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

void object::AddChild(object *child){}

void object::RemoveChild(object *child){}

void object::EnableAxes(bool show_axes){}

void object::EnableOrigin(bool show_origin){}

void object::AddFrame(void){}

void object::RemoveFrame(frame *frame){}
