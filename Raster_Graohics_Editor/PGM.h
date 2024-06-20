#pragma once
#include "Image.h"
class PGM : public Image
{
private:
	unsigned maxValue = 0;
	uint16_t** data;
};

