/*
 * Frustum.cpp
 *
 *  Created on: Sep 20, 2012
 *      Author: zrbecker
 */

#include "Frustum.hpp"

namespace z3d {

Frustum::Frustum()
: left(-1), right(1), bottom(-1), top(1), near(1), far(10) {

}

Frustum::Frustum(double left, double right, double bottom, double top, double near, double far)
: left(left), right(right), bottom(bottom), top(top), near(near), far(far) {

}

Frustum::~Frustum() {
    // TODO Auto-generated destructor stub
}

} /* namespace z3d */
