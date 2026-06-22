#include "../include/view.h"
#include "../include/scene.h"
#include "../include/gui/tsgui.h"
#include "../include/math3d.h"
#include "../include/tools.h"
#include <fstream>
#include <sstream>
#include <map>
#include <array>

// ============================================================
// Shader sources
// ============================================================

static const char* solid_vert_src = R"(
#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormal;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform mat3 normalMatrix;
out vec3 FragPos;
out vec3 Normal;
void main() {
    vec4 worldPos = model * vec4(aPos, 1.0);
    FragPos = worldPos.xyz;
    Normal = normalMatrix * aNormal;
    gl_Position = projection * view * worldPos;
}
)";

static const char* solid_frag_src = R"(
#version 330 core
in vec3 FragPos;
in vec3 Normal;
uniform vec3 lightDir;
uniform vec3 lightColor;
uniform vec3 objectColor;
uniform float ambient;
uniform float alpha;
out vec4 FragColor;
void main() {
    vec3 norm = normalize(Normal);
    float diff = max(dot(norm, normalize(-lightDir)), 0.0);
    vec3 result = (ambient + diff) * lightColor * objectColor;
    FragColor = vec4(result, alpha);
}
)";

static const char* wire_vert_src = R"(
#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormal;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
void main() {
    gl_Position = projection * view * model * vec4(aPos, 1.0);
}
)";

static const char* wire_frag_src = R"(
#version 330 core
uniform vec3 lineColor;
out vec4 FragColor;
void main() {
    FragColor = vec4(lineColor, 1.0);
}
)";

// Vertex-color shader: uses aNormal channel as RGB color (for axes, gizmos)
static const char* vertcolor_vert_src = R"(
#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aColor;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
out vec3 vColor;
void main() {
    vColor = aColor;
    gl_Position = projection * view * model * vec4(aPos, 1.0);
}
)";

static const char* vertcolor_frag_src = R"(
#version 330 core
in vec3 vColor;
out vec4 FragColor;
void main() {
    FragColor = vec4(vColor, 1.0);
}
)";

static const char* grid_vert_src = R"(
#version 330 core
layout(location = 0) in vec3 aPos;
uniform mat4 view;
uniform mat4 projection;
out vec3 nearPoint;
out vec3 farPoint;
out mat4 fragView;
out mat4 fragProj;

vec3 unprojectPoint(float x, float y, float z, mat4 v, mat4 p) {
    mat4 viewInv = inverse(v);
    mat4 projInv = inverse(p);
    vec4 unprojectedPoint = viewInv * projInv * vec4(x, y, z, 1.0);
    return unprojectedPoint.xyz / unprojectedPoint.w;
}

void main() {
    nearPoint = unprojectPoint(aPos.x, aPos.y, 0.0, view, projection);
    farPoint = unprojectPoint(aPos.x, aPos.y, 1.0, view, projection);
    fragView = view;
    fragProj = projection;
    gl_Position = vec4(aPos, 1.0);
}
)";

static const char* grid_frag_src = R"(
#version 330 core
in vec3 nearPoint;
in vec3 farPoint;
in mat4 fragView;
in mat4 fragProj;
uniform vec3 gridColor;
uniform float gridScale;
out vec4 FragColor;

vec4 grid(vec3 fragPos3D, float scale) {
    vec2 coord = fragPos3D.xz * scale;
    vec2 derivative = fwidth(coord);
    vec2 grid = abs(fract(coord - 0.5) - 0.5) / derivative;
    float line = min(grid.x, grid.y);
    float minimumz = min(derivative.y, 1.0);
    float minimumx = min(derivative.x, 1.0);
    vec4 color = vec4(gridColor, 1.0 - min(line, 1.0));
    if (fragPos3D.x > -0.1 * minimumx && fragPos3D.x < 0.1 * minimumx)
        color.z = 1.0;
    if (fragPos3D.z > -0.1 * minimumz && fragPos3D.z < 0.1 * minimumz)
        color.x = 1.0;
    return color;
}

float computeDepth(vec3 pos) {
    vec4 clip_space_pos = fragProj * fragView * vec4(pos.xyz, 1.0);
    return (clip_space_pos.z / clip_space_pos.w) * 0.5 + 0.5;
}

float computeLinearDepth(vec3 pos) {
    float near = 0.1;
    float far = 1000.0;
    vec4 clip_space_pos = fragProj * fragView * vec4(pos.xyz, 1.0);
    float clip_space_depth = clip_space_pos.z / clip_space_pos.w;
    float linearDepth = (2.0 * near * far) / (far + near - clip_space_depth * (far - near));
    return linearDepth / far;
}

void main() {
    float t = -nearPoint.y / (farPoint.y - nearPoint.y);
    if (t < 0.0) discard;
    vec3 fragPos3D = nearPoint + t * (farPoint - nearPoint);

    gl_FragDepth = computeDepth(fragPos3D);

    float linearDepth = computeLinearDepth(fragPos3D);
    float fading = max(0.0, (1.0 - linearDepth));

    FragColor = grid(fragPos3D, gridScale) + grid(fragPos3D, gridScale * 0.1);
    FragColor.a *= fading;
    if (FragColor.a < 0.01) discard;
}
)";

// Pick shader: outputs gl_PrimitiveID as color for sub-element picking
static const char* pick_vert_src = R"(
#version 330 core
layout(location = 0) in vec3 aPos;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
void main() {
    gl_PointSize = 10.0;
    gl_Position = projection * view * model * vec4(aPos, 1.0);
}
)";

static const char* pick_frag_src = R"(
#version 330 core
out vec4 FragColor;
void main() {
    int id = gl_PrimitiveID + 1;
    FragColor = vec4(
        float(id & 0xFF) / 255.0,
        float((id >> 8) & 0xFF) / 255.0,
        float((id >> 16) & 0xFF) / 255.0,
        1.0
    );
}
)";

// ============================================================
// Helper: generate arrow mesh along an axis with a given color
// ============================================================
static void buildArrowMesh(Mesh& m, float dx, float dy, float dz, float r, float g, float b, float length) {
	m.vertex_data.clear();
	m.triangle_indices.clear();
	m.line_indices.clear();

	auto addV = [&](float x, float y, float z) -> int {
		int idx = m.vertex_data.size() / 6;
		m.vertex_data.push_back(x); m.vertex_data.push_back(y); m.vertex_data.push_back(z);
		m.vertex_data.push_back(r); m.vertex_data.push_back(g); m.vertex_data.push_back(b);
		return idx;
	};

	int v0 = addV(0, 0, 0);
	int v1 = addV(dx * length, dy * length, dz * length);
	m.line_indices.push_back(v0);
	m.line_indices.push_back(v1);

	// arrowhead: small cone at the tip
	float tip = length;
	float base = length * 0.85f;
	float rad = length * 0.05f;
	int segments = 8;
	int tip_v = addV(dx * tip, dy * tip, dz * tip);

	float perp1x, perp1y, perp1z, perp2x, perp2y, perp2z;
	if (fabs(dx) < 0.9f) { perp1x = 0; perp1y = -dz; perp1z = dy; }
	else                  { perp1x = -dz; perp1y = 0; perp1z = dx; }
	float len = sqrtf(perp1x*perp1x + perp1y*perp1y + perp1z*perp1z);
	if (len > 0) { perp1x /= len; perp1y /= len; perp1z /= len; }
	perp2x = dy*perp1z - dz*perp1y;
	perp2y = dz*perp1x - dx*perp1z;
	perp2z = dx*perp1y - dy*perp1x;

	int ring_start = m.vertex_data.size() / 6;
	for (int i = 0; i < segments; i++) {
		float a = 2.0f * M_PI * i / segments;
		float cx = dx*base + (perp1x*cosf(a) + perp2x*sinf(a)) * rad;
		float cy = dy*base + (perp1y*cosf(a) + perp2y*sinf(a)) * rad;
		float cz = dz*base + (perp1z*cosf(a) + perp2z*sinf(a)) * rad;
		addV(cx, cy, cz);
	}
	for (int i = 0; i < segments; i++) {
		m.triangle_indices.push_back(tip_v);
		m.triangle_indices.push_back(ring_start + i);
		m.triangle_indices.push_back(ring_start + (i + 1) % segments);
	}
}

