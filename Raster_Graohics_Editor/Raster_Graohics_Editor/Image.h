#pragma once
#include "MyString.h"

class Image
{
public:
	Image(const char* filepath);
	virtual ~Image();
	virtual Image* clone() const =0;
private:
	MyString Filepath;
	unsigned magicNumber = 0;
	unsigned width = 0;
	unsigned height = 0;
};

