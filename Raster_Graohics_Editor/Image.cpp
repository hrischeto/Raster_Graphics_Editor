#pragma once
#include "Image.h"

Image::Image(const char* filepath, unsigned magicNumber, unsigned width, unsigned height):Filepath(filepath),
													magicNumber(magicNumber), width(width), height(height){}
Image:: ~Image() = default;

const MyString& Image::getName() const
{
	return Filepath;
}

bool Image:: isGray() const
{
	grayscaleCheck = 1;
	return true;
}

bool Image::monochromeChecked() const
{
	return monochromeCheck;
}
bool Image::grayscaleChecked() const
{
	return grayscaleCheck;
}

void Image::grayscale()
{

}