// ============================================================
// Init
// ============================================================

void view::initShaders() {
	if (!solid_shader.build(solid_vert_src, solid_frag_src))
		std::cerr << "Failed to build solid shader" << std::endl;
	if (!wireframe_shader.build(wire_vert_src, wire_frag_src))
		std::cerr << "Failed to build wireframe shader" << std::endl;
	if (!grid_shader.build(grid_vert_src, grid_frag_src))
		std::cerr << "Failed to build grid shader" << std::endl;
	if (!vertcolor_shader.build(vertcolor_vert_src, vertcolor_frag_src))
		std::cerr << "Failed to build vertcolor shader" << std::endl;
	if (!pick_shader.build(pick_vert_src, pick_frag_src))
		std::cerr << "Failed to build pick shader" << std::endl;
	shaders_initialized = true;
}

void view::initAxesMesh() {
	axes_mesh.vertex_data = {
		0.0f, 0.0f, 0.0f,  1.0f, 0.2f, 0.2f,
		2.0f, 0.0f, 0.0f,  1.0f, 0.2f, 0.2f,
		0.0f, 0.0f, 0.0f,  0.3f, 0.3f, 1.0f,
		0.0f, 2.0f, 0.0f,  0.3f, 0.3f, 1.0f,
		0.0f, 0.0f, 0.0f,  0.2f, 1.0f, 0.2f,
		0.0f, 0.0f, 2.0f,  0.2f, 1.0f, 0.2f,
	};
	axes_mesh.line_indices = { 0, 1, 2, 3, 4, 5 };
	axes_mesh.uploadToGPU();
}

void view::initGridMesh() {
	grid_mesh.vertex_data.clear();
	grid_mesh.line_indices.clear();
	grid_mesh.triangle_indices.clear();

	int res = 32;
	if (scene_ptr) res = scene_ptr->prefs.get_grid_resolution();
	if (res < 1) res = 1;

	float half = res / 2.0f;

	auto addV = [&](float x, float y, float z) -> int {
		int idx = grid_mesh.vertex_data.size() / 6;
		grid_mesh.vertex_data.push_back(x);
		grid_mesh.vertex_data.push_back(y);
		grid_mesh.vertex_data.push_back(z);
		grid_mesh.vertex_data.push_back(0.0f);
		grid_mesh.vertex_data.push_back(1.0f);
		grid_mesh.vertex_data.push_back(0.0f);
		return idx;
	};

	for (int i = 0; i <= res; i++) {
		float pos = -half + (float)i;
		int v0 = addV(pos, 0.0f, -half);
		int v1 = addV(pos, 0.0f,  half);
		grid_mesh.line_indices.push_back(v0);
		grid_mesh.line_indices.push_back(v1);

		int v2 = addV(-half, 0.0f, pos);
		int v3 = addV( half, 0.0f, pos);
		grid_mesh.line_indices.push_back(v2);
		grid_mesh.line_indices.push_back(v3);
	}

	grid_mesh.uploadToGPU();

	grid_axis_lines.vertex_data.clear();
	grid_axis_lines.line_indices.clear();
	grid_axis_lines.triangle_indices.clear();
	grid_axis_lines.vertex_data = {
		-half, 0.0f, 0.0f,  0.2f, 1.0f, 0.2f,
		 half, 0.0f, 0.0f,  0.2f, 1.0f, 0.2f,
		0.0f, 0.0f, -half,  0.5f, 0.8f, 1.0f,
		0.0f, 0.0f,  half,  0.5f, 0.8f, 1.0f,
	};
	grid_axis_lines.line_indices = { 0, 1, 2, 3 };
	grid_axis_lines.uploadToGPU();
}

void view::initGizmoMeshes() {
	buildArrowMesh(gizmo_arrow_x, 1, 0, 0, 1.0f, 0.2f, 0.2f, 1.5f);
	gizmo_arrow_x.uploadToGPU();
	buildArrowMesh(gizmo_arrow_y, 0, 0, 1, 0.2f, 1.0f, 0.2f, 1.5f);
	gizmo_arrow_y.uploadToGPU();
	buildArrowMesh(gizmo_arrow_z, 0, 1, 0, 0.3f, 0.3f, 1.0f, 1.5f);
	gizmo_arrow_z.uploadToGPU();
}

// ============================================================
// OBJ parser for control widget
// ============================================================
struct NamedMesh {
	std::string name;
	Mesh mesh;
};

static std::vector<NamedMesh> loadOBJFile(const std::string& filename,
	const std::map<std::string, std::array<float,3>>& colors)
{
	std::vector<NamedMesh> result;
	std::ifstream file(filename);
	if (!file.is_open()) return result;

	std::vector<std::array<float,3>> positions;
	int current = -1;
	std::map<int, int> vert_remap;
	std::array<float,3> cur_color = {0.5f, 0.5f, 0.5f};

	std::string line;
	while (std::getline(file, line)) {
		if (line.empty() || line[0] == '#' || line[0] == 'm' || line[0] == 's') continue;

		std::istringstream iss(line);
		std::string token;
		iss >> token;

		if (token == "o") {
			std::string name;
			iss >> name;
			result.push_back({name, Mesh()});
			current = (int)result.size() - 1;
			vert_remap.clear();
			auto it = colors.find(name);
			if (it != colors.end()) cur_color = it->second;
			else cur_color = {0.5f, 0.5f, 0.5f};
		} else if (token == "v") {
			float x, y, z;
			iss >> x >> y >> z;
			positions.push_back({x, y, z});
		} else if (token == "f" && current >= 0) {
			Mesh& m = result[current].mesh;
			std::vector<int> face_local;
			std::string ftoken;
			while (iss >> ftoken) {
				int vi = 0;
				sscanf(ftoken.c_str(), "%d", &vi);
				if (vi < 0) vi = (int)positions.size() + vi + 1;
				int global_idx = vi - 1;

				int local_idx;
				auto it = vert_remap.find(global_idx);
				if (it != vert_remap.end()) {
					local_idx = it->second;
				} else {
					local_idx = (int)m.vertex_data.size() / 6;
					auto& p = positions[global_idx];
					m.vertex_data.push_back(p[0]);
					m.vertex_data.push_back(p[1]);
					m.vertex_data.push_back(p[2]);
					m.vertex_data.push_back(cur_color[0]);
					m.vertex_data.push_back(cur_color[1]);
					m.vertex_data.push_back(cur_color[2]);
					vert_remap[global_idx] = local_idx;
				}
				face_local.push_back(local_idx);
			}
			for (int i = 1; i < (int)face_local.size() - 1; i++) {
				m.triangle_indices.push_back(face_local[0]);
				m.triangle_indices.push_back(face_local[i]);
				m.triangle_indices.push_back(face_local[i + 1]);
			}
			for (int i = 0; i < (int)face_local.size(); i++) {
				m.line_indices.push_back(face_local[i]);
				m.line_indices.push_back(face_local[(i + 1) % face_local.size()]);
			}
		}
	}
	return result;
}

