#pragma once
#include "Image.h"
#include "Command.h"
#include "ImageCollection.h"

class Session
{
public:
	Session();

	void addImage(const char* filepath);
	
	void setID(unsigned id);
	int getNumberOfImages() const;

	const Image& operator[](int index) const;
private:
	unsigned _id = 0;
	ImageCollection	loadedImages;
};