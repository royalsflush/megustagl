#ifdef __APPLE__
	#include <OpenGL/OpenGL.h>
	#include <GLUT/glut.h>
#else
	#include <glut.h>
#endif

#include "vector.h"
#include "mggl_light.h"
#include "mggl_vertexOps.h"


Vector mggl_processVertex(const Vector& v, const Vector& n) {
	Vector col = mggl_calcColor(v,n);
	glColor3f(col.x, col.y, col.z);	

//	glNormal3f(n.x, n.y, n.z);
	glVertex3f(v.x, v.y, v.z);
}
