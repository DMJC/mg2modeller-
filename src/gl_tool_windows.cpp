#include "../include/gl_tool_windows.h"
#include "../include/gl_widgets.h"
#include "../include/gl_window_manager.h"
#include <iostream>
#include <cstdio>

static void show_or_create(scene& sc, const std::string& name,
                           std::function<GLWindow*()> factory) {
    GLWindow* w = sc.window_manager.findWindow(name);
    if (!w) {
        w = factory();
        sc.window_manager.addWindow(w);
    }
    sc.window_manager.showWindow(name);
}

// Helper: two-row lat/long window
static GLWindow* make_lat_long_window(const std::string& name, const std::string& title,
    double lat_val, double lat_min, double long_val, double long_min,
    std::function<void(double)> on_lat, std::function<void(double)> on_long) {
    auto* w = new GLWindow(name, title, 180, 56);
    w->setPosition(100, 100);
    auto* l1 = new GLLabel("Latitude");  l1->setBounds(4, 4, 70, 22); w->addWidget(l1);
    auto* s1 = new GLSpinButton(lat_min, 9999, 1, 0, on_lat);
    s1->setBounds(80, 4, 90, 22); s1->setValue(lat_val); w->addWidget(s1);
    auto* l2 = new GLLabel("Longitude"); l2->setBounds(4, 30, 70, 22); w->addWidget(l2);
    auto* s2 = new GLSpinButton(long_min, 9999, 1, 0, on_long);
    s2->setBounds(80, 30, 90, 22); s2->setValue(long_val); w->addWidget(s2);
    return w;
}

// ============================================================
// Shape parameter windows
// ============================================================

void show_gl_plane_window(scene& sc) {
    show_or_create(sc, "gl_plane", [&]() {
        auto* w = new GLWindow("gl_plane", "Plane", 180, 30); w->setPosition(100, 100);
        auto* l = new GLLabel("Resolution"); l->setBounds(4, 4, 70, 22); w->addWidget(l);
        auto* s = new GLSpinButton(1, 9999, 1, 0, [&sc](double v){ sc.prefs.set_plane_resolution((int)v); });
        s->setBounds(80, 4, 90, 22); s->setValue(sc.prefs.get_plane_resolution()); w->addWidget(s);
        return w;
    });
    auto* w = sc.window_manager.findWindow("gl_plane");
    if (w) { auto* s = dynamic_cast<GLSpinButton*>(w->findWidget(1)); if (s) s->setValue(sc.prefs.get_plane_resolution()); }
}

void show_gl_cube_window(scene& sc) {
    show_or_create(sc, "gl_cube", [&]() {
        auto* w = new GLWindow("gl_cube", "Cube", 180, 30); w->setPosition(100, 100);
        auto* l = new GLLabel("Resolution"); l->setBounds(4, 4, 70, 22); w->addWidget(l);
        auto* s = new GLSpinButton(1, 9999, 1, 0, [&sc](double v){ sc.prefs.set_cube_resolution((int)v); });
        s->setBounds(80, 4, 90, 22); s->setValue(sc.prefs.get_cube_resolution()); w->addWidget(s);
        return w;
    });
    auto* w = sc.window_manager.findWindow("gl_cube");
    if (w) { auto* s = dynamic_cast<GLSpinButton*>(w->findWidget(1)); if (s) s->setValue(sc.prefs.get_cube_resolution()); }
}

void show_gl_geosphere_window(scene& sc) {
    show_or_create(sc, "gl_geosphere", [&]() {
        auto* w = new GLWindow("gl_geosphere", "GeoSphere", 180, 30); w->setPosition(100, 100);
        auto* l = new GLLabel("Resolution"); l->setBounds(4, 4, 70, 22); w->addWidget(l);
        auto* s = new GLSpinButton(0, 9999, 1, 0, [&sc](double v){ sc.prefs.set_geosphere_resolution((int)v); });
        s->setBounds(80, 4, 90, 22); s->setValue(sc.prefs.get_geosphere_resolution()); w->addWidget(s);
        return w;
    });
    auto* w = sc.window_manager.findWindow("gl_geosphere");
    if (w) { auto* s = dynamic_cast<GLSpinButton*>(w->findWidget(1)); if (s) s->setValue(sc.prefs.get_geosphere_resolution()); }
}

void show_gl_cone_window(scene& sc) {
    show_or_create(sc, "gl_cone", [&]() {
        return make_lat_long_window("gl_cone", "Cone",
            sc.prefs.get_cone_latitude(), 1, sc.prefs.get_cone_longitude(), 3,
            [&sc](double v){ sc.prefs.set_cone_latitude((int)v); },
            [&sc](double v){ sc.prefs.set_cone_longitude((int)v); });
    });
    auto* w = sc.window_manager.findWindow("gl_cone");
    if (w) { auto* s1 = dynamic_cast<GLSpinButton*>(w->findWidget(1)); auto* s2 = dynamic_cast<GLSpinButton*>(w->findWidget(3));
        if (s1) s1->setValue(sc.prefs.get_cone_latitude()); if (s2) s2->setValue(sc.prefs.get_cone_longitude()); }
}

void show_gl_sphere_window(scene& sc) {
    show_or_create(sc, "gl_sphere", [&]() {
        return make_lat_long_window("gl_sphere", "Sphere",
            sc.prefs.get_sphere_latitude(), 2, sc.prefs.get_sphere_longitude(), 3,
            [&sc](double v){ sc.prefs.set_sphere_latitude((int)v); },
            [&sc](double v){ sc.prefs.set_sphere_longitude((int)v); });
    });
    auto* w = sc.window_manager.findWindow("gl_sphere");
    if (w) { auto* s1 = dynamic_cast<GLSpinButton*>(w->findWidget(1)); auto* s2 = dynamic_cast<GLSpinButton*>(w->findWidget(3));
        if (s1) s1->setValue(sc.prefs.get_sphere_latitude()); if (s2) s2->setValue(sc.prefs.get_sphere_longitude()); }
}

