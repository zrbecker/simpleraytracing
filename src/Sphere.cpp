/*
 * Sphere.cpp
 *
 *  Created on: Sep 19, 2012
 *      Author: zrbecker
 */

#include "Sphere.hpp"
#include <cmath>

namespace z3d {

Sphere::Sphere()
: center(), radius(0) {

}

Sphere::Sphere(const Vector3d &center, double radius)
: center(center), radius(radius) {

}

Sphere::~Sphere() {

}

Intersection Sphere::intersect(const Ray &ray, double near, double far) const {
    const Sphere &sphere = *this;

    double a = dot(ray.origin - sphere.center, ray.origin - sphere.center);
    double b = dot(ray.direction, ray.direction);
    double c = dot(ray.direction, ray.origin - sphere.center);

    double d = c * c - b * (a - sphere.radius * sphere.radius);

    // Ray does not have a direction
    if (b == 0.0)
        return Intersection(false);
    // Ray does not intersect sphere
    if (d < 0)
        return Intersection(false);

    double t1 = (-c + sqrt(d)) / b;
    double t2 = (-c - sqrt(d)) / b;

    if ((near <= t1 && t1 <= far) && (t1 < t2 || t2 < near)) {
        Vector3d point = ray.origin + t1 * ray.direction;
        Vector3d normal = point - sphere.center;
        normal = normal / sqrt(dot(normal, normal));
        return Intersection(true, t1, point, normal);
    } else if (near <= t2 && t2 <= far) {
        Vector3d point = ray.origin + t2 * ray.direction;
        Vector3d normal = point - sphere.center;
        normal = normal / sqrt(dot(normal, normal));
        return Intersection(true, t2, point, normal);
    } else {
        return Intersection(false);
    }
}

} /* namespace z3d */
