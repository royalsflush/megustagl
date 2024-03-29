#include <assert.h>
#include <math.h>

#include "vector.h"
#include "mggl_light.h"
#include "mggl_material.h"
#include "mggl_transforms.h"
#include "mggl_vertexOps.h"

#define VLIGHTS_TAM 8
#define max(a,b) ((a>b)?a:b)

static Light lightsVec[VLIGHTS_TAM];

Vector mggl_calcColor(const Vector& v, const Vector& n) {
	Vector color(0.0, 0.0, 0.0, 0.0);

	Vector ldif, lspec, lamb, lpos;
	Vector mdif, mspec, mamb;

	mdif = mggl_getMaterial()->diffuse;
	mspec = mggl_getMaterial()->specular;
	mamb = mggl_getMaterial()->ambient;
	float shi = mggl_getMaterial()->shininess;

	for (int i=0; i<VLIGHTS_TAM; i++) {
		if (lightsVec[i].on==false) continue;

		ldif = lightsVec[i].diffuse;
		lamb = lightsVec[i].ambient;
		lpos = lightsVec[i].position;
		lspec = lightsVec[i].specular;		

		Vector l = lpos-v; l.w=0;
		l.normalize();

		Vector obs = v*(-1); obs.w=0;
		obs.normalize();		

		Vector h = l+obs; h.w=0;
		h.normalize();

		color.x+=(lamb.x)*(mamb.x);
		color.y+=(lamb.y)*(mamb.y);
		color.z+=(lamb.z)*(mamb.z);

		if (l*n>0) {
			//Diffuse
			color.x+=(ldif.x)*(l*n)*(mdif.x);
			color.y+=(ldif.y)*(l*n)*(mdif.y);
			color.z+=(ldif.z)*(l*n)*(mdif.z);

			//Specular
			double coef = pow(max(h*n,0), shi);
			color.x+=(lspec.x)*(mspec.x)*coef;
			color.y+=(lspec.y)*(mspec.y)*coef;
			color.z+=(lspec.z)*(mspec.z)*coef;
		}		
	}

	return color;
}

Light* mggl_getLight(int idx) {
	assert(idx>=0 && idx<VLIGHTS_TAM);
	return &lightsVec[idx];
}

void mggl_lightsOff() {
	for (int i=0; i<VLIGHTS_TAM; i++)
		lightsVec[i].on=false;
}

Vector mggl_calcContribForRaytracing(int idx, const Vector& v, const Vector& n,
		const Vector& eye) {
	Vector color(0.0, 0.0, 0.0, 0.0);
	if (lightsVec[idx].on==false) return color;

	Vector ldif, lspec, lamb, lpos;
	Vector mdif, mspec, mamb;

	mdif = mggl_getMaterial()->diffuse;
	mspec = mggl_getMaterial()->specular;
	mamb = mggl_getMaterial()->ambient;
	float shi = mggl_getMaterial()->shininess;

	ldif = lightsVec[idx].diffuse;
	lamb = lightsVec[idx].ambient;
	lpos = lightsVec[idx].position;
	lspec = lightsVec[idx].specular;		

	Vector l = lpos-v; l.w=0;
	l.normalize();

	Vector obs = v*(-1); obs.w=0;
	obs.normalize();		

	Vector h = l+obs; h.w=0;
	h.normalize();

	color.x+=(lamb.x)*(mamb.x);
	color.y+=(lamb.y)*(mamb.y);
	color.z+=(lamb.z)*(mamb.z);

	if (l*n>0) {
		//Diffuse
		color.x+=(ldif.x)*(l*n)*(mdif.x);
		color.y+=(ldif.y)*(l*n)*(mdif.y);
		color.z+=(ldif.z)*(l*n)*(mdif.z);

		//Specular
		double coef = pow(max(h*n,0), shi);
		color.x+=(lspec.x)*(mspec.x)*coef;
		color.y+=(lspec.y)*(mspec.y)*coef;
		color.z+=(lspec.z)*(mspec.z)*coef;
	}
}

int mggl_getLightVecSize() {
	return VLIGHTS_TAM;
}