void show_gl_rounded_cube_window(scene& sc) {
    show_or_create(sc, "gl_rounded_cube", [&]() {
        return make_lat_long_window("gl_rounded_cube", "Rounded Cube",
            sc.prefs.get_rounded_cube_latitude(), 1, sc.prefs.get_rounded_cube_longitude(), 1,
            [&sc](double v){ sc.prefs.set_rounded_cube_latitude((int)v); },
            [&sc](double v){ sc.prefs.set_rounded_cube_longitude((int)v); });
    });
    auto* w = sc.window_manager.findWindow("gl_rounded_cube");
    if (w) { auto* s1 = dynamic_cast<GLSpinButton*>(w->findWidget(1)); auto* s2 = dynamic_cast<GLSpinButton*>(w->findWidget(3));
        if (s1) s1->setValue(sc.prefs.get_rounded_cube_latitude()); if (s2) s2->setValue(sc.prefs.get_rounded_cube_longitude()); }
}

void show_gl_rounded_cylinder_window(scene& sc) {
    show_or_create(sc, "gl_rounded_cylinder", [&]() {
        return make_lat_long_window("gl_rounded_cylinder", "Rounded Cylinder",
            sc.prefs.get_rounded_cylinder_latitude(), 1, sc.prefs.get_rounded_cylinder_longitude(), 1,
            [&sc](double v){ sc.prefs.set_rounded_cylinder_latitude((int)v); },
            [&sc](double v){ sc.prefs.set_rounded_cylinder_longitude((int)v); });
    });
    auto* w = sc.window_manager.findWindow("gl_rounded_cylinder");
    if (w) { auto* s1 = dynamic_cast<GLSpinButton*>(w->findWidget(1)); auto* s2 = dynamic_cast<GLSpinButton*>(w->findWidget(3));
        if (s1) s1->setValue(sc.prefs.get_rounded_cylinder_latitude()); if (s2) s2->setValue(sc.prefs.get_rounded_cylinder_longitude()); }
}

void show_gl_cylinder_window(scene& sc) {
    show_or_create(sc, "gl_cylinder", [&]() {
        auto* w = new GLWindow("gl_cylinder", "Cylinder", 190, 82); w->setPosition(100, 100);
        auto* l1 = new GLLabel("Latitude");   l1->setBounds(4, 4, 80, 22);  w->addWidget(l1);
        auto* s1 = new GLSpinButton(1, 9999, 1, 0, [&sc](double v){ sc.prefs.set_cylinder_latitude((int)v); });
        s1->setBounds(90, 4, 90, 22); s1->setValue(sc.prefs.get_cylinder_latitude()); w->addWidget(s1);
        auto* l2 = new GLLabel("Longitude");  l2->setBounds(4, 30, 80, 22); w->addWidget(l2);
        auto* s2 = new GLSpinButton(3, 9999, 1, 0, [&sc](double v){ sc.prefs.set_cylinder_longitude((int)v); });
        s2->setBounds(90, 30, 90, 22); s2->setValue(sc.prefs.get_cylinder_longitude()); w->addWidget(s2);
        auto* l3 = new GLLabel("Top Radius"); l3->setBounds(4, 56, 80, 22); w->addWidget(l3);
        auto* s3 = new GLSpinButton(0, 9999, 0.01, 2, [&sc](double v){ sc.prefs.set_cylinder_top_radius((float)v); });
        s3->setBounds(90, 56, 90, 22); s3->setValue(sc.prefs.get_cylinder_top_radius()); w->addWidget(s3);
        return w;
    });
    auto* w = sc.window_manager.findWindow("gl_cylinder");
    if (w) { auto* s1 = dynamic_cast<GLSpinButton*>(w->findWidget(1)); auto* s2 = dynamic_cast<GLSpinButton*>(w->findWidget(3)); auto* s3 = dynamic_cast<GLSpinButton*>(w->findWidget(5));
        if (s1) s1->setValue(sc.prefs.get_cylinder_latitude()); if (s2) s2->setValue(sc.prefs.get_cylinder_longitude()); if (s3) s3->setValue(sc.prefs.get_cylinder_top_radius()); }
}

void show_gl_torus_window(scene& sc) {
    show_or_create(sc, "gl_torus", [&]() {
        auto* w = new GLWindow("gl_torus", "Torus", 195, 82); w->setPosition(100, 100);
        auto* l1 = new GLLabel("Latitude");     l1->setBounds(4, 4, 85, 22);  w->addWidget(l1);
        auto* s1 = new GLSpinButton(1, 100, 1, 0, [&sc](double v){ sc.prefs.set_torus_latitude((int)v); });
        s1->setBounds(95, 4, 90, 22); s1->setValue(sc.prefs.get_torus_latitude()); w->addWidget(s1);
        auto* l2 = new GLLabel("Longitude");    l2->setBounds(4, 30, 85, 22); w->addWidget(l2);
        auto* s2 = new GLSpinButton(1, 100, 1, 0, [&sc](double v){ sc.prefs.set_torus_longitude((int)v); });
        s2->setBounds(95, 30, 90, 22); s2->setValue(sc.prefs.get_torus_longitude()); w->addWidget(s2);
        auto* l3 = new GLLabel("Inner Radius"); l3->setBounds(4, 56, 85, 22); w->addWidget(l3);
        auto* s3 = new GLSpinButton(0, 9999, 0.01, 2, [&sc](double v){ sc.prefs.set_torus_inner_radius((float)v); });
        s3->setBounds(95, 56, 90, 22); s3->setValue(sc.prefs.get_torus_inner_radius()); w->addWidget(s3);
        return w;
    });
    auto* w = sc.window_manager.findWindow("gl_torus");
    if (w) { auto* s1 = dynamic_cast<GLSpinButton*>(w->findWidget(1)); auto* s2 = dynamic_cast<GLSpinButton*>(w->findWidget(3)); auto* s3 = dynamic_cast<GLSpinButton*>(w->findWidget(5));
        if (s1) s1->setValue(sc.prefs.get_torus_latitude()); if (s2) s2->setValue(sc.prefs.get_torus_longitude()); if (s3) s3->setValue(sc.prefs.get_torus_inner_radius()); }
}

// ============================================================
// Tool parameter windows
// ============================================================

