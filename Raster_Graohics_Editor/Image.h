#pragma once
#include "MyString.h"

class Image
{
public:
	Image(const char* filepath, unsigned magicNumber, unsigned width, unsigned height);
	virtual ~Image();
	virtual Image* clone() const =0;
	const MyString& getName() const;

protected:
	MyString Filepath;
	unsigned magicNumber = 0;
	unsigned width = 0;
    unsigned height = 0;
};

