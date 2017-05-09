#include <iostream>
#include <iomanip>
#include "Vec.h"

using namespace std;

int main()
{
	Vec test0;
	test0.PrintVec();
	cout << '\n';
	
	Vec test1(1.3, 2.4, 3.5);
	test1.PrintVec();
	cout << '\n';

	cout << "the x value for test1 is: " << test1.getX() << "\n" << '\n';

	Vec test3(4.6, 5.7, 6.8);

	Vec testsum = test1 + test3;
	Vec testsub = test3 - test1;
	double testdot = test3*test1;
	Vec testcross = test3.cross(test1);
	double testnorm = test1.norm();

	cout << "test 1 + test 3 = ";
	testsum.PrintVec();
	cout << '\n';

	cout << "test 1 - test 3 = ";
	testsub.PrintVec();
	cout << '\n';


	cout << "test 1 dot test 3 = " << testdot << '\n';

	cout << "test 1 cross test 3 = ";
	testcross.PrintVec();
	cout << '\n';

	cout << "the norm of test 1 = " << testnorm << '\n';

	return 0;
}