void show_gl_boolean_window(scene& sc) {
    show_or_create(sc, "gl_boolean", [&]() {
        auto* w = new GLWindow("gl_boolean", "Booleans", 200, 160); w->setPosition(120, 100);
        auto* l1 = new GLLabel("Identity");       l1->setBounds(4, 4, 80, 22);   w->addWidget(l1);
        auto* s1 = new GLSpinButton(0, 100, 1, 0); s1->setBounds(90, 4, 100, 22); s1->setValue(50); w->addWidget(s1);
        auto* c1 = new GLCheckBox("Delete Edges");      c1->setBounds(4, 30, 190, 22);  w->addWidget(c1);
        auto* c2 = new GLCheckBox("Triangulate First");  c2->setBounds(4, 56, 190, 22);  w->addWidget(c2);
        auto* c3 = new GLCheckBox("Keep Drill");         c3->setBounds(4, 82, 190, 22);  w->addWidget(c3);
        auto* c4 = new GLCheckBox("Keep Material");      c4->setBounds(4, 108, 190, 22); w->addWidget(c4);
        auto* l2 = new GLLabel("On Fly Offset");  l2->setBounds(4, 134, 80, 22);  w->addWidget(l2);
        auto* s2 = new GLSpinButton(0, 100, 0.1, 1); s2->setBounds(90, 134, 100, 22); s2->setValue(0.2); w->addWidget(s2);
        return w;
    });
}

void show_gl_bevel_window(scene& sc) {
    show_or_create(sc, "gl_bevel", [&]() {
        auto* w = new GLWindow("gl_bevel", "Bevel", 190, 56); w->setPosition(120, 120);
        auto* l1 = new GLLabel("Bevel"); l1->setBounds(4, 4, 60, 22);  w->addWidget(l1);
        auto* s1 = new GLSpinButton(0, 9999, 0.1, 2); s1->setBounds(70, 4, 110, 22); w->addWidget(s1);
        auto* l2 = new GLLabel("Angle"); l2->setBounds(4, 30, 60, 22); w->addWidget(l2);
        auto* s2 = new GLSpinButton(0, 360, 1, 0);    s2->setBounds(70, 30, 110, 22); s2->setValue(45); w->addWidget(s2);
        return w;
    });
}

void show_gl_chamfer_window(scene& sc) {
    show_or_create(sc, "gl_chamfer", [&]() {
        auto* w = new GLWindow("gl_chamfer", "Chamfer", 220, 160); w->setPosition(120, 120);
        int y = 4;
        auto* lt = new GLLabel("Type");       lt->setBounds(4, y, 70, 22); w->addWidget(lt);
        auto* ct = new GLComboBox({"Len", "Len/Len", "Len/Ang"}); ct->setBounds(80, y, 130, 22); ct->setSelectedIndex(0); w->addWidget(ct); y += 26;
        auto* l1 = new GLLabel("Length 1");   l1->setBounds(4, y, 70, 22); w->addWidget(l1);
        auto* s1 = new GLSpinButton(0, 9999, 0.01, 3); s1->setBounds(80, y, 130, 22); w->addWidget(s1); y += 26;
        auto* l2 = new GLLabel("Length 2");   l2->setBounds(4, y, 70, 22); w->addWidget(l2);
        auto* s2 = new GLSpinButton(0, 9999, 0.01, 3); s2->setBounds(80, y, 130, 22); w->addWidget(s2); y += 26;
        auto* l3 = new GLLabel("Angle 2");    l3->setBounds(4, y, 70, 22); w->addWidget(l3);
        auto* e3 = new GLTextInput();         e3->setBounds(80, y, 130, 22); e3->setText("0.200"); w->addWidget(e3); y += 26;
        auto* lb = new GLLabel("Base plane"); lb->setBounds(4, y, 70, 22); w->addWidget(lb);
        auto* cb = new GLComboBox({"Auto", "Prepend"}); cb->setBounds(80, y, 130, 22); cb->setSelectedIndex(0); w->addWidget(cb); y += 26;
        w->setSize(220, y);
        return w;
    });
}

void show_gl_fillet_window(scene& sc) {
    show_or_create(sc, "gl_fillet", [&]() {
        auto* w = new GLWindow("gl_fillet", "Fillet", 220, 112); w->setPosition(120, 120);
        auto* l1 = new GLLabel("Radius");     l1->setBounds(4, 4, 80, 22);  w->addWidget(l1);
        auto* e1 = new GLTextInput();         e1->setBounds(90, 4, 120, 22); e1->setText("0.200"); w->addWidget(e1);
        auto* l2 = new GLLabel("Div. angle"); l2->setBounds(4, 30, 80, 22); w->addWidget(l2);
        auto* s2 = new GLSpinButton(1, 180, 1, 0); s2->setBounds(90, 30, 120, 22); s2->setValue(10); w->addWidget(s2);
        auto* l3 = new GLLabel("Base plane"); l3->setBounds(4, 56, 80, 22); w->addWidget(l3);
        auto* c3 = new GLComboBox({"Auto", "Prepend"}); c3->setBounds(90, 56, 120, 22); c3->setSelectedIndex(0); w->addWidget(c3);
        auto* l4 = new GLLabel("Boolean fix"); l4->setBounds(4, 82, 80, 22); w->addWidget(l4);
        auto* s4 = new GLSpinButton(0, 9999, 1, 0); s4->setBounds(90, 82, 120, 22); w->addWidget(s4);
        return w;
    });
}

