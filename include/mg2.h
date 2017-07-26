#ifndef MG2_H
#define MG2_H

#include <gtkmm.h>
#include <GL/glew.h>
#include <GL/gl.h>
#include <list>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include "preferences.h"
#include "divider.h"
/*#define objmode 0
#define facmode 1
#define linmode 2
#define vermode 3*/

using namespace std;

typedef struct _tool_menu tool_menu;
using callback = void(*)();

enum mg2_tool_state
{
        MG2_TOOL_CONFIG,
        MG2_TOOL_SELECTED,
        MG2_TOOL_UNSELECTED,
        MG2_TOOL_NO_MOVEMENT
/*	MG2_TOOL_NO_MOVEMENT,
	MG2_TOOL_OBJECT_CHANGE,
	MG2_TOOL_OBJECT_
	MG2_TOOL_ACTIVE,
	MG2_TOOL_INACTIVE*/
};

struct mg2_material
{
	gulong ref_count;
	float ambient[4]; // ambient data
	float diffuse[4]; // diffuse data
	float specular[4];
	float shininess;
	float emission[4];
	GLuint textureid;
	guint material_list; // display list of material
	// function to draw a face with the material's properties
//	mg2_face_render_func DrawFaceWithMaterial;
};

struct mg2_vertex
{
	gfloat p[3]; // a point or vector, however you look at it
};

struct mg2_frame
{
	char is_keyframe;
	float rotate[16]; // object rotation matrix
        float translate[3]; // translate data
        float  scale[3]; // scale data
	//gfloat lookat[3]; // look at a point. haven't implemented yet.

};

enum mg2_object_type
{
	MG2_OBJECT,
	MG2_LIGHT,
	MG2_CAMERA,
	MG2_OTHER,
	MG2_ALL,
	MG2_NOTHING
};

enum mg2_object_draw_type
{
	MG2_DRAW_LINES,
	MG2_DRAW_TRIANGLES,
	MG2_DRAW_QUADS,
	MG2_DRAW_POLYGONS,
	MG2_DRAW_FUNCTION,
	MG2_DRAW_NONE
};

// render types

enum mg2_render_how
{
	MG2_RENDER_ALL,
	MG2_RENDER_ONE,
	MG2_RENDER_NONE
};

#endif
