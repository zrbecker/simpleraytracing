/*
 * Ray.h
 *
 *  Created on: Sep 19, 2012
 *      Author: zrbecker
 */

#ifndef RAY_H_
#define RAY_H_

#include "Vector3.hpp"

namespace z3d {

class Intersection;
class Shape;

class Ray {
public:
	Ray();
	Ray(const Vector3d &origin, const Vector3d &direction);
	virtual ~Ray();

	Intersection intersect(const Shape &shape, double near, double far) const;

	Vector3d origin;
	Vector3d direction;
};

} /* namespace z3d */
#endif /* RAY_H_ */
