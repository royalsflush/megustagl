#ifndef MGGL_FRAG_OPS_H
#define MGGL_FRAG_OPS_H

#include "vector.h"

//Draws buffer on the screen
void mggl_drawBuffers();

//Clears both depth and color buffer
void mggl_clearBuffers();

//Init buffers
void mggl_initBuffers(int wid, int hei);

//Set color to pixel x,y
void setColor(int x, int y, Vector& color);

//Get depth of pixel x,y
float getDepth(int x, int y);

//Set depth of pixel x,y
void setDepth(int x, int y, float z);

void rasterTriangle(Vector& v1, Vector& v2,
		Vector& v3, const Vector& c1,
		const Vector& c2, const Vector& c3);

#endif //MGGL_FRAG_OPS_H