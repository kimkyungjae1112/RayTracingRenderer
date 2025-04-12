#include "Vector.h"

Vector Vector::OuterProduct(const Vector& lhs, const Vector& rhs)
{
    return Vector(lhs.y * rhs.z - lhs.z * rhs.y, 
                lhs.z * rhs.x - lhs.x * rhs.z,
                lhs.x * rhs.y - lhs.y * rhs.x);
}

double Vector::Dist(const Vector& lhs, const Vector& rhs)
{
    return fabs(sqrt(pow((lhs.x - rhs.x), 2) + pow((lhs.y - rhs.y), 2) + pow((lhs.z - rhs.z), 2)));
}

Vector Vector::OuterProduct(const Vector& InVector) const
{
    return Vector(y * InVector.z - z * InVector.y, 
                z * InVector.x - x * InVector.z,
                x * InVector.y - y * InVector.x);
}

double Vector::DotProduct(const Vector& InVector) const
{
    return x * InVector.x + y * InVector.y + z * InVector.z;
}

double Vector::Size() const
{
   return sqrt(x * x + y * y + z * z);
}

Vector Vector::Normalization() const
{
    double size = Size();
    if(size == 0) return *this;
    return Vector(x / size, y / size, z / size, w);
}

Vector Vector::operator+(const Vector& InVector) const
{
    return Vector(x + InVector.x, y + InVector.y, z + InVector.z);
}

Vector Vector::operator-(const Vector& InVector) const
{
    return Vector(x - InVector.x, y - InVector.y, z - InVector.z);
}

Vector Vector::operator*(const Vector& InVector) const
{
    return Vector(y * InVector.z - z * InVector.y,
        z * InVector.x - x * InVector.z,
        x * InVector.y - y * InVector.x);
}

Vector Vector::operator*(const double& rhs) const
{
    return Vector(x * rhs, y * rhs, z * rhs);
}

Vector Vector::operator/(const double& rhs) const
{ 
    return Vector(x / rhs, y / rhs, z / rhs);
}

Vector& Vector::operator+=(const Vector& InVector)
{
    x += InVector.x;
    y += InVector.y;
    z += InVector.z;
    return *this;
}

Vector& Vector::operator-=(const Vector& InVector)
{
    x -= InVector.x;
    y -= InVector.y;
    z -= InVector.z;
    return *this;
}

Vector& Vector::operator*=(const double& rhs)
{
    x *= rhs;
    y *= rhs;
    z *= rhs;
    return *this;
}

Vector& Vector::operator/=(const double& rhs)
{
    x /= rhs;
    y /= rhs;
    z /= rhs;
    return *this;
}

Vector& Vector::operator-()
{
    x *= -1;
    y *= -1;
    z *= -1;
    return *this;
}

Vector operator*(const double& rhs, const Vector& InVector)
{
    return Vector(rhs * InVector.x, rhs * InVector.y, rhs * InVector.z);
}

Vector operator/(const double& rhs, const Vector& InVector)
{
    return Vector(rhs / InVector.x, rhs / InVector.y, rhs / InVector.z);
}

std::ostream& operator<<(std::ostream& os, const Vector& InVector)
{
    os << "[벡터의 성분]" << std::endl;
    os << "[x : " << InVector.x << " y : " << InVector.y << " z : " << InVector.z << " w : " << InVector.w << "]" << std::endl;
    return os;
}
