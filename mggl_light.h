#ifndef MGGL_LIGHT_H
#define MGGL_LIGHT_H

#include "vector.h"

struct Light {
	Vector ambient;
	Vector specular;
	Vector diffuse;
	Vector position;

	float shininess;
	bool on;
};

Vector mggl_calcColor(const Vector& v, const Vector& n);
Light* mggl_getLight(int idx);
void mggl_lightsOff();
Vector mggl_calcContribForRaytracing(int idx, const Vector& v, const Vector& n,
		const Vector& eye);
int mggl_getLightVecSize();

#endif // MGGL_LIGHT_H
