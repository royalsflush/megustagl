#include <stdlib.h>

#ifdef __APPLE__
	#include <GLUT/glut.h>
#else
	#include <glut.h>
#endif

#include "mggl_light.h"
#include "mggl_fragOps.h"

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

//Getters for my lib
void mggl_getDrawFunc(void (*func)()) {
	//(*func)();
	glutDisplayFunc(mggl_drawBuffers);
}

void mggl_resizeFunc(void (*func)(int, int)) {
	glutReshapeFunc(func);
}
