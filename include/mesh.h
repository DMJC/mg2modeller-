#ifndef MESH_H
#define MESH_H

#include <epoxy/gl.h>
#include <vector>

class Mesh {
private:
	GLuint vao = 0;
	GLuint vbo = 0;
	GLuint ebo_triangles = 0;
	GLuint ebo_lines = 0;
	int tri_index_count = 0;
	int line_index_count = 0;
	bool dirty = true;

public:
	std::vector<float> vertex_data;
	std::vector<unsigned int> triangle_indices;
	std::vector<unsigned int> line_indices;
	std::vector<int> triangle_face_map;
	int logical_face_count = 0;

	Mesh();
	~Mesh();

	void uploadToGPU();
	void drawSolid();
	void drawWireframe();
	void drawPoints(float point_size);
	void cleanup();
	void markDirty();
	bool isDirty() const;
	bool hasData() const;
	int getVertexCount() const;
	int getTriangleCount() const;
	int getLineCount() const;
	int getLogicalFaceCount() const;
	int getFaceFromTriangle(int tri_index) const;
	GLuint getVAO() const;
	GLuint getTriEBO() const;
	GLuint getLineEBO() const;
	void getVertexPosition(int idx, float& x, float& y, float& z) const;
	void setVertexPosition(int idx, float x, float y, float z);
	void getEdgeVertices(int edge_idx, int& v0, int& v1) const;
};

#endif // MESH_H
