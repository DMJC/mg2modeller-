#include "../include/animation.h"

void frame::set_look_at_point(bool look_at_point, int X, int Y, int Z)
{
	this -> look_at_point = true;
	if (X != 0){
		this -> lookat[0] = X;
	}
	if (Y != 0){
		this -> lookat[1] = Y;
	}
	if (Z != 0){
		this -> lookat[2] = Z;
	}
}

void frame::unset_look_at_point(bool look_at_point)
{
	this -> look_at_point = false;
}

void frame::set_rotation(float rotation[16])
{
	
}

void frame::set_translation(int X, int Y, int Z)
{
	if (X != 0){
		this -> translate[0] = X;
	}
	if (Y != 0){
		this -> translate[1] = Y;
	}
	if (Z != 0){
		this -> translate[2] = Z;
	}
}

void frame::set_scale(int X, int Y, int Z)
{
	if (X != 0){
		this -> scale[0] = X;
	}
	if (Y != 0){
		this -> scale[1] = Y;
	}
	if (Z != 0){
		this -> scale[2] = Z;
	}
}

float* frame::get_rotate(void)
{
	return this->rotate;
}

float* frame::get_translate(void)
{
	return this -> translate;
}

float* frame::get_scale(void)
{
	return this -> scale;
}