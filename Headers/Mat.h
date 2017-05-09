#ifndef MAT_H
#define MAT_H

#include "Vec.h"

class Mat
{
private:

	double mat[3][3];

	//Vec x1;
	//Vec y1;
	//Vec z1;

public:
// Constructors
	Mat();
	Mat(double x11, double x12, double x13, double x21, double x22, double x23, double x31, double x32, double x33);
	Mat(Vec &v1, Vec &v2, Vec &v3);

// Operator Overloads
	friend Mat operator+(const Mat &m1, const Mat &m2);
	friend Mat operator-(const Mat &m1, const Mat &m2);
	friend Mat operator*(const Mat &m1, const Mat &m2);
	friend Vec operator*(const Mat &m1, const Vec &v1);
	Mat & operator=(const Mat &m2);

// Member Functions
	Mat transpose(const Mat &m1);

	double det() const;
	double det2(double a, double b, double c, double d);
	Mat inv(const Mat &m1);

	void SetMat(double x11, double x12, double x13, double x21, double x22, double x23, double x31, double x32, double x34);

	void SetMat(Vec &v1, Vec &v2, Vec &v3);

	void PrintMat() const;

	double get(int row, int col);
};

#endif
