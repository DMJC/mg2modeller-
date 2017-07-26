#ifndef TOOLS_H
#define TOOLS_H
#include "mg2.h"

class tool
{
	protected:
		string name;
		string icon;
		string tooltip;
		int* right_click_action;
		int* left_click_action;
	public:
		void create_tool( string name, string icon, string tooltip, int* right_click_action, int* left_click_action );
};
#endif // TOOLS_H
