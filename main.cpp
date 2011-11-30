#include <stdio.h>
#include <stdlib.h>

#include "meGustaGL.h"

#ifdef __APPLE__
	#include <OpenGL/OpenGL.h>
	#include <GLUT/glut.h>
#else
	#include <glut.h>
#endif

using namespace std;

#define WIN_W 1024
#define WIN_H 768

void setMaterial() {
	mggl_getMaterial()->ambient = Vector(0.33, 0.22, 0.03, 1.0);
	mggl_getMaterial()->diffuse = Vector(0.78, 0.57, 0.11, 1.0);
	mggl_getMaterial()->specular = Vector(0.99, 0.91, 0.81, 1.0);
	mggl_getMaterial()->shininess = 27.8;
}

void draw() {	
	mggl_clearBuffers();	
	setMaterial();

	mggl_solidCube(1);
}

void keyboardHandle(unsigned char k, int x,
		int y) {

	switch (k) {
		case 'q':
			exit(0);
			break;
		case 'r':
			mggl_setRenderMode(MGGL_RAYTRACING);
			break;
		case 'g':
			mggl_setRenderMode(MGGL_OPENGL_STYLE);
			break;
	}
}

void resizeHandler(int nWidth, int nHeight) {
	mggl_setClearColor(Vector(0.4,0.4,0.4,1.0));

	mggl_viewport(0,0, nWidth, nHeight);
	mggl_matrixMode(MGGL_PROJECTION);
	mggl_loadIdentity();
	mggl_perspective(45, 4./3, 0.5, 10);

	mggl_matrixMode(MGGL_MODELVIEW);
	mggl_loadIdentity();
	mggl_lookAt(Vector(1.5, 1.5, 1.2),
		Vector(0.0f, 0.0f, 0.0f),
		Vector(0.0f, 0.0f, 1.0f));
} 

void initLight() {
	float position[]={0.5f,2.f,0.f,1.f};   
	float low[]={0.2f,0.2f,0.2f,1};   
	float white[]={1,1,1,1};

	mggl_matrixMode(MGGL_MODELVIEW);
	mggl_loadIdentity(); 

	mggl_getLight(0)->on=true;
	mggl_getLight(0)->ambient=Vector(low);
	mggl_getLight(0)->diffuse=Vector(white);
	mggl_getLight(0)->specular=Vector(white);
	mggl_getLight(0)->position=Vector(position); 	
}

int main(int argc, char ** argv) {
	mggl_initLib(argc,argv);
	mggl_createWindow(WIN_W,WIN_H, "Me gusta demo");

	mggl_getKeyboardFunc(keyboardHandle);
	mggl_getDrawFunc(draw);
	mggl_resizeFunc(resizeHandler);
	initLight();

	mggl_run();

	return 0;
}
