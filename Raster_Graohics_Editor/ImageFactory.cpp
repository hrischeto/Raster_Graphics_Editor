#include "ImageFactory.h"
#include "PPM.h"
#include "PGM.h"
#include "PBM.h"
#include <fstream>

static void getWidth(std::ifstream& ifs, int& width)
{
	//logic for ignoring comments
	ifs.ignore();
	ifs >> width;

	if (ifs.fail())
		throw std::runtime_error("Could read image width!");
}

static void getHeight(std::ifstream& ifs, int& height)
{
	//logic for ignoring comments
	ifs >> height;

	if (ifs.fail())
		throw std::runtime_error("Could read image height!");
}

static void getMaxValue(std::ifstream& ifs, uint16_t& maxValue)
{
	//logic for ignoring comments
	ifs >> maxValue;

	if (ifs.fail())
		throw std::runtime_error("Could read image max value!");
}

static void getBasicInfo(std::ifstream& ifs, int& magicNumber, int& width, int& height)
{
	ifs.ignore();
	ifs >> magicNumber;
	
	if (ifs.fail())
		throw std::runtime_error("Could read magic number!");

	getWidth(ifs, width);
	getHeight(ifs, height);
}


static void readP1Matrix(std::ifstream& ifs, int width , int height, DynamicSet** data)
{
	uint8_t bit = 0;
	for (int i = 0;i < height;i++)
	{
		for (int j = 0;j < width;j++)
		{
			ifs >> bit;
			if (bit)
				data[i][j].add(j);
		}

	}
}

static void readP2Matrix(std::ifstream& ifs, int width, int height, uint16_t& maxValue, uint16_t** data)

{
	uint16_t num = 0;

	for (int i = 0;i < height;i++)
	{
		for (int j = 0;j < width;j++)
		{
			ifs >> num;

			if (num > maxValue)
				maxValue = num;

			data[i][j] = num;
		}

	}
}

static void readP3Matrix(std::ifstream& ifs, int width, int height, uint16_t& maxValue, Pixel** data)
{
	uint16_t r = 0, g = 0, b = 0;

	for (int i = 0;i < height;i++)
	{
		for (int j = 0;j < width;j++)
		{
			ifs >> r >> g >> b;

			data[i][j] = Pixel(r, g, b);
		}

	}
}


static Image* readP1(std::ifstream& ifs, int width, int height, const char* filepath, int magicNumber)
{
	if (!filepath)
		throw std::runtime_error("Nullptr recieved");

	DynamicSet** data = new DynamicSet*[height];
	readP1Matrix(ifs, width, height, data);
	return new PBM(filepath, magicNumber, width, height, data);
}

static Image* readP2(std::ifstream& ifs, int width, int height, const char* filepath, int magicNumber)
{
	if (!filepath)
		throw std::runtime_error("Nullptr recieved");

	uint16_t maxValue = 0;
	getMaxValue(ifs, maxValue);

	uint16_t** data = new uint16_t * [height];

	readP2Matrix(ifs, width, height, maxValue, data);
	return new PGM(filepath, magicNumber, width, height, maxValue, data);
}

static Image* readP3(std::ifstream& ifs, int width, int height, const char* filepath, int magicNumber)
{
	if (!filepath)
		throw std::runtime_error("Nullptr recieved");

	uint16_t maxValue = 0;
	getMaxValue(ifs, maxValue);

	Pixel** data3 = new Pixel * [height];

	readP3Matrix(ifs, width, height, maxValue, data3);
	return new PPM(filepath, magicNumber, width, height, maxValue, data3);
	
}

Image* imageFactory(const char* filepath)
{
	if (!filepath)
		throw std::runtime_error("Nullptr recieved");

	//validation of file type

	std::ifstream ifs(filepath);

	if (!ifs.is_open())
		throw std::runtime_error("Could not open file!");

	int magicNumber = 0;
	int width = 0;
	int height = 0;
	getBasicInfo(ifs, magicNumber, width, height);

	switch (magicNumber)
	{
	case 1:
		return readP1(ifs, width, height, filepath, magicNumber);
		break;

	case 2:
		return readP2(ifs, width, height, filepath, magicNumber);
		break;
		
	case 3:
		return readP3(ifs, width, height, filepath, magicNumber);
		break;

	case 4:
		//read p4
		break;

	case 5:
		//read p5
		break;

	case 6:
		//read p6;
		break;

	default:
	   //read p6
		break;
	}
}