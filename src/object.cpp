#include "../include/object.h"
#include "../include/math3d.h"
#include <unordered_map>

GLuint wireframe_object_bo;

object::object() {
	IdentityMatrix(compensation);
	IdentityMatrix(rot_origin);
}

object::~object() {}

void object::set_object_type(type_of_object object_type){
	this -> object_type = object_type;
}

type_of_object object::get_object_type(void){
	return this -> object_type;		
}

void object::object::set_name(string name){
    this -> name = name;
}

string object::get_name(void){
    return this -> name;
}

void object::set_location(double loc_X, double loc_Y, double loc_Z)
{
	this -> location[0] = loc_X;
	this -> location[1] = loc_Y;
	this -> location[2] = loc_Z;
}

void object::set_rotation(float rot_X, float rot_Y, float rot_Z)
{
	this -> rotation[0] = rot_X;
	this -> rotation[1] = rot_Y;
	this -> rotation[2] = rot_Z;
}

void object::set_scale(float sca_X, float sca_Y, float sca_Z)
{
	this -> scale[0] = sca_X;
	this -> scale[1] = sca_Y;
	this -> scale[2] = sca_Z;
}

double* object::get_location()
{
	return this -> location;
}

float* object::get_rotation()
{
	return this -> rotation;
}

float* object::get_scale()
{
	return this -> scale;
}

int object::get_num_vertices()
{
	return this -> num_vertices;
}

int object::get_num_faces()
{
	return this -> num_faces;
}
void object::set_num_vertices(int num_vertices)
{
	this -> num_vertices = num_vertices;
}

void object::set_num_faces(int num_faces)
{
	this -> num_faces = num_faces;
}

void object::add_child(shared_ptr<object> child)
{
	child->parent = this;
	children.push_back(child);
}

void object::remove_child(shared_ptr<object> child)
{
	child->parent = nullptr;
	children.remove(child);
}

void object::add_sibling(shared_ptr<object> sib)
{
	sib->parent = this->parent;
	sibling.push_back(sib);
}

void object::remove_sibling(shared_ptr<object> sib)
{
	sib->parent = nullptr;
	sibling.remove(sib);
}

object* object::get_parent()
{
	return parent;
}

void object::set_parent(object* p)
{
	parent = p;
}

list<shared_ptr<object>>& object::get_children()
{
	return children;
}

list<shared_ptr<object>>& object::get_siblings()
{
	return sibling;
}

void object::enable_axes(bool state)
{
	this -> show_axes = state;
}

bool object::get_show_axes(void)
{
	return this -> show_axes;
}

void object::enable_origin(bool state)
{
	this -> show_origin = state;
}

void object::add_frame(void)
{
	
}

void object::remove_frame(frame *frame)
{

}

shared_ptr<object> object::clone() {
	auto copy = make_shared<object>();
	copy->set_name(name + " copy");
	copy->set_location(location[0], location[1], location[2]);
	copy->set_rotation(rotation[0], rotation[1], rotation[2]);
	copy->set_scale(scale[0], scale[1], scale[2]);
	copy->setSelectedColor(selected_color[0], selected_color[1], selected_color[2]);
	copy->setUnselectedColor(unselected_color[0], unselected_color[1], unselected_color[2]);
	copy->set_object_type(object_type);
	copy->set_num_vertices(num_vertices);
	copy->set_num_faces(num_faces);
	copy->vertices = vertices;
	copy->edges = edges;
	copy->faces = faces;

	Mesh& src = mesh;
	Mesh& dst = copy->getMesh();
	dst.vertex_data = src.vertex_data;
	dst.triangle_indices = src.triangle_indices;
	dst.line_indices = src.line_indices;
	dst.markDirty();
	return copy;
}

void object::generateMesh() {
	mesh.vertex_data.clear();
	mesh.triangle_indices.clear();
	mesh.line_indices.clear();

	if (vertices.empty()) return;

	int idx = 0;
	std::unordered_map<vertex*, int> vert_index_map;

	for (auto& v : vertices) {
		double* loc = v.get_location();
		mesh.vertex_data.push_back((float)loc[0]);
		mesh.vertex_data.push_back((float)loc[1]);
		mesh.vertex_data.push_back((float)loc[2]);
		// default normal pointing up
		mesh.vertex_data.push_back(0.0f);
		mesh.vertex_data.push_back(1.0f);
		mesh.vertex_data.push_back(0.0f);
		vert_index_map[&v] = idx++;
	}

	mesh.markDirty();
}

void object::buildModelMatrix(float* out) {
	IdentityMatrix(out);
	TranslateMatrix((float)location[0], (float)location[1], (float)location[2], out);
	if (rotation[0] != 0.0f || rotation[1] != 0.0f || rotation[2] != 0.0f) {
		RotateMatrix(rotation[0], rotation[1], rotation[2], out);
	}
	ScaleMatrix(scale[0], scale[1], scale[2], out);
}

Mesh& object::getMesh() {
	return mesh;
}

list<vertex>& object::getVertices() {
	return vertices;
}

list<face>& object::getFaces() {
	return faces;
}

float* object::getSelectedColor() {
	return selected_color;
}

float* object::getUnselectedColor() {
	return unselected_color;
}

void object::setSelectedColor(float r, float g, float b) {
	selected_color[0] = r; selected_color[1] = g; selected_color[2] = b;
}

void object::setUnselectedColor(float r, float g, float b) {
	unselected_color[0] = r; unselected_color[1] = g; unselected_color[2] = b;
}

void object::clearSubSelection() {
	selected_vertices.clear();
	selected_edges.clear();
	selected_faces.clear();
}

void object::selectFace(int idx, int mode) {
	if (mode == SEL_ADD) {
		selected_faces.insert(idx);
	} else if (mode == SEL_REMOVE) {
		selected_faces.erase(idx);
	} else {
		clearSubSelection();
		selected_faces.insert(idx);
	}
}

void object::selectEdge(int idx, int mode) {
	if (mode == SEL_ADD) {
		selected_edges.insert(idx);
	} else if (mode == SEL_REMOVE) {
		selected_edges.erase(idx);
	} else {
		clearSubSelection();
		selected_edges.insert(idx);
	}
}

void object::selectVertex(int idx, int mode) {
	if (mode == SEL_ADD) {
		selected_vertices.insert(idx);
	} else if (mode == SEL_REMOVE) {
		selected_vertices.erase(idx);
	} else {
		clearSubSelection();
		selected_vertices.insert(idx);
	}
}

const std::set<int>& object::getSelectedFaces() const { return selected_faces; }
const std::set<int>& object::getSelectedEdges() const { return selected_edges; }
const std::set<int>& object::getSelectedVertices() const { return selected_vertices; }