void view::initControlWidget() {
	std::map<std::string, std::array<float,3>> colors = {
		{"X-Arrow",          {1.0f, 0.2f, 0.2f}},
		{"Y-Arrow",          {0.2f, 1.0f, 0.2f}},
		{"Z-Arrow",          {0.3f, 0.3f, 1.0f}},
		{"Turn_Cylinder",    {1.0f, 1.0f, 0.2f}},
		{"Relocate_Sphere",  {1.0f, 0.6f, 0.1f}},
		{"Move_Turn_Plane",  {0.5f, 0.5f, 0.5f}},
		{"Movement_Plane",   {0.6f, 0.6f, 0.6f}},
	};

	auto meshes = loadOBJFile("control_widget.obj", colors);
	if (meshes.empty()) return;

	std::map<std::string, int> name_to_idx = {
		{"Move_Turn_Plane",  CW_MOVE_TURN_PLANE},
		{"Movement_Plane",   CW_MOVEMENT_PLANE},
		{"Z-Arrow",          CW_Z_ARROW},
		{"X-Arrow",          CW_X_ARROW},
		{"Y-Arrow",          CW_Y_ARROW},
		{"Relocate_Sphere",  CW_RELOCATE_SPHERE},
		{"Turn_Cylinder",    CW_TURN_CYLINDER},
	};

	for (auto& nm : meshes) {
		auto it = name_to_idx.find(nm.name);
		if (it != name_to_idx.end()) {
			cw_meshes[it->second] = std::move(nm.mesh);
			cw_meshes[it->second].uploadToGPU();
		}
	}
	cw_loaded = true;
}

void view::renderControlWidget(float* view_mat, float* proj_mat) {
	if (!cw_loaded || !vertcolor_shader.getId()) return;
	if (scene_ptr && !scene_ptr->prefs.get_draw_control_widget()) return;

	float model_mat[16];
	IdentityMatrix(model_mat);
	TranslateMatrix(cw_position[0], cw_position[1], cw_position[2], model_mat);

	vertcolor_shader.use();
	vertcolor_shader.setMat4("view", view_mat);
	vertcolor_shader.setMat4("projection", proj_mat);
	vertcolor_shader.setMat4("model", model_mat);

	glDisable(GL_DEPTH_TEST);
	for (int i = 0; i < CW_COUNT; i++) {
		if (cw_meshes[i].hasData()) {
			cw_meshes[i].drawSolid();
			cw_meshes[i].drawWireframe();
		}
	}
	glEnable(GL_DEPTH_TEST);
}

int view::pickControlWidgetAt(int x, int y, float* view_mat, float* proj_mat) {
	if (!cw_loaded || !wireframe_shader.getId()) return 0;
	if (scene_ptr && !scene_ptr->prefs.get_draw_control_widget()) return 0;

	int w = mGlArea.get_allocated_width();
	int h = mGlArea.get_allocated_height();
	if (w <= 0 || h <= 0) return 0;

	ensurePickFBO(w, h);

	float model_mat[16];
	IdentityMatrix(model_mat);
	TranslateMatrix(cw_position[0], cw_position[1], cw_position[2], model_mat);

	glBindFramebuffer(GL_FRAMEBUFFER, pick_fbo);
	glViewport(0, 0, w, h);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_BLEND);

	wireframe_shader.use();
	wireframe_shader.setMat4("model", model_mat);
	wireframe_shader.setMat4("view", view_mat);
	wireframe_shader.setMat4("projection", proj_mat);

	for (int i = 0; i < CW_COUNT; i++) {
		if (!cw_meshes[i].hasData()) continue;
		int id = i + 1;
		float r = (id & 0xFF) / 255.0f;
		float g = ((id >> 8) & 0xFF) / 255.0f;
		float b = ((id >> 16) & 0xFF) / 255.0f;
		float pick_col[3] = {r, g, b};
		wireframe_shader.setVec3("lineColor", pick_col);
		cw_meshes[i].drawSolid();
	}

	int read_y = h - y - 1;
	unsigned char pixel[4] = {0, 0, 0, 0};
	glReadPixels(x, read_y, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, pixel);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	int picked = pixel[0] | (pixel[1] << 8) | (pixel[2] << 16);
	if (picked < 1 || picked > CW_COUNT) return 0;
	return picked;
}

void view::handleControlWidgetDrag(double dx, double dy, int part) {
	float scale = camera.getDistance() * 0.005f;

	if (part == CW_X_ARROW + 1 || part == CW_Y_ARROW + 1 || part == CW_Z_ARROW + 1) {
		float axis[3] = {0, 0, 0};
		if (part == CW_X_ARROW + 1)      axis[0] = 1.0f;
		else if (part == CW_Y_ARROW + 1) axis[1] = 1.0f;
		else                              axis[2] = 1.0f;

		float view_mat[16], proj_mat[16];
		camera.getViewMatrix(view_mat);
		int w = mGlArea.get_allocated_width();
		int h = mGlArea.get_allocated_height();
		float aspect = (float)w / (float)h;
		camera.getProjectionMatrix(aspect, proj_mat);

		float mvp[16];
		float temp[16];
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++) {
				temp[i * 4 + j] = 0;
				for (int k = 0; k < 4; k++)
					temp[i * 4 + j] += proj_mat[i * 4 + k] * view_mat[k * 4 + j];
			}
		for (int i = 0; i < 16; i++) mvp[i] = temp[i];

		auto project = [&](float wx, float wy, float wz, float& sx, float& sy) {
			float cx = mvp[0]*wx + mvp[4]*wy + mvp[8]*wz + mvp[12];
			float cy = mvp[1]*wx + mvp[5]*wy + mvp[9]*wz + mvp[13];
			float cw = mvp[3]*wx + mvp[7]*wy + mvp[11]*wz + mvp[15];
			if (fabs(cw) < 1e-6f) cw = 1e-6f;
			sx = (cx / cw + 1.0f) * 0.5f * w;
			sy = (1.0f - cy / cw) * 0.5f * h;
		};

		float sx0, sy0, sx1, sy1;
		project(cw_position[0], cw_position[1], cw_position[2], sx0, sy0);
		project(cw_position[0] + axis[0], cw_position[1] + axis[1], cw_position[2] + axis[2], sx1, sy1);

		float screen_dx = sx1 - sx0;
		float screen_dy = sy1 - sy0;
		float len = sqrtf(screen_dx * screen_dx + screen_dy * screen_dy);
		if (len < 1e-4f) return;
		screen_dx /= len;
		screen_dy /= len;

		float amount = (dx * screen_dx + dy * screen_dy) * scale;
		camera.panAlongWorldAxis(amount, axis[0], axis[1], axis[2]);
	} else if (part == CW_TURN_CYLINDER + 1) {
		camera.orbit(dx * 0.3f, dy * 0.3f);
	} else if (part == CW_RELOCATE_SPHERE + 1) {
		float view_mat[16];
		camera.getViewMatrix(view_mat);
		float right[3] = {view_mat[0], view_mat[4], view_mat[8]};
		float up[3] = {view_mat[1], view_mat[5], view_mat[9]};
		for (int i = 0; i < 3; i++)
			cw_position[i] += (right[i] * dx - up[i] * dy) * scale;
	}
}

void view::ensurePickFBO(int w, int h) {
	if (pick_fbo && pick_fbo_w == w && pick_fbo_h == h) return;

	if (pick_fbo) {
		glDeleteFramebuffers(1, &pick_fbo);
		glDeleteTextures(1, &pick_color_tex);
		glDeleteRenderbuffers(1, &pick_depth_rbo);
	}

	glGenFramebuffers(1, &pick_fbo);
	glBindFramebuffer(GL_FRAMEBUFFER, pick_fbo);

	glGenTextures(1, &pick_color_tex);
	glBindTexture(GL_TEXTURE_2D, pick_color_tex);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, pick_color_tex, 0);

	glGenRenderbuffers(1, &pick_depth_rbo);
	glBindRenderbuffer(GL_RENDERBUFFER, pick_depth_rbo);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT24, w, h);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, pick_depth_rbo);

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	pick_fbo_w = w;
	pick_fbo_h = h;
}

void view::onRealize() {
	mGlArea.make_current();
}

