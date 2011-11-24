#ifdef __APPLE__
	#include <OpenGL/OpenGL.h>
	#include <GLUT/glut.h>
#else
	#include <glut.h>
#endif

#include "vector.h"
#include "mggl_light.h"
#include "mggl_transforms.h"
#include "mggl_vertexOps.h"

Vector mggl_processVertex(const Vector& v, const Vector& n) {
	Vector eyeV = mggl_modelViewTransform(v);
	Vector eyeN = mggl_normalToEyeTransform(n);
	Vector col = mggl_calcColor(eyeV,eyeN);
	
	glColor3f(col.x, col.y, col.z);
//	glNormal3f(n.x, n.y, n.z);
	glVertex3f(v.x, v.y,v.z);
	
	return col;
}

Vector mggl_modelViewTransform(const Vector& v) {
	Matrix<float> mv = mggl_getModelViewMatrix();	
	Vector eyeV;

	eyeV.x = mv[0][0]*(v.x)+mv[0][1]*(v.y)+mv[0][2]*(v.z)+mv[0][3]*(v.w);
	eyeV.y = mv[1][0]*(v.x)+mv[1][1]*(v.y)+mv[1][2]*(v.z)+mv[1][3]*(v.w);
	eyeV.z = mv[2][0]*(v.x)+mv[2][1]*(v.y)+mv[2][2]*(v.z)+mv[2][3]*(v.w);
	eyeV.w = mv[3][0]*(v.x)+mv[3][1]*(v.y)+mv[3][2]*(v.z)+mv[3][3]*(v.w);

	return eyeV;
}

Vector mggl_normalToEyeTransform(const Vector& v) {
	Matrix<float> invMv = mggl_getInverseMVMatrix();
	invMv.t(); Vector eyeN; eyeN.w = 0;

	eyeN.x = invMv[0][0]*(v.x)+invMv[0][1]*(v.y)+invMv[0][2]*(v.z);
	eyeN.y = invMv[1][0]*(v.x)+invMv[1][1]*(v.y)+invMv[1][2]*(v.z);
	eyeN.z = invMv[2][0]*(v.x)+invMv[2][1]*(v.y)+invMv[2][2]*(v.z);
	eyeN.normalize();

	return eyeN;
}

Vector mggl_projectionTransform(const Vector& v) {
	Vector projV;
	Matrix<float> projMat = mggl_getProjectionMatrix();

	projV.x = projMat[0][0]*(v.x)+projMat[0][1]*(v.y)+projMat[0][2]*(v.z)+projMat[0][3]*(v.w);
	projV.y = projMat[1][0]*(v.x)+projMat[1][1]*(v.y)+projMat[1][2]*(v.z)+projMat[1][3]*(v.w);
	projV.z = projMat[2][0]*(v.x)+projMat[2][1]*(v.y)+projMat[2][2]*(v.z)+projMat[2][3]*(v.w);
	projV.w = projMat[3][0]*(v.x)+projMat[3][1]*(v.y)+projMat[3][2]*(v.z)+projMat[3][3]*(v.w);

	return projV;
}

Vector mggl_viewportTransform(const Vector& v) {
	Vector win; win.z=0; win.w=0;
	Vector vp = mggl_getViewport();

	//Here z is width, w is height
	win.x=(v.x+1)*(vp.z/2.0)+vp.x;
	win.y=(v.y+1)*(vp.w/2.0)+vp.y;

	return win;
}
