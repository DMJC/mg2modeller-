#include "mg2toolbutton.h"
#include "edit_tools.h"

using namespace std;

int main(int argc, char *argv[]){
	cout << "test button" << endl;
	auto app = Gtk::Application::create(argc, argv, "test");

	list<tool> tool_list = {
	    { "Edit Vertex" , "Selects Object Vertex Mode" , "pix/tool_edit_vertex.xpm", nullptr, nullptr, nullptr, nullptr },
	    { "Edit Edge" , "Selects Object Edge Mode" , "pix/tool_edit_edge.xpm", nullptr, nullptr, nullptr, nullptr },
	    { "Edit Face" , "Selects Object Face Mode" , "pix/tool_edit_face.xpm", nullptr, nullptr, nullptr, nullptr },
	    { "Edit Object" , "Selects Object Mode" , "pix/tool_edit_object.xpm", nullptr, nullptr, nullptr, nullptr },
	    { "Extrude" , "Extrudes Object Faces" , "pix/tool_edit_extrude.xpm", nullptr, nullptr, nullptr, nullptr },
    	    { "Rotate" , "Rotate Object/Face/Edge" , "pix/tool_edit_rotate.xpm", nullptr, nullptr, nullptr, nullptr },
	    { "Translate" , "Scale Object/Face/Edge" , "pix/tool_edit_scale.xpm", nullptr, nullptr, nullptr, nullptr },
	    { "Scale" , "Translate Object/Face/Edge/Vertex" , "pix/tool_edit_trans.xpm", nullptr, nullptr, nullptr, nullptr }
	};
/*
	tool_list.push_back({ "Scale" , "Translate Object/Face/Edge/Vertex" , "pix/tool_edit_trans.xpm" });
*/
	Gtk::Window testwindow;
	ToolButton testbutton = ToolButton(tool_list);
	int start_time = 0;
	int finish_time = 0;
	testwindow.set_default_size(32, 24);
	testwindow.set_decorated(false);
	testwindow.add(testbutton);
	testwindow.show();
	return app->run(testwindow);
}
