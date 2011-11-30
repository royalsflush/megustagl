#ifndef MGGL_RAY_H
#define MGGL_RAY_H

struct Ray {
	Vector o;
	Vector dir;

	Ray(const Vector& po, const Vector& pd);
	Ray& operator=(const Ray& a);
};

#endif //MGGL_RAY_H
