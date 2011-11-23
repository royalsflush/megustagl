#ifndef ME_GUSTA_GL_H
#define ME_GUSTA_GL_H

//All the coords are given using this
//lib
#include "vector.h"

//Using GLUT functions to create
// a simple window
#include "mggl_glutWrapper.h"

//All camera and space transformations
// are in this file
#include "mggl_transforms.h"

//All vertex handlers are in this file
#include "mggl_primitives.h"

/*
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
