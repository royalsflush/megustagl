#ifndef MGGL_TRANSFORMS
#define MGGL_TRANSFORMS

//Matrix setter
enum mggl_matrixModeEnum {
	MGGL_PROJECTION,
	MGGL_MODELVIEW
};

void mggl_matrixMode(mggl_matrixModeEnum matType);
void mggl_loadIdentity();

//Camera setters
void mggl_lookAt(const Vector& eye, const Vector& center, 
		const Vector& up);
void mggl_frustum(float left, float right, float bottom,
		float top, float zNear, float zFar);
void mggl_viewport(int bottom, int left, int width, int height);
void mggl_perspective(float fovy, float aspect, float znear, float zfar);
Vector& mggl_getEyePos();

#endif //MGGL_TRANSFORMS
