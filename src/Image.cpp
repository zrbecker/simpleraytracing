/*
 * Image.cpp
 *
 *  Created on: Sep 19, 2012
 *      Author: zrbecker
 */

#include "Image.hpp"

using namespace std;

namespace z3d {

Image::Image()
: width(0), height(0), pixels() {

}

Image::Image(uint32 width, uint32 height)
: width(width), height(height), pixels() {
	pixels.resize(width * height * 4);
	for (uint32 i = 0; i < pixels.size(); ++i)
	    pixels[i] = 0;
}

Image::~Image() {

}

uint32 Image::getWidth() const {
	return width;
}

uint32 Image::getHeight() const {
	return height;
}

const uint8 *Image::getPixels() const {
	return &pixels[0];
}

void Image::setPixel(uint32 x, uint32 y, Color color) {
    if (x >= width || y >= height)
        return;
    y = height - y - 1;
	pixels[4 * (y * width + x) + 0] = color.r;
	pixels[4 * (y * width + x) + 1] = color.g;
	pixels[4 * (y * width + x) + 2] = color.b;
	pixels[4 * (y * width + x) + 3] = color.a;
}

}

