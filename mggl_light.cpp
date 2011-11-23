#include <assert.h>
#include <math.h>

#include "vector.h"
#include "mggl_light.h"
#include "mggl_material.h"
#include "mggl_transforms.h"

#define VLIGHTS_TAM 8

static Light lightsVec[VLIGHTS_TAM];

Vector mggl_calcColor(const Vector& v, const Vector& n) {
	Vector eye = mggl_getEyePos();
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

		Vector l = lpos - v;
		l.normalize();
		n.print();

//		Vector r = (n*(l*n))*2.0-l;
//		r.normalize();

//		Vector obs = eye-v;
//		obs.normalize();		

		color.x=(lamb.x)*(mamb.x);
		color.y=(lamb.y)*(mamb.y);
		color.z=(lamb.z)*(mamb.z);

		if (l*n>0) {
			//Diffuse
			color.x+=(ldif.x)*(l*n)*(mdif.x);
			color.y+=(ldif.y)*(l*n)*(mdif.y);
			color.z+=(ldif.z)*(l*n)*(mdif.z);

			color.print();			
			//double robs = pow(r*obs, shi);
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
