#ifndef SCENE_H
#define SCENE_H
#include "preferences.h"
#include "guide.h"
#include "mg2.h"
#include "nurbs.h"
#include "animation.h"
#include "gl_toolbar.h"
#include <memory>
#include <set>

class ts_gui;

struct lod_group {
	string name;
	list<shared_ptr<object>> members;
};

class scene
{
		public:
		ts_gui *curr_gui = nullptr;
		shared_ptr<object> current_object;
		shared_ptr<object> previous_object;
		list<shared_ptr<object>> object_list;
		std::set<shared_ptr<object>> selected_objects;
		list<lod_group> lod_groups;
		list<guide> guide_list;
		list<frame> frames_list;
		preferences prefs;
		shared_ptr<object> GetCurrentObject(void);
		shared_ptr<object> GetPrevObject(void);
		int current_tool = 0;
		int current_edit_mode = 0;
		int current_draw_mode = 1;
		int hierarchy_level = 0;
		shared_ptr<object> clipboard;
		GLToolbar view_object_toolbar;
		GLToolbar main_toolbar;
		GLToolbar object_toolbar;
		std::vector<std::list<tool>*> owned_tool_lists;
		scene();

		void SetGui(ts_gui *curr_gui);
		ts_gui *GetGui(void);
		void SetCurrentObject(shared_ptr<object> obj);
		void SetPrevObject(shared_ptr<object> obj);
		void AddObject(shared_ptr<object> new_object);
		void DeleteObject(shared_ptr<object> obj);
		void Draw_Axes(void);
		void Draw_Solid_Grid(preferences &prefs);
		void Draw_Wire_Grid(preferences &prefs);
		void Draw_As_Wireframe(preferences &prefs);
		void Draw_As_Solid(preferences &prefs);
		void Set_Current_Object(shared_ptr<object> obj);
		void Bind_Preferences(preferences &prefs);
		void AddFrame(frame new_frame);
		void RemoveFrame(int frame_to_delete);
		int Get_Current_Tool(void);
		void Set_Current_Tool(int curr_tool);
		int Get_Edit_Mode(void);
		void Set_Edit_Mode(int mode);
		shared_ptr<object> GetObjectByIndex(int index);
		void SelectObject(shared_ptr<object> obj, bool shift);
		bool IsSelected(shared_ptr<object> obj);
		void ClearSelection();
		lod_group* FindLodGroup(shared_ptr<object> obj);
		shared_ptr<object> FindObjectPtr(object* raw);
		shared_ptr<object> GetGroupRoot(shared_ptr<object> obj);
		void CollectGroupMembers(shared_ptr<object> obj, std::set<shared_ptr<object>>& out);
		virtual ~scene(){};
};
#endif // SCENE_H
