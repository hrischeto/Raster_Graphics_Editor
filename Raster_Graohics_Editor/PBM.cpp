#include "PBM.h"
#include <fstream>

PBM::PBM(const char* filepath, int magicNumber, int width, int height, DynamicSet** data):Image(filepath,magicNumber,width,height)
{
	if (!data)
		throw std::runtime_error("Could not find data.");

	_data = data;
	data = nullptr;

	monochromeCheck = 1;
	grayscaleCheck = 1;
}

PBM::PBM(const PBM& other):Image(other)
{
	copyFrom(other);
}
PBM::PBM(PBM&& other) noexcept:Image(std::move(other))
{
	moveFrom(std::move(other));
}

PBM& PBM::operator=(const PBM& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
PBM& PBM::operator= (PBM&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

PBM::~PBM() noexcept
{
	free();
}

Image* PBM::clone() const
{
	return new PBM(*this);
}

void PBM::copyFrom(const PBM& other)
{
	_data = new DynamicSet * [height] {nullptr};//creates an array of pointers

	for (int i = 0;i < height;i++) //go through all pointers
	{
		if (other._data[i] == nullptr)
			_data[i] = nullptr;
		else
		_data[i] = new DynamicSet(*other._data[i]);
	}
}
void PBM::moveFrom(PBM&& other)
{
	_data = other._data;
	other._data = nullptr;
}
void PBM::free()
{
	for (int i = 0; i < height; i++)
		delete _data[i];
	delete[] _data;
}

void PBM::serialize() const
{
	std::ofstream ofs(Filepath.c_str());

	ofs << 'P';
	ofs << magicNumber << "\n";
	ofs << width << " " << height;
	for (int i = 0;i < height;i++)
	{
		for (int j = 0;j < width;j++)
		{
			ofs << _data[i][j]<<"\n";
		}
	}

}