#include "../include/primitive.h"
#include <cmath>
#include <memory>
#include <map>
#include <vector>

primitive::primitive(){
	this->scale[0] = 1.0f;
	this->scale[1] = 1.0f;
	this->scale[2] = 1.0f;
}

primitive::~primitive(){
}

void primitive::set_edit_mode(primitive_edit_mode mode) {
	this->edit_mode = mode;
}

primitive_edit_mode primitive::get_edit_mode(void) {
	return this->edit_mode;
}

void primitive::generateMesh() {
	mesh.vertex_data.clear();
	mesh.triangle_indices.clear();
	mesh.line_indices.clear();

	if (vertices.empty()) return;

	int idx = 0;
	for (auto& v : vertices) {
		double* loc = v.get_location();
		mesh.vertex_data.push_back((float)loc[0]);
		mesh.vertex_data.push_back((float)loc[1]);
		mesh.vertex_data.push_back((float)loc[2]);
		mesh.vertex_data.push_back(0.0f);
		mesh.vertex_data.push_back(1.0f);
		mesh.vertex_data.push_back(0.0f);
		idx++;
	}

	mesh.markDirty();
}

static void addQuadToMesh(Mesh& mesh, int v0, int v1, int v2, int v3,
						  float nx, float ny, float nz) {
	int face_id = mesh.logical_face_count++;

	mesh.triangle_indices.push_back(v0);
	mesh.triangle_indices.push_back(v1);
	mesh.triangle_indices.push_back(v2);
	mesh.triangle_face_map.push_back(face_id);

	mesh.triangle_indices.push_back(v0);
	mesh.triangle_indices.push_back(v2);
	mesh.triangle_indices.push_back(v3);
	mesh.triangle_face_map.push_back(face_id);

	mesh.line_indices.push_back(v0); mesh.line_indices.push_back(v1);
	mesh.line_indices.push_back(v1); mesh.line_indices.push_back(v2);
	mesh.line_indices.push_back(v2); mesh.line_indices.push_back(v3);
	mesh.line_indices.push_back(v3); mesh.line_indices.push_back(v0);
}

static void addTriToMesh(Mesh& mesh, int v0, int v1, int v2) {
	int face_id = mesh.logical_face_count++;
	mesh.triangle_indices.push_back(v0);
	mesh.triangle_indices.push_back(v1);
	mesh.triangle_indices.push_back(v2);
	mesh.triangle_face_map.push_back(face_id);

	mesh.line_indices.push_back(v0); mesh.line_indices.push_back(v1);
	mesh.line_indices.push_back(v1); mesh.line_indices.push_back(v2);
	mesh.line_indices.push_back(v2); mesh.line_indices.push_back(v0);
}

// Helper to add a vertex with position and normal to mesh data
static int addVertex(Mesh& mesh, float x, float y, float z, float nx, float ny, float nz) {
	int idx = mesh.vertex_data.size() / 6;
	mesh.vertex_data.push_back(x);
	mesh.vertex_data.push_back(y);
	mesh.vertex_data.push_back(z);
	mesh.vertex_data.push_back(nx);
	mesh.vertex_data.push_back(ny);
	mesh.vertex_data.push_back(nz);
	return idx;
}

plane::plane(int resolution, scene &curr_scene){
	auto obj = make_shared<plane>(*this);
	obj->set_name("Plane");
	obj->set_location(0.0, 0.0, 0.0);
	obj->set_rotation(0.0, 0.0, 0.0);
	obj->set_scale(1.0, 1.0, 1.0);

	Mesh& m = obj->getMesh();
	m.vertex_data.clear();
	m.triangle_indices.clear();
	m.triangle_face_map.clear();
	m.logical_face_count = 0;
	m.line_indices.clear();

	int res = resolution + 1;
	float step = 2.0f / res;

	for (int z = 0; z <= res; z++) {
		for (int x = 0; x <= res; x++) {
			float px = -1.0f + x * step;
			float pz = -1.0f + z * step;
			addVertex(m, px, 0.0f, pz, 0.0f, 1.0f, 0.0f);
			obj->getVertices().push_back(vertex(px, 0.0f, pz));
		}
	}

	int cols = res + 1;
	for (int z = 0; z < res; z++) {
		for (int x = 0; x < res; x++) {
			int v0 = z * cols + x;
			int v1 = z * cols + x + 1;
			int v2 = (z + 1) * cols + x + 1;
			int v3 = (z + 1) * cols + x;
			addQuadToMesh(m, v0, v1, v2, v3, 0.0f, 1.0f, 0.0f);
		}
	}

	obj->set_num_vertices(m.vertex_data.size() / 6);
	obj->set_num_faces(res * res);
	m.markDirty();
	curr_scene.AddObject(obj);
	cout << "Created Plane with " << obj->get_num_vertices() << " verts, " << obj->get_num_faces() << " faces" << endl;
}

