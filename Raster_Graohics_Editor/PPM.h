#pragma once
#include "Image.h"
#include "Pixel.h"
#include <iostream>


class PPM : public Image
{
public:

	PPM(const char* filepath,  uint16_t magicNumber, int width, int height, uint16_t maxValue, Pixel** data);
	PPM(const PPM& other);
	PPM(PPM&& other) noexcept;

	PPM& operator=(const PPM& other);
	PPM& operator=(PPM&& other) noexcept;

	~PPM() noexcept;

	Image* clone() const override;

	bool isGray() const override;

	void grayscale() override;
private:

	void copyFrom(const PPM& other);
	void moveFrom(PPM&& other);
	void free();

	unsigned _maxValue = 0;
	Pixel** _data=nullptr;
	};

