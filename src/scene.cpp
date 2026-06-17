#include "../include/gui/tsgui.h"
#include "../include/scene.h"

scene::scene() {}

void scene::SetGui(ts_gui *curr_gui){
	this->curr_gui = curr_gui;
}

ts_gui *scene::GetGui(void){
	return this->curr_gui;
}

shared_ptr<object> scene::GetCurrentObject(void){
	return this->current_object;
}

shared_ptr<object> scene::GetPrevObject(void){
	return this->previous_object;
}

void scene::SetCurrentObject(shared_ptr<object> obj){
	this->previous_object = this->current_object;
	this->current_object = obj;
}

void scene::SetPrevObject(shared_ptr<object> obj){
	this->previous_object = obj;
}

void scene::AddObject(shared_ptr<object> obj){
	cout << "adding " << obj->get_name() << " to scene" << endl;
	float* sel = prefs.get_selected_color();
	float* unsel = prefs.get_unselected_color();
	obj->setSelectedColor(sel[0], sel[1], sel[2]);
	obj->setUnselectedColor(unsel[0], unsel[1], unsel[2]);
	this->object_list.push_back(obj);
	SetCurrentObject(obj);
	if (curr_gui)
		curr_gui->update_object_info(*this);
}

void scene::DeleteObject(shared_ptr<object> obj){
	cout << "deleting " << obj->get_name() << " from scene" << endl;
	if (current_object == obj) {
		current_object = nullptr;
	}
	this->object_list.remove(obj);
}

void scene::Draw_Axes(void) {}
void scene::Draw_Solid_Grid(preferences &prefs) {}
void scene::Draw_Wire_Grid(preferences &prefs) {}
void scene::Draw_As_Wireframe(preferences &prefs) {}
void scene::Draw_As_Solid(preferences &prefs) {}
void scene::Bind_Preferences(preferences &prefs) {}

void scene::AddFrame(frame new_frame) {}
void scene::RemoveFrame(int frame_to_delete) {}

int scene::Get_Current_Tool(void){
	return this->current_tool;
}

void scene::Set_Current_Tool(int curr_tool){
	this->current_tool = curr_tool;
}

int scene::Get_Edit_Mode(void){
	return this->current_edit_mode;
}

void scene::Set_Edit_Mode(int mode){
	this->current_edit_mode = mode;
}

shared_ptr<object> scene::GetObjectByIndex(int index){
	if (index < 0) return nullptr;
	int i = 0;
	for (auto& obj : object_list) {
		if (i == index) return obj;
		i++;
	}
	return nullptr;
}
