#include "include/mg2.h"
#include "include/scene.h"
#include "include/gui.h"
#include "include/gui/tsgui.h"
#include "include/gui/tdsgui.h"

using namespace std;

int main(){
	cout <<"Welcome to MG2 Modeller C++ Edition ;)\n";
	preferences prefs;
	prefs.load_preferences("preferences.ini");
	scene new_scene;
	/*load the GUI*/

	int interface_type = prefs.get_interface_type();

	if(interface_type == 1){
		ts_gui ts;
		ts.setbuilder("src/gui.gtkbuilder");
		ts.make_gui(prefs, new_scene);
	} else {
		tds_gui tds;
		tds.setbuilder("src/gui.gtkbuilder");
		tds.make_gui(prefs, new_scene);
	}
return 0;
}