plane::plane(int horizontal_subdiv, int vertical_subdiv, int conic_subdiv, int spherical_long_subdiv, int spherical_lat_subdiv, int x_rotation, int torus_angle, int top_radius, int bot_radius, int radius, int spherical_radius, int conic_angle, int height, int rot_subdiv, scene &curr_scene){
	plane(1, curr_scene);
}

cube::cube(int resolution, scene &curr_scene){
	auto obj = make_shared<cube>(*this);
	obj->set_name("Cube");
	obj->set_location(0.0, 0.0, 0.0);
	obj->set_rotation(0.0, 0.0, 0.0);
	obj->set_scale(1.0, 1.0, 1.0);

	Mesh& m = obj->getMesh();
	m.vertex_data.clear();
	m.triangle_indices.clear();
	m.triangle_face_map.clear();
	m.logical_face_count = 0;
	m.line_indices.clear();

	// Unit cube: 24 vertices (4 per face for correct normals)
	// Front face (z = 1)
	int v0  = addVertex(m, -1, -1,  1,  0,  0,  1);
	int v1  = addVertex(m,  1, -1,  1,  0,  0,  1);
	int v2  = addVertex(m,  1,  1,  1,  0,  0,  1);
	int v3  = addVertex(m, -1,  1,  1,  0,  0,  1);
	// Back face (z = -1)
	int v4  = addVertex(m,  1, -1, -1,  0,  0, -1);
	int v5  = addVertex(m, -1, -1, -1,  0,  0, -1);
	int v6  = addVertex(m, -1,  1, -1,  0,  0, -1);
	int v7  = addVertex(m,  1,  1, -1,  0,  0, -1);
	// Top face (y = 1)
	int v8  = addVertex(m, -1,  1,  1,  0,  1,  0);
	int v9  = addVertex(m,  1,  1,  1,  0,  1,  0);
	int v10 = addVertex(m,  1,  1, -1,  0,  1,  0);
	int v11 = addVertex(m, -1,  1, -1,  0,  1,  0);
	// Bottom face (y = -1)
	int v12 = addVertex(m, -1, -1, -1,  0, -1,  0);
	int v13 = addVertex(m,  1, -1, -1,  0, -1,  0);
	int v14 = addVertex(m,  1, -1,  1,  0, -1,  0);
	int v15 = addVertex(m, -1, -1,  1,  0, -1,  0);
	// Right face (x = 1)
	int v16 = addVertex(m,  1, -1,  1,  1,  0,  0);
	int v17 = addVertex(m,  1, -1, -1,  1,  0,  0);
	int v18 = addVertex(m,  1,  1, -1,  1,  0,  0);
	int v19 = addVertex(m,  1,  1,  1,  1,  0,  0);
	// Left face (x = -1)
	int v20 = addVertex(m, -1, -1, -1, -1,  0,  0);
	int v21 = addVertex(m, -1, -1,  1, -1,  0,  0);
	int v22 = addVertex(m, -1,  1,  1, -1,  0,  0);
	int v23 = addVertex(m, -1,  1, -1, -1,  0,  0);

	addQuadToMesh(m, v0, v1, v2, v3, 0, 0, 1);      // front
	addQuadToMesh(m, v4, v5, v6, v7, 0, 0, -1);      // back
	addQuadToMesh(m, v8, v9, v10, v11, 0, 1, 0);     // top
	addQuadToMesh(m, v12, v13, v14, v15, 0, -1, 0);  // bottom
	addQuadToMesh(m, v16, v17, v18, v19, 1, 0, 0);   // right
	addQuadToMesh(m, v20, v21, v22, v23, -1, 0, 0);  // left

	// Also store logical vertices
	obj->getVertices().push_back(vertex(-1, -1,  1));
	obj->getVertices().push_back(vertex( 1, -1,  1));
	obj->getVertices().push_back(vertex( 1,  1,  1));
	obj->getVertices().push_back(vertex(-1,  1,  1));
	obj->getVertices().push_back(vertex(-1, -1, -1));
	obj->getVertices().push_back(vertex( 1, -1, -1));
	obj->getVertices().push_back(vertex( 1,  1, -1));
	obj->getVertices().push_back(vertex(-1,  1, -1));

	obj->set_num_vertices(8);
	obj->set_num_faces(6);
	m.markDirty();
	curr_scene.AddObject(obj);
	cout << "Created Cube" << endl;
}

