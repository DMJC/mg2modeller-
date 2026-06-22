#ifndef GL_TOOL_WINDOWS_H
#define GL_TOOL_WINDOWS_H

#include "scene.h"

// Shape parameter windows
void show_gl_plane_window(scene& sc);
void show_gl_cube_window(scene& sc);
void show_gl_cone_window(scene& sc);
void show_gl_sphere_window(scene& sc);
void show_gl_cylinder_window(scene& sc);
void show_gl_geosphere_window(scene& sc);
void show_gl_torus_window(scene& sc);
void show_gl_rounded_cube_window(scene& sc);
void show_gl_rounded_cylinder_window(scene& sc);

// Tool parameter windows
void show_gl_boolean_window(scene& sc);
void show_gl_bevel_window(scene& sc);
void show_gl_chamfer_window(scene& sc);
void show_gl_fillet_window(scene& sc);
void show_gl_lathe_window(scene& sc);
void show_gl_sweep_tip_window(scene& sc);
void show_gl_macro_window(scene& sc);
void show_gl_shell_properties_window(scene& sc);
void show_gl_smooth_quad_window(scene& sc);
void show_gl_polygon_reduction_window(scene& sc);
void show_gl_coords_window(scene& sc);
void show_gl_mirror_options_window(scene& sc);
void show_gl_lights_window(scene& sc);
void show_gl_wind_window(scene& sc);
void show_gl_metaball_window(scene& sc);
void show_gl_object_info_window(scene& sc);

// NURBS parameter windows
void show_gl_nurbs_plane_window(scene& sc);
void show_gl_nurbs_cube_window(scene& sc);
void show_gl_nurbs_cylinder_window(scene& sc);
void show_gl_nurbs_cone_window(scene& sc);
void show_gl_nurbs_sphere_window(scene& sc);
void show_gl_nurbs_torus_window(scene& sc);

// Settings windows
void show_gl_display_options_window(scene& sc);
void show_gl_preferences_window(scene& sc);

// Object info update
void update_gl_object_info(scene& sc);

#endif // GL_TOOL_WINDOWS_H
