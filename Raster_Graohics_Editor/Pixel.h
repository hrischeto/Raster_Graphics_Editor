#pragma once
#include <iostream>

struct Pixel
{
public:
	Pixel(uint16_t red, uint16_t green, uint16_t blue);
	Pixel();

	uint16_t red = 0;
	uint16_t green = 0;
	uint16_t blue = 0;
};