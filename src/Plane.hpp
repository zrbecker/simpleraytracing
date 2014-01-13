/*
 * Plane.hpp
 *
 *  Created on: Sep 19, 2012
 *      Author: zrbecker
 */

#ifndef PLANE_HPP_
#define PLANE_HPP_

#include "Vector3.hpp"
#include "Shape.hpp"

namespace z3d {

class Plane : public Shape {
public:
	Plane();
	Plane(const Vector3d &norm, double offset);
	virtual ~Plane();

	Intersection intersect(const Ray &ray, double near, double far) const;

	Vector3d norm;
	double offset;
};

} /* namespace z3d */
#endif /* PLANE_HPP_ */
