/*
 * Frustum.hpp
 *
 *  Created on: Sep 20, 2012
 *      Author: zrbecker
 */

#ifndef FRUSTUM_HPP_
#define FRUSTUM_HPP_

namespace z3d {

class Frustum {
public:
    Frustum();
    Frustum(double left, double right, double bottom, double top, double near, double far);
    virtual ~Frustum();

    double left, right, bottom, top, near, far;
};

} /* namespace z3d */
#endif /* FRUSTUM_HPP_ */