void view::initGL() {
	mGlArea.make_current();
	while (glGetError() != GL_NO_ERROR) {}

	glEnable(GL_DEPTH_TEST);
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);

	initShaders();
	initAxesMesh();
	initGridMesh();
	initGizmoMeshes();
	initControlWidget();

	while (glGetError() != GL_NO_ERROR) {}
}

void view::onUnrealize() {
	mGlArea.make_current();
	solid_shader.cleanup();
	wireframe_shader.cleanup();
	grid_shader.cleanup();
	vertcolor_shader.cleanup();
	pick_shader.cleanup();
	axes_mesh.cleanup();
	grid_mesh.cleanup();
	grid_axis_lines.cleanup();
	gizmo_arrow_x.cleanup();
	gizmo_arrow_y.cleanup();
	gizmo_arrow_z.cleanup();
	for (int i = 0; i < CW_COUNT; i++) cw_meshes[i].cleanup();
	if (pick_fbo) {
		glDeleteFramebuffers(1, &pick_fbo);
		glDeleteTextures(1, &pick_color_tex);
		glDeleteRenderbuffers(1, &pick_depth_rbo);
		pick_fbo = 0;
	}
	if (scene_ptr) {
		scene_ptr->view_object_toolbar.cleanup();
		scene_ptr->main_toolbar.cleanup();
		scene_ptr->object_toolbar.cleanup();
		scene_ptr->window_manager.cleanup();
	}
}

// ============================================================
// Rendering
// ============================================================

void view::renderGrid(float* view_mat, float* proj_mat) {
	if (!wireframe_shader.getId()) return;
	if (!scene_ptr->prefs.get_draw_ground_plane()) return;
	if (!grid_mesh.hasData()) return;

	float identity[16];
	IdentityMatrix(identity);

	float* gc = scene_ptr->prefs.get_grid_color();

	wireframe_shader.use();
	wireframe_shader.setMat4("model", identity);
	wireframe_shader.setMat4("view", view_mat);
	wireframe_shader.setMat4("projection", proj_mat);
	wireframe_shader.setVec3("lineColor", gc);
	grid_mesh.drawWireframe();

	if (vertcolor_shader.getId() && grid_axis_lines.hasData()) {
		glLineWidth(2.0f);
		vertcolor_shader.use();
		vertcolor_shader.setMat4("model", identity);
		vertcolor_shader.setMat4("view", view_mat);
		vertcolor_shader.setMat4("projection", proj_mat);
		grid_axis_lines.drawWireframe();
		glLineWidth(1.0f);
	}
}

void view::renderAxes(float* view_mat, float* proj_mat) {
	if (!vertcolor_shader.getId() || !axes_mesh.hasData()) return;

	float identity[16];
	IdentityMatrix(identity);

	vertcolor_shader.use();
	vertcolor_shader.setMat4("model", identity);
	vertcolor_shader.setMat4("view", view_mat);
	vertcolor_shader.setMat4("projection", proj_mat);
	glLineWidth(2.0f);
	axes_mesh.drawWireframe();
	glLineWidth(1.0f);
}

void view::renderObjects(float* view_mat, float* proj_mat) {
	if (!scene_ptr) return;
	if (!solid_shader.getId() && !wireframe_shader.getId()) return;

	int draw_mode = scene_ptr->current_draw_mode;
	int edit_mode = scene_ptr->Get_Edit_Mode();

	for (auto& obj_ptr : scene_ptr->object_list) {
		if (!obj_ptr) continue;

		if (!obj_ptr->getMesh().hasData())
			obj_ptr->generateMesh();
		if (obj_ptr->getMesh().hasData() && obj_ptr->getMesh().isDirty())
			obj_ptr->getMesh().uploadToGPU();
		if (!obj_ptr->getMesh().hasData()) continue;

		float model_mat[16];
		obj_ptr->buildModelMatrix(model_mat);
		bool is_selected = scene_ptr->IsSelected(obj_ptr);
		int tool = scene_ptr->Get_Current_Tool();
		bool is_context = (tool == 250 && edit_mode == 0);
		bool is_edit_target = ((edit_mode >= 1 && edit_mode <= 3) || is_context) &&
							   obj_ptr == scene_ptr->current_object;
		float* color = is_selected ? obj_ptr->getSelectedColor() : obj_ptr->getUnselectedColor();

		if (is_edit_target) {
			if (solid_shader.getId()) {
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glDepthMask(GL_FALSE);

				solid_shader.use();
				solid_shader.setMat4("model", model_mat);
				solid_shader.setMat4("view", view_mat);
				solid_shader.setMat4("projection", proj_mat);
				float normal_mat[9] = {
					model_mat[0], model_mat[1], model_mat[2],
					model_mat[4], model_mat[5], model_mat[6],
					model_mat[8], model_mat[9], model_mat[10]
				};
				solid_shader.setMat3("normalMatrix", normal_mat);
				float light_dir[3] = {-0.5f, -1.0f, -0.5f};
				float light_color[3] = {1.0f, 1.0f, 1.0f};
				solid_shader.setVec3("lightDir", light_dir);
				solid_shader.setVec3("lightColor", light_color);
				solid_shader.setFloat("ambient", 0.25f);
				solid_shader.setVec3("objectColor", color);
				solid_shader.setFloat("alpha", 0.5f);

				obj_ptr->getMesh().drawSolid();

				glDepthMask(GL_TRUE);
				glDisable(GL_BLEND);
			}
			if (wireframe_shader.getId()) {
				wireframe_shader.use();
				wireframe_shader.setMat4("model", model_mat);
				wireframe_shader.setMat4("view", view_mat);
				wireframe_shader.setMat4("projection", proj_mat);
				float edit_wire[3] = {0.2f, 0.2f, 0.4f};
				wireframe_shader.setVec3("lineColor", edit_wire);
				obj_ptr->getMesh().drawWireframe();
			}
			continue;
		}

		bool draw_solid = (draw_mode == SOLID_VIEW || draw_mode == SOLID_WIREFRAME_VIEW ||
						   draw_mode == TRANSPARENT_SOLID_VIEW || draw_mode == TRANSPARENT_WIREFRAME_VIEW ||
						   draw_mode == RADIOSITY_VIEW);
		bool draw_wire  = (draw_mode == WIREFRAME_VIEW || draw_mode == SOLID_WIREFRAME_VIEW ||
						   draw_mode == TRANSPARENT_WIREFRAME_VIEW);
		bool transparent = (draw_mode == TRANSPARENT_SOLID_VIEW || draw_mode == TRANSPARENT_WIREFRAME_VIEW);

		if (draw_solid && solid_shader.getId()) {
			if (transparent) {
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glDepthMask(GL_FALSE);
			}

			solid_shader.use();
			solid_shader.setMat4("model", model_mat);
			solid_shader.setMat4("view", view_mat);
			solid_shader.setMat4("projection", proj_mat);
			float normal_mat[9] = {
				model_mat[0], model_mat[1], model_mat[2],
				model_mat[4], model_mat[5], model_mat[6],
				model_mat[8], model_mat[9], model_mat[10]
			};
			solid_shader.setMat3("normalMatrix", normal_mat);
			float light_dir[3] = {-0.5f, -1.0f, -0.5f};
			float light_color[3] = {1.0f, 1.0f, 1.0f};
			solid_shader.setVec3("lightDir", light_dir);
			solid_shader.setVec3("lightColor", light_color);
			solid_shader.setFloat("ambient", 0.25f);
			solid_shader.setVec3("objectColor", color);
			solid_shader.setFloat("alpha", transparent ? 0.4f : 1.0f);

			obj_ptr->getMesh().drawSolid();

			if (transparent) {
				glDepthMask(GL_TRUE);
				glDisable(GL_BLEND);
			}
		}

		if (draw_wire && wireframe_shader.getId()) {
			wireframe_shader.use();
			wireframe_shader.setMat4("model", model_mat);
			wireframe_shader.setMat4("view", view_mat);
			wireframe_shader.setMat4("projection", proj_mat);
			wireframe_shader.setVec3("lineColor", color);
			obj_ptr->getMesh().drawWireframe();
		}

		if (!draw_wire && is_selected && wireframe_shader.getId()) {
			wireframe_shader.use();
			wireframe_shader.setMat4("model", model_mat);
			wireframe_shader.setMat4("view", view_mat);
			wireframe_shader.setMat4("projection", proj_mat);
			float sel_wire[3] = {1.0f, 1.0f, 1.0f};
			wireframe_shader.setVec3("lineColor", sel_wire);
			obj_ptr->getMesh().drawWireframe();
		}
	}
}