cube::cube(int cube_horizontal_subdiv, int cube_vertical_subdiv, int cube_conic_subdiv, int cube_spherical_long_subdiv, int cube_spherical_lat_subdiv, int cube_x_rotation, int cube_torus_angle, int cube_top_radius, int cube_bot_radius, int cube_radius, int cube_spherical_radius, int cube_conic_angle, int cube_height, int cube_rot_subdiv, scene &curr_scene){
	cube(1, curr_scene);
}

sphere::sphere(int horizontal_subdiv, int vertical_subdiv, scene &curr_scene){
	auto obj = make_shared<sphere>(*this);
	obj->set_name("Sphere");
	obj->set_location(0.0, 0.0, 0.0);
	obj->set_rotation(0.0, 0.0, 0.0);
	obj->set_scale(1.0, 1.0, 1.0);

	int stacks = vertical_subdiv < 4 ? 4 : vertical_subdiv;
	int slices = horizontal_subdiv < 4 ? 4 : horizontal_subdiv;
	float radius = 1.0f;

	Mesh& m = obj->getMesh();
	m.vertex_data.clear();
	m.triangle_indices.clear();
	m.triangle_face_map.clear();
	m.logical_face_count = 0;
	m.line_indices.clear();

	// Generate vertices
	for (int i = 0; i <= stacks; i++) {
		float phi = M_PI * (float)i / (float)stacks;
		for (int j = 0; j <= slices; j++) {
			float theta = 2.0f * M_PI * (float)j / (float)slices;
			float x = radius * sinf(phi) * cosf(theta);
			float y = radius * cosf(phi);
			float z = radius * sinf(phi) * sinf(theta);
			float nx = sinf(phi) * cosf(theta);
			float ny = cosf(phi);
			float nz = sinf(phi) * sinf(theta);
			addVertex(m, x, y, z, nx, ny, nz);
		}
	}

	for (int i = 0; i < stacks; i++) {
		for (int j = 0; j < slices; j++) {
			int v0 = i * (slices + 1) + j;
			int v1 = v0 + 1;
			int v2 = v0 + (slices + 1);
			int v3 = v2 + 1;

			int face_id = m.logical_face_count++;
			if (i != 0) {
				m.triangle_indices.push_back(v0);
				m.triangle_indices.push_back(v2);
				m.triangle_indices.push_back(v1);
				m.triangle_face_map.push_back(face_id);
			}
			if (i != stacks - 1) {
				m.triangle_indices.push_back(v1);
				m.triangle_indices.push_back(v2);
				m.triangle_indices.push_back(v3);
				m.triangle_face_map.push_back(face_id);
			}

			m.line_indices.push_back(v0); m.line_indices.push_back(v1);
			m.line_indices.push_back(v0); m.line_indices.push_back(v2);
		}
	}

	obj->set_num_vertices((stacks + 1) * (slices + 1));
	obj->set_num_faces(stacks * slices * 2);
	m.markDirty();
	curr_scene.AddObject(obj);
	cout << "Created Sphere" << endl;
}

sphere::sphere(int horizontal_subdiv, int vertical_subdiv, int conic_subdiv, int spherical_long_subdiv, int spherical_lat_subdiv, int x_rotation, int torus_angle, int top_radius, int bot_radius, int radius, int spherical_radius, int conic_angle, int height, int rot_subdiv){

}

