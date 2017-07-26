#include "../include/texture.h"

void texture::set_coordinates(float X, float Y, float Z)
{
	if (X != 0 ){
		this -> coordinates[0] = X;
	}
	if (Y != 0 ){
		this -> coordinates[1] = Y;
	}
	if (Z != 0 ){
		this -> coordinates[2] = Z;
	}
}

void texture::set_material(material mat)
{
	this -> mat = mat;
}

float* texture::get_coordinates(void)
{
	return this -> coordinates;
}

material texture::get_material(void)
{
	return this -> mat;
}