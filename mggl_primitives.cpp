#include "vector.h"
#include "mggl_vertexOps.h"
#include "mggl_fragOps.h"
#include "mggl_primitives.h"
#include "mggl_renderMode.h"
#include "mggl_raytracer.h"
#include "mggl_material.h"
#include "mggl_triangle.h"

//Triangle that uses plane normal ((v3-v2)X(v1-v2))
void mggl_triangle(const Vector& v1, const Vector& v2, const Vector& v3) {
	if (mggl_getRenderMode()==MGGL_OPENGL_STYLE) {
		Vector n = (v3-v2).cross(v1-v2);
		n.w=0; n.normalize();

		Vector c1,c2,c3;
		Vector p1,p2,p3;

		c1=mggl_processVertex(v1,n);
		c2=mggl_processVertex(v2,n);
		c3=mggl_processVertex(v3,n);

		Vector e1, e2, e3;
		e1 = mggl_modelViewTransform(v1);
		e2 = mggl_modelViewTransform(v2);
		e3 = mggl_modelViewTransform(v3);

		p1 = mggl_projectionTransform(e1);
		p2 = mggl_projectionTransform(e2);
		p3 = mggl_projectionTransform(e3);

		mggl_rasterTriangle(p1, p2, p3,
				c1, c2, c3);
	}
	else mggl_getRaytracer().objs.push_back(
		new Triangle(*mggl_getMaterial(), v1, v2, v3));
}

//Triangle with given normals (DOES NOT WORK)
void mggl_triangle(const Vector& v1, const Vector& v2, const Vector& v3,
		const Vector& n1, const Vector& n2, const Vector& n3) {

	mggl_processVertex(v1,n1);
	mggl_processVertex(v2,n2);
	mggl_processVertex(v3,n3);

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
