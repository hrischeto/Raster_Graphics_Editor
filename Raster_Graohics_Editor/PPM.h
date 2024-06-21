#pragma once
#include "Image.h"
#include "Pixel.h"
#include <iostream>


class PPM : public Image
{
public:
	PPM(const char* filepath,  uint16_t magicNumber, int width, int height, uint16_t maxValue, Pixel** data);
	PPM(const PPM& other);
	PPM(PPM&& other);

	PPM& operator=(const PPM& other);
	PPM& operator=(PPM&& other);

	~PPM();

	Image* clone() const override;


private:

	void copyFrom(const PPM& other);
	void moveFrom(PPM&& other);
	void free();

	unsigned maximumValue = 0;
	Pixel** data;
	};

