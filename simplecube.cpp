#include <stdlib.h>

#ifdef __APPLE__
	#include <OpenGL/OpenGL.h>
	#include <GLUT/glut.h>
#else
	#include <glut.h>
#endif

typedef struct {float ambiente[4]; float diffuse[4]; float specular[4];

float shininess[1]; } Material;
Material brass={{0.33f, 0.22f, 0.03f, 1}, {0.78f, 0.57f, 0.11f, 1}, {0.99f, 0.91f, 0.81f, 1}, {27.8f}};

void setMaterial(Material* p)

{

   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, p->ambiente);

   glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, p->diffuse);

   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, p->specular);

   glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, p->shininess);

}

void displayCall(void)

{

   glClearColor(0.4f,0.4f,0.4f,1);

   glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

   setMaterial(&brass);

   glutSolidCube(1);

   glFlush();

} /* Callback de REDISPLAY */

void reshapeCall(int width, int height)

{

   glViewport(0, 0, (GLsizei)(width), (GLsizei)(height));

   glMatrixMode(GL_PROJECTION);

   glLoadIdentity();

   gluPerspective(45,4./3,0.5,10);

   glMatrixMode(GL_MODELVIEW);

   glLoadIdentity();

   gluLookAt(1.5,1.5,1.2, 0,0,0, 0,0,1);

} /* Callback de RESHAPE */

void keyboardCall(unsigned char c, int x, int y)

{

   switch (c) { case 27: exit(1); }
}/* Callback de KEYBOARD */

void initLight( )

{

   float position[]={ 0.5f,2.f,0.f,1.f};   float low[]={0.2f,0.2f,0.2f,1};   float white[]={1,1,1,1};
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    glLightfv(GL_LIGHT0, GL_AMBIENT, low);

    glLightfv(GL_LIGHT0, GL_DIFFUSE, white);

    glLightfv(GL_LIGHT0, GL_SPECULAR, white);

    glLightfv(GL_LIGHT0, GL_POSITION, position);

    glEnable(GL_LIGHTING);

    glEnable(GL_LIGHT0);

}

int main(int argc, char **argv)

{

    glutInit(&argc, argv); /* Inicializando a GLUT */

    glutInitDisplayMode(GLUT_RGB|GLUT_DEPTH);

    glutInitWindowSize(640, 480);

    glutCreateWindow("CG11:Simple cube");

    glutDisplayFunc(displayCall);

    glutReshapeFunc(reshapeCall);

    glutKeyboardFunc(keyboardCall);

    glEnable(GL_DEPTH_TEST);

    glEnable(GL_NORMALIZE);

    initLight(); /* Inicializando a luz e o material */

        glutMainLoop(); /* GLUT main loop */

   return 0;
}
