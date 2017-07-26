#include "../include/render.h"

render::render (void){
	this->mode = 0;
	this->frames = 0;
}
	
void render::set_render_mode(int mode){
	this->mode = mode;
}

int render::get_render_mode(void){
	return this->mode;
}

void render::set_render_frames(int frames){
	this->frames = frames;
}

int render::get_render_frames(void){
	return this->frames;
}

void render::run_render(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.5, 0.5, 0.5, 1);
	glFlush();
}