void view::renderGizmo(float* view_mat, float* proj_mat) {
	if (!scene_ptr || !scene_ptr->current_object) return;
	if (!vertcolor_shader.getId()) return;

	int tool = scene_ptr->Get_Current_Tool();
	if (tool != 40 && tool != 41 && tool != 42) return;

	float model_mat[16];
	IdentityMatrix(model_mat);
	double* loc = scene_ptr->current_object->get_location();
	TranslateMatrix((float)loc[0], (float)loc[1], (float)loc[2], model_mat);

	vertcolor_shader.use();
	vertcolor_shader.setMat4("view", view_mat);
	vertcolor_shader.setMat4("projection", proj_mat);
	vertcolor_shader.setMat4("model", model_mat);

	glDisable(GL_DEPTH_TEST);
	glLineWidth(2.0f);
	gizmo_arrow_x.drawWireframe();
	gizmo_arrow_x.drawSolid();
	gizmo_arrow_y.drawWireframe();
	gizmo_arrow_y.drawSolid();
	gizmo_arrow_z.drawWireframe();
	gizmo_arrow_z.drawSolid();
	glLineWidth(1.0f);
	glEnable(GL_DEPTH_TEST);
}

// ============================================================
// Picking
// ============================================================

int view::pickObjectAt(int x, int y) {
	if (!scene_ptr || !wireframe_shader.getId()) return -1;

	int w = mGlArea.get_allocated_width();
	int h = mGlArea.get_allocated_height();
	if (w <= 0 || h <= 0) return -1;

	ensurePickFBO(w, h);

	float aspect = (float)w / (float)h;
	float view_mat[16], proj_mat[16];
	camera.getViewMatrix(view_mat);
	camera.getProjectionMatrix(aspect, proj_mat);

	glBindFramebuffer(GL_FRAMEBUFFER, pick_fbo);
	glViewport(0, 0, w, h);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_BLEND);

	wireframe_shader.use();
	wireframe_shader.setMat4("view", view_mat);
	wireframe_shader.setMat4("projection", proj_mat);

	int obj_index = 1;
	for (auto& obj_ptr : scene_ptr->object_list) {
		if (!obj_ptr || !obj_ptr->getMesh().hasData()) { obj_index++; continue; }

		float model_mat[16];
		obj_ptr->buildModelMatrix(model_mat);
		wireframe_shader.setMat4("model", model_mat);

		float r = ((obj_index) & 0xFF) / 255.0f;
		float g = ((obj_index >> 8) & 0xFF) / 255.0f;
		float b = ((obj_index >> 16) & 0xFF) / 255.0f;
		float pick_col[3] = {r, g, b};
		wireframe_shader.setVec3("lineColor", pick_col);
		obj_ptr->getMesh().drawSolid();
		obj_index++;
	}

	int read_y = h - y - 1;
	unsigned char pixel[4] = {0, 0, 0, 0};
	glReadPixels(x, read_y, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, pixel);

	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	int picked = pixel[0] | (pixel[1] << 8) | (pixel[2] << 16);
	if (picked == 0) return -1;
	return picked - 1;
}

// ============================================================
// Sub-element picking
// ============================================================

int view::pickSubElementAt(int x, int y, int edit_mode) {
	if (!scene_ptr || !scene_ptr->current_object) return -1;
	if (!pick_shader.getId()) return -1;

	auto obj = scene_ptr->current_object;
	if (!obj->getMesh().hasData()) return -1;

	int w = mGlArea.get_allocated_width();
	int h = mGlArea.get_allocated_height();
	if (w <= 0 || h <= 0) return -1;

	ensurePickFBO(w, h);

	float aspect = (float)w / (float)h;
	float view_mat[16], proj_mat[16], model_mat[16];
	camera.getViewMatrix(view_mat);
	camera.getProjectionMatrix(aspect, proj_mat);
	obj->buildModelMatrix(model_mat);

	glBindFramebuffer(GL_FRAMEBUFFER, pick_fbo);
	glViewport(0, 0, w, h);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_BLEND);

	pick_shader.use();
	pick_shader.setMat4("model", model_mat);
	pick_shader.setMat4("view", view_mat);
	pick_shader.setMat4("projection", proj_mat);

	Mesh& m = obj->getMesh();
	glBindVertexArray(m.getVAO());

	if (edit_mode == 3) {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m.getTriEBO());
		glDrawElements(GL_TRIANGLES, m.getTriangleCount() * 3, GL_UNSIGNED_INT, 0);
	} else if (edit_mode == 2) {
		glLineWidth(5.0f);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m.getLineEBO());
		glDrawElements(GL_LINES, m.getLineCount() * 2, GL_UNSIGNED_INT, 0);
		glLineWidth(1.0f);
	} else if (edit_mode == 1) {
		glEnable(GL_PROGRAM_POINT_SIZE);
		glDrawArrays(GL_POINTS, 0, m.getVertexCount());
		glDisable(GL_PROGRAM_POINT_SIZE);
	}

	glBindVertexArray(0);

	int read_y = h - y - 1;
	unsigned char pixel[4] = {0, 0, 0, 0};
	glReadPixels(x, read_y, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, pixel);

	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	int picked = pixel[0] | (pixel[1] << 8) | (pixel[2] << 16);
	if (picked == 0) return -1;
	int tri_index = picked - 1;

	if (edit_mode == 3)
		return m.getFaceFromTriangle(tri_index);
	return tri_index;
}

// ============================================================
// Sub-element highlight rendering
// ============================================================

