#ifndef GUI_H
#define GUI_H
#include "mg2.h"
#include "scene.h"
#include "tools.h"
#include "view.h"

class gui
{
	protected:
		double location[3];
		float rotation[3];
		float scale[3];
		Glib::RefPtr<Gtk::Builder> builder;
		Glib::RefPtr<Gtk::Application> app = Gtk::Application::create("MG2modeller++");

	public:
		void make_gui(preferences &prefs, scene &scene);
		virtual ~gui();
		void setbuilder(string);

		void setlocation(double X, double Y, double Z);
		void setrotation(float X, float Y, float Z);
		void setscale(float X, float Y, float Z);
		double* getlocation(void);
		float* getrotation(void);
		float* getscale(void);
		int quit(void);
};

#endif // GUI_H
