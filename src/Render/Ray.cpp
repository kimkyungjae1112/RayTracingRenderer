#include "Ray.h"

Vector Ray::At(double t) const
{
    return Origin + Direction * t;
}