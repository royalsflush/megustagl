#ifndef VECTOR_H
#define VECTOR_H

class Vector {
	public:
	//Homogeneous coordinates
	double x,y,z,w;

	Vector(double px=0.0, double py=0.0, double pz=0.0,
		double pw=1.0);
	Vector(const Vector& a);
	Vector(const float* v);

	Vector& operator=(const Vector& a);
	Vector& operator+=(const Vector& a);
	Vector& operator-=(const Vector& a);
	Vector operator+(const Vector& a) const;
	Vector operator-(const Vector& a) const;
	Vector& operator*=(const double a);
	Vector operator*(const double a) const;
	double operator*(const Vector& a) const;
	Vector& operator/=(const double a);

	double length();
	void normalize();
	void print() const;
	Vector cross(const Vector& a);
};

#endif //VECTOR_H
