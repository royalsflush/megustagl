#include <stdlib.h>

#ifdef __APPLE__
	#include <GLUT/glut.h>
#else
	#include <glut.h>
#endif

#include "mggl_light.h"
#include "mggl_fragOps.h"

static void (*drawFunc)();

//Initialization functions
void mggl_initLib(int argc, char ** argv) {
	glutInit(&argc,argv);

	//We're only using opengl to paint pixels
	//so won't need anything else
	glutInitDisplayMode(GLUT_DEPTH | GLUT_RGB);

	//Lights start off
	mggl_lightsOff();	
}

void mggl_createWindow(int winW, int winH,
	const char* title) {
	
	glutInitWindowSize(winW,winH);
	glutCreateWindow(title);
	mggl_initBuffers(winW, winH);
}

//Execution loop
void mggl_run() {
	glutMainLoop();
}

//Getter for GLUT
void mggl_getKeyboardFunc(void (*func)(unsigned char,
			int,int)) {
	glutKeyboardFunc(func);
}	

void mggl_drawFunc() {
	(*drawFunc)();
	mggl_drawBuffers();
}

//Getters for my lib
void mggl_getDrawFunc(void (*func)()) {
	drawFunc=func;
	glutDisplayFunc(mggl_drawFunc);
}

void mggl_resizeFunc(void (*func)(int, int)) {
	glutReshapeFunc(func);
}