cone::cone(int horizontal_subdiv, int vertical_subdiv, scene &curr_scene){
	auto obj = make_shared<cone>(*this);
	obj->set_name("Cone");
	obj->set_location(0.0, 0.0, 0.0);
	obj->set_rotation(0.0, 0.0, 0.0);
	obj->set_scale(1.0, 1.0, 1.0);

	int slices = horizontal_subdiv < 4 ? 4 : horizontal_subdiv;
	float height = 2.0f;
	float half_h = height * 0.5f;
	float radius = 1.0f;

	Mesh& m = obj->getMesh();
	m.vertex_data.clear();
	m.triangle_indices.clear();
	m.triangle_face_map.clear();
	m.logical_face_count = 0;
	m.line_indices.clear();

	int apex = addVertex(m, 0.0f, half_h, 0.0f, 0.0f, 1.0f, 0.0f);

	int base_start = m.vertex_data.size() / 6;
	for (int j = 0; j <= slices; j++) {
		float theta = 2.0f * M_PI * (float)j / (float)slices;
		float x = radius * cosf(theta);
		float z = radius * sinf(theta);
		float slope = radius / height;
		float ny = slope;
		float nx = cosf(theta);
		float nz = sinf(theta);
		float len = sqrtf(nx*nx + ny*ny + nz*nz);
		addVertex(m, x, -half_h, z, nx/len, ny/len, nz/len);
	}

	for (int j = 0; j < slices; j++) {
		addTriToMesh(m, apex, base_start + j + 1, base_start + j);
		m.line_indices.push_back(apex); m.line_indices.push_back(base_start + j);
	}

	int base_center = addVertex(m, 0.0f, -half_h, 0.0f, 0.0f, -1.0f, 0.0f);
	int base_ring2 = m.vertex_data.size() / 6;
	for (int j = 0; j <= slices; j++) {
		float theta = 2.0f * M_PI * (float)j / (float)slices;
		float x = radius * cosf(theta);
		float z = radius * sinf(theta);
		addVertex(m, x, -half_h, z, 0.0f, -1.0f, 0.0f);
	}
	for (int j = 0; j < slices; j++) {
		addTriToMesh(m, base_center, base_ring2 + j, base_ring2 + j + 1);
	}

	obj->set_num_vertices(m.vertex_data.size() / 6);
	obj->set_num_faces(slices * 2);
	m.markDirty();
	curr_scene.AddObject(obj);
	cout << "Created Cone" << endl;
}

cone::cone(int cone_horizontal_subdiv, int cone_vertical_subdiv, int cone_conic_subdiv, int cone_spherical_long_subdiv, int cone_spherical_lat_subdiv, int cone_x_rotation, int cone_torus_angle, int cone_top_radius, int cone_bot_radius, int cone_radius, int cone_spherical_radius, int cone_conic_angle, int cone_height, int cone_rot_subdiv, scene &curr_scene){
	cone(cone_horizontal_subdiv, cone_vertical_subdiv, curr_scene);
}

