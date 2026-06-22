#ifndef VIEW_CAMERA_H
#define VIEW_CAMERA_H

#include <cmath>
#include <cstring>

class ViewCamera {
private:
	float position[3];
	float target[3];
	float up[3];
	float yaw;
	float pitch;
	float distance;
	float ortho_zoom;
	bool is_perspective;

public:
	ViewCamera();

	void setupForView(int view_type);
	void orbit(float delta_yaw, float delta_pitch);
	void pan(float dx, float dy, float viewport_width, float viewport_height);
	void panAlongWorldAxis(float amount, float axis_x, float axis_y, float axis_z);
	void zoom(float delta);

	void getViewMatrix(float* out) const;
	void getPerspectiveMatrix(float fov, float aspect, float near_plane, float far_plane, float* out) const;
	void getOrthoMatrix(float aspect, float near_plane, float far_plane, float* out) const;
	void getProjectionMatrix(float aspect, float* out) const;

	bool isPerspective() const;
	float getDistance() const;
	const float* getPosition() const;
	const float* getTarget() const;
};

void LookAtMatrix(const float* eye, const float* center, const float* up, float* out);
void PerspectiveMatrix(float fov_radians, float aspect, float near_plane, float far_plane, float* out);
void OrthoMatrix(float left, float right, float bottom, float top, float near_plane, float far_plane, float* out);

#endif // VIEW_CAMERA_H
