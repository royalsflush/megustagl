#include <math.h>
#include <assert.h>

#include "matrix.h"
#include "vector.h"
#include "mggl_transforms.h"

static Matrix<float> projection;
static Matrix<float> invProj;
static Matrix<float> modelview;
static Matrix<float> invMV;
static Matrix<float>* currMatrix;
static Matrix<float>* currInv;

static Vector eyePos;
static Vector viewport;

const double pi = acos(-1.0); 

//Utility functions
double toRad(double x) {
	return (pi*x)/180.0;
}

void mggl_matrixMode(mggl_matrixModeEnum matType) {
	if (matType==MGGL_PROJECTION) {
		currMatrix = &projection;
		currInv = &invProj;
	}
	else {
		currMatrix = &modelview;
		currInv = &invMV;
	}
}

// Ok!
void mggl_loadIdentity() {
	currMatrix->identity();
}

//Ok!
void mggl_lookAt(const Vector& eye, const Vector& center, 
		const Vector& up) {
	Matrix<float> matR, matT;
	eyePos=eye;

	Vector ze = center-eye;	ze.w=0;
	Vector xe = ze.cross(up); xe.w=0;
	Vector ye = xe.cross(ze); ye.w=0;
	
	xe.normalize();
	ye.normalize();
	ze.normalize();

	matR.set(4,4,
		 xe.x,  xe.y,  xe.z, 0.0f,
		 ye.x,  ye.y,  ye.z, 0.0f,
		-ze.x, -ze.y, -ze.z, 0.0f,
	 	 0.0f,  0.0f,  0.0f, 1.0f); 

	matT.set(4,4,
		1.0f, 0.0f, 0.0f, -eye.x,
		0.0f, 1.0f, 0.0f, -eye.y,
		0.0f, 0.0f, 1.0f, -eye.z,
		0.0f, 0.0f, 0.0f, 1.0f);

	*currMatrix = matR*matT;
	Matrix<float> tmp = matR*matT;
	*currInv = tmp; currInv->invert();
	tmp.t();
}

void mggl_frustum(float left, float right, float bottom,
		float top, float zNear, float zFar) {
	Matrix<float> matP;
	float l=left, r=right, b=bottom, t=top,
		n=zNear, f=zFar;

	matP.set(4,4,
		(2*n)/(r-l),         0.0f,  (r+l)/(r-l),           0.0f,
		        0.0f, (2*n)/(t-b),  (t+b)/(t-b),           0.0f,
		        0.0f,        0.0f, -(f+n)/(f-n), -(2*f*n)/(f-n),
		        0.0f,        0.0f,        -1.0f,           0.0f);

}

//Ok!
void mggl_perspective(float fovy, float aspect, float znear, float zfar) {
	Matrix<float> matP;

	float f=zfar, n=znear;
	float t = n*tan(toRad(fovy/2.0)), b=-t;
	float r=((t-b)*aspect)/2.0, l=-r;

	matP.set(4,4,
		(2*n)/(r-l),         0.0f,  (r+l)/(r-l),           0.0f,
		        0.0f, (2*n)/(t-b),  (t+b)/(t-b),           0.0f,
		        0.0f,        0.0f, -(f+n)/(f-n), -(2*f*n)/(f-n),
		        0.0f,        0.0f,        -1.0f,           0.0f);

	*currMatrix = matP;
	Matrix<float> tmp = matP;
	tmp.t();
}

void mggl_viewport(int left, int bottom, int width, int height) {
	viewport = Vector(left, bottom, width, height);
}

Vector& mggl_getEyePos() {
	return eyePos;
}

Matrix<float>& mggl_getModelViewMatrix() {
	return modelview;  
}

Matrix<float>& mggl_getInverseMVMatrix() {
	return invMV;
}

Matrix<float>& mggl_getProjectionMatrix() {
	return projection;
}

Vector& mggl_getViewport() {
	return viewport;
}
