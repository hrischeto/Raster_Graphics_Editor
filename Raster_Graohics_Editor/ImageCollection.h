#pragma once
#include "Image.h"
class ImageCollection
{
public:
	ImageCollection();
	ImageCollection(const ImageCollection& other);
	ImageCollection(ImageCollection&& other) noexcept;
	
	ImageCollection& operator=(const ImageCollection& other);
	ImageCollection& operator=(ImageCollection&& other) noexcept;

	~ImageCollection() noexcept;

	void addImage(Image* image);
	//void addImage(const Image& image);

	unsigned getSize();

	const Image* operator[](unsigned index) const;
	Image* operator[](unsigned index);

	//void removeImage(unsigned index);
private:
	void copyFrom(const ImageCollection& other);
	void moveFrom(ImageCollection&& other);
	void free();
	void resize();

	Image** data = nullptr;
	size_t size = 0;
	size_t capacity = 0;
};

