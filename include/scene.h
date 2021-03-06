#ifndef SCENE_H
#define SCENE_H
#include "preferences.h"
#include "guide.h"
#include "mg2.h"
#include "nurbs.h"
#include "animation.h"

class ts_gui;

class scene
{
		public:
		ts_gui *curr_gui;
		object previous_object;
		object current_object;
		list<object> object_list;
		list<guide> guide_list;
		list<frame> frames_list;
		preferences prefs;
		object GetCurrentObject(void);
		object GetPrevObject(void);
		int current_tool = 0;
		scene();
		
		void SetGui(ts_gui *curr_gui);
		ts_gui *GetGui(void);
		void SetCurrentObject(object obj);
		void SetPrevObject(object obj);
		void AddObject(object new_object);
		void DeleteObject(object obj);
		void Draw_Axes(void);
		void Draw_Solid_Grid(preferences &prefs);
		void Draw_Wire_Grid(preferences &prefs);
		void Draw_As_Wireframe(preferences &prefs);
		void Draw_As_Solid(preferences &prefs);
		void Set_Current_Object(object obj);
		void Bind_Preferences(preferences &prefs);
		void AddFrame(frame new_frame);
		void RemoveFrame(int frame_to_delete);
		int Get_Current_Tool(void);
		void Set_Current_Tool(int curr_tool);
		virtual ~scene(){};
};
#endif // SCENE_H

