#include <stdio.h>
#include <stdlib.h>

#include "meGustaGL.h"
using namespace std;

#define WIN_W 1024
#define WIN_H 768

void keyboardHandle(unsigned char k, int x,
	int y) {
	
	switch (k) {
		case 'q':
			exit(0);
	}
}

void draw() {

}

void resizeHandler(int nWidth, int nHeight) {

} 

int main(int argc, char ** argv) {
	mggl_initLib(argc,argv);
	mggl_createWindow(WIN_W,WIN_H, "Me gusta demo");

	mggl_getKeyboardFunc(keyboardHandle);
	mggl_getDrawFunc(draw);
	mggl_resizeFunc(resizeHandler);

	mggl_run();
	
	return 0;
}