void view::renderSubElementHighlights(float* view_mat, float* proj_mat) {
	if (!scene_ptr || !scene_ptr->current_object) return;
	int edit_mode = scene_ptr->Get_Edit_Mode();
	int tool = scene_ptr->Get_Current_Tool();
	bool is_context = (tool == 250 && edit_mode == 0);
	if (edit_mode == 0 && !is_context) return;
	if (!wireframe_shader.getId()) return;

	auto obj = scene_ptr->current_object;
	Mesh& m = obj->getMesh();
	if (!m.hasData()) return;

	float model_mat[16];
	obj->buildModelMatrix(model_mat);

	float hover_color[3] = { 0.0f, 0.8f, 0.8f };
	float select_color[3] = { 0.4f, 1.0f, 0.6f };

	glDisable(GL_DEPTH_TEST);
	glBindVertexArray(m.getVAO());

	auto drawFaceWireframe = [&](int face_id, float* color) {
		wireframe_shader.use();
		wireframe_shader.setMat4("model", model_mat);
		wireframe_shader.setMat4("view", view_mat);
		wireframe_shader.setMat4("projection", proj_mat);
		wireframe_shader.setVec3("lineColor", color);

		std::map<std::pair<unsigned int,unsigned int>, int> edge_count;
		auto addEdge = [&](unsigned int a, unsigned int b) {
			auto key = (a < b) ? std::make_pair(a, b) : std::make_pair(b, a);
			edge_count[key]++;
		};
		for (int tri = 0; tri < m.getTriangleCount(); tri++) {
			if (m.getFaceFromTriangle(tri) == face_id) {
				int base = tri * 3;
				unsigned int i0 = m.triangle_indices[base];
				unsigned int i1 = m.triangle_indices[base + 1];
				unsigned int i2 = m.triangle_indices[base + 2];
				addEdge(i0, i1); addEdge(i1, i2); addEdge(i2, i0);
			}
		}
		std::vector<unsigned int> edge_verts;
		for (auto& kv : edge_count) {
			if (kv.second == 1) {
				edge_verts.push_back(kv.first.first);
				edge_verts.push_back(kv.first.second);
			}
		}
		if (!edge_verts.empty()) {
			GLuint tmp_ebo;
			glGenBuffers(1, &tmp_ebo);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, tmp_ebo);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, edge_verts.size() * sizeof(unsigned int),
						 edge_verts.data(), GL_STREAM_DRAW);
			glLineWidth(3.0f);
			glDrawElements(GL_LINES, edge_verts.size(), GL_UNSIGNED_INT, 0);
			glLineWidth(1.0f);
			glDeleteBuffers(1, &tmp_ebo);
		}
	};

	bool draw_faces = (edit_mode == 3 || is_context);
	bool draw_edges = (edit_mode == 2 || is_context);
	bool draw_verts = (edit_mode == 1 || is_context);

	if (draw_faces) {
		for (int face_id : obj->getSelectedFaces())
			drawFaceWireframe(face_id, select_color);
		if (hovered_sub_element >= 0 &&
			(is_context ? hovered_edit_mode == 3 : true) &&
			obj->getSelectedFaces().count(hovered_sub_element) == 0)
			drawFaceWireframe(hovered_sub_element, hover_color);
	}

	if (draw_edges && !obj->getSelectedEdges().empty()) {
		wireframe_shader.use();
		wireframe_shader.setMat4("model", model_mat);
		wireframe_shader.setMat4("view", view_mat);
		wireframe_shader.setMat4("projection", proj_mat);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m.getLineEBO());
		glLineWidth(3.0f);
		wireframe_shader.setVec3("lineColor", select_color);
		for (int idx : obj->getSelectedEdges()) {
			if (idx < m.getLineCount()) {
				int offset = idx * 2 * sizeof(unsigned int);
				glDrawElements(GL_LINES, 2, GL_UNSIGNED_INT, (void*)(intptr_t)offset);
			}
		}
		glLineWidth(1.0f);
	}
	if (draw_edges && hovered_sub_element >= 0 &&
		(is_context ? hovered_edit_mode == 2 : true) &&
		hovered_sub_element < m.getLineCount() &&
		obj->getSelectedEdges().count(hovered_sub_element) == 0) {
		wireframe_shader.use();
		wireframe_shader.setMat4("model", model_mat);
		wireframe_shader.setMat4("view", view_mat);
		wireframe_shader.setMat4("projection", proj_mat);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m.getLineEBO());
		glLineWidth(3.0f);
		wireframe_shader.setVec3("lineColor", hover_color);
		int offset = hovered_sub_element * 2 * sizeof(unsigned int);
		glDrawElements(GL_LINES, 2, GL_UNSIGNED_INT, (void*)(intptr_t)offset);
		glLineWidth(1.0f);
	}

	if (draw_verts) {
		wireframe_shader.use();
		wireframe_shader.setMat4("model", model_mat);
		wireframe_shader.setMat4("view", view_mat);
		wireframe_shader.setMat4("projection", proj_mat);
		glPointSize(8.0f);
		if (!obj->getSelectedVertices().empty()) {
			wireframe_shader.setVec3("lineColor", select_color);
			for (int idx : obj->getSelectedVertices()) {
				if (idx < m.getVertexCount())
					glDrawArrays(GL_POINTS, idx, 1);
			}
		}
		if (hovered_sub_element >= 0 &&
			(is_context ? hovered_edit_mode == 1 : true) &&
			hovered_sub_element < m.getVertexCount() &&
			obj->getSelectedVertices().count(hovered_sub_element) == 0) {
			wireframe_shader.setVec3("lineColor", hover_color);
			glDrawArrays(GL_POINTS, hovered_sub_element, 1);
		}
		glPointSize(1.0f);
	}

	glBindVertexArray(0);
	glEnable(GL_DEPTH_TEST);
}

// ============================================================
// Transform dragging
// ============================================================

void view::handleTransformDrag(double dx, double dy, int button) {
	if (!scene_ptr || scene_ptr->selected_objects.empty()) return;

	int tool = scene_ptr->Get_Current_Tool();

	for (auto& obj : scene_ptr->selected_objects) {
		if (!obj) continue;

		if (tool == 40) {
			double* loc = obj->get_location();
			float s = camera.getDistance() * 0.005f;
			if (button == 1) {
				obj->set_location(loc[0] + dx * s, loc[1], loc[2] - dy * s);
			} else if (button == 3) {
				obj->set_location(loc[0], loc[1] - dy * s, loc[2]);
			}
			obj->getMesh().markDirty();
		} else if (tool == 41) {
			float* rot = obj->get_rotation();
			if (button == 1) {
				obj->set_rotation(rot[0], rot[1] + dx * 0.5f, rot[2]);
			} else if (button == 3) {
				obj->set_rotation(rot[0] + dy * 0.5f, rot[1], rot[2] + dx * 0.5f);
			}
			obj->getMesh().markDirty();
		} else if (tool == 42) {
			float* sc = obj->get_scale();
			float delta = 1.0f + dy * -0.005f;
			if (delta < 0.01f) delta = 0.01f;
			if (button == 1) {
				obj->set_scale(sc[0] * delta, sc[1], sc[2] * delta);
			} else if (button == 3) {
				obj->set_scale(sc[0], sc[1] * delta, sc[2]);
			}
			obj->getMesh().markDirty();
		}
	}

	if (scene_ptr->curr_gui)
		scene_ptr->curr_gui->update_object_info(*scene_ptr);
}

// ============================================================
// Render loop
// ============================================================

bool view::onRender(const Glib::RefPtr<Gdk::GLContext>& context) {
	if (!shaders_initialized) {
		initGL();
		if (!shaders_initialized) {
			while (glGetError() != GL_NO_ERROR) {}
			return true;
		}
	}

	float* bg = scene_ptr->prefs.get_background_color();
	glClearColor(bg[0], bg[1], bg[2], 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);

	int width = mGlArea.get_allocated_width();
	int height = mGlArea.get_allocated_height();
	if (height == 0) height = 1;
	int scale = mGlArea.get_scale_factor();
	GLTextRenderer::setScaleFactor(scale);
	float aspect = (float)width / (float)height;
	glViewport(0, 0, width * scale, height * scale);

	float view_mat[16], proj_mat[16];
	camera.getViewMatrix(view_mat);
	camera.getProjectionMatrix(aspect, proj_mat);

	renderGrid(view_mat, proj_mat);

	glDisable(GL_DEPTH_TEST);
	renderAxes(view_mat, proj_mat);
	glEnable(GL_DEPTH_TEST);

	glDisable(GL_BLEND);
	renderObjects(view_mat, proj_mat);

	renderGizmo(view_mat, proj_mat);
	renderControlWidget(view_mat, proj_mat);
	renderSubElementHighlights(view_mat, proj_mat);

	renderToolbars();

	glBindVertexArray(0);
	glUseProgram(0);
	while (glGetError() != GL_NO_ERROR) {}

	return true;
}

// ============================================================
// Toolbar overlay
// ============================================================

void view::renderToolbars() {
	if (!scene_ptr) return;
	int w = mGlArea.get_allocated_width();
	int h = mGlArea.get_allocated_height();
	scene_ptr->view_object_toolbar.render(w, h);
	scene_ptr->main_toolbar.render(w, h);
	scene_ptr->object_toolbar.render(w, h);
	if (scene_ptr->editing_toolbar_visible)
		scene_ptr->editing_toolbar.render(w, h);
	scene_ptr->window_manager.render(w, h);
}

