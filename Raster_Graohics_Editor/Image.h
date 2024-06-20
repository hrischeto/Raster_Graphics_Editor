#pragma once
#include "vector.hpp"
#include "MyString.h"
class Image
{
public:
	Image(const char* filePath);
	virtual ~Image();
	virtual Image* clone();
private:
	MyString Filepath;
	unsigned magicNumber = 0;
	unsigned height = 0;
	unsigned width = 0;
};

