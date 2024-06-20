#include "Image.h"
#include <iostream>
#include <fstream>


Image::Image(const char* filepath)
{
	if (!filepath)
		throw std::invalid_argument("Nullptr");



}