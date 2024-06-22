#pragma once
#include "MyString.h"

class Image
{
public:
	Image(const char* filepath, unsigned magicNumber, unsigned width, unsigned height);
	virtual ~Image();
	virtual Image* clone() const =0;
private:
	MyString Filepath;
	const unsigned magicNumber = 0;
	const unsigned width = 0;
	const unsigned height = 0;
};

