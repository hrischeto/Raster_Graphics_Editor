#pragma once
#include "MyString.h"

class Image
{
public:
	Image(const char* filepath, unsigned magicNumber, unsigned width, unsigned height);
	virtual ~Image();
	virtual Image* clone() const =0;
	const MyString& getName() const;

	bool monochromeChecked() const;
	bool grayscaleChecked() const;

	virtual bool isGray() const;
	virtual void grayscale();

	virtual void serialize() const =0;
protected:
	MyString Filepath;

	mutable bool monochromeCheck = 0;
	mutable bool grayscaleCheck = 0;

	unsigned magicNumber = 0;
	unsigned width = 0;
    unsigned height = 0;

};

