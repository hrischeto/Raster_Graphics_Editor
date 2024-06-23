#include "Session.h"
#include "ImageFactory.h"
void Session::addImage(const char* filepath)
{
	loadedImages.addImage(ImageFactory(filepath));
}

void Session::setID(unsigned id)
{
	_id = id;
}

int Session::getNumberOfImages() const
{
	return loadedImages.getSize();
}


Image* Session::operator[](int index)
{
	return loadedImages[index];
}
const Image* Session::operator[](int index) const
{
	return loadedImages[index];
}