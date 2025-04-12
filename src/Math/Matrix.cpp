#include "Matrix.h"

Matrix Matrix::Identity()
{
    return Matrix(1.0);
}

Matrix::Matrix(double Diagonal)
{
    Mat4[0] = { Diagonal,0,0,0 };
    Mat4[1] = { 0,Diagonal,0,0 };
    Mat4[2] = { 0,0,Diagonal,0 };
    Mat4[3] = { 0,0,0,Diagonal };
}

void Matrix::ViewingTransformationMat(std::vector<Vector> UVWE)
{
    Mat4[0] = UVWE[0].Normalization();
    Mat4[1] = UVWE[1].Normalization();
    Mat4[2] = UVWE[2].Normalization();
    Mat4[3] = UVWE[3];
}

Vector Matrix::operator*(const Vector& rhs)
{
    return Vector(
        rhs.x * Mat4[0].x + rhs.y * Mat4[1].x + rhs.z * Mat4[2].x + rhs.w * Mat4[3].x,
        rhs.x * Mat4[0].y + rhs.y * Mat4[1].y + rhs.z * Mat4[2].y + rhs.w * Mat4[3].y,
        rhs.x * Mat4[0].z + rhs.y * Mat4[1].z + rhs.z * Mat4[2].z + rhs.w * Mat4[3].z,
        rhs.x * Mat4[0].w + rhs.y * Mat4[1].w + rhs.z * Mat4[2].w + rhs.w * Mat4[3].w
    );
}

std::ostream& operator<<(std::ostream& os, const Matrix& Mat)
{
    os << "[Mat 의 원소]" << std::endl;
    os << "[" << Mat.Mat4[0].x << " " << Mat.Mat4[1].x << " " << Mat.Mat4[2].x << " " << Mat.Mat4[3].x << "]" << std::endl;
    os << "[" << Mat.Mat4[0].y << " " << Mat.Mat4[1].y << " " << Mat.Mat4[2].y << " " << Mat.Mat4[3].y << "]" << std::endl;
    os << "[" << Mat.Mat4[0].z << " " << Mat.Mat4[1].z << " " << Mat.Mat4[2].z << " " << Mat.Mat4[3].z << "]" << std::endl;
    os << "[" << Mat.Mat4[0].w << " " << Mat.Mat4[1].w << " " << Mat.Mat4[2].w << " " << Mat.Mat4[3].w << "]" << std::endl;
    return os;
}
