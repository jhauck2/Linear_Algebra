//Finish Inverse Function

#include "Vec.h"
#include "Mat.h"
#include <iostream>
#include <iomanip>

using namespace std;

//***********************************************
//************ Matrix Constructors **************
//***********************************************

Mat::Mat()
{
	SetMat(0,0,0,0,0,0,0,0,0);
}

Mat::Mat(double x11, double x12, double x13, double x21, double x22, double x23, double x31, double x32, double x33)
{
	SetMat(x11, x12, x13, x21, x22, x23, x31, x32, x33);
}

Mat::Mat(Vec &v1, Vec &v2, Vec &v3)
{
	SetMat(v1, v2, v3);
}

//***********************************************
//********* End Matrix Constructors *************
//***********************************************

//***********************************************
//********* Matrix Member Functions *************
//***********************************************

// Sets Matrix values given 9 numbers
void Mat::SetMat(double x11, double x12, double x13, double x21, double x22, double x23, double x31, double x32, double x33)
{
	Vec tempx(x11, x21, x31);
	Vec tempy(x12, x22, x32);
	Vec tempz(x13, x23, x33);

	x1 = tempx;
	y1 = tempy;
	z1 = tempz;
}
// Sets Matrix values given 3 column vectors;
void Mat::SetMat(Vec &v1, Vec &v2, Vec &v3)
{
	x1 = v1;
	y1 = v2;
	z1 = v3;
}

void Mat::PrintMat() const
{
	cout << "[" << x1.getX() << ", " << y1.getX() << ", " << z1.getX() << "] \n";
	cout << "[" << x1.getY() << ", " << y1.getY() << ", " << z1.getY() << "] \n";
	cout << "[" << x1.getZ() << ", " << y1.getZ() << ", " << z1.getZ() << "] \n";
}
	
// Returns a matrix value at specific indices
double Mat::get(int row, int col)
{
	Vec temp;

	switch (col)
	{
		case 1:
			temp = x1;
		break;
		
		case 2:
			temp = y1;
		break;

		case 3:
			temp = z1;
		break;

		default:
			cout << "Invalid Index";
			return 0;
	}

	switch (row)
	{
		case 1:
			return temp.getX();
		break;

		case 2:
			return temp.getY();
		break;

		case 3:
			return temp.getZ();
		break;

		default:
			cout << "Invalid Index";
			return 0;
	}
}

Vec Mat::getX1()
{
	return this.x1;
}

Vec Mat::getY1()
{
	return this.y1;
}

Vec Mat::getZ1()
{
	return this.z1;
}

Mat Mat::transpose(const Mat &m1)
{
	Vec tempx;
	Vec tempy;
	Vec tempz;
	Mat tempmat;

	tempx.SetVec(m1.x1.getX(), m1.y1.getX(), m1.z1.getX());
	tempy.SetVec(m1.x1.getY(), m1.y1.getY(), m1.z1.getY());
	tempz.SetVec(m1.x1.getZ(), m1.y1.getZ(), m1.z1.getZ());

	tempmat.SetMat(tempx, tempy, tempz);

	return tempmat;
}

double Mat::det()
{
	double temp1 = x1.getX()*(y1.getY()*z1.getZ() - z1.getY()*y1.getZ());
	double temp2 = x1.getY()*(y1.getX()*z1.getZ() - z1.getX()*y1.getZ());
	double temp3 = x1.getZ()*(y1.getX()*z1.getY() - z1.getX()*y1.getY());

	return temp1 - temp2 + temp3;
}

Mat Mat::inv(const Mat &m1)
{
	double det1 = m1.det();
	Mat temp();
	
	if (det1 < 0)
	{
		det1 = -1*(det1);
	}

	if (det1 < .00001)
	{
		cout << "Determinant value of " << det1 << " is too close to zero";
	}



//***********************************************
//******* End Matrix Member Functions ***********
//***********************************************

//***********************************************
//************* Operator Overloads **************
//***********************************************

Mat operator+(const Mat &m1, const Mat &m2)
{
	Mat temp;
	Vec tempx;
	Vec tempy;
	Vec tempz;

	tempx = m1.x1 + m2.x1;
	tempy = m1.y1 + m2.y1;
	tempz = m1.z1 + m2.z1;

	temp.SetMat(tempx, tempy, tempz);

	return temp;
}

Mat operator-(const Mat &m1, const Mat &m2)
{
	Mat temp;
	Vec tempx;
	Vec tempy;
	Vec tempz;

	tempx = m1.x1 - m2.x1;
	tempy = m1.y1 - m2.y1;
	tempz = m1.z1 - m2.z1;

	temp.SetMat(tempx, tempy, tempz);

	return temp;
}

Mat operator*(const Mat &m1, const Mat &m2)
{
	Mat temp;
	double tempx;
	double tempy;
	double tempz;
	Vec tempvecx;
	Vec tempvecy;
	Vec tempvecz;

	tempx = m1.x1.getX()*m2.x1.getX() + m1.y1.getX()*m2.x1.getY() + m1.z1.getX()*m2.x1.getZ();
	tempy = m1.x1.getY()*m2.x1.getX() + m1.y1.getY()*m2.x1.getY() + m1.z1.getY()*m2.x1.getZ();
	tempz = m1.x1.getZ()*m2.x1.getX() + m1.y1.getZ()*m2.x1.getY() + m1.z1.getZ()*m2.x1.getZ();

	tempvecx.SetVec(tempx, tempy, tempz);

	tempx = m1.x1.getX()*m2.y1.getX() + m1.y1.getX()*m2.y1.getY() + m1.z1.getX()*m2.y1.getZ();
	tempy = m1.x1.getY()*m2.y1.getX() + m1.y1.getY()*m2.y1.getY() + m1.z1.getY()*m2.y1.getZ();
	tempz = m1.x1.getZ()*m2.y1.getX() + m1.y1.getZ()*m2.y1.getY() + m1.z1.getZ()*m2.y1.getZ();

	tempvecy.SetVec(tempx, tempy, tempz);

	tempx = m1.x1.getX()*m2.z1.getX() + m1.y1.getX()*m2.z1.getY() + m1.z1.getX()*m2.z1.getZ();
	tempy = m1.x1.getY()*m2.z1.getX() + m1.y1.getY()*m2.z1.getY() + m1.z1.getY()*m2.z1.getZ();
	tempz = m1.x1.getZ()*m2.z1.getX() + m1.y1.getZ()*m2.z1.getY() + m1.z1.getZ()*m2.z1.getZ();
	
	tempvecz.SetVec(tempx, tempy, tempz);

	temp.SetMat(tempvecx, tempvecy, tempvecz);	

	return temp;
}

Vec operator*(const Mat &m1, const Vec &v1)
{
	double tempx;
	double tempy;
	double tempz;

	tempx = m1.x1.getX()*v1.getX() + m1.y1.getX()*v1.getY() + m1.z1.getX()*v1.getZ();
	tempy = m1.x1.getY()*v1.getX() + m1.y1.getY()*v1.getY() + m1.z1.getY()*v1.getZ();
	tempz = m1.x1.getZ()*v1.getX() + m1.y1.getZ()*v1.getY() + m1.z1.getZ()*v1.getZ();

	Vec temp(tempx, tempy, tempz);

	return temp;
}

Mat& Mat::operator=(const Mat &m2)
{
	x1 = m2.x1;
	y1 = m2.y1;
	z1 = m2.z1;

	return *this;
}



//