void show_gl_lathe_window(scene& sc) {
    show_or_create(sc, "gl_lathe", [&]() {
        auto* w = new GLWindow("gl_lathe", "Lathe", 200, 134); w->setPosition(120, 120);
        auto* l1 = new GLLabel("Segments"); l1->setBounds(4, 4, 80, 22);  w->addWidget(l1);
        auto* s1 = new GLSpinButton(1, 9999, 1, 0); s1->setBounds(90, 4, 100, 22); s1->setValue(3); w->addWidget(s1);
        auto* l2 = new GLLabel("Angle");    l2->setBounds(4, 30, 80, 22); w->addWidget(l2);
        auto* s2 = new GLSpinButton(0, 360, 1, 0);  s2->setBounds(90, 30, 100, 22); s2->setValue(270); w->addWidget(s2);
        auto* l3 = new GLLabel("Radius");   l3->setBounds(4, 56, 80, 22); w->addWidget(l3);
        auto* s3 = new GLSpinButton(0, 9999, 0.1, 2); s3->setBounds(90, 56, 100, 22); w->addWidget(s3);
        auto* l4 = new GLLabel("Rotation"); l4->setBounds(4, 82, 80, 22); w->addWidget(l4);
        auto* s4 = new GLSpinButton(0, 360, 1, 0); s4->setBounds(90, 82, 100, 22); w->addWidget(s4);
        auto* l5 = new GLLabel("Helix");    l5->setBounds(4, 108, 80, 22); w->addWidget(l5);
        auto* s5 = new GLSpinButton(0, 9999, 0.1, 2); s5->setBounds(90, 108, 100, 22); w->addWidget(s5);
        return w;
    });
}

void show_gl_sweep_tip_window(scene& sc) {
    show_or_create(sc, "gl_sweep_tip", [&]() {
        auto* w = new GLWindow("gl_sweep_tip", "Sweep / Tip", 200, 112); w->setPosition(120, 120);
        auto* c1 = new GLCheckBox("Bend"); c1->setBounds(4, 4, 190, 22); w->addWidget(c1);
        auto* l1 = new GLLabel("Segments"); l1->setBounds(4, 30, 70, 22); w->addWidget(l1);
        auto* s1 = new GLSpinButton(1, 9999, 1, 0); s1->setBounds(80, 30, 110, 22); s1->setValue(1); w->addWidget(s1);
        auto* lx = new GLLabel("X");        lx->setBounds(4, 56, 20, 22); w->addWidget(lx);
        auto* ex = new GLTextInput();       ex->setBounds(30, 56, 70, 22); w->addWidget(ex);
        auto* ly = new GLLabel("Y");        ly->setBounds(110, 56, 20, 22); w->addWidget(ly);
        auto* ey = new GLTextInput();       ey->setBounds(135, 56, 55, 22); w->addWidget(ey);
        auto* lx2 = new GLLabel("X");       lx2->setBounds(4, 82, 20, 22); w->addWidget(lx2);
        auto* ex2 = new GLTextInput();      ex2->setBounds(30, 82, 70, 22); ex2->setText("0.500"); w->addWidget(ex2);
        return w;
    });
}

void show_gl_macro_window(scene& sc) {
    show_or_create(sc, "gl_macro", [&]() {
        auto* w = new GLWindow("gl_macro", "Macro", 120, 30); w->setPosition(120, 120);
        auto* c = new GLCheckBox("Bend"); c->setBounds(4, 4, 110, 22); w->addWidget(c);
        return w;
    });
}

void show_gl_shell_properties_window(scene& sc) {
    show_or_create(sc, "gl_shell", [&]() {
        auto* w = new GLWindow("gl_shell", "Shell Properties", 210, 134); w->setPosition(120, 120);
        auto* l1 = new GLLabel("Thickness");    l1->setBounds(4, 4, 90, 22);  w->addWidget(l1);
        auto* s1 = new GLSpinButton(0, 9999, 0.01, 2); s1->setBounds(100, 4, 100, 22); w->addWidget(s1);
        auto* l2 = new GLLabel("Edge Offset");  l2->setBounds(4, 30, 90, 22); w->addWidget(l2);
        auto* s2 = new GLSpinButton(0, 9999, 0.01, 2); s2->setBounds(100, 30, 100, 22); w->addWidget(s2);
        auto* c1 = new GLCheckBox("Apply Offset");    c1->setBounds(4, 56, 200, 22);  w->addWidget(c1);
        auto* c2 = new GLCheckBox("Keep Source Copy"); c2->setBounds(4, 82, 200, 22);  w->addWidget(c2);
        return w;
    });
}

void show_gl_smooth_quad_window(scene& sc) {
    show_or_create(sc, "gl_smooth_quad", [&]() {
        auto* w = new GLWindow("gl_smooth_quad", "Smooth Quad", 180, 30); w->setPosition(120, 120);
        auto* l = new GLLabel("Angle"); l->setBounds(4, 4, 60, 22); w->addWidget(l);
        auto* s = new GLSpinButton(0, 180, 1, 0); s->setBounds(70, 4, 100, 22); s->setValue(80); w->addWidget(s);
        return w;
    });
}

void show_gl_polygon_reduction_window(scene& sc) {
    show_or_create(sc, "gl_poly_reduce", [&]() {
        auto* w = new GLWindow("gl_poly_reduce", "Polygon Reduction", 210, 160); w->setPosition(120, 100);
        auto* l1 = new GLLabel("Number");     l1->setBounds(4, 4, 80, 22);  w->addWidget(l1);
        auto* s1 = new GLSpinButton(0, 99999, 1, 0); s1->setBounds(90, 4, 110, 22); w->addWidget(s1);
        auto* l2 = new GLLabel("MinDetail%"); l2->setBounds(4, 30, 80, 22); w->addWidget(l2);
        auto* s2 = new GLSpinButton(0, 100, 1, 0);   s2->setBounds(90, 30, 110, 22); w->addWidget(s2);
        auto* l3 = new GLLabel("CavityDet");  l3->setBounds(4, 56, 80, 22); w->addWidget(l3);
        auto* s3 = new GLSpinButton(0, 9999, 1, 0);  s3->setBounds(90, 56, 110, 22); w->addWidget(s3);
        auto* c1 = new GLCheckBox("LOD Group");   c1->setBounds(4, 82, 200, 22);  w->addWidget(c1);
        auto* c2 = new GLCheckBox("Union First"); c2->setBounds(4, 108, 200, 22); w->addWidget(c2);
        auto* c3 = new GLCheckBox("LongEdges");   c3->setBounds(4, 134, 200, 22); w->addWidget(c3);
        return w;
    });
}

