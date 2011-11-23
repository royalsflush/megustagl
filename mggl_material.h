#ifndef MGGL_MATERIAL_H
#define MGGL_MATERIAL_H

#include "vector.h"

struct Material {
	Vector ambient;
	Vector specular;
	Vector diffuse;
	float shininess;
};

Material* mggl_getMaterial();

#endif // MGGL_MATERIAL_H
