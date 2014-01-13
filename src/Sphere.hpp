/*
 * Sphere.hpp
 *
 *  Created on: Sep 19, 2012
 *      Author: zrbecker
 */

#ifndef SPHERE_HPP_
#define SPHERE_HPP_

#include "Vector3.hpp"
#include "Shape.hpp"

namespace z3d {

class Sphere : public Shape {
public:
	Sphere();
	Sphere(const Vector3d &center, double radius);
	virtual ~Sphere();

	Intersection intersect(const Ray &ray, double near, double far) const;

	Vector3d center;
	double radius;
};

} /* namespace z3d */
#endif /* SPHERE_HPP_ */