void show_gl_coords_window(scene& sc) {
    show_or_create(sc, "gl_coords", [&]() {
        auto* w = new GLWindow("gl_coords", "Coordinates", 130, 82); w->setPosition(120, 120);
        auto* cx = new GLCheckBox("X"); cx->setBounds(4, 4, 60, 22);  w->addWidget(cx); cx->setChecked(true);
        auto* cy = new GLCheckBox("Y"); cy->setBounds(4, 30, 60, 22); w->addWidget(cy); cy->setChecked(true);
        auto* cz = new GLCheckBox("Z"); cz->setBounds(4, 56, 60, 22); w->addWidget(cz); cz->setChecked(true);
        return w;
    });
}

void show_gl_mirror_options_window(scene& sc) {
    show_or_create(sc, "gl_mirror", [&]() {
        auto* w = new GLWindow("gl_mirror", "Mirror Options", 220, 160); w->setPosition(120, 100);
        auto* c1 = new GLCheckBox("Remove Interior Faces"); c1->setBounds(4, 4, 210, 22);  w->addWidget(c1);
        auto* c2 = new GLCheckBox("Reverse Mirror");        c2->setBounds(4, 30, 210, 22); w->addWidget(c2);
        auto* c3 = new GLCheckBox("Keep Source Copy");       c3->setBounds(4, 56, 210, 22); w->addWidget(c3);
        auto* c4 = new GLCheckBox("Quick Weld");             c4->setBounds(4, 82, 210, 22); w->addWidget(c4);
        auto* l1 = new GLLabel("Epsilon"); l1->setBounds(4, 108, 60, 22); w->addWidget(l1);
        auto* e1 = new GLTextInput();      e1->setBounds(70, 108, 140, 22); w->addWidget(e1);
        auto* b1 = new GLButton("Default Epsilon", nullptr); b1->setBounds(4, 134, 210, 22); w->addWidget(b1);
        return w;
    });
}

void show_gl_lights_window(scene& sc) {
    show_or_create(sc, "gl_lights", [&]() {
        auto* w = new GLWindow("gl_lights", "Light Properties", 200, 56); w->setPosition(120, 120);
        auto* l1 = new GLLabel("Intensity"); l1->setBounds(4, 4, 70, 22); w->addWidget(l1);
        auto* s1 = new GLSpinButton(0, 100, 1, 0); s1->setBounds(80, 4, 110, 22); s1->setValue(100); w->addWidget(s1);
        auto* l2 = new GLLabel("Color");     l2->setBounds(4, 30, 70, 22); w->addWidget(l2);
        auto* e2 = new GLTextInput();        e2->setBounds(80, 30, 110, 22); e2->setText("1.0 1.0 1.0"); w->addWidget(e2);
        return w;
    });
}

void show_gl_wind_window(scene& sc) {
    show_or_create(sc, "gl_wind", [&]() {
        auto* w = new GLWindow("gl_wind", "Wind", 180, 30); w->setPosition(120, 120);
        auto* l = new GLLabel("Power"); l->setBounds(4, 4, 50, 22); w->addWidget(l);
        auto* e = new GLTextInput();    e->setBounds(60, 4, 110, 22); e->setText("1.00"); w->addWidget(e);
        return w;
    });
}

void show_gl_metaball_window(scene& sc) {
    show_or_create(sc, "gl_metaball", [&]() {
        auto* w = new GLWindow("gl_metaball", "Metaball Options", 220, 112); w->setPosition(120, 100);
        auto* c1 = new GLCheckBox("Use X offset for prims"); c1->setBounds(4, 4, 210, 22); w->addWidget(c1);
        auto* l1 = new GLLabel("Render res.");    l1->setBounds(4, 30, 90, 22); w->addWidget(l1);
        auto* s1 = new GLSpinButton(1, 9999, 1, 0); s1->setBounds(100, 30, 110, 22); w->addWidget(s1);
        auto* l2 = new GLLabel("Navigation Res"); l2->setBounds(4, 56, 90, 22); w->addWidget(l2);
        auto* s2 = new GLSpinButton(1, 9999, 1, 0); s2->setBounds(100, 56, 110, 22); w->addWidget(s2);
        auto* l3 = new GLLabel("Conversion");     l3->setBounds(4, 82, 90, 22); w->addWidget(l3);
        auto* cb = new GLComboBox({"On Move", "On Release", "On Demand"}); cb->setBounds(100, 82, 110, 22); cb->setSelectedIndex(0); w->addWidget(cb);
        return w;
    });
}

// ============================================================
// NURBS parameter windows
// ============================================================

void show_gl_nurbs_plane_window(scene& sc) {
    show_or_create(sc, "gl_nurbs_plane", [&]() {
        auto* w = new GLWindow("gl_nurbs_plane", "NURBS Plane", 180, 30); w->setPosition(120, 120);
        auto* l = new GLLabel("Resolution"); l->setBounds(4, 4, 70, 22); w->addWidget(l);
        auto* s = new GLSpinButton(1, 9999, 1, 0); s->setBounds(80, 4, 90, 22); w->addWidget(s);
        return w;
    });
}

void show_gl_nurbs_cube_window(scene& sc) {
    show_or_create(sc, "gl_nurbs_cube", [&]() {
        auto* w = new GLWindow("gl_nurbs_cube", "NURBS Cube", 180, 56); w->setPosition(120, 120);
        auto* l = new GLLabel("Resolution"); l->setBounds(4, 4, 70, 22); w->addWidget(l);
        auto* s = new GLSpinButton(1, 9999, 1, 0); s->setBounds(80, 4, 90, 22); w->addWidget(s);
        auto* c = new GLCheckBox("One patch"); c->setBounds(4, 30, 170, 22); w->addWidget(c);
        return w;
    });
}

