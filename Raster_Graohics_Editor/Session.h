#pragma once
#include "Image.h"
#include "Command.h"
#include "ImageCollection.h"
class Session
{
public:
	friend class Command;
private:
	unsigned id = 0;
	ImageCollection	loadedImages;
};