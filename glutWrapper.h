#ifndef GLUT_ABST_LAYER_H
#define GLUT_ABST_LAYER_H

//Initialization functions
void mggl_initLib(int argc, char ** argv);
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


#endif // GLUT_ABST_LAYER_H
