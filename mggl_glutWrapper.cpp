#include <stdlib.h>

#ifdef __APPLE__
	#include <GLUT/glut.h>
#else
	#include <glut.h>
#endif

#include "mggl_light.h"
#include "mggl_fragOps.h"
#include "mggl_raytracer.h"
#include "mggl_renderMode.h"

static void (*drawFunc)();
static void (*resizeFunc)(int,int);

//Initialization functions
void mggl_initLib(int argc, char ** argv) {
	glutInit(&argc,argv);

	//We're only using opengl to paint pixels
	//so won't need anything else
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);

	//Lights start off
	mggl_lightsOff();	
}

void mggl_createWindow(int winW, int winH,
	const char* title) {
	
	glutInitWindowSize(winW,winH);
	glutCreateWindow(title);
	mggl_initBuffers(winW, winH);

	//Init OpenGL
	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glDisable(GL_DEPTH);
	glEnable(GL_COLOR);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, winW, 0.0, winH);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();	
	glViewport(0, 0, winW, winH);
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
	if (mggl_getRenderMode()==MGGL_RAYTRACING)
		mggl_getRaytracer().clearTriangleList();	

	(*drawFunc)();

	if (mggl_getRenderMode()==MGGL_RAYTRACING)
		mggl_getRaytracer().renderToBuffer();

	glClear(GL_COLOR_BUFFER_BIT);
	mggl_drawBuffers();

	glFlush();
	glutSwapBuffers();
}

//Getters for my lib
void mggl_getDrawFunc(void (*func)()) {
	drawFunc=func;
	glutDisplayFunc(mggl_drawFunc);
}

void mggl_resize(int nW, int nH) {
	(*resizeFunc)(nW,nH);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,nW,0.0,nH);

	glMatrixMode(GL_MODELVIEW);	
	glViewport(0,0,nW,nH);
}

void mggl_resizeFunc(void (*func)(int, int)) {
	resizeFunc=func;
	glutReshapeFunc(mggl_resize);
}
