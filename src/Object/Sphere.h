#include "../Math/Vector.h"
#include "../Render/Ray.h"

class Sphere
{
public:
    Sphere() = default;
    Sphere(const Vector& center, double radius) noexcept
        : Center(center), Radius(radius) {}

    bool Intersect(const Ray& ray, double& t) const;

    Vector Center;
    double Radius;
};