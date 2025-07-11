#pragma once
#include "PPM.h"

PPM::PPM(const char* filepath, uint16_t magicNumber, int width, int height, uint16_t maxValue, Pixel** data)
	:Image(filepath, magicNumber, width, height)
{
	_maxValue = maxValue;
	_data = data;
	data = nullptr;
}
PPM::PPM(const PPM& other):Image(other)
{
	copyFrom(other);
}
PPM::PPM(PPM&& other) noexcept:Image(std::move(other))
{
	moveFrom(std::move(other));
}

PPM& PPM::operator=(const PPM& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
PPM& PPM::operator=(PPM&& other)noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;

}

PPM::~PPM() noexcept
{
	free();
}

Image* PPM::clone() const
{
	return new PPM(*this);
}

void PPM::copyFrom(const PPM& other)
{
	_data = new Pixel * [height] {nullptr};//creates an array of pointers

	for (int i = 0;i < height;i++) //go through all pointers
	{
		if (other._data[i] == nullptr)
			_data[i] = nullptr;
		else {
			_data[i] = new Pixel[width];
			for (int j = 0;j < width;j++)
			{
				_data[i][j] = other._data[i][j];
			}
		}
	}
}
void PPM::moveFrom(PPM&& other)
{
	_maxValue = other._maxValue;
	other._maxValue = 0;
	_data = other._data;
	other._data = nullptr;
}
void PPM::free()
{
	for (int i = 0;i < height;i++)
	{
		delete[] _data[i];
	}

	delete[] _data;
	}

bool PPM::isGray() const
{
	for (int i = 0;i < height;i++)
	{
		for (int j = 0;j < width;j++)
		{
			if ((_data[i][j].red != _data[i][j].green)
				|| (_data[i][j].red != _data[i][j].blue)
				|| (_data[i][j].green != _data[i][j].blue))
			{
				grayscaleCheck = 1;
				return false;
			}
				
		}
	}
	grayscaleCheck = 1;
	return true;
}

void PPM::grayscale()
{
	for (int i = 0;i < height;i++)
	{
		for (int j = 0;j < width;j++)
		{
			uint16_t gray = _data[i][j].red * 0. + _data[i][j].green *0.59 +_data[i][j].blue * 0.11;
			_data[i][j].red = gray;
			_data[i][j].green = gray;
			_data[i][j].blue = gray;

		}
	}
}

void PPM::serialize() const
{

}
