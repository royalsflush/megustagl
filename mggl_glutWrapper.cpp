#include <stdlib.h>

#ifdef __APPLE__
	#include <GLUT/glut.h>
#else
	#include <glut.h>
#endif

//Initialization functions
void mggl_initLib(int argc, char ** argv) {
	glutInit(&argc,argv);

	//We're only using opengl to paint pixels
	//so won't need anything else
	glutInitDisplayMode(GLUT_DEPTH | GLUT_RGB);
}

void mggl_createWindow(int winW, int winH,
	const char* title) {
	
	glutInitWindowSize(winW,winH);
	glutCreateWindow(title);
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
	glutDisplayFunc(func);	
}

void mggl_resizeFunc(void (*func)(int, int)) {
	glutReshapeFunc(func);
}
