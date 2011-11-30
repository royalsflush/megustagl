#ifndef MGGL_RAYTRACER_H
#define MGGL_RAYTRACER_H

#include <vector>
using namespace std;

#include "vector.h"
#include "mggl_light.h"

struct Triangle;

struct Raytracer {
	Vector eye;
	Vector xe, ye, ze;
	double znear;

	//Viewport
	double width, height;

	//Cached
	double a, b;

	//For the rendering
	Vector bgVec;
	vector<Triangle*> objs;
	int raysPP, depth; 

	Vector getPixelColor(int px, int py);
	Vector getColor(double px, double py);
	void setBackground(float pr, float pg, float pg, 
		float pa); 
	void renderToBuffer();
	void clearTriangleList();
};

Raytracer& mggl_getRaytracer();

#endif // MGGL_RAYTRACER_H
