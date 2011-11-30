#ifndef MGGL_RAYTRACER_H
#define MGGL_RAYTRACER_H

#include <vector>
using namespace std;

#include "vector.h"
#include "mggl_light.h"

struct Triangle;

struct Raytracer {
	double fovy, asp;
	double znear, zfar;
	Vector eye, up, center;

	//Viewport
	double bot, left, 
		width, height;

	//Cached
	double a, b;
	Vector xe, ye, ze;

	//For the rendering
	Vector bgVec;
	vector<Triangle*> objs;
	int raysPP, depth; 

	Vector getPixelColor(int px, int py);
	Vector getColor(double px, double py);
	void setBackground(float pr, float pg, float pg, 
		float pa); 
};

#endif // MGGL_RAYTRACER_H
