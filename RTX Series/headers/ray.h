#pragma once
#include "vec3.h"

class ray
{
public:
    ray() = default;

    ray(const point3& orig, const vec3& dir) : orig{ orig }, dir{ dir } {}

    point3 at(float t) const
    {
        return orig + dir * t;
    }

    // Getters
    const vec3& direction() const
    {
        return dir;
    }

    const point3& origin() const
    {
        return orig;
    }

private:
    point3 orig;
    vec3 dir;
};
