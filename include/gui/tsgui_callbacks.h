#ifndef TSGUI_CALLBACKS_H
#define TSGUI_CALLBACKS_H
#include "../mg2.h"
extern "C" {
void file_new_cb(void);

void file_open_cb(void);

void file_save_cb(string filename);

void file_saveas_cb(void);
}

#endif //TSGUI_CALLBACKS_H
