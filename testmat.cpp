#include <iostream>
#include "Mat.h"

using namespace std;

int main()
{
	Vec vec1(1, 2, 3);
	Vec vec2(4, 5, 6);
	Vec vec3(7, 8, 9);
	Vec vec0;

	Mat eye(1, 0, 0, 0, 1, 0, 0, 0, 1);
	Mat mat0;
	Mat mat1(vec1, vec2, vec3);
	Mat mat2(vec2, vec0, vec3);
	Mat mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
	double det3 = mat3.det();

	Mat matsum = mat1+mat2;
	Mat matsub = mat2-mat3;
	Mat matmult = mat1*mat3;
	double detsum = matsum.det();
	double deteye = eye.det();
	Vec mult;
	mult = mat3*vec1;
	
	cout << "matsum is: \n";
	matsum.PrintMat();
	cout << "matsub is: \n";
	matsub.PrintMat();
	cout << "matmult is: \n";
	matmult.PrintMat();
	cout << "det(eye) is: " << deteye << "\n";
	cout << "mat3*vec1 is: \n";
	mult.PrintVec();


	return 0;
}
