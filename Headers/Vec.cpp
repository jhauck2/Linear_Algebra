#include "Vec.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Vector Constructor
Vec::Vec()
{
	SetVec(0,0,0);
}

Vec::Vec(double x, double y, double z)
{
	SetVec(x, y, z);
}

// Vector member functions
void Vec::SetVec(double x, double y, double z)
{
	x_m = x;
	y_m = y;
	z_m = z;
}

// Prints a vector with a certain precision 'x'
void Vec::PrintVec(int x) const
{
	cout << '[' << setprecision(x) << x_m << ']' << '\n';
	cout << '[' << setprecision(x) << y_m << ']' << '\n';
	cout << '[' << setprecision(x) << z_m << ']' << '\n';
}

Vec operator+(const Vec &v1, const Vec &v2)
{
	Vec temp(v1.x_m+v2.x_m, v1.y_m+v2.y_m, v1.z_m+v2.z_m);

	return temp;
}

Vec operator-(const Vec &v1, const Vec &v2)
{
	Vec temp(v1.x_m-v2.x_m, v1.y_m-v2.y_m, v1.z_m-v2.z_m);

	return temp;
}

// Takes the dot productor of a vector and another vector v2
double operator*(const Vec &v1, const Vec &v2)
{
	return v1.x_m*v2.x_m + v1.y_m*v2.y_m + v1.z_m*v2.z_m;
}

 Vec& Vec::operator = (const Vec &v2)
{
	x_m = v2.x_m;
	y_m = v2.y_m;
	z_m = v2.z_m;

	return *this;
}

// Takes the cross product of a vector and another vector v2
Vec Vec::cross(const Vec &v2)
{
	double xtemp = y_m*v2.z_m - v2.y_m*z_m;
	double ytemp = z_m*v2.x_m - v2.z_m*x_m;
	double ztemp = x_m*v2.y_m - v2.x_m*y_m;

	Vec temp(xtemp, ytemp, ztemp);

	return temp;
}

// Takes the magnitude of a vector
double Vec::norm()
{
	Vec temp = *this;
	return temp*temp;
}
