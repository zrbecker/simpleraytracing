/*
 * Ray.cpp
 *
 *  Created on: Sep 19, 2012
 *      Author: zrbecker
 */

#include "Ray.hpp"
#include "Sphere.hpp"
#include "Plane.hpp"

#include <cmath>

namespace z3d {

Ray::Ray()
: origin(0, 0, 0), direction(0, 0, -1) {

}

Ray::Ray(const Vector3d &origin, const Vector3d &direction)
: origin(origin), direction(direction) {

}

Ray::~Ray() {

}

Intersection Ray::intersect(const Shape &shape, double near, double far) const {
    return shape.intersect(*this, near, far);
}

} /* namespace z3d */
