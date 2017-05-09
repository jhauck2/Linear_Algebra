// Finish Inverse Function
// Fix Header File

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
	SetMat(1,0,0,0,1,0,0,0,1);
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

	mat = 
	{
		{x11, x12, x13},
		{x21, x22, x23},
		{x31, x32, x33}
	};

/*
	Vec tempx(x11, x21, x31);
	Vec tempy(x12, x22, x32);
	Vec tempz(x13, x23, x33);

	x1 = tempx;
	y1 = tempy;
	z1 = tempz;
*/
}
// Sets Matrix values given 3 column vectors;
void Mat::SetMat(Vec &v1, Vec &v2, Vec &v3)
{
	mat = 
	{
		{v1.getX(), v2.getX(), v3.getX()},
		{v1.getY(), v2.getY(), v3.getY()},
		{v1.getZ(), v2.getZ(), v3.getZ()}
	};

/*
	x1 = v1;
	y1 = v2;
	z1 = v3;
*/
}

void Mat::PrintMat() const
{
	cout << "[" << mat.get(1,1) << ", " << mat.get(1,2) << ", " << mat.get(1,3) << "] \n";
	cout << "[" << mat.get(2,1) << ", " << mat.get(2,2) << ", " << mat.get(2,3) << "] \n";
	cout << "[" << mat.get(3,1) << ", " << mat.get(3,2) << ", " << mat.get(3,3) << "] \n";
}
	
// Returns a matrix value at specific indices
double Mat::get(int row, int col) const
{
	return mat[row-1][col-1];
}

// Returns X collumn vector

Mat Mat::transpose(const Mat &m1)
{
	Mat tempmat;
	
	tempmat = 
	{
		{mat[0][0], mat[1][0], mat[2][0]},
		{mat[0][1], mat[1][1], mat[2][1]},
		{mat[0][2], mat[1][2], mat[2][2]},

	return tempmat;
}

double Mat::detMin(const Mat &m1, int row, int col)
{
	int row1 = (row == 1 ? 2 : 1);
	int row2 = (row == 2 ? 3 : 2);
	int col1 = (col == 1 ? 2 : 1);
	int col2 = (col == 2 ? 3 : 2);

	return m1.get(row1, col1)*m1.get(row2,col2) - m1.get(row2,col1)*m1.get(row1,col2);
			
}

double Mat::det(const Mat &m1)
{
	double temp1 = m1.get(1,1)*
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
	
	Vec tempx(

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
