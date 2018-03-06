#include "../include/gui.h"

void gui::make_gui(preferences &prefs, scene &scene)
{
	cout << "Opening Glade File: " << endl;
	this -> builder = Gtk::Builder::create_from_file("src/gui.gtkbuilder");
	cout << "File opened, now testing contents: " << endl;
};

gui::~gui()
{

}

void gui::setbuilder(string filename)
{
	this -> builder = Gtk::Builder::create_from_file(filename);
}

void gui::setlocation(double X, double Y, double Z)
{
	this -> location[0] = X;
	this -> location[1] = Y;
	this -> location[2] = Z;
}

void gui::setrotation(float X, float Y, float Z)
{
	this -> rotation[0] = X;
	this -> rotation[1] = Y;
	this -> rotation[2] = Z;
}

void gui::setscale(float X, float Y, float Z)
{
	this -> scale[0] = X;
	this -> scale[1] = Y;
	this -> scale[2] = Z;
}

double* gui::getlocation(void)
{
	return this -> location;
}

float* gui::getrotation(void)
{
	return this -> rotation;
}

float* gui::getscale(void)
{
	return this -> scale;
}

int gui::quit(void)
{
	cout << "Closing Application." << endl;
	this -> app->quit();
	return 0;
};
