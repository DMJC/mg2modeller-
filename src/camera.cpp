#include "../include/camera.h"

void camera::SetCameraName(string name)
{
	this -> name = name;
	
}

void camera::SetCameraType(int camera_type)
{
	this -> type = camera_type;
}

void panoramic_camera::set_mode(bool mode)
{
	this -> mode = mode;
}

void panoramic_camera::set_quality(float quality)
{
	this -> quality = quality;
}

void panoramic_camera::set_pan_frames(int frames)
{
	this -> pan_frames = frames;
}

void panoramic_camera::set_pan_min(int min)
{
	this -> pan_min = min;
}

void panoramic_camera::set_pan_max(int max)
{
	this -> pan_max = max;
}

void panoramic_camera::set_pan_init(int pan_init)
{
	this -> pan_init = pan_init;
}

void panoramic_camera::set_tilt_frames(int tilt_frames)
{
	this -> tilt_frames = tilt_frames;
}

void panoramic_camera::set_tilt_min(int min)
{
	this -> tilt_min = min;
}

void panoramic_camera::set_tilt_max(int max)
{
	this -> tilt_max = max;
}

void panoramic_camera::set_tilt_init(int tilt_init)
{
	this -> tilt_init = tilt_init;
}

bool panoramic_camera::get_mode(void)
{
	return this -> mode;
}

float panoramic_camera::get_quality(void)
{
	return this -> quality;
}

int panoramic_camera::get_pan_frames(void)
{
	return this -> pan_frames;
}

int panoramic_camera::get_pan_min(void)
{
	return this -> pan_min;
}

int panoramic_camera::get_pan_max(void)
{
	return this -> pan_max;
}

int panoramic_camera::get_pan_init(void)
{
	return this -> pan_init;
}

int panoramic_camera::get_tilt_frames(void)
{
	return this -> tilt_frames;
}

int panoramic_camera::get_tilt_min(void)
{
	return this -> tilt_min;
}

int panoramic_camera::get_tilt_max(void)
{
	return this -> tilt_max;
}

int panoramic_camera::get_tilt_init(void)
{
	return this -> tilt_init;
}