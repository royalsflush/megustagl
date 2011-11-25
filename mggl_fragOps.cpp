#include <math.h>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <stdio.h>
using namespace std;

#ifdef __APPLE__
	#include <OpenGL/OpenGL.h>
	#include <GLUT/glut.h>
#else
	#include <glut.h>
#endif

#include "vector.h"
#include "mggl_fragOps.h"
#include "mggl_vertexOps.h"

static int width;
static int height;

Vector clearColor;
Vector* colorBuffer;
float* depthBuffer;

//Draws buffer on the screen
void mggl_drawBuffers() {
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POINTS);

	for (int i=0; i<width; i++)
		for (int j=0; j<height; j++) {
			Vector c = colorBuffer[i*height+j];
			glColor3f(c.x, c.y, c.z);
			glVertex2i(i,j);
		}

	glEnd();
}

//Clears both depth and color buffer
void mggl_clearBuffers() {
	for (int i=0; i<width; i++)
		for (int j=0; j<height; j++)
			colorBuffer[i*height+j]=clearColor;

	for (int i=0; i<width; i++)
		for (int j=0; j<height; j++)
			depthBuffer[i*height+j]=INFINITY;	
}

//Init buffers
void mggl_initBuffers(int wid, int hei) {
	width=wid;
	height=hei;

	colorBuffer = new Vector[wid*hei];
	depthBuffer = new float[wid*hei];

	mggl_clearBuffers();
}


//Set color to pixel x,y
void setColor(int x, int y, Vector& color) {
	colorBuffer[x*height+y]=color;
}

//Get depth of pixel x,y
float getDepth(int x, int y) {
	return depthBuffer[x*height+y];
}

//Set depth of pixel x,y
void setDepth(int x, int y, float z) {
	depthBuffer[x*width+y]=z;
}

//build triangle

double intersectWithY(double y, const Vector& v1, const Vector& v2) {
	assert(fabs(v2.y-v1.y)>1e-9);

	double t = (y-v1.y)/(v2.y-v1.y);

	if (t<0.0 || t>1.0) return INFINITY;
	return v1.x+t*(v2.x-v1.x);
}

Vector calcCoefs(double x, double y, const Vector& v1, const Vector& v2,
			const Vector& v3) {
	Vector coefs;
	double a[3][4];
	int n=3;

	a[0][0]=v1.y; a[0][1]=v2.y; a[0][2]=v3.y; a[0][3]=y;
	a[1][0]=v1.x; a[1][1]=v2.x; a[1][2]=v3.x; a[1][3]=x;
	a[2][0]=1.0; a[2][1]=1.0; a[2][2]=1.0; a[2][3]=1.0;

	for (int k=0; k<n; k++) {
		int pivot; double maxVal=-1.0;

		for (int i=k; i<n; i++)
			if (maxVal<fabs(a[i][k]))
				maxVal=fabs(a[i][k]), pivot=i;

		for (int i=0; i<(n+1); i++)
			swap(a[pivot][i], a[k][i]);

		for (int i=k+1; i<n; i++) {
			double coef = -a[i][k]/a[k][k];

			for (int j=0; j<(n+1); j++)
				a[i][j]+=coef*a[k][j];
		}
	}

	 for(int i = n-1; i >= 0; i--) {
    		for(int j = i-1; j >= 0; j--) {
      			double coef = -a[j][i]/a[i][i];
      			
			for(int k = j; k<(n+1); k++)
        			a[j][k]+=coef*a[i][k];
    		}
    		
		a[i][3] /= a[i][i];
		a[i][i] = 1;
  	}	

	coefs.x = a[0][3];
	coefs.y = a[1][3];
	coefs.z = a[2][3];

	return coefs;	
}

Vector interpolate(const Vector& coefs, const Vector& c1, const Vector& c2,
			const Vector& c3) {
	Vector col;
	col.x = (c1.x)*coefs.x+ (c2.x)*coefs.y + (c3.x)*coefs.z;
	col.y = (c1.y)*coefs.x+ (c2.y)*coefs.y + (c3.y)*coefs.z;
	col.z = (c1.z)*coefs.x+ (c2.z)*coefs.y + (c3.z)*coefs.z;
	
	return col;
}

void rasterTriangle(Vector& p1, Vector& p2,
		Vector& p3, const Vector& c1,
		const Vector& c2, const Vector& c3) {

	Vector v1, v2, v3;
	v1 = mggl_viewportTransform(p1);
	v2 = mggl_viewportTransform(p2);
	v3 = mggl_viewportTransform(p3);
	
	int minY=ceil(min(v1.y, min(v2.y, v3.y)));
	int maxY=floor(max(v1.y, max(v2.y, v3.y)));
	double tmpX; vector<int> validX;

	for (int y=minY; y<=maxY; y++) {
		validX.clear();

		tmpX = intersectWithY(y,v1,v2);
		if (tmpX<INFINITY) validX.push_back(ceil(tmpX+0.5));
		tmpX = intersectWithY(y,v2,v3);
		if (tmpX<INFINITY) validX.push_back(ceil(tmpX+0.5));
		tmpX = intersectWithY(y,v3,v1);
		if (tmpX<INFINITY) validX.push_back(ceil(tmpX+0.5));
		
		sort(validX.begin(), validX.end());
		
		for (int x=validX[0]; x<=validX[validX.size()-1]; x++) {
			Vector coefs = calcCoefs(x,y,v1,v2,v3);

		//	if (getDepth(x,y)<z) {
		//		Vector col = c1;
			//	setDepth(x,y,z);
		//		setColor(x, y, col);	
		//	}
		}
	}

//	for (int i=minY; i<=maxY; i++) {
	//	for (int j=0; j<500; j++)
	//		colorBuffer[j*height+i].print();
	//	printf("\n");
//	}
}
