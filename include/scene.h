#ifndef SCENE_H
#define SCENE_H
#include "mg2.h"
#include "object.h"
#include "animation.h"

class scene
{
	protected:
		object prev_object;
		object cur_object;
		list<object> object_list;
		list<frame> frames_list;
		preferences prefs;

	public:
//		iostream file;
		object GetCurrentObject(void);
		object GetPrevObject(void);
		void SetCurrentObject(object obj);
		void SetPrevObject(object obj);
		void AddObject(void);
		void DeleteObject(object obj);
        	void Draw_Axes(void);
        	void Draw_Solid_Grid(preferences &prefs);
        	void Draw_Wire_Grid(preferences &prefs);
        	void Draw_As_Wireframe(preferences &prefs);
        	void Draw_As_Solid(preferences &prefs);
        	void Set_Current_Object(object obj);
        	void Bind_Preferences(preferences &prefs);
		void AddFrame(void);
		void RemoveFrame(frame *frame);
		virtual ~scene(){};
};
#endif // SCENE_H

