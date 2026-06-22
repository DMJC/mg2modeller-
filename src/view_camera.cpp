#include "../include/view_camera.h"
#include "../include/view.h"

ViewCamera::ViewCamera() {
	position[0] = 5.0f; position[1] = 3.5f; position[2] = 5.0f;
	target[0] = 0.0f; target[1] = 0.0f; target[2] = 0.0f;
	up[0] = 0.0f; up[1] = 1.0f; up[2] = 0.0f;
	yaw = -135.0f;
	pitch = -25.0f;
	distance = 8.0f;
	ortho_zoom = 5.0f;
	is_perspective = true;
}

void ViewCamera::setupForView(int view_type) {
	target[0] = 0.0f; target[1] = 0.0f; target[2] = 0.0f;

	switch (view_type) {
	case TOP_VIEW:
		position[0] = 0.0f; position[1] = distance; position[2] = 0.0f;
		up[0] = 0.0f; up[1] = 0.0f; up[2] = -1.0f;
		is_perspective = false;
		break;
	case BOTTOM_VIEW:
		position[0] = 0.0f; position[1] = -distance; position[2] = 0.0f;
		up[0] = 0.0f; up[1] = 0.0f; up[2] = 1.0f;
		is_perspective = false;
		break;
	case LEFT_VIEW:
		position[0] = -distance; position[1] = 0.0f; position[2] = 0.0f;
		up[0] = 0.0f; up[1] = 1.0f; up[2] = 0.0f;
		is_perspective = false;
		break;
	case RIGHT_VIEW:
		position[0] = distance; position[1] = 0.0f; position[2] = 0.0f;
		up[0] = 0.0f; up[1] = 1.0f; up[2] = 0.0f;
		is_perspective = false;
		break;
	case FRONT_VIEW:
		position[0] = 0.0f; position[1] = 0.0f; position[2] = distance;
		up[0] = 0.0f; up[1] = 1.0f; up[2] = 0.0f;
		is_perspective = false;
		break;
	case BACK_VIEW:
		position[0] = 0.0f; position[1] = 0.0f; position[2] = -distance;
		up[0] = 0.0f; up[1] = 1.0f; up[2] = 0.0f;
		is_perspective = false;
		break;
	case CAMERA_VIEW:
		is_perspective = true;
		break;
	case PERSPECTIVE_VIEW:
	default:
		yaw = -135.0f;
		pitch = -25.0f;
		float yaw_rad = yaw * M_PI / 180.0f;
		float pitch_rad = pitch * M_PI / 180.0f;
		position[0] = target[0] + distance * cosf(pitch_rad) * cosf(yaw_rad);
		position[1] = target[1] + distance * sinf(-pitch_rad);
		position[2] = target[2] + distance * cosf(pitch_rad) * sinf(yaw_rad);
		up[0] = 0.0f; up[1] = 1.0f; up[2] = 0.0f;
		is_perspective = true;
		break;
	}
}

void ViewCamera::orbit(float delta_yaw, float delta_pitch) {
	if (!is_perspective) return;

	yaw += delta_yaw;
	pitch += delta_pitch;
	if (pitch > -1.0f) pitch = -1.0f;
	if (pitch < -89.0f) pitch = -89.0f;

	float yaw_rad = yaw * M_PI / 180.0f;
	float pitch_rad = pitch * M_PI / 180.0f;
	position[0] = target[0] + distance * cosf(pitch_rad) * cosf(yaw_rad);
	position[1] = target[1] + distance * sinf(-pitch_rad);
	position[2] = target[2] + distance * cosf(pitch_rad) * sinf(yaw_rad);
}

void ViewCamera::pan(float dx, float dy, float viewport_width, float viewport_height) {
	float forward[3] = {
		target[0] - position[0],
		target[1] - position[1],
		target[2] - position[2]
	};
	float len = sqrtf(forward[0]*forward[0] + forward[1]*forward[1] + forward[2]*forward[2]);
	if (len > 0.0f) { forward[0] /= len; forward[1] /= len; forward[2] /= len; }

	float right[3] = {
		forward[1]*up[2] - forward[2]*up[1],
		forward[2]*up[0] - forward[0]*up[2],
		forward[0]*up[1] - forward[1]*up[0]
	};
	len = sqrtf(right[0]*right[0] + right[1]*right[1] + right[2]*right[2]);
	if (len > 0.0f) { right[0] /= len; right[1] /= len; right[2] /= len; }

	float cam_up[3] = {
		right[1]*forward[2] - right[2]*forward[1],
		right[2]*forward[0] - right[0]*forward[2],
		right[0]*forward[1] - right[1]*forward[0]
	};

	float scale = is_perspective ? distance * 0.002f : ortho_zoom * 0.002f;
	float move_x = -dx * scale;
	float move_y = dy * scale;

	for (int i = 0; i < 3; i++) {
		float offset = right[i] * move_x + cam_up[i] * move_y;
		position[i] += offset;
		target[i] += offset;
	}
}

