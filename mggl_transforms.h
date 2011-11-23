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
void mggl_lookAt(Vector& eye, Vector& center, Vector& up);
void mggl_frustum(float left, float right, float bottom,
		float top, float zNear, float zFar);
void mggl_viewport(int bottom, int left, int width, int height);

#endif //MGGL_TRANSFORMS
