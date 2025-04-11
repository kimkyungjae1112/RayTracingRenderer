#pragma once
#ifndef __MATRIX_H__
#define __MATRIX_H__

#include "Vector.h"
#include <vector>
const int MatrixLength = 4;

class Matrix
{
public:
	static Matrix Identity();
	
	Matrix() {}
	Matrix(double Diagonal);

	void ViewingTransformationMat(std::vector<Vector> UVWE);
	
	/* 선형 변환 */
	Vector operator*(const Vector& rhs);

	friend std::ostream& operator<<(std::ostream& os, const Matrix& Mat);
private:

	Vector Mat4[MatrixLength];
};


#endif //__MATRIX_H__