bool view::toolbarHitTest(int mx, int my) {
	if (!scene_ptr) return false;
	int w = mGlArea.get_allocated_width();
	int h = mGlArea.get_allocated_height();
	if (scene_ptr->view_object_toolbar.hitTest(mx, my, w, h)) return true;
	if (scene_ptr->main_toolbar.hitTest(mx, my, w, h)) return true;
	if (scene_ptr->object_toolbar.hitTest(mx, my, w, h)) return true;
	if (scene_ptr->editing_toolbar_visible &&
		scene_ptr->editing_toolbar.hitTest(mx, my, w, h)) return true;
	return false;
}

// ============================================================
// Input handling
// ============================================================

bool view::onButtonPress(GdkEventButton* event) {
	mGlArea.grab_focus();
	int w = mGlArea.get_allocated_width();
	int h = mGlArea.get_allocated_height();
	int mx = (int)event->x, my = (int)event->y;
	last_press_time = event->time;

	if (scene_ptr) {
		if (scene_ptr->window_manager.onPress(mx, my, event->button, event->time)) {
			toolbar_dragging = true;
			mGlArea.queue_render();
			return true;
		}
		if (scene_ptr->view_object_toolbar.onPress(mx, my, event->button, event->time, w, h) ||
			scene_ptr->main_toolbar.onPress(mx, my, event->button, event->time, w, h) ||
			scene_ptr->object_toolbar.onPress(mx, my, event->button, event->time, w, h) ||
			(scene_ptr->editing_toolbar_visible &&
			 scene_ptr->editing_toolbar.onPress(mx, my, event->button, event->time, w, h))) {
			toolbar_dragging = true;
			return true;
		}
	}

	if (event->button == 1 && cw_loaded && scene_ptr &&
		scene_ptr->prefs.get_draw_control_widget()) {
		mGlArea.make_current();
		float view_mat[16], proj_mat[16];
		camera.getViewMatrix(view_mat);
		float aspect = (float)w / (float)h;
		camera.getProjectionMatrix(aspect, proj_mat);
		int part = pickControlWidgetAt(mx, my, view_mat, proj_mat);
		if (part > 0) {
			cw_drag_part = part;
			dragging = true;
			drag_button = event->button;
			last_mouse_x = event->x;
			last_mouse_y = event->y;
			return true;
		}
	}

	dragging = true;
	drag_button = event->button;
	last_mouse_x = event->x;
	last_mouse_y = event->y;
	return true;
}

bool view::onButtonRelease(GdkEventButton* event) {
	if (cw_drag_part > 0) {
		cw_drag_part = 0;
		dragging = false;
		drag_button = 0;
		mGlArea.queue_render();
		return true;
	}

	if (toolbar_dragging && scene_ptr) {
		int w = mGlArea.get_allocated_width();
		int h = mGlArea.get_allocated_height();
		int mx = (int)event->x, my = (int)event->y;
		scene_ptr->window_manager.onRelease(mx, my, event->button, event->time);
		scene_ptr->view_object_toolbar.onRelease(mx, my, event->button, event->time, w, h, *scene_ptr);
		scene_ptr->main_toolbar.onRelease(mx, my, event->button, event->time, w, h, *scene_ptr);
		scene_ptr->object_toolbar.onRelease(mx, my, event->button, event->time, w, h, *scene_ptr);
		if (scene_ptr->editing_toolbar_visible)
			scene_ptr->editing_toolbar.onRelease(mx, my, event->button, event->time, w, h, *scene_ptr);
		toolbar_dragging = false;
		mGlArea.queue_render();
		return true;
	}

	if (!dragging) return true;

	double dx = event->x - last_mouse_x;
	double dy = event->y - last_mouse_y;
	bool was_click = (fabs(dx) < 3.0 && fabs(dy) < 3.0);

	if (event->button == 1 && was_click && scene_ptr) {
		int tool = scene_ptr->Get_Current_Tool();
		int edit_mode = scene_ptr->Get_Edit_Mode();
		bool ctrl = (event->state & GDK_CONTROL_MASK) != 0;
		bool shift = (event->state & GDK_SHIFT_MASK) != 0;
		int sel_mode = ctrl ? object::SEL_ADD : (shift ? object::SEL_REMOVE : object::SEL_REPLACE);
		bool is_object_select = (tool == 0 || tool == 250);
		bool is_transform_tool = (tool == 40 || tool == 41 || tool == 42);
		bool is_subelement_mode = (edit_mode >= 1 && edit_mode <= 3) &&
								  (tool == 251 || tool == 252 || tool == 253);

		bool is_primitive_tool = (tool >= 50 && tool <= 58);

		bool is_context_mode = (tool == 250 && edit_mode == 0);

		if (is_primitive_tool) {
			spawn_primitive(*scene_ptr);
			mGlArea.queue_render();
		} else if ((is_subelement_mode || is_context_mode) && scene_ptr->current_object) {
			auto obj = scene_ptr->current_object;
			if (is_context_mode) {
				if (hovered_sub_element >= 0 && hovered_edit_mode >= 1) {
					if (hovered_edit_mode == 3)
						obj->selectFace(hovered_sub_element, sel_mode);
					else if (hovered_edit_mode == 2)
						obj->selectEdge(hovered_sub_element, sel_mode);
					else if (hovered_edit_mode == 1)
						obj->selectVertex(hovered_sub_element, sel_mode);
				} else if (!ctrl && !shift) {
					obj->clearSubSelection();
				}
			} else {
				mGlArea.make_current();
				int picked = pickSubElementAt((int)event->x, (int)event->y, edit_mode);
				if (picked >= 0) {
					if (edit_mode == 3)
						obj->selectFace(picked, sel_mode);
					else if (edit_mode == 2)
						obj->selectEdge(picked, sel_mode);
					else if (edit_mode == 1)
						obj->selectVertex(picked, sel_mode);
				} else if (!ctrl && !shift) {
					obj->clearSubSelection();
				}
			}
			if (scene_ptr->curr_gui)
				scene_ptr->curr_gui->update_object_info(*scene_ptr);
			mGlArea.queue_render();
		} else if (is_object_select || is_transform_tool) {
			mGlArea.make_current();
			int picked = pickObjectAt((int)event->x, (int)event->y);
			auto obj = scene_ptr->GetObjectByIndex(picked);
			scene_ptr->SelectObject(obj, shift);
			if (obj) obj->clearSubSelection();
			if (scene_ptr->curr_gui)
				scene_ptr->curr_gui->update_object_info(*scene_ptr);
			mGlArea.queue_render();
		}
	}

	dragging = false;
	drag_button = 0;
	return true;
}

