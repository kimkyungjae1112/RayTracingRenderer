#ifndef __RAY_H__
#define __RAY_H__

#include "../Math/Vector.h"

class Ray
{
public:
    Ray() noexcept : Origin(Vector()), Direction(Vector(0,0,0)) {}
    Ray(const Vector& Origin, const Vector& Diretion) noexcept
        : Origin(Origin), Direction(Direction) {}

    Ray(const Ray& ray) = default;
    Ray& operator=(const Ray& ray) = default;

    Ray(Ray&& ray) = default;
    Ray& operator=(Ray&& ray) = default;

    Vector At(double t) const;

    Vector Origin;
    Vector Direction;

};

#endif // __RAY_H__