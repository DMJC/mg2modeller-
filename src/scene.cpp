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
	SelectObject(obj, false);
	if (curr_gui)
		curr_gui->update_object_info(*this);
}

void scene::DeleteObject(shared_ptr<object> obj){
	cout << "deleting " << obj->get_name() << " from scene" << endl;
	selected_objects.erase(obj);
	if (current_object == obj) {
		current_object = selected_objects.empty() ? nullptr : *selected_objects.begin();
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

void scene::SelectObject(shared_ptr<object> obj, bool shift){
	if (!obj) {
		if (!shift) {
			selected_objects.clear();
			SetCurrentObject(nullptr);
		}
		return;
	}

	bool is_grouped = (obj->get_parent() ||
					   !obj->get_children().empty() ||
					   !obj->get_siblings().empty());

	if (hierarchy_level == 0 && is_grouped) {
		auto root = GetGroupRoot(obj);
		std::set<shared_ptr<object>> members;
		CollectGroupMembers(root, members);

		if (shift) {
			bool all_selected = true;
			for (auto& m : members) {
				if (!selected_objects.count(m)) { all_selected = false; break; }
			}
			if (all_selected) {
				for (auto& m : members) selected_objects.erase(m);
				if (selected_objects.count(current_object) == 0)
					current_object = selected_objects.empty() ? nullptr : *selected_objects.begin();
			} else {
				for (auto& m : members) selected_objects.insert(m);
				SetCurrentObject(root);
			}
		} else {
			selected_objects.clear();
			for (auto& m : members) selected_objects.insert(m);
			SetCurrentObject(root);
		}
	} else {
		if (shift) {
			if (selected_objects.count(obj)) {
				selected_objects.erase(obj);
				if (current_object == obj) {
					current_object = selected_objects.empty() ? nullptr : *selected_objects.begin();
				}
			} else {
				selected_objects.insert(obj);
				SetCurrentObject(obj);
			}
		} else {
			selected_objects.clear();
			selected_objects.insert(obj);
			SetCurrentObject(obj);
		}
	}
}

bool scene::IsSelected(shared_ptr<object> obj){
	return selected_objects.count(obj) > 0;
}

void scene::ClearSelection(){
	selected_objects.clear();
	current_object = nullptr;
}

lod_group* scene::FindLodGroup(shared_ptr<object> obj){
	for (auto& grp : lod_groups) {
		for (auto& m : grp.members) {
			if (m == obj) return &grp;
		}
	}
	return nullptr;
}

shared_ptr<object> scene::FindObjectPtr(object* raw){
	if (!raw) return nullptr;
	for (auto& obj : object_list) {
		if (obj.get() == raw) return obj;
	}
	return nullptr;
}

shared_ptr<object> scene::GetGroupRoot(shared_ptr<object> obj){
	if (!obj) return nullptr;
	object* raw = obj.get();
	while (raw->get_parent()) {
		raw = raw->get_parent();
	}
	auto root = FindObjectPtr(raw);
	return root ? root : obj;
}

void scene::CollectGroupMembers(shared_ptr<object> obj, std::set<shared_ptr<object>>& out){
	if (!obj || out.count(obj)) return;
	out.insert(obj);
	for (auto& child : obj->get_children())
		CollectGroupMembers(child, out);
	for (auto& sib : obj->get_siblings())
		CollectGroupMembers(sib, out);
}
