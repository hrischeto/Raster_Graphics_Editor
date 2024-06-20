#pragma once
#include "Image.h"
#include <iostream>

class PPM : public Image
{
private:
	unsigned maximumValue = 0;
	uint16_t** data;
	};