bool view::onMotionNotify(GdkEventMotion* event) {
	if (toolbar_dragging && scene_ptr) {
		int w = mGlArea.get_allocated_width();
		int h = mGlArea.get_allocated_height();
		int mx = (int)event->x, my = (int)event->y;
		if (scene_ptr->window_manager.onMotion(mx, my, w, h)) {
			mGlArea.queue_render();
			return true;
		}
		if (scene_ptr->view_object_toolbar.onMotion(mx, my, w, h) ||
			scene_ptr->main_toolbar.onMotion(mx, my, w, h) ||
			scene_ptr->object_toolbar.onMotion(mx, my, w, h) ||
			(scene_ptr->editing_toolbar_visible &&
			 scene_ptr->editing_toolbar.onMotion(mx, my, w, h))) {
			mGlArea.queue_render();
			return true;
		}
	}

	if (!dragging) {
		if (scene_ptr && scene_ptr->current_object) {
			int edit_mode = scene_ptr->Get_Edit_Mode();
			int tool = scene_ptr->Get_Current_Tool();
			bool is_context = (tool == 250 && edit_mode == 0);
			if (edit_mode >= 1 && edit_mode <= 3) {
				mGlArea.make_current();
				int mx = (int)event->x, my = (int)event->y;
				int prev = hovered_sub_element;
				hovered_sub_element = pickSubElementAt(mx, my, edit_mode);
				hovered_edit_mode = edit_mode;
				if (hovered_sub_element != prev)
					mGlArea.queue_render();
			} else if (is_context) {
				mGlArea.make_current();
				int mx = (int)event->x, my = (int)event->y;
				int prev = hovered_sub_element;
				int prev_mode = hovered_edit_mode;
				hovered_sub_element = pickSubElementAt(mx, my, 2);
				hovered_edit_mode = 2;
				if (hovered_sub_element < 0) {
					hovered_sub_element = pickSubElementAt(mx, my, 1);
					hovered_edit_mode = 1;
				}
				if (hovered_sub_element < 0) {
					hovered_sub_element = pickSubElementAt(mx, my, 3);
					hovered_edit_mode = 3;
				}
				if (hovered_sub_element < 0)
					hovered_edit_mode = 0;
				if (hovered_sub_element != prev || hovered_edit_mode != prev_mode)
					mGlArea.queue_render();
			} else {
				if (hovered_sub_element != -1) {
					hovered_sub_element = -1;
					hovered_edit_mode = 0;
					mGlArea.queue_render();
				}
			}
		}
		return false;
	}

	double dx = event->x - last_mouse_x;
	double dy = event->y - last_mouse_y;
	last_mouse_x = event->x;

	if (cw_drag_part > 0) {
		handleControlWidgetDrag(dx, dy, cw_drag_part);
		last_mouse_y = event->y;
		mGlArea.queue_render();
		return true;
	}
	last_mouse_y = event->y;

	int tool = scene_ptr ? scene_ptr->Get_Current_Tool() : 0;

	bool is_transform = (tool == 40 || tool == 41 || tool == 42);

	if (drag_button == 1) {
		if (tool == 37) {
			camera.pan(dx, dy, mGlArea.get_allocated_width(), mGlArea.get_allocated_height());
			mGlArea.queue_render();
		} else if (tool == 38) {
			camera.orbit(dx * 0.3f, dy * 0.3f);
			mGlArea.queue_render();
		} else if (tool == 39) {
			camera.zoom(-dy * 0.1f);
			mGlArea.queue_render();
		} else if (is_transform) {
			handleTransformDrag(dx, dy, 1);
			mGlArea.queue_render();
		}
	} else if (drag_button == 2) {
		if (event->state & GDK_SHIFT_MASK)
			camera.pan(dx, dy, mGlArea.get_allocated_width(), mGlArea.get_allocated_height());
		else
			camera.orbit(dx * 0.3f, dy * 0.3f);
		mGlArea.queue_render();
	} else if (drag_button == 3) {
		if (is_transform) {
			handleTransformDrag(dx, dy, 3);
		} else {
			camera.pan(dx, dy, mGlArea.get_allocated_width(), mGlArea.get_allocated_height());
		}
		mGlArea.queue_render();
	}

	return true;
}

bool view::onScroll(GdkEventScroll* event) {
	if (event->direction == GDK_SCROLL_UP)
		camera.zoom(1.0f);
	else if (event->direction == GDK_SCROLL_DOWN)
		camera.zoom(-1.0f);
	mGlArea.queue_render();
	return true;
}

bool view::onKeyPress(GdkEventKey* event) {
	if (!scene_ptr) return false;

	if (scene_ptr->window_manager.hasFocus()) {
		if (event->keyval == GDK_KEY_Escape) {
			scene_ptr->window_manager.clearFocus();
			mGlArea.queue_render();
			return true;
		}
		bool handled = scene_ptr->window_manager.onKeyPress(event->keyval, event->state);
		if (!handled && event->string && event->string[0] >= 32) {
			handled = scene_ptr->window_manager.onTextInput(event->string);
		}
		if (handled) mGlArea.queue_render();
		return true;
	}

	if (event->keyval == GDK_KEY_Delete || event->keyval == GDK_KEY_KP_Delete) {
		if (!scene_ptr->selected_objects.empty()) {
			auto to_delete = scene_ptr->selected_objects;
			for (auto& obj : to_delete) {
				if (obj) scene_ptr->DeleteObject(obj);
			}
			if (scene_ptr->curr_gui)
				scene_ptr->curr_gui->update_object_info(*scene_ptr);
			mGlArea.queue_render();
		}
		return true;
	}

	bool ctrl = (event->state & GDK_CONTROL_MASK);

	if (ctrl && (event->keyval == GDK_KEY_c || event->keyval == GDK_KEY_C)) {
		auto obj = scene_ptr->GetCurrentObject();
		if (obj) {
			scene_ptr->clipboard = obj->clone();
			cout << "Copied: " << obj->get_name() << endl;
		}
		return true;
	}

	if (ctrl && (event->keyval == GDK_KEY_v || event->keyval == GDK_KEY_V)) {
		if (scene_ptr->clipboard) {
			auto paste = scene_ptr->clipboard->clone();
			double* loc = paste->get_location();
			paste->set_location(loc[0] + 0.5, loc[1], loc[2] + 0.5);
			scene_ptr->AddObject(paste);
			mGlArea.queue_render();
			cout << "Pasted: " << paste->get_name() << endl;
		}
		return true;
	}

	if (event->keyval == GDK_KEY_Up || event->keyval == GDK_KEY_KP_Up) {
		hierarchy_up(*scene_ptr);
		mGlArea.queue_render();
		return true;
	}

	if (event->keyval == GDK_KEY_Down || event->keyval == GDK_KEY_KP_Down) {
		hierarchy_down(*scene_ptr);
		mGlArea.queue_render();
		return true;
	}

	return false;
}

// ============================================================
// Construction and accessors
// ============================================================

view::view(int view_type, int draw_type, scene &curr_scene) {
	scene_ptr = &curr_scene;
	m_view_type = view_type;
	m_draw_type = draw_type;

	camera.setupForView(view_type);

	add(mGlArea);
	mGlArea.set_auto_render(true);
	mGlArea.set_hexpand();
	mGlArea.set_vexpand();
	mGlArea.set_halign(Gtk::ALIGN_FILL);
	mGlArea.set_valign(Gtk::ALIGN_FILL);
	mGlArea.set_required_version(3, 3);
	mGlArea.set_has_depth_buffer(true);

	mGlArea.add_events(
		Gdk::BUTTON_PRESS_MASK |
		Gdk::BUTTON_RELEASE_MASK |
		Gdk::POINTER_MOTION_MASK |
		Gdk::SCROLL_MASK |
		Gdk::KEY_PRESS_MASK
	);
	mGlArea.set_can_focus(true);

	mGlArea.signal_realize().connect(sigc::mem_fun(this, &view::onRealize));
	mGlArea.signal_unrealize().connect(sigc::mem_fun(this, &view::onUnrealize), false);
	mGlArea.signal_render().connect(sigc::mem_fun(this, &view::onRender));
	mGlArea.signal_button_press_event().connect(sigc::mem_fun(this, &view::onButtonPress), false);
	mGlArea.signal_button_release_event().connect(sigc::mem_fun(this, &view::onButtonRelease), false);
	mGlArea.signal_motion_notify_event().connect(sigc::mem_fun(this, &view::onMotionNotify), false);
	mGlArea.signal_scroll_event().connect(sigc::mem_fun(this, &view::onScroll), false);
	mGlArea.signal_key_press_event().connect(sigc::mem_fun(this, &view::onKeyPress), false);
}

void view::setDrawType(int dt) {
	m_draw_type = dt;
	mGlArea.queue_render();
}

void view::setViewType(int vt) {
	m_view_type = vt;
	camera.setupForView(vt);
	mGlArea.queue_render();
}

ViewCamera& view::getCamera() {
	return camera;
}
