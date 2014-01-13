/*
 * Image.h
 *
 *  Created on: Sep 19, 2012
 *      Author: zrbecker
 */

#ifndef IMAGE_H_
#define IMAGE_H_

#include "Color.hpp"
#include "common.hpp"

#include <vector>

namespace z3d {

class Image {
public:
	Image();
	Image(uint32 width, uint32 height);
	virtual ~Image();

	uint32 getWidth() const;
	uint32 getHeight() const;
	const uint8 *getPixels() const;

	void setPixel(uint32 x, uint32 y, Color color);

private:
	uint32 width;
	uint32 height;
	std::vector<uint8> pixels;
};

}

#endif /* IMAGE_H_ */
