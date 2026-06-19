#include "../include/mesh.h"

Mesh::Mesh() {}

Mesh::~Mesh() {
	cleanup();
}

void Mesh::uploadToGPU() {
	if (vertex_data.empty()) return;

	if (!vao) {
		glGenVertexArrays(1, &vao);
		glGenBuffers(1, &vbo);
		glGenBuffers(1, &ebo_triangles);
		glGenBuffers(1, &ebo_lines);
	}

	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, vertex_data.size() * sizeof(float),
				 vertex_data.data(), GL_DYNAMIC_DRAW);

	// position attribute: 3 floats at offset 0, stride 6 floats
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// normal attribute: 3 floats at offset 3, stride 6 floats
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	if (!triangle_indices.empty()) {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_triangles);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER,
					 triangle_indices.size() * sizeof(unsigned int),
					 triangle_indices.data(), GL_DYNAMIC_DRAW);
		tri_index_count = triangle_indices.size();
	}

	glBindVertexArray(0);

	if (!line_indices.empty()) {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_lines);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER,
					 line_indices.size() * sizeof(unsigned int),
					 line_indices.data(), GL_DYNAMIC_DRAW);
		line_index_count = line_indices.size();
	}

	dirty = false;
}

void Mesh::drawSolid() {
	if (!vao || tri_index_count == 0) return;
	glBindVertexArray(vao);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_triangles);
	glDrawElements(GL_TRIANGLES, tri_index_count, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void Mesh::drawWireframe() {
	if (!vao || line_index_count == 0) return;
	glBindVertexArray(vao);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_lines);
	glDrawElements(GL_LINES, line_index_count, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void Mesh::cleanup() {
	if (vao) {
		glDeleteVertexArrays(1, &vao);
		vao = 0;
	}
	if (vbo) {
		glDeleteBuffers(1, &vbo);
		vbo = 0;
	}
	if (ebo_triangles) {
		glDeleteBuffers(1, &ebo_triangles);
		ebo_triangles = 0;
	}
	if (ebo_lines) {
		glDeleteBuffers(1, &ebo_lines);
		ebo_lines = 0;
	}
	tri_index_count = 0;
	line_index_count = 0;
}

void Mesh::markDirty() {
	dirty = true;
}

bool Mesh::isDirty() const {
	return dirty;
}

bool Mesh::hasData() const {
	return !vertex_data.empty();
}

void Mesh::drawPoints(float point_size) {
	if (!vao) return;
	int count = vertex_data.size() / 6;
	if (count == 0) return;
	glPointSize(point_size);
	glBindVertexArray(vao);
	glDrawArrays(GL_POINTS, 0, count);
	glBindVertexArray(0);
}

int Mesh::getVertexCount() const { return vertex_data.size() / 6; }
int Mesh::getTriangleCount() const { return tri_index_count / 3; }
int Mesh::getLineCount() const { return line_index_count / 2; }
GLuint Mesh::getVAO() const { return vao; }
GLuint Mesh::getTriEBO() const { return ebo_triangles; }
GLuint Mesh::getLineEBO() const { return ebo_lines; }

void Mesh::getVertexPosition(int idx, float& x, float& y, float& z) const {
	int base = idx * 6;
	if (base + 2 < (int)vertex_data.size()) {
		x = vertex_data[base];
		y = vertex_data[base + 1];
		z = vertex_data[base + 2];
	} else {
		x = y = z = 0.0f;
	}
}

void Mesh::setVertexPosition(int idx, float x, float y, float z) {
	int base = idx * 6;
	if (base + 2 < (int)vertex_data.size()) {
		vertex_data[base] = x;
		vertex_data[base + 1] = y;
		vertex_data[base + 2] = z;
		dirty = true;
	}
}

void Mesh::getEdgeVertices(int edge_idx, int& v0, int& v1) const {
	int base = edge_idx * 2;
	if (base + 1 < (int)line_indices.size()) {
		v0 = line_indices[base];
		v1 = line_indices[base + 1];
	} else {
		v0 = v1 = 0;
	}
}

int Mesh::getLogicalFaceCount() const { return logical_face_count; }

int Mesh::getFaceFromTriangle(int tri_index) const {
	if (tri_index >= 0 && tri_index < (int)triangle_face_map.size())
		return triangle_face_map[tri_index];
	return tri_index;
}