cylinder::cylinder(int horizontal_subdiv, int vertical_subdiv, int top_radius, scene &curr_scene){
	auto obj = make_shared<cylinder>(*this);
	obj->set_name("Cylinder");
	obj->set_location(0.0, 0.0, 0.0);
	obj->set_rotation(0.0, 0.0, 0.0);
	obj->set_scale(1.0, 1.0, 1.0);

	int slices = horizontal_subdiv < 4 ? 4 : horizontal_subdiv;
	int stacks = vertical_subdiv < 1 ? 1 : vertical_subdiv;
	float height = 2.0f;
	float half_h = height * 0.5f;
	float radius = 1.0f;

	Mesh& m = obj->getMesh();
	m.vertex_data.clear();
	m.triangle_indices.clear();
	m.triangle_face_map.clear();
	m.logical_face_count = 0;
	m.line_indices.clear();

	int side_start = m.vertex_data.size() / 6;
	for (int i = 0; i <= stacks; i++) {
		float y = -half_h + (float)i / (float)stacks * height;
		for (int j = 0; j <= slices; j++) {
			float theta = 2.0f * M_PI * (float)j / (float)slices;
			float x = radius * cosf(theta);
			float z = radius * sinf(theta);
			addVertex(m, x, y, z, cosf(theta), 0.0f, sinf(theta));
		}
	}

	for (int i = 0; i < stacks; i++) {
		for (int j = 0; j < slices; j++) {
			int v0 = side_start + i * (slices + 1) + j;
			int v1 = v0 + 1;
			int v2 = v0 + (slices + 1);
			int v3 = v2 + 1;
			int face_id = m.logical_face_count++;
			m.triangle_indices.push_back(v0);
			m.triangle_indices.push_back(v2);
			m.triangle_indices.push_back(v1);
			m.triangle_face_map.push_back(face_id);
			m.triangle_indices.push_back(v1);
			m.triangle_indices.push_back(v2);
			m.triangle_indices.push_back(v3);
			m.triangle_face_map.push_back(face_id);
			m.line_indices.push_back(v0); m.line_indices.push_back(v1);
			m.line_indices.push_back(v0); m.line_indices.push_back(v2);
		}
	}

	int top_center = addVertex(m, 0.0f, half_h, 0.0f, 0.0f, 1.0f, 0.0f);
	int top_ring = m.vertex_data.size() / 6;
	for (int j = 0; j <= slices; j++) {
		float theta = 2.0f * M_PI * (float)j / (float)slices;
		addVertex(m, radius * cosf(theta), half_h, radius * sinf(theta), 0.0f, 1.0f, 0.0f);
	}
	for (int j = 0; j < slices; j++) {
		addTriToMesh(m, top_center, top_ring + j, top_ring + j + 1);
	}

	int bot_center = addVertex(m, 0.0f, -half_h, 0.0f, 0.0f, -1.0f, 0.0f);
	int bot_ring = m.vertex_data.size() / 6;
	for (int j = 0; j <= slices; j++) {
		float theta = 2.0f * M_PI * (float)j / (float)slices;
		addVertex(m, radius * cosf(theta), -half_h, radius * sinf(theta), 0.0f, -1.0f, 0.0f);
	}
	for (int j = 0; j < slices; j++) {
		addTriToMesh(m, bot_center, bot_ring + j + 1, bot_ring + j);
	}

	obj->set_num_vertices(m.vertex_data.size() / 6);
	obj->set_num_faces(stacks * slices * 2 + slices * 2);
	m.markDirty();
	curr_scene.AddObject(obj);
	cout << "Created Cylinder" << endl;
}

cylinder::cylinder(int cylinder_horizontal_subdiv, int cylinder_vertical_subdiv, int cylinder_conic_subdiv, int cylinder_spherical_long_subdiv, int cylinder_spherical_lat_subdiv, int cylinder_x_rotation, int cylinder_torus_angle, int cylinder_top_radius, int cylinder_bot_radius, int cylinder_radius, int cylinder_spherical_radius, int cylinder_conic_angle, int cylinder_height, int cylinder_rot_subdiv, scene &curr_scene){
	cylinder(cylinder_horizontal_subdiv, cylinder_vertical_subdiv, cylinder_top_radius, curr_scene);
}

