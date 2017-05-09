#ifndef VEC_H
#define VEC_H

class Vec
{
private:
	double x_m;
	double y_m;
	double z_m;

public:
	Vec();
	Vec(double x, double y, double z);

	friend Vec operator+(const Vec &v1, const Vec &v2);
	friend Vec operator-(const Vec &v1, const Vec &v2);
	friend double operator*(const Vec &v1, const Vec &v2);
	Vec & operator = (const Vec &v2);

	Vec cross(const Vec &v2);
	double norm();
	void SetVec(double x, double y, double z);

	double getX() const {return x_m;}
	double getY() const {return y_m;}
	double getZ() const {return z_m;}

	void PrintVec(int x = 3) const;

};

#endif
