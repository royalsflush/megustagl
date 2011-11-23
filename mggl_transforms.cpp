#include "matrix.h"
#include "vector.h"
#include "mggl_transforms.h"

static Matrix<float> projection;
static Matrix<float> modelview;
static Matrix<float>* currMatrix;

void mggl_matrixMode(mggl_matrixModeEnum matType) {
	if (matType==MGGL_PROJECTION)
		currMatrix = &projection;
	else
		currMatrix = &modelview;
}

void mggl_loadIdentity() {
	currMatrix->identity();
}

//Camera setters
void mggl_lookAt(Vector& eye, Vector& center, Vector& up);
void mggl_frustum(float left, float right, float bottom,
		float top, float zNear, float zFar);
void mggl_viewport(int bottom, int left, int width, int height);
