#ifndef VIEW_H
#define VIEW_H
#include "gui.h"
#include "mg2.h"

using namespace std;

enum view_type { TOP_VIEW, BOTTOM_VIEW, LEFT_VIEW, RIGHT_VIEW, FRONT_VIEW, BACK_VIEW, CAMERA_VIEW, PERSPECTIVE_VIEW };
enum draw_type {SOLID_VIEW, WIREFRAME_VIEW, TRANSPARENT_SOLID_VIEW, TRANSPARENT_WIREFRAME_VIEW };

class view : public Gtk::Grid {
protected:
	Gtk::GLArea mGlArea;
	void onRealize();
    void onUnrealize();
    bool onRender(const Glib::RefPtr<Gdk::GLContext>& context, int view_type, int draw_type);
	
public:
	view(int view_type, int draw_type, scene);
};

#endif // VIEW_H
