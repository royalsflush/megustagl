#ifdef __APPLE__
	#include <OpenGL/OpenGL.h>
	#include <GLUT/glut.h>
#else
	#include <glut.h>
#endif

#include "vector.h"
#include "mggl_primitives.h"

//Triangle that uses plane normal ((v1-v2)X(v3-v2))
void mggl_triangle(const Vector& v1, const Vector& v2, const Vector& v3) {
	Vector n = (v1-v2).cross(v3-v2);

	glBegin(GL_TRIANGLES);
		glNormal3f(n.x, n.y, n.z);
		glVertex3f(v1.x, v1.y, v1.z);
		glVertex3f(v2.x, v2.y, v2.z);
		glVertex3f(v3.x, v3.y, v3.z);
	glEnd();
}

//Triangle with given normals
void mggl_triangle(const Vector& v1, const Vector& v2, const Vector& v3,
		const Vector& n1, const Vector& n2, const Vector& n3) {
	
	glBegin(GL_TRIANGLES);
		glNormal3f(n1.x, n1.y, n1.z);
		glVertex3f(v1.x, v1.y, v1.z);
		
		glNormal3f(n2.x, n2.y, n2.z);
		glVertex3f(v2.x, v2.y, v2.z);
		
		glNormal3f(n3.x, n3.y, n3.z);
		glVertex3f(v3.x, v3.y, v3.z);
	glEnd();

}

void mggl_solidCube(float length) {
	Vector v1(length/2.0, length/2.0, length/2.0); 
	Vector v2(-length/2.0, length/2.0, length/2.0); 
	Vector v3(length/2.0, -length/2.0, length/2.0); 
	Vector v4(-length/2.0, -length/2.0, length/2.0); 
	
	Vector v5(length/2.0, length/2.0, -length/2.0); 
	Vector v6(-length/2.0, length/2.0, -length/2.0); 
	Vector v7(length/2.0, -length/2.0, -length/2.0); 
	Vector v8(-length/2.0, -length/2.0, -length/2.0); 

	mggl_triangle(v1,v3,v4);
	mggl_triangle(v4,v2,v1);

	mggl_triangle(v1,v5,v7);
	mggl_triangle(v7,v3,v1);

	mggl_triangle(v2,v4,v8);
	mggl_triangle(v8,v6,v2);
	
	mggl_triangle(v5,v6,v8);
	mggl_triangle(v8,v7,v5);

	mggl_triangle(v2,v1,v5);
	mggl_triangle(v5,v6,v2);

	mggl_triangle(v4,v3,v7);
	mggl_triangle(v7,v8,v4);
}
