#include "../include/scene.h"

object scene::GetCurrentObject(void){
	return this -> cur_object;
}

object scene::GetPrevObject(void){
	return this -> prev_object;
}

void scene::SetCurrentObject(object obj){
	this -> cur_object = obj;
}

void scene::SetPrevObject(object obj){
	this -> prev_object = obj;
}

void scene::AddObject(void){

}

void scene::DeleteObject(object obj){

}

void scene::Draw_Axes(void){

}

void scene::Draw_Solid_Grid(preferences &prefs){

}

void scene::Draw_Wire_Grid(preferences &prefs){

}

void scene::Draw_As_Wireframe(preferences &prefs){

}

void scene::Draw_As_Solid(preferences &prefs){

}

void scene::Bind_Preferences(preferences &prefs){

}

void scene::AddFrame(void){

}

void scene::RemoveFrame(frame *frame){

}

