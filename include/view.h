#ifndef VIEW_H
#define VIEW_H
#include "gui.h"
#include "mg2.h"
#include "shader.h"
#include "view_camera.h"
#include "mesh.h"

using namespace std;

enum view_type { TOP_VIEW, BOTTOM_VIEW, LEFT_VIEW, RIGHT_VIEW, FRONT_VIEW, BACK_VIEW, CAMERA_VIEW, PERSPECTIVE_VIEW };
enum draw_type {
	SOLID_VIEW,
	WIREFRAME_VIEW,
	TRANSPARENT_SOLID_VIEW,
	TRANSPARENT_WIREFRAME_VIEW,
	SOLID_WIREFRAME_VIEW,
	RADIOSITY_VIEW
};
enum edit_mode { OBJECT_MODE, VERTEX_MODE, EDGE_MODE, FACE_MODE };

class scene;

class view : public Gtk::Grid {
protected:
	Gtk::GLArea mGlArea;
	scene *scene_ptr;
	int m_view_type;
	int m_draw_type;

	ViewCamera camera;
	ShaderProgram solid_shader;
	ShaderProgram wireframe_shader;
	ShaderProgram grid_shader;
	ShaderProgram vertcolor_shader;
	ShaderProgram pick_shader;
	Mesh axes_mesh;
	Mesh grid_mesh;
	Mesh grid_axis_lines;
	Mesh gizmo_arrow_x, gizmo_arrow_y, gizmo_arrow_z;

	enum { CW_MOVE_TURN_PLANE=0, CW_MOVEMENT_PLANE, CW_Z_ARROW,
	       CW_X_ARROW, CW_Y_ARROW, CW_RELOCATE_SPHERE, CW_TURN_CYLINDER, CW_COUNT };
	Mesh cw_meshes[CW_COUNT];
	bool cw_loaded = false;
	float cw_position[3] = {3.0f, 0.0f, 3.0f};
	int cw_drag_part = 0;

	bool shaders_initialized = false;

	// Picking FBO
	GLuint pick_fbo = 0;
	GLuint pick_color_tex = 0;
	GLuint pick_depth_rbo = 0;
	int pick_fbo_w = 0;
	int pick_fbo_h = 0;

	double last_mouse_x = 0.0;
	double last_mouse_y = 0.0;
	bool dragging = false;
	int drag_button = 0;
	int hovered_sub_element = -1;
	int hovered_edit_mode = 0;

	void onRealize();
	void onUnrealize();
	void initGL();
	bool onRender(const Glib::RefPtr<Gdk::GLContext>& context);
	bool onButtonPress(GdkEventButton* event);
	bool onButtonRelease(GdkEventButton* event);
	bool onMotionNotify(GdkEventMotion* event);
	bool onScroll(GdkEventScroll* event);
	bool onKeyPress(GdkEventKey* event);

	void initShaders();
	void initAxesMesh();
	void initGridMesh();
	void initGizmoMeshes();
	void initControlWidget();
	void renderControlWidget(float* view_mat, float* proj_mat);
	int pickControlWidgetAt(int x, int y, float* view_mat, float* proj_mat);
	void handleControlWidgetDrag(double dx, double dy, int part);
	void ensurePickFBO(int w, int h);
	void renderGrid(float* view_mat, float* proj_mat);
	void renderAxes(float* view_mat, float* proj_mat);
	void renderObjects(float* view_mat, float* proj_mat);
	void renderGizmo(float* view_mat, float* proj_mat);
	int pickObjectAt(int x, int y);
	int pickSubElementAt(int x, int y, int edit_mode);
	void renderSubElementHighlights(float* view_mat, float* proj_mat);
	void handleTransformDrag(double dx, double dy, int button);
	void renderToolbars();
	bool toolbarHitTest(int mx, int my);
	bool toolbar_dragging = false;
	unsigned int last_press_time = 0;

public:
	view(int view_type, int draw_type, scene &curr_scene);
	void setDrawType(int dt);
	void setViewType(int vt);
	ViewCamera& getCamera();
};

#endif // VIEW_H
