#pragma once
#include "Image.h"
#include "Bitset.h"
#include "Pixel.h"

static void getWidth(std::ifstream& ifs, int& width);

static void getHeight(std::ifstream& ifs, int& height);

static void getMaxValue(std::ifstream& ifs, uint16_t& maxValue);

static void getBasicInfo(std::ifstream& ifs, int& magicNumber, int& width, int& height);


static void readP1Matrix(std::ifstream& ifs, int width, int height, DynamicSet** data);

static void readP2Matrix(std::ifstream& ifs, int width, int height, uint16_t& maxValue, uint16_t** data);

static void readP3Matrix(std::ifstream& ifs, int width, int height, uint16_t& maxValue, Pixel** data);


static Image* readP1(std::ifstream& ifs, int width, int height, const char* filepath, int magicNumber);

static Image* readP2(std::ifstream& ifs, int width, int height, const char* filepath, int magicNumber);

static Image* readP3(std::ifstream& ifs, int width, int height, const char* filepath, int magicNumber);

Image* imageFactory(const char* filepath);