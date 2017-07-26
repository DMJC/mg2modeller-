#ifndef TSGUI_H
#define TSGUI_H
#include "../gui.h"
#include "../scene.h"
#include "callbacks.h"
#include "tsgui_callbacks.h"

class ts_gui : public gui
{
private:

public:
	void make_gui(preferences &prefs, scene &scene);
};
#endif //TSGUI_H
