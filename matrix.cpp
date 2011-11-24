#include <assert.h>
#include <stdarg.h>

#include "matrix.h"
using namespace std;

	template <>
void Matrix<float>::set(int pr, int pc, ...)
{
	if (this->r!=pr || this->c!=pc) {
		delete[] this->mat;
		this->r=pr; this->c=pc;	
		this->mat = new float[r*c];
	}	

	va_list args;
	va_start(args, pc);

	for (int i=0; i<pr; i++) {
		for (int j=0; j<pc; j++)
			this->mat[i*pc+j]= (float) va_arg(args, double);
	}

	va_end(args);
}


	template <>
void Matrix<short>::set(int pr, int pc, ...)
{
	if (this->r!=pr || this->c!=pc) {
		delete[] this->mat;
		this->r=pr; this->c=pc;	
		this->mat = new short[pr*pc];
	}

	va_list args;
	va_start(args, pc);

	for (int i=0; i<pr; i++) {
		for (int j=0; j<pc; j++)
			this->mat[i*pc+j]= (short) va_arg(args, int);
	}

	va_end(args);
}
