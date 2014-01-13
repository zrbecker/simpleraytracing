/*
 * Plane.cpp
 *
 *  Created on: Sep 19, 2012
 *      Author: zrbecker
 */

#include "Plane.hpp"

namespace z3d {

Plane::Plane()
: norm(0, 1, 0), offset(0) {

}

Plane::Plane(const Vector3d &norm, double offset)
: norm(norm), offset(offset) {

}

Plane::~Plane() {

}

Intersection Plane::intersect(const Ray &ray, double near, double far) const {
    const Plane &plane = *this;

    double a = dot(ray.origin, plane.norm);
    double b = dot(ray.direction, plane.norm);

    // Invalid plane
    if (plane.norm == Vector3d(0, 0, 0))
        return Intersection(false);
    // Ray is parallel to the plane
    if (b == 0)
        return Intersection(false);

    double t = (plane.offset - a) / b;
    if (near <= t && t <= far)
        return Intersection(true, t, ray.origin + t * ray.direction, plane.norm);
    // Intersection occurs behind the origin
    else
        return Intersection(false);
}

} /* namespace z3d */
