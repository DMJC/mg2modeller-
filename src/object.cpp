#include "../include/object.h"

GLuint wireframe_object_bo;
GLuint triangles_bo;
GLuint quads_bo;

list<object> next;

struct pos_color_vertex
{
  float pos[3];
  float color[3];
};

static struct pos_color_vertex
make_vertex(float x, float y, float z, float r, float g, float b)
{
  struct pos_color_vertex v;
  v.pos[0] = x; v.pos[1] = y; v.pos[2] = z;
  v.color[0] = r; v.color[1] = g; v.color[2] = b;
  return v;
}

/*
vertex center_of_selection;
object object = NULL;
object curr_obj = NULL;// the currently selected object
object old_obj = NULL;
float temp_origin[] = { 0,0,0 }; // origin offset during origin change
*/

void object::SetLocation(double loc_X, double loc_Y, double loc_Z)
{
	this -> location[0] = loc_X;
	this -> location[1] = loc_Y;
	this -> location[2] = loc_Z;
}

void object::SetRotation(double rot_X, double rot_Y, double rot_Z)
{
	this -> rotation[0] = rot_X;
	this -> rotation[1] = rot_Y;
	this -> rotation[2] = rot_Z;
}

void object::SetScale(double sca_X, double sca_Y, double sca_Z)
{
	this -> scale[0] = sca_X;
	this -> scale[1] = sca_Y;
	this -> scale[2] = sca_Z;
}

int* object::GetLocation()
{
	return this -> location;
}

int* object::GetRotation()
{
	return this -> rotation;
}

int* object::GetScale()
{
	return this -> scale;
}

int object::GetNumVertices()
{
	return this -> num_vertices;
}

int object::GetNumFaces()
{
	return this -> num_faces;
}
void object::SetNumVertices(int num_vertices)
{
	this -> num_vertices = num_vertices;
}

void object::SetNumFaces(int num_faces)
{
	this -> num_faces = num_faces;
}

void object::AddChild(object *child){}

void object::RemoveChild(object *child){}

void object::EnableAxes(bool show_axes){}

void object::EnableOrigin(bool show_origin){}

void object::AddFrame(void){}

void object::RemoveFrame(frame *frame){}