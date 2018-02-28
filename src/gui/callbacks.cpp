#include "../../include/gui/callbacks.h"
//file contains callbacks universal to both tds/ts style interfaces.
extern "C" {
    void quit_cb (Gtk::Application app){
        cout << "Have we saved recently?" << endl;
		
		cout << "Quitting" << endl;
		app.quit();
    }

	void file_new_cb (void){
	    cout << "Creating New Scene File" << endl;
		
    }
    void file_open_scene_cb (void){
    	cout << "Opening Scene" << endl;
    }
    void file_open_cb (void){
	    cout << "Opening File" << endl;
    }
	void file_save_cb (string filename){
	    cout << "Saving File" << endl;
    }
	void file_saveas_cb (void){
	    cout << "Saving File As" << endl;
    }
}
