#pragma once
#include "Vector3.h"

namespace Math {

    const float infinity = std::numeric_limits<float>::infinity();

    const float PI = 3.1415926535897932385f;

    float LenghtSquared(vec3 v);

    // Returns a random real in [0,1).
    inline float randf();

    inline float randf(float min, float max);

    inline int random_int(int min = 0, int max = 1);

    inline vec3 clamp(vec3& v, float min = 0.f, float max = 1.f);
    inline static vec3 random();

    inline static vec3 random(double min, double max);

    vec3 random_in_unit_sphere();

    vec3 random_unit_vector();

    vec3 random_in_hemisphere(const vec3& normal);

    // convert degrees to radians
    inline float toRadians(float degrees);
}