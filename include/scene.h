#ifndef SCENE_H
#define SCENE_H
#include "preferences.h"
#include "guide.h"
#include "mg2.h"
#include "nurbs.h"
#include "animation.h"
//#include "gui.h"

class ts_gui;

class scene
{
		public:
		object previous_object;
		object current_object;
		list<object> object_list;
		list<guide> guide_list;
		list<frame> frames_list;
		preferences prefs;
		object GetCurrentObject(void);
		object GetPrevObject(void);
		scene();
		void SetCurrentObject(object obj);
		void SetPrevObject(object obj);
		void AddObject(object new_object);
		void DeleteObject(int object_to_delete);
		void Draw_Axes(void);
		void Draw_Solid_Grid(preferences &prefs);
		void Draw_Wire_Grid(preferences &prefs);
		void Draw_As_Wireframe(preferences &prefs);
		void Draw_As_Solid(preferences &prefs);
		void Set_Current_Object(object obj);
		void Bind_Preferences(preferences &prefs);
		void AddFrame(frame new_frame);
		void RemoveFrame(int frame_to_delete);
		virtual ~scene(){};
};
#endif // SCENE_H

