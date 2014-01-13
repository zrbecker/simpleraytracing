/*
 * Color.cpp
 *
 *  Created on: Sep 19, 2012
 *      Author: zrbecker
 */

#include "Color.hpp"
#include "common.hpp"

namespace z3d {

Color::Color()
: r(0), g(0), b(0), a(0) {

}

Color::Color(uint8 r, uint8 g, uint8 b, uint8 a)
: r(r), g(g), b(b), a(a) {

}

Color::~Color() {

}

}
