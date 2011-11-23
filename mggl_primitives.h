#ifndef MGGL_PRIMITIVES
#define MGGL_PRIMITIVES

class Vector;

//Triangle that uses plane normal ((v1-v2)X(v3-v2))
void mggl_triangle(const Vector& v1, const Vector& v2, const Vector& v3);

//Triangle with given normals
void mggl_triangle(const Vector& v1, const Vector& v2, const Vector& v3,
		const Vector& n1, const Vector& n2, const Vector& n3);

//Solid cube
void mggl_solidCube(float length);

#endif //MGGL_PRIMITIVES
