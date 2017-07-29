#include <gtkmm.h>
#include <iostream>

using namespace std;

extern "C" {
    void on_button1_clicked() {
        cout << "Clicked" << endl;
    }
}

int main(int argc, char *argv[]) {
    Gtk::Main kit(argc, argv);

    Glib::RefPtr <Gtk::Builder> builder = Gtk::Builder::create_from_file("minimal.gtkbuilder");

    gtk_builder_connect_signals (builder->gobj(), NULL);


    Gtk::Window *mainWnd = 0;
    builder->get_widget("window1", mainWnd);
    Gtk::Main::run(*mainWnd);

    return 0;
}
