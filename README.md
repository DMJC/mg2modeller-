# mg2modeller++
A 3d modeller inspired by Caligari Truespace and another popular 3d modelling tool. Written in GTK and C++.

Development Notes:
Primarily developed using CodeLite IDE, can be built using either the CLI or CodeLite. Simply type Make in the toplevel. Requirs GTKMM 3.0, and glade/gtkbuilder.

Coding Style:
Indentation should use four spaces. Callback functions are declared using extern "C". This is to work around a limitation with gtkbuilder files and C++.

