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

/*
typedef struct {
	float ambiente[4]; 
	float diffuse[4]; 
	float specular[4];
	float shininess[1]; 
} Material;
Material brass={{0.33f, 0.22f, 0.03f, 1}, {0.78f, 0.57f, 0.11f, 1}, {0.99f, 0.91f, 0.81f, 1}, {27.8f}};
*/

void setMaterial() {
	/*
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, p->ambiente);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, p->diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, p->specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, p->shininess);
	*/
	
	mggl_getMaterial()->ambient = Vector(0.33, 0.22, 0.03, 1.0);
	mggl_getMaterial()->diffuse = Vector(0.78, 0.57, 0.11, 1.0);
	mggl_getMaterial()->specular = Vector(0.99, 0.91, 0.81, 1.0);
	mggl_getMaterial()->shininess = 27.8; 
}

void draw() {	
	glClearColor(0.4f,0.4f,0.4f,1);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	setMaterial();

//	glutSolidCube(1);	
	mggl_solidCube(1);
	glFlush();
}

void keyboardHandle(unsigned char k, int x,
		int y) {

	switch (k) {
		case 'q':
			exit(0);
	}
}

void resizeHandler(int nWidth, int nHeight) {
	glViewport(0, 0, (GLsizei)nWidth, (GLsizei)nHeight);

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
	float position[]={ 0.5f,2.f,0.f,1.f};   float low[]={0.2f,0.2f,0.2f,1};   float white[]={1,1,1,1};

/*
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glLightfv(GL_LIGHT0, GL_AMBIENT, low);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	*/	

	mggl_matrixMode(MGGL_MODELVIEW);
	mggl_loadIdentity(); 

	mggl_getLight(0)->on=true;
	mggl_getLight(0)->ambient=Vector(low);
	mggl_getLight(0)->diffuse=Vector(white);
	mggl_getLight(0)->specular=Vector(white);
	mggl_getLight(0)->position=position;
}

int main(int argc, char ** argv) {
	mggl_initLib(argc,argv);
	mggl_createWindow(WIN_W,WIN_H, "Me gusta demo");

	mggl_getKeyboardFunc(keyboardHandle);
	mggl_getDrawFunc(draw);
	mggl_resizeFunc(resizeHandler);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	initLight();

	mggl_run();

	return 0;
}