void show_gl_nurbs_cylinder_window(scene& sc) {
    show_or_create(sc, "gl_nurbs_cylinder", [&]() {
        auto* w = new GLWindow("gl_nurbs_cylinder", "NURBS Cylinder", 220, 238); w->setPosition(120, 80);
        int y = 4;
        auto* l1 = new GLLabel("Top radius");   l1->setBounds(4, y, 90, 22); w->addWidget(l1);
        auto* s1 = new GLSpinButton(0, 9999, 0.01, 2); s1->setBounds(100, y, 110, 22); w->addWidget(s1); y += 26;
        auto* l2 = new GLLabel("Start angle");   l2->setBounds(4, y, 90, 22); w->addWidget(l2);
        auto* s2 = new GLSpinButton(0, 360, 1, 0); s2->setBounds(100, y, 110, 22); w->addWidget(s2); y += 26;
        auto* l3 = new GLLabel("End angle");     l3->setBounds(4, y, 90, 22); w->addWidget(l3);
        auto* s3 = new GLSpinButton(0, 360, 1, 0); s3->setBounds(100, y, 110, 22); w->addWidget(s3); y += 26;
        auto* l4 = new GLLabel("Latitude");      l4->setBounds(4, y, 90, 22); w->addWidget(l4);
        auto* s4 = new GLSpinButton(1, 9999, 1, 0); s4->setBounds(100, y, 110, 22); w->addWidget(s4); y += 26;
        auto* l5 = new GLLabel("Longitude");     l5->setBounds(4, y, 90, 22); w->addWidget(l5);
        auto* s5 = new GLSpinButton(1, 9999, 1, 0); s5->setBounds(100, y, 110, 22); w->addWidget(s5); y += 26;
        auto* c1 = new GLCheckBox("Closed arc");  c1->setBounds(4, y, 210, 22); w->addWidget(c1); y += 26;
        auto* c2 = new GLCheckBox("Top cap");      c2->setBounds(4, y, 210, 22); w->addWidget(c2); y += 26;
        auto* c3 = new GLCheckBox("Bottom cap");   c3->setBounds(4, y, 210, 22); w->addWidget(c3); y += 26;
        auto* c4 = new GLCheckBox("One patch");    c4->setBounds(4, y, 210, 22); w->addWidget(c4);
        return w;
    });
}

void show_gl_nurbs_cone_window(scene& sc) {
    show_or_create(sc, "gl_nurbs_cone", [&]() {
        auto* w = new GLWindow("gl_nurbs_cone", "NURBS Cone", 220, 212); w->setPosition(120, 80);
        int y = 4;
        auto* l1 = new GLLabel("Start angle"); l1->setBounds(4, y, 90, 22); w->addWidget(l1);
        auto* s1 = new GLSpinButton(0, 360, 1, 0); s1->setBounds(100, y, 110, 22); w->addWidget(s1); y += 26;
        auto* l2 = new GLLabel("End angle");   l2->setBounds(4, y, 90, 22); w->addWidget(l2);
        auto* s2 = new GLSpinButton(0, 360, 1, 0); s2->setBounds(100, y, 110, 22); w->addWidget(s2); y += 26;
        auto* l3 = new GLLabel("Latitude");    l3->setBounds(4, y, 90, 22); w->addWidget(l3);
        auto* s3 = new GLSpinButton(1, 9999, 1, 0); s3->setBounds(100, y, 110, 22); w->addWidget(s3); y += 26;
        auto* l4 = new GLLabel("Longitude");   l4->setBounds(4, y, 90, 22); w->addWidget(l4);
        auto* s4 = new GLSpinButton(1, 9999, 1, 0); s4->setBounds(100, y, 110, 22); w->addWidget(s4); y += 26;
        auto* c1 = new GLCheckBox("Bottom cap");  c1->setBounds(4, y, 210, 22); w->addWidget(c1); y += 26;
        auto* c2 = new GLCheckBox("One patch");    c2->setBounds(4, y, 210, 22); w->addWidget(c2); y += 26;
        auto* c3 = new GLCheckBox("Closed arc");   c3->setBounds(4, y, 210, 22); w->addWidget(c3);
        return w;
    });
}

void show_gl_nurbs_sphere_window(scene& sc) {
    show_or_create(sc, "gl_nurbs_sphere", [&]() {
        auto* w = new GLWindow("gl_nurbs_sphere", "NURBS Sphere", 220, 264); w->setPosition(120, 60);
        int y = 4;
        auto* l1 = new GLLabel("Start angle");  l1->setBounds(4, y, 90, 22); w->addWidget(l1);
        auto* s1 = new GLSpinButton(0, 360, 1, 0); s1->setBounds(100, y, 110, 22); w->addWidget(s1); y += 26;
        auto* l2 = new GLLabel("End angle");    l2->setBounds(4, y, 90, 22); w->addWidget(l2);
        auto* s2 = new GLSpinButton(0, 360, 1, 0); s2->setBounds(100, y, 110, 22); w->addWidget(s2); y += 26;
        auto* l3 = new GLLabel("Top angle");    l3->setBounds(4, y, 90, 22); w->addWidget(l3);
        auto* s3 = new GLSpinButton(0, 360, 1, 0); s3->setBounds(100, y, 110, 22); w->addWidget(s3); y += 26;
        auto* l4 = new GLLabel("Bottom angle"); l4->setBounds(4, y, 90, 22); w->addWidget(l4);
        auto* s4 = new GLSpinButton(0, 360, 1, 0); s4->setBounds(100, y, 110, 22); w->addWidget(s4); y += 26;
        auto* l5 = new GLLabel("Latitude");     l5->setBounds(4, y, 90, 22); w->addWidget(l5);
        auto* s5 = new GLSpinButton(1, 9999, 1, 0); s5->setBounds(100, y, 110, 22); w->addWidget(s5); y += 26;
        auto* l6 = new GLLabel("Longitude");    l6->setBounds(4, y, 90, 22); w->addWidget(l6);
        auto* s6 = new GLSpinButton(1, 9999, 1, 0); s6->setBounds(100, y, 110, 22); w->addWidget(s6); y += 26;
        auto* c1 = new GLCheckBox("Closed arc");  c1->setBounds(4, y, 210, 22); w->addWidget(c1); y += 26;
        auto* c2 = new GLCheckBox("Top cap");      c2->setBounds(4, y, 210, 22); w->addWidget(c2); y += 26;
        auto* c3 = new GLCheckBox("Bottom cap");   c3->setBounds(4, y, 210, 22); w->addWidget(c3); y += 26;
        auto* c4 = new GLCheckBox("One patch");    c4->setBounds(4, y, 210, 22); w->addWidget(c4);
        return w;
    });
}

