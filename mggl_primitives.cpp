#ifdef __APPLE__
	#include <OpenGL/OpenGL.h>
	#include <GLUT/glut.h>
#else
	#include <glut.h>
#endif

#include "vector.h"
#include "mggl_vertexOps.h"
#include "mggl_primitives.h"

//Triangle that uses plane normal ((v3-v2)X(v1-v2))
void mggl_triangle(const Vector& v1, const Vector& v2, const Vector& v3) {
	Vector n = (v3-v2).cross(v1-v2);
	n.w=0; n.normalize();

	glBegin(GL_TRIANGLES);
		mggl_processVertex(v1,n);
		mggl_processVertex(v2,n);
		mggl_processVertex(v3,n);
	glEnd();
}

//Triangle with given normals
void mggl_triangle(const Vector& v1, const Vector& v2, const Vector& v3,
		const Vector& n1, const Vector& n2, const Vector& n3) {
	
	glBegin(GL_TRIANGLES);
		mggl_processVertex(v1,n1);
		mggl_processVertex(v2,n2);
		mggl_processVertex(v3,n3);
	glEnd();

}

//Looks good!
void mggl_solidCube(float length) {
	Vector v1(length/2.0, length/2.0, length/2.0); 
	Vector v2(-length/2.0, length/2.0, length/2.0); 
	Vector v3(length/2.0, -length/2.0, length/2.0); 
	Vector v4(-length/2.0, -length/2.0, length/2.0); 
	
	Vector v5(length/2.0, length/2.0, -length/2.0); 
	Vector v6(-length/2.0, length/2.0, -length/2.0); 
	Vector v7(length/2.0, -length/2.0, -length/2.0); 
	Vector v8(-length/2.0, -length/2.0, -length/2.0); 

	mggl_triangle(v4,v3,v1);
	mggl_triangle(v1,v2,v4);
	
	mggl_triangle(v7,v5,v1);
	mggl_triangle(v1,v3,v7);

	mggl_triangle(v4,v2,v6);
	mggl_triangle(v6,v8,v4);

	mggl_triangle(v8,v6,v5);
	mggl_triangle(v5,v7,v8);

	mggl_triangle(v2,v1,v5);
	mggl_triangle(v5,v6,v2);

	mggl_triangle(v8,v7,v3);
	mggl_triangle(v3,v4,v8);
}
