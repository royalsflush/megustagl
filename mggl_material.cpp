#include "vector.h"
#include "mggl_material.h"

static Material currMaterial;

Material* mggl_getMaterial() {
	return &currMaterial;
}

void mggl_setMaterial(const Material& pmat) {
	currMaterial = pmat;
}