void show_gl_nurbs_torus_window(scene& sc) {
    show_or_create(sc, "gl_nurbs_torus", [&]() {
        auto* w = new GLWindow("gl_nurbs_torus", "NURBS Torus", 220, 186); w->setPosition(120, 80);
        int y = 4;
        auto* l1 = new GLLabel("Latitude");     l1->setBounds(4, y, 90, 22); w->addWidget(l1);
        auto* s1 = new GLSpinButton(1, 9999, 1, 0); s1->setBounds(100, y, 110, 22); w->addWidget(s1); y += 26;
        auto* l2 = new GLLabel("Longitude");    l2->setBounds(4, y, 90, 22); w->addWidget(l2);
        auto* s2 = new GLSpinButton(1, 9999, 1, 0); s2->setBounds(100, y, 110, 22); w->addWidget(s2); y += 26;
        auto* l3 = new GLLabel("Inner radius"); l3->setBounds(4, y, 90, 22); w->addWidget(l3);
        auto* s3 = new GLSpinButton(0, 9999, 0.01, 2); s3->setBounds(100, y, 110, 22); w->addWidget(s3); y += 26;
        auto* l4 = new GLLabel("Start angle");  l4->setBounds(4, y, 90, 22); w->addWidget(l4);
        auto* s4 = new GLSpinButton(0, 360, 1, 0); s4->setBounds(100, y, 110, 22); w->addWidget(s4); y += 26;
        auto* l5 = new GLLabel("End angle");    l5->setBounds(4, y, 90, 22); w->addWidget(l5);
        auto* s5 = new GLSpinButton(0, 360, 1, 0); s5->setBounds(100, y, 110, 22); w->addWidget(s5); y += 26;
        auto* l6 = new GLLabel("Start angle 2"); l6->setBounds(4, y, 90, 22); w->addWidget(l6);
        auto* s6 = new GLSpinButton(0, 360, 1, 0); s6->setBounds(100, y, 110, 22); w->addWidget(s6); y += 26;
        auto* l7 = new GLLabel("End angle 2");   l7->setBounds(4, y, 90, 22); w->addWidget(l7);
        auto* s7 = new GLSpinButton(0, 360, 1, 0); s7->setBounds(100, y, 110, 22); w->addWidget(s7);
        return w;
    });
}

// ============================================================
// Object Info Window
// ============================================================

void show_gl_object_info_window(scene& sc) {
    show_or_create(sc, "gl_obj_info", [&]() {
        auto* w = new GLWindow("gl_obj_info", "Object Info", 280, 310); w->setPosition(200, 50);
        int y = 4;
        auto* ln = new GLLabel("Name"); ln->setBounds(4, y, 40, 22); w->addWidget(ln);
        auto* en = new GLTextInput();   en->setBounds(50, y, 220, 22); w->addWidget(en); y += 26;

        auto* hx = new GLLabel("X"); hx->setBounds(90, y, 20, 22); w->addWidget(hx);
        auto* hy = new GLLabel("Y"); hy->setBounds(155, y, 20, 22); w->addWidget(hy);
        auto* hz = new GLLabel("Z"); hz->setBounds(220, y, 20, 22); w->addWidget(hz); y += 22;

        auto* ll = new GLLabel("Loc"); ll->setBounds(4, y, 30, 22); w->addWidget(ll);
        auto* elx = new GLTextInput(); elx->setBounds(40, y, 75, 22); elx->setText("0.0000"); w->addWidget(elx);
        auto* ely = new GLTextInput(); ely->setBounds(120, y, 75, 22); ely->setText("0.0000"); w->addWidget(ely);
        auto* elz = new GLTextInput(); elz->setBounds(200, y, 70, 22); elz->setText("0.0000"); w->addWidget(elz); y += 26;

        auto* lr = new GLLabel("Rot"); lr->setBounds(4, y, 30, 22); w->addWidget(lr);
        auto* erx = new GLTextInput(); erx->setBounds(40, y, 75, 22); erx->setText("0.0000"); w->addWidget(erx);
        auto* ery = new GLTextInput(); ery->setBounds(120, y, 75, 22); ery->setText("0.0000"); w->addWidget(ery);
        auto* erz = new GLTextInput(); erz->setBounds(200, y, 70, 22); erz->setText("0.0000"); w->addWidget(erz); y += 26;

        auto* ls = new GLLabel("Sca"); ls->setBounds(4, y, 30, 22); w->addWidget(ls);
        auto* esx = new GLTextInput(); esx->setBounds(40, y, 75, 22); esx->setText("1.0000"); w->addWidget(esx);
        auto* esy = new GLTextInput(); esy->setBounds(120, y, 75, 22); esy->setText("1.0000"); w->addWidget(esy);
        auto* esz = new GLTextInput(); esz->setBounds(200, y, 70, 22); esz->setText("1.0000"); w->addWidget(esz); y += 26;

        auto* lv = new GLLabel("#Verts"); lv->setBounds(4, y, 50, 22);  w->addWidget(lv);
        auto* vv = new GLLabel("0");      vv->setBounds(60, y, 60, 22); w->addWidget(vv);
        auto* lf = new GLLabel("#Faces"); lf->setBounds(130, y, 50, 22); w->addWidget(lf);
        auto* vf = new GLLabel("0");      vf->setBounds(185, y, 60, 22); w->addWidget(vf); y += 26;

        auto* lw = new GLLabel("World"); lw->setBounds(4, y, 50, 22); w->addWidget(lw);
        auto* cw = new GLComboBox({"Millimeters","Centimeters","Meters","Kilometers","Inches","Feet","Yards","Miles","Points"});
        cw->setBounds(60, y, 210, 22); cw->setSelectedIndex(2); w->addWidget(cw); y += 26;

        auto* lo = new GLLabel("Object"); lo->setBounds(4, y, 50, 22); w->addWidget(lo);
        auto* co = new GLComboBox({"Millimeters","Centimeters","Meters","Kilometers","Inches","Feet","Yards","Miles","Points"});
        co->setBounds(60, y, 210, 22); co->setSelectedIndex(2); w->addWidget(co); y += 26;

        auto* ci = new GLCheckBox("Inlined");   ci->setBounds(4, y, 130, 22);   w->addWidget(ci);
        auto* cd = new GLCheckBox("Dynaunits"); cd->setBounds(140, y, 130, 22); w->addWidget(cd);
        w->setSize(280, y + 26);
        return w;
    });
    update_gl_object_info(sc);
}