geosphere::geosphere(int resolution, scene &curr_scene){
	auto obj = make_shared<geosphere>(*this);
	obj->set_name("Geosphere");
	obj->set_location(0.0, 0.0, 0.0);
	obj->set_rotation(0.0, 0.0, 0.0);
	obj->set_scale(1.0, 1.0, 1.0);

	int subdivisions = resolution < 1 ? 1 : resolution;

	// Icosahedron base vertices
	float t = (1.0f + sqrtf(5.0f)) / 2.0f;

	struct vec3f { float x, y, z; };
	std::vector<vec3f> verts = {
		{-1,  t,  0}, { 1,  t,  0}, {-1, -t,  0}, { 1, -t,  0},
		{ 0, -1,  t}, { 0,  1,  t}, { 0, -1, -t}, { 0,  1, -t},
		{ t,  0, -1}, { t,  0,  1}, {-t,  0, -1}, {-t,  0,  1}
	};

	// Normalize to unit sphere
	for (auto& v : verts) {
		float len = sqrtf(v.x*v.x + v.y*v.y + v.z*v.z);
		v.x /= len; v.y /= len; v.z /= len;
	}

	struct tri { int v0, v1, v2; };
	std::vector<tri> faces = {
		{0,11,5}, {0,5,1}, {0,1,7}, {0,7,10}, {0,10,11},
		{1,5,9}, {5,11,4}, {11,10,2}, {10,7,6}, {7,1,8},
		{3,9,4}, {3,4,2}, {3,2,6}, {3,6,8}, {3,8,9},
		{4,9,5}, {2,4,11}, {6,2,10}, {8,6,7}, {9,8,1}
	};

	// Subdivide: split each triangle into 4 by adding midpoints
	auto getMidpoint = [&](int i0, int i1, std::map<uint64_t, int>& cache) -> int {
		uint64_t key = (i0 < i1) ? ((uint64_t)i0 << 32 | i1) : ((uint64_t)i1 << 32 | i0);
		auto it = cache.find(key);
		if (it != cache.end()) return it->second;
		vec3f& a = verts[i0];
		vec3f& b = verts[i1];
		vec3f mid = { (a.x+b.x)*0.5f, (a.y+b.y)*0.5f, (a.z+b.z)*0.5f };
		float len = sqrtf(mid.x*mid.x + mid.y*mid.y + mid.z*mid.z);
		mid.x /= len; mid.y /= len; mid.z /= len;
		int idx = verts.size();
		verts.push_back(mid);
		cache[key] = idx;
		return idx;
	};

	for (int s = 1; s < subdivisions; s++) {
		std::map<uint64_t, int> midpoint_cache;
		std::vector<tri> new_faces;
		for (auto& f : faces) {
			int a = getMidpoint(f.v0, f.v1, midpoint_cache);
			int b = getMidpoint(f.v1, f.v2, midpoint_cache);
			int c = getMidpoint(f.v2, f.v0, midpoint_cache);
			new_faces.push_back({f.v0, a, c});
			new_faces.push_back({f.v1, b, a});
			new_faces.push_back({f.v2, c, b});
			new_faces.push_back({a, b, c});
		}
		faces = new_faces;
	}

	Mesh& m = obj->getMesh();
	m.vertex_data.clear();
	m.triangle_indices.clear();
	m.triangle_face_map.clear();
	m.logical_face_count = 0;
	m.line_indices.clear();

	for (auto& v : verts) {
		addVertex(m, v.x, v.y, v.z, v.x, v.y, v.z);
	}

	for (auto& f : faces) {
		addTriToMesh(m, f.v0, f.v1, f.v2);
	}

	obj->set_num_vertices(verts.size());
	obj->set_num_faces(m.logical_face_count);
	m.markDirty();
	curr_scene.AddObject(obj);
	cout << "Created Geosphere (subdivisions=" << subdivisions << " verts=" << verts.size() << " faces=" << faces.size() << ")" << endl;
}

