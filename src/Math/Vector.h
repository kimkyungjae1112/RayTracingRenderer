#pragma once
#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <iostream>
#include <math.h>

class Vector
{
public:
	/* 아무 값도 넣어주지 않았다면 점으로 인식 */
	Vector() : x(0), y(0), z(0), w(1) {}
	/* 기본 Vector 인스턴스를 점이 아닌 벡터로 인식 */
	Vector(const double& x, const double& y, const double& z, const double& w = 0) : x(x), y(y), z(z), w(w) {}

    static Vector OuterProduct(const Vector& lhs, const Vector& rhs);
    static double Dist(const Vector& lhs, const Vector& rhs);

	Vector OuterProduct(const Vector& InVector) const;
	double DotProduct(const Vector& InVector) const;
	double Size() const;
	Vector Normalization() const;

	Vector operator+(const Vector& InVector) const;
	Vector operator-(const Vector& InVector) const;
	Vector operator*(const Vector& InVector) const;
	Vector operator*(const double& rhs) const;
	Vector operator/(const double& rhs) const;

	Vector& operator+=(const Vector& InVector);
	Vector& operator-=(const Vector& InVector);
	Vector& operator*=(const double& rhs);
	Vector& operator/=(const double& rhs);

	Vector& operator-();

	friend Vector operator*(const double& rhs, const Vector& InVector);
	friend Vector operator/(const double& rhs, const Vector& InVector);
	
	friend std::ostream& operator<<(std::ostream& os, const Vector& InVector);

	double x, y, z, w;
};

#endif //__VECTOR_H__