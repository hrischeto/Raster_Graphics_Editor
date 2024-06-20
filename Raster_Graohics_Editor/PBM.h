#pragma once
#include "Image.h"
#include "Bitset.h"

class PBM : public Image
{
private:
	DynamicSet** data;
};

