/*
 * Color.h
 *
 *  Created on: Sep 19, 2012
 *      Author: zrbecker
 */

#ifndef COLOR_H_
#define COLOR_H_

#include "common.hpp"

namespace z3d {

class Color {
public:
	Color();
	Color(uint8 r, uint8 g, uint8 b, uint8 a);
	virtual ~Color();

	uint8 r, g, b, a;
};

}
#endif

