/*
 * Shape.hpp
 *
 *  Created on: Sep 21, 2012
 *      Author: zrbecker
 */

#ifndef SHAPE_HPP_
#define SHAPE_HPP_

#include "Ray.hpp"

namespace z3d {

struct Intersection {
    Intersection() : intersect(false), t(), intersection(), normal() {}
    Intersection(bool intersect) : intersect(intersect), t(), intersection(), normal() {}
    Intersection(bool intersect, double t, Vector3d intersection, Vector3d normal)
    : intersect(intersect), t(t), intersection(intersection), normal(normal) {}

    bool intersect;
    double t;
    Vector3d intersection;
    Vector3d normal;
};

class Shape {
public:
    virtual ~Shape();
    virtual Intersection intersect(const Ray &ray, double near, double far) const = 0;
};

}


#endif /* SHAPE_HPP_ */
