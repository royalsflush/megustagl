#ifndef MGGL_TRANSFORMS
#define MGGL_TRANSFORMS

#include "matrix.h"

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

//Internal getters
Vector& mggl_getEyePos();
Matrix<float>& mggl_getModelViewMatrix();
Matrix<float>& mggl_getInverseMVMatrix();
Matrix<float>& mggl_getProjectionMatrix();
Vector& mggl_getViewport();

#endif //MGGL_TRANSFORMS
