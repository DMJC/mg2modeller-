#include "../include/scene.h"

object scene::GetCurrentObject(void){
	return this -> current_object;
}

object scene::GetPrevObject(void){
	return this -> previous_object;
}

void scene::SetCurrentObject(object obj){
	this -> current_object = obj;
}

void scene::SetPrevObject(object obj){
	this -> previous_object = obj;
}

void scene::AddObject(object obj){
//	this->object_list.append(obj);
}

void scene::DeleteObject(int object_to_delete){
//	this->object_list.delete(object_number);

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

void scene::AddFrame(frame new_frame){
//	this->frame_list.append(new_frame);
}

void scene::RemoveFrame(int frame_to_delete){
//	this->frame_list.delete(frame_to_delete);
}

