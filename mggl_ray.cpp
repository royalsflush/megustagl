#include "vector.h"
#include "mggl_ray.h"

Ray::Ray(const Vector& po, const Vector& pd) : o(po), dir(pd) {
	dir.normalize();
}

Ray& Ray::operator=(const Ray& a) {
	this->o = a.o;
	this->dir = a.dir;

	return *this;
}
