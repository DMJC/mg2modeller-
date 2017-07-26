#ifndef CALLBACKS_H
#define CALLBACKS_H
#include "../gui.h"
#include "../scene.h"
#include <string>
extern "C" {
    void quit_cb(Gtk::Application app);

    void file_new_cb (void);

    void file_open_scene_cb (void);

    void file_open_cb (void);

    void file_save_cb (string filename);

    void file_saveas_cb (void);
}
#endif //CALLBACKS_H
