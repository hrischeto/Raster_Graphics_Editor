#include "ImageCollection.h"


ImageCollection::ImageCollection()
{
	capacity = 8;
	data = new Image * [capacity] {nullptr};
	size = 0;
}
ImageCollection::ImageCollection(const ImageCollection& other)
{
	copyFrom(other);
}
ImageCollection::ImageCollection(ImageCollection&& other) noexcept
{
	moveFrom(std::move(other));
}

ImageCollection& ImageCollection::operator=(const ImageCollection& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
ImageCollection& ImageCollection::operator=(ImageCollection&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

ImageCollection::~ImageCollection() noexcept
{
	free();
}

void ImageCollection::addImage(Image* image)
{
	if (size == capacity)
		resize();
	data[size++] = image; 
	image = nullptr;
}

//void ImageCollection::addImage(const Image& image)
//{
//	Image* cloned = image.clone();
//	addImage(cloned);
//}

unsigned ImageCollection::getSize() const  
{
	return size;
}

const Image* ImageCollection::operator[](unsigned index) const
{
	return data[index];
}

Image* ImageCollection::operator[](unsigned index)
{
	return data[index];
}

void ImageCollection::copyFrom(const ImageCollection& other)
{
	for (int i = 0; i < other.size; i++)
		data[i] = other.data[i]->clone();

	size = other.size;
	capacity = other.capacity;
}

void ImageCollection::moveFrom(ImageCollection&& other)
{
	data = other.data;
	other.data = nullptr;

	size = other.size;
	capacity = other.capacity;

	other.size = other.capacity = 0;
}

void ImageCollection::free()
{
	for (int i = 0; i < size; i++)
		delete data[i];
	delete[] data;
}

void ImageCollection::resize()
{
	unsigned newCap = capacity * 2;
	Image** newData = new Image * [newCap];
	for (int i = 0; i < size; i++)
		newData[i] = data[i];
	delete[] data;
	data = newData;
	capacity = newCap;
}