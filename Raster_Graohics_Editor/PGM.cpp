#pragma once
#include "PGM.h"

PGM::PGM(const char* filepath, int magicNumber, int width, int height, uint16_t maxValue, uint16_t** data):Image(filepath, magicNumber, width, height)
{
	if (!data)
		throw std::runtime_error("Could not find data.");

	_maxValue = maxValue;
	_data = data;
	data = nullptr;
}
PGM::PGM(const PGM& other) :Image(other)
{
	copyFrom(other);
}
PGM::PGM(PGM&& other) noexcept : Image(std::move(other))
{
	moveFrom(std::move(other));
}

PGM& PGM:: operator=(const PGM& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

PGM& PGM:: operator=(PGM&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}
PGM::~PGM() noexcept
{
	free();
}

Image* PGM::clone() const
{
	return new PGM(*this);
}

void PGM::copyFrom(const PGM& other)
{
	_data = new uint16_t * [height] {nullptr};

	for (int i = 0;i < height;i++)
	{
		if (other._data[i] == nullptr)
			_data[i] = nullptr;
		else 
		{
			_data[i] = new uint16_t[width];

			for (int j = 0;j < width;j++)
			{
				_data[i][j] = other._data[i][j];
			}
		}
	}
}
void PGM::moveFrom(PGM&& other)
{
	_maxValue = other._maxValue;
	other._maxValue = 0;

	_data = other._data;
	other._data = nullptr;
}
void PGM::free()
{
	for (int i = 0; i < height; i++)
		delete _data[i];
	delete[] _data;
}