void update_gl_object_info(scene& sc) {
    GLWindow* w = sc.window_manager.findWindow("gl_obj_info");
    if (!w || !w->isVisible()) return;

    auto fmt = [](double v) -> std::string {
        char buf[32]; snprintf(buf, sizeof(buf), "%.4f", v); return buf;
    };

    // Widget indices: 0=name_lbl, 1=name_entry, 2=X_lbl, 3=Y_lbl, 4=Z_lbl,
    // 5=Loc_lbl, 6=loc_x, 7=loc_y, 8=loc_z, 9=Rot_lbl, 10=rot_x, 11=rot_y, 12=rot_z,
    // 13=Sca_lbl, 14=sca_x, 15=sca_y, 16=sca_z, 17=verts_lbl, 18=verts_val, 19=faces_lbl, 20=faces_val
    auto* en  = dynamic_cast<GLTextInput*>(w->findWidget(1));
    auto* elx = dynamic_cast<GLTextInput*>(w->findWidget(6));
    auto* ely = dynamic_cast<GLTextInput*>(w->findWidget(7));
    auto* elz = dynamic_cast<GLTextInput*>(w->findWidget(8));
    auto* erx = dynamic_cast<GLTextInput*>(w->findWidget(10));
    auto* ery = dynamic_cast<GLTextInput*>(w->findWidget(11));
    auto* erz = dynamic_cast<GLTextInput*>(w->findWidget(12));
    auto* esx = dynamic_cast<GLTextInput*>(w->findWidget(14));
    auto* esy = dynamic_cast<GLTextInput*>(w->findWidget(15));
    auto* esz = dynamic_cast<GLTextInput*>(w->findWidget(16));
    auto* vv  = dynamic_cast<GLLabel*>(w->findWidget(18));
    auto* vf  = dynamic_cast<GLLabel*>(w->findWidget(20));

    auto obj = sc.GetCurrentObject();
    if (!obj) {
        if (en) en->setText("");
        if (elx) elx->setText("0.0000"); if (ely) ely->setText("0.0000"); if (elz) elz->setText("0.0000");
        if (erx) erx->setText("0.0000"); if (ery) ery->setText("0.0000"); if (erz) erz->setText("0.0000");
        if (esx) esx->setText("1.0000"); if (esy) esy->setText("1.0000"); if (esz) esz->setText("1.0000");
        if (vv) vv->setText("0"); if (vf) vf->setText("0");
        return;
    }

    if ((int)sc.selected_objects.size() > 1) {
        double cx = 0, cy = 0, cz = 0;
        int tv = 0, tf = 0;
        for (auto& so : sc.selected_objects) {
            if (!so) continue;
            double* loc = so->get_location();
            cx += loc[0]; cy += loc[1]; cz += loc[2];
            tv += so->get_num_vertices(); tf += so->get_num_faces();
        }
        double n = (double)sc.selected_objects.size();
        cx /= n; cy /= n; cz /= n;
        if (en) en->setText(std::to_string((int)n) + " objects");
        if (elx) elx->setText(fmt(cx)); if (ely) ely->setText(fmt(cy)); if (elz) elz->setText(fmt(cz));
        if (erx) erx->setText("0.0000"); if (ery) ery->setText("0.0000"); if (erz) erz->setText("0.0000");
        if (esx) esx->setText("1.0000"); if (esy) esy->setText("1.0000"); if (esz) esz->setText("1.0000");
        if (vv) vv->setText(std::to_string(tv)); if (vf) vf->setText(std::to_string(tf));
        return;
    }

    double* loc = obj->get_location();
    float* rot = obj->get_rotation();
    float* sca = obj->get_scale();
    if (en) en->setText(obj->get_name());
    if (elx) elx->setText(fmt(loc[0])); if (ely) ely->setText(fmt(loc[1])); if (elz) elz->setText(fmt(loc[2]));
    if (erx) erx->setText(fmt(rot[0])); if (ery) ery->setText(fmt(rot[1])); if (erz) erz->setText(fmt(rot[2]));
    if (esx) esx->setText(fmt(sca[0])); if (esy) esy->setText(fmt(sca[1])); if (esz) esz->setText(fmt(sca[2]));
    if (vv) vv->setText(std::to_string(obj->get_num_vertices()));
    if (vf) vf->setText(std::to_string(obj->get_num_faces()));
}

void show_gl_display_options_window(scene& sc) {
    show_or_create(sc, "gl_display_options", [&]() {
        auto* w = new GLWindow("gl_display_options", "Display Options", 220, 82);
        w->setPosition(120, 100);
        auto* c1 = new GLCheckBox("Draw Axes", [&sc](bool v){ sc.prefs.set_draw_axes(v); });
        c1->setBounds(4, 4, 210, 22);
        c1->setChecked(sc.prefs.get_draw_axes());
        w->addWidget(c1);
        auto* c2 = new GLCheckBox("Draw Ground Plane", [&sc](bool v){ sc.prefs.set_draw_ground_plane(v); });
        c2->setBounds(4, 30, 210, 22);
        c2->setChecked(sc.prefs.get_draw_ground_plane());
        w->addWidget(c2);
        auto* c3 = new GLCheckBox("Show Control Widget", [&sc](bool v){ sc.prefs.set_draw_control_widget(v); });
        c3->setBounds(4, 56, 210, 22);
        c3->setChecked(sc.prefs.get_draw_control_widget());
        w->addWidget(c3);
        return w;
    });
}

void show_gl_preferences_window(scene& sc) {
    show_or_create(sc, "gl_preferences", [&]() {
        auto* w = new GLWindow("gl_preferences", "Preferences", 250, 30);
        w->setPosition(150, 100);
        auto* c1 = new GLCheckBox("3D Controls", [&sc](bool v){ sc.prefs.set_draw_control_widget(v); });
        c1->setBounds(4, 4, 240, 22);
        c1->setChecked(sc.prefs.get_draw_control_widget());
        w->addWidget(c1);
        return w;
    });
}
