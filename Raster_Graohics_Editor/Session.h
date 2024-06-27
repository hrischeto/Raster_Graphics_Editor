#pragma once
#include "Image.h"
#include "ImageCollection.h"

class Session
{
public:
	void addImage(const char* filepath);
	
	void setID(unsigned id);
	int getNumberOfImages() const;

	
	Image* operator[](int index);
	const Image* operator[](int index) const;

private:
	unsigned _id = 0;
	ImageCollection	loadedImages;
};