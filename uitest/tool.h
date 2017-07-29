#ifndef TOOL_H
#define TOOL_H
#include <string>
#include <gtkmm.h>
using namespace std;
struct tool{
    string name;
    string tooltip;
    string image_filename;
    void (*left_click_callback)(void);
    void (*right_click_callback)(void);
    void (*long_left_click_callback)(void);
    void (*long_right_click_callback)(void);
};
#endif //TOOL_H
