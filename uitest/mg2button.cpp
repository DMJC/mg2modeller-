#include "mg2buttonmenu.h"
#include <list>
#include <gtkmm.h>

class ButtonMenu : public Gtk::Button
{
protected:
    Gtk::Menu *menu;
    Gtk::Button *button;
    Gtk::Image *image;
public:
    void left_click();
    void right_click();
    void hold_left_click();
    void hold_right_click();
    void set_button(Gtk::Image *image);
};
£endif //BUTTONMENU_H