void ViewCamera::panAlongWorldAxis(float amount, float axis_x, float axis_y, float axis_z) {
	position[0] += amount * axis_x;
	position[1] += amount * axis_y;
	position[2] += amount * axis_z;
	target[0] += amount * axis_x;
	target[1] += amount * axis_y;
	target[2] += amount * axis_z;
}

void ViewCamera::zoom(float delta) {
	if (is_perspective) {
		distance -= delta;
		if (distance < 0.1f) distance = 0.1f;
		if (distance > 1000.0f) distance = 1000.0f;

		float yaw_rad = yaw * M_PI / 180.0f;
		float pitch_rad = pitch * M_PI / 180.0f;
		position[0] = target[0] + distance * cosf(pitch_rad) * cosf(yaw_rad);
		position[1] = target[1] + distance * sinf(-pitch_rad);
		position[2] = target[2] + distance * cosf(pitch_rad) * sinf(yaw_rad);
	} else {
		ortho_zoom -= delta * 0.5f;
		if (ortho_zoom < 0.1f) ortho_zoom = 0.1f;
		if (ortho_zoom > 500.0f) ortho_zoom = 500.0f;
	}
}

void ViewCamera::getViewMatrix(float* out) const {
	LookAtMatrix(position, target, up, out);
}

void ViewCamera::getPerspectiveMatrix(float fov, float aspect, float near_plane, float far_plane, float* out) const {
	PerspectiveMatrix(fov, aspect, near_plane, far_plane, out);
}

void ViewCamera::getOrthoMatrix(float aspect, float near_plane, float far_plane, float* out) const {
	float half_h = ortho_zoom;
	float half_w = half_h * aspect;
	OrthoMatrix(-half_w, half_w, -half_h, half_h, near_plane, far_plane, out);
}

void ViewCamera::getProjectionMatrix(float aspect, float* out) const {
	if (is_perspective) {
		PerspectiveMatrix(45.0f * M_PI / 180.0f, aspect, 0.1f, 1000.0f, out);
	} else {
		getOrthoMatrix(aspect, -1000.0f, 1000.0f, out);
	}
}

bool ViewCamera::isPerspective() const { return is_perspective; }
float ViewCamera::getDistance() const { return distance; }
const float* ViewCamera::getPosition() const { return position; }
const float* ViewCamera::getTarget() const { return target; }

// Standalone matrix functions

void LookAtMatrix(const float* eye, const float* center, const float* up, float* out) {
	float f[3] = {
		center[0] - eye[0],
		center[1] - eye[1],
		center[2] - eye[2]
	};
	float len = sqrtf(f[0]*f[0] + f[1]*f[1] + f[2]*f[2]);
	if (len > 0.0f) { f[0] /= len; f[1] /= len; f[2] /= len; }

	float s[3] = {
		f[1]*up[2] - f[2]*up[1],
		f[2]*up[0] - f[0]*up[2],
		f[0]*up[1] - f[1]*up[0]
	};
	len = sqrtf(s[0]*s[0] + s[1]*s[1] + s[2]*s[2]);
	if (len > 0.0f) { s[0] /= len; s[1] /= len; s[2] /= len; }

	float u[3] = {
		s[1]*f[2] - s[2]*f[1],
		s[2]*f[0] - s[0]*f[2],
		s[0]*f[1] - s[1]*f[0]
	};

	memset(out, 0, sizeof(float) * 16);
	out[0]  =  s[0]; out[4]  =  s[1]; out[8]  =  s[2];
	out[1]  =  u[0]; out[5]  =  u[1]; out[9]  =  u[2];
	out[2]  = -f[0]; out[6]  = -f[1]; out[10] = -f[2];
	out[12] = -(s[0]*eye[0] + s[1]*eye[1] + s[2]*eye[2]);
	out[13] = -(u[0]*eye[0] + u[1]*eye[1] + u[2]*eye[2]);
	out[14] =  (f[0]*eye[0] + f[1]*eye[1] + f[2]*eye[2]);
	out[15] = 1.0f;
}

void PerspectiveMatrix(float fov_radians, float aspect, float near_plane, float far_plane, float* out) {
	float f = 1.0f / tanf(fov_radians / 2.0f);
	memset(out, 0, sizeof(float) * 16);
	out[0]  = f / aspect;
	out[5]  = f;
	out[10] = (far_plane + near_plane) / (near_plane - far_plane);
	out[11] = -1.0f;
	out[14] = (2.0f * far_plane * near_plane) / (near_plane - far_plane);
}

void OrthoMatrix(float left, float right, float bottom, float top, float near_plane, float far_plane, float* out) {
	memset(out, 0, sizeof(float) * 16);
	out[0]  = 2.0f / (right - left);
	out[5]  = 2.0f / (top - bottom);
	out[10] = -2.0f / (far_plane - near_plane);
	out[12] = -(right + left) / (right - left);
	out[13] = -(top + bottom) / (top - bottom);
	out[14] = -(far_plane + near_plane) / (far_plane - near_plane);
	out[15] = 1.0f;
}
