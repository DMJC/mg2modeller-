#include "../include/gui/tsgui.h"
#include "../include/scene.h"


scene::scene(){
	
}
/*scene::scene(gui app_gui){
	this -> gui = app_gui;
}

void scene::set_gui(gui app_gui){
		this -> gui = app_gui;
}*/

void scene::SetGui(ts_gui *curr_gui){
	this -> curr_gui = curr_gui;
}

ts_gui *scene::GetGui(void){
	return this -> curr_gui;
}

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
	cout << "adding " << obj.get_name() << " to scene" << endl;
	this->object_list.push_back(obj);
}

void scene::DeleteObject(object obj){
	cout << "deleting " /*<< obj.get_name()*/ << " from scene" << endl;
//	this->object_list.remove(obj);
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

int scene::Get_Current_Tool(void){
	return this->current_tool;
}


void scene::Set_Current_Tool(int curr_tool){
	this->current_tool = curr_tool;
}