torus::torus(int horizontal_subdiv, int vertical_subdiv, float torus_radius, scene &curr_scene){
	auto obj = make_shared<torus>(*this);
	obj->set_name("Torus");
	obj->set_location(0.0, 0.0, 0.0);
	obj->set_rotation(0.0, 0.0, 0.0);
	obj->set_scale(1.0, 1.0, 1.0);

	int slices = horizontal_subdiv < 4 ? 4 : horizontal_subdiv;
	int rings = vertical_subdiv < 4 ? 4 : vertical_subdiv;
	float R = 1.0f;     // major radius
	float r = torus_radius > 0 ? torus_radius : 0.4f;  // minor radius

	Mesh& m = obj->getMesh();
	m.vertex_data.clear();
	m.triangle_indices.clear();
	m.triangle_face_map.clear();
	m.logical_face_count = 0;
	m.line_indices.clear();

	for (int i = 0; i <= rings; i++) {
		float phi = 2.0f * M_PI * (float)i / (float)rings;
		for (int j = 0; j <= slices; j++) {
			float theta = 2.0f * M_PI * (float)j / (float)slices;
			float x = (R + r * cosf(theta)) * cosf(phi);
			float y = r * sinf(theta);
			float z = (R + r * cosf(theta)) * sinf(phi);
			float nx = cosf(theta) * cosf(phi);
			float ny = sinf(theta);
			float nz = cosf(theta) * sinf(phi);
			addVertex(m, x, y, z, nx, ny, nz);
		}
	}

	for (int i = 0; i < rings; i++) {
		for (int j = 0; j < slices; j++) {
			int v0 = i * (slices + 1) + j;
			int v1 = v0 + 1;
			int v2 = v0 + (slices + 1);
			int v3 = v2 + 1;
			int face_id = m.logical_face_count++;
			m.triangle_indices.push_back(v0);
			m.triangle_indices.push_back(v2);
			m.triangle_indices.push_back(v1);
			m.triangle_face_map.push_back(face_id);
			m.triangle_indices.push_back(v1);
			m.triangle_indices.push_back(v2);
			m.triangle_indices.push_back(v3);
			m.triangle_face_map.push_back(face_id);
			m.line_indices.push_back(v0); m.line_indices.push_back(v1);
			m.line_indices.push_back(v0); m.line_indices.push_back(v2);
		}
	}

	obj->set_num_vertices(m.vertex_data.size() / 6);
	obj->set_num_faces(rings * slices * 2);
	m.markDirty();
	curr_scene.AddObject(obj);
	cout << "Created Torus" << endl;
}

torus::torus(int torus_horizontal_subdiv, int torus_vertical_subdiv, int torus_conic_subdiv, int torus_spherical_long_subdiv, int torus_spherical_lat_subdiv, int torus_x_rotation, int torus_angle, int torus_top_radius, int torus_bot_radius, int torus_radius, int torus_spherical_radius, int torus_conic_angle, int torus_height, int torus_rot_subdiv, scene &curr_scene){
	torus(torus_horizontal_subdiv, torus_vertical_subdiv, 0.4f, curr_scene);
}

rounded_cube::rounded_cube(int horizontal_subdiv, int vertical_subdiv, scene &curr_scene){
	// Create as a regular cube for now
	cube(1, curr_scene);
}

rounded_cube::rounded_cube(int rounded_cube_horizontal_subdiv, int rounded_cube_vertical_subdiv, int rounded_cube_conic_subdiv, int rounded_cube_spherical_long_subdiv, int rounded_cube_spherical_lat_subdiv, int rounded_cube_x_rotation, int rounded_cube_torus_angle, int rounded_cube_top_radius, int rounded_cube_bot_radius, int rounded_cube_radius, int rounded_cube_spherical_radius, int rounded_cube_conic_angle, int rounded_cube_height, int rounded_cube_rot_subdiv, scene &curr_scene){
	rounded_cube(rounded_cube_horizontal_subdiv, rounded_cube_vertical_subdiv, curr_scene);
}

rounded_cylinder::rounded_cylinder(int horizontal_subdiv, int vertical_subdiv, scene &curr_scene){
	// Create as a regular cylinder for now
	cylinder(horizontal_subdiv, vertical_subdiv, 1, curr_scene);
}

rounded_cylinder::rounded_cylinder(int rounded_cylinder_horizontal_subdiv, int rounded_cylinder_vertical_subdiv, int rounded_cylinder_conic_subdiv, int rounded_cylinder_spherical_long_subdiv, int rounded_cylinder_spherical_lat_subdiv, int rounded_cylinder_x_rotation, int rounded_cylinder_torus_angle, int rounded_cylinder_top_radius, int rounded_cylinder_bot_radius, int rounded_cylinder_radius, int rounded_cylinder_spherical_radius, int rounded_cylinder_conic_angle, int rounded_cylinder_height, int rounded_cylinder_rot_subdiv, scene &curr_scene){
	rounded_cylinder(rounded_cylinder_horizontal_subdiv, rounded_cylinder_vertical_subdiv, curr_scene);
}

shape::shape(int horizontal_subdiv, int vertical_subdiv, int conic_subdiv, int spherical_long_subdiv, int spherical_lat_subdiv, int x_rotation, int angle, float top_radius, float bottom_radius, float radius, int spherical_radius, float conic_angle, float height, int rot_subdiv, scene &curr_scene){
	// Shape is a generic shape-of-revolution generator - used internally
}
