#include "Math.h"

namespace Math {
    float LenghtSquared(vec3 v)
    {
        return glm::length(v) * glm::length(v);
    }

    // Returns a random real in [0,1).
    inline float randf() {
        return static_cast<float>(rand() / (RAND_MAX + 1.0));
    }

    inline float randf(float min, float max) {
        // Returns a random real in [min,max).
        return min + (max - min) * randf();
    }

    inline int random_int(int min, int max )
    {
        return static_cast<int>(randf((float)min, (float)max));
    }

    inline vec3 clamp(vec3& v, float min , float max)
    {
        return glm::clamp(v, vec3(min), vec3(max));
    }
    inline static vec3 random() {
        return vec3(randf(), randf(), randf());
    }

    inline static vec3 random(double min, double max) {
        return vec3(randf(min, max), randf(min, max), randf(min, max));
    }

    vec3 random_in_unit_sphere() {
        while (true) {
            auto p = random(-1, 1);
            if (LenghtSquared(p) >= 1) continue;
            return p;
        }
    }

    vec3 random_unit_vector() {
        return normalize(random_in_unit_sphere());
    }

    vec3 random_in_hemisphere(const vec3& normal) {
        vec3 in_unit_sphere = random_in_unit_sphere();
        if (dot(in_unit_sphere, normal) > 0.0) // In the same hemisphere as the normal
            return in_unit_sphere;
        else
            return -in_unit_sphere;
    }

    // convert degrees to radians
    inline float toRadians(float degrees) {
        return degrees * PI / 180.0f;
    }
}