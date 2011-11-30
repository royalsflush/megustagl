#include <math.h>
#include <stdlib.h>

#include <vector>
using namespace std;

#include "vector.h"
#include "mggl_ray.h"
#include "mggl_light.h"
#include "mggl_triangle.h"
#include "mggl_raytracer.h"

const int negInf = 0xc0c0c0c0;
const int inf = 0x3f3f3f3f;

Vector Raytracer::getColor(double px, double py) {
	Vector o, d;

	Ray r(o,d); //calcRay
	Triangle* obj=NULL;
	int minZ=inf; 

	for (int i=0; i<(int)objs.size(); i++) {
		Triangle* tmp=objs[i]->checkIntersection(r);

		if (tmp) {
			Vector tmpPt=objs[i]->getIntersectionPoint(r);

			if (tmpPt.z<minZ) {
				obj=tmp;
				minZ = tmpPt.z;
			} 
		}
	}	

	if (!obj) return bgVec;

	Vector color(0.0,0.0,0.0,0.0);
	Vector pt = obj->getIntersectionPoint(r);
	Vector n = obj->getNormalAtPoint(pt);

	for (int i=0; i<mggl_getLightVecSize(); i++) { 
		//Check if light is actually hitting is object
		Vector l = mggl_getLight(i)->position;
		Ray ol(l, pt-l);

//		if (root->checkIntersection(ol)==obj)
			color+=mggl_calcContribForRaytracing(i,pt,n,eye);
	}

	return color;
}

Vector Raytracer::getPixelColor(int px, int py) {
	srand(time(NULL));
	Vector color(0.0,0.0,0.0,0.0);

	for (int i=0; i<this->raysPP; i++) {
		double dx = (double)rand()/(double)RAND_MAX;
		double dy = (double)rand()/(double)RAND_MAX;

		color+=getColor(px+dx,py+dy);
	}

	if (this->raysPP)
		color/=(double)raysPP;
	return color;
}

void Raytracer::setBackground(float pr, float pg, float pb, float pa) {
	bgVec = Vector(pr,pg,pb,pa);
}
