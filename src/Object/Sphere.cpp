#include "Sphere.h"

bool Sphere::Intersect(const Ray& ray, double& t) const
{
    Vector oc = ray.Origin - Center;

    double a = ray.Direction.DotProduct(ray.Direction);
    double b = 2.0 * oc.DotProduct(ray.Direction);
    double c = oc.DotProduct(oc) - Radius * Radius;
    double discriminant = b * b - 4 * a * c;
    //std::cout << "a: " << a << ", b: " << b << ", c: " << c << ", discriminant: " << discriminant << std::endl;
    if (discriminant < 0) return false;

    t = (-b - sqrt(discriminant)) / (2.0 * a);
    if (t < 0) {
        t = (-b + sqrt(discriminant)) / (2.0 * a);
        if (t < 0) return false;
    }
    return true;
}