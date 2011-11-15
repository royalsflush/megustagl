#ifndef ME_GUSTA_GL_H
#define ME_GUSTA_GL_H

class Vector;

//Using GLUT functions to create
// a simple window
#include "glutWrapper.h"

/*
//Initialization functions
bool mggl_initLib();
void mggl_createWindow(int winW, int winH,
	const char* title);

//Execution loop
void mggl_run();

//Getter for GLUT
void mggl_getKeyboardFunc(void (*func)(unsigned char,
			int,int));	

//Getters for my lib
void mggl_getDrawFunc(void (*func)());
void mggl_resizeFunc(void (*func)(int, int));

//Matrix setter
enum mggl_matrixModeEnum {
	MGGL_PROJECTION,
	MGGL_MODELVIEW
};

void mggl_matrixMode(mggl_matrixModeEnum matType);
void mggl_loadIdentity();

//Camera setters
void mggl_lookAt(Vector& eye, Vector& center, Vector& up);
void mggl_frustum(float left, float right, float bottom,
		float top, float zNear, float zFar);
void mggl_viewport(int bottom, int left, int width, int height);

//Simplified vertex
void mggl_triangle(Vector& v1, Vector& v2, Vector& v3);

//Light setters
enum mggl_lightParameters {
	MGGL_SPECULAR,
	MGGL_DIFFUSE,
	MGGL_AMBIENT,
	MGGL_POSITION,
	MGGL_SHININESS
};

void mggl_turnOn(int lightIdx);
void mggl_changeLight(int lightIdx, mggl_lightParameters 
	parToChange, Vector& newVec);

//Material 
*/
#endif // ME_GUSTA_GL_H
