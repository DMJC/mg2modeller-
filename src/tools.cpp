#include "../include/tools.h"
/*
void tool::create_tool{ string name, string icon, string tooltip, int* right_click_action, int* left_click_action ){
	
}
*/
/*
struct _tool_menu {
	string icon;
	string name;
	string tool_tip;	
	callback left_click_action;
	callback right_click_action;
};

	tool_menu primitive_tool[] = {
	  { "pix/plane.xpm", "plane", "Create Plane", nullptr, nullptr },
	  { "pix/cube.xpm", "cube", "Create Primitive Cube", nullptr, nullptr },
	  { "pix/cylinder.xpm", "cylinder", "Create Primitive Cylinder", nullptr, nullptr },
	  { "pix/cone.xpm", "cone", "Create Primitive Cone", nullptr, nullptr },
	  { "pix/sphere.xpm", "sphere", "Create Primitive Sphere", nullptr, nullptr },
	  { "pix/geosphere.xpm", "geosphere", "Create Primitive Geosphere", nullptr, nullptr },
	  { "pix/rounded_cylinder.xpm", "rounded cylinder", "Create Primitive Rounded Cylinder", nullptr, nullptr },
	  { "pix/rounded_cube.xpm", "rounded cube", "Create Primitive Rounded Cube", nullptr, nullptr },
	  { "pix/torus.xpm", "torus", "Create Primitive Torus", nullptr, nullptr },
	};

	tool_menu light_tool[] = {
	 { "pix/local_light.xpm", "local light", "Create a Local Light", nullptr, nullptr },
	 { "pix/spot_light.xpm", "spot light", "Create a Spot Light", nullptr, nullptr },
	 { "pix/infinite_light.xpm", "infinite light", "Create an Infinite Light", nullptr, nullptr },
	 { "pix/projector_light.xpm", "projector light", "Create a Projector Light", nullptr, nullptr },
	 { "pix/skylight.xpm", "skylight", "Create a Skylight", nullptr, nullptr },
	 { "pix/image_based_light.xpm", "image based light", "Create an Image-based Light", nullptr, nullptr },
	 { "pix/area_light.xpm", "Area light", "Create an Area Light", nullptr, nullptr },
	 { "pix/goniometric_light.xpm", "Goniometric light", "Create an Goniometric Light", nullptr, nullptr },
	};
	
	tool_menu edit_tool[] = {
	 { "pix/fillet.xpm", "fillet", "Fillet Tool", nullptr, nullptr },
	 { "pix/chamfer.xpm", "chamfer", "Chamfer Tool", nullptr, nullptr },
	 { "pix/bevel.xpm", "bevel", "Bevel Tool", nullptr, nullptr },
	 { "pix/macro.xpm", "macro/sweep", "Macro/Sweep Tool", nullptr, nullptr },
	 { "pix/lathe.xpm", "lathe", "Lathe Tool", nullptr, nullptr },
	 { "pix/tip.xpm", "tip", "Tip Tool", nullptr, nullptr },
	 { "pix/sweep.xpm", "sweep","Sweep Tool", nullptr, nullptr },
	};
	
	tool_menu camera_deformation_tool[] = {
	 { "pix/camera.xpm", "camera", "camera", nullptr, nullptr },
	 { "pix/panoramic_camera.xpm", "panoramic camera", "panoramic camera", nullptr, nullptr },
	 { "pix/global_physical_wind.xpm", "global physical wind", "global physical wind", nullptr, nullptr },
	 { "pix/standalone_deformation_plane.xpm", "standalone deformation plane", "standalone deformation plane", nullptr, nullptr },
	 { "pix/standalone_deformation_pipe.xpm", "standalone deformation pipe", "standalone deformation pipe", nullptr, nullptr },
	 { "pix/standalone_deformation_object.xpm", "standalone deformation object", "standalone deformation object", nullptr, nullptr }
	};
	
	tool_menu subdivision_tool[] = {
	 { "pix/subdivision_object.xpm", "subdivision object", "subdivision object", nullptr, nullptr },
	 { "pix/plastiform.xpm", "plastiform", "plastiform", nullptr, nullptr },
	};
	
	tool_menu boolean_tool[] = {
	 { "pix/shell.xpm", "shell", "Create Shell Object", nullptr, nullptr },
	 { "pix/subtract.xpm", "subtract", "Boolean Object Subtraction", nullptr, nullptr },
	 { "pix/intersection.xpm", "intersection", "Boolean Object Intersection", nullptr, nullptr },
	 { "pix/union.xpm", "union","Boolean Object Union", nullptr, nullptr },
	};
	
	tool_menu deformation_tool[] = {
	 { "pix/deform.xpm", "deform", "Deform Selection", nullptr, nullptr },
	 { "pix/sculpt.xpm", "sculpt", "Sculpt Selection", nullptr, nullptr },
	 { "pix/standalone_deformation_object.xpm", "standalone deformation object", "Create Standalone Deformation Object", nullptr, nullptr },
	 { "pix/taper.xpm", "taper", "Taper Selection", nullptr, nullptr },
	 { "pix/skew.xpm", "skew", "Skew Selection", nullptr, nullptr },
	 { "pix/bend.xpm", "bend", "Bend Selection", nullptr, nullptr },
	};



	tool_menu array_tool[] = {
	 { "pix/grid_array of objects.xpm", "grid array of objects", "grid array of objects", nullptr, nullptr },
	 { "pix/radial_array of objects.xpm", "radial array of objects", "radial array of objects", nullptr, nullptr },
	 { "pix/spline_array of objects.xpm", "spline array of objects", "spline array of objects", nullptr, nullptr },
	 { "pix/convert_array to a group of objects.xpm", "convert array to a group of objects", "convert array to a group of objects", nullptr, nullptr },
	};

	tool_menu drawpanel_tool[] = {
	 { "pix/drawpanel_tool.xpm", "drawpanel", "Draw Panel", nullptr, nullptr }
	};


	tool_menu drawing_tool[] = {
	 { "pix/add_curve.xpm", "add curve", nullptr, nullptr },
	 { "pix/add_circle.xpm", "add circle", nullptr, nullptr },
	 { "pix/add_elipse.xpm", "add elipse", nullptr, nullptr },
	 { "pix/add_text.xpm", "add text", nullptr, nullptr },
	};


	tool_menu skin_tool[] = {
	 { "pix/skin.xpm" "skin", nullptr, nullptr },
	 { "pix/blend.xpm" "blend", nullptr, nullptr },
	 { "pix/draw.xpm" "draw", nullptr, nullptr },
	 { "pix/convert.xpm" "convert", nullptr, nullptr },
	};

	tool_menu material_tool[] = {
	 { "pix/material_editor.xpm", "material editor", "material editor", nullptr, nullptr },
	};

	tool_menu paint_tool[] = {
	 { "pix/paint_tool.xpm", "paint tool" "3D Paint Tool", nullptr, nullptr },
	};


	tool_menu uv_tool[] = {
	 { "pix/uv_mapping.xpm", "uv mapping", "UV Mapping Tool", nullptr, nullptr },
	 { "pix/material_rectangle.xpm", "material rectangle", "Material Rectangle", nullptr, nullptr },
	};


	tool_menu mapping_tool[] = {
	 { "pix/spherical_mapping.xpm", "spherical mapping", "Spherical Mapping", nullptr, nullptr },
	 { "pix/cylindrical_mapping.xpm", "cylindrical mapping", "Cylindrical Mapping", nullptr, nullptr },
	 { "pix/planar_mapping.xpm", "planar mapping", "Planar Mapping", nullptr, nullptr },
	 { "pix/cubic_mapping.xpm", "cubic mapping", "Cubic Mapping", nullptr, nullptr },
	};
*/