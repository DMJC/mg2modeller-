#ifndef SCENE_H
#define SCENE_H
#include "preferences.h"
#include "guide.h"
#include "mg2.h"
#include "nurbs.h"
#include "animation.h"
#include <memory>

class ts_gui;

class scene
{
		public:
		ts_gui *curr_gui = nullptr;
		shared_ptr<object> current_object;
		shared_ptr<object> previous_object;
		list<shared_ptr<object>> object_list;
		list<guide> guide_list;
		list<frame> frames_list;
		preferences prefs;
		shared_ptr<object> GetCurrentObject(void);
		shared_ptr<object> GetPrevObject(void);
		int current_tool = 0;
		int current_edit_mode = 0;
		int current_draw_mode = 1;
		shared_ptr<object> clipboard;
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
		virtual ~scene(){};
};
#endif // SCENE_H
