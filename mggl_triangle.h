#ifndef MGGL_TRIANGLE_H
#define MGGL_TRIANGLE_H

#include "vector.h"
#include "mggl_material.h"

class Ray;

struct Triangle {
	Vector p1,p2,p3;	
	Material m;

	Triangle(const Material& pmat, const Vector& pp1,
		const Vector& pp2, const Vector& pp3);

	Triangle* checkIntersection(Ray& r);
	Vector getIntersectionPoint(Ray& r);
	Vector getNormalAtPoint(Vector& p);
};

#endif //MGGL_TRIANGLE_H
