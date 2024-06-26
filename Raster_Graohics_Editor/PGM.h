#pragma once
#include "Image.h"
class PGM : public Image
{
public:
	PGM(const char* filepath, int magicNumber, int width, int height, uint16_t maxValue, uint16_t** data);
	PGM(const PGM& other);
	PGM(PGM&& other) noexcept;

	PGM& operator=(const PGM& other);
	PGM& operator= (PGM&& other) noexcept;

	~PGM() noexcept;

	Image* clone() const override;
	void serialize() const override;


private:

	void copyFrom(const PGM& other);
	void moveFrom(PGM&& other);
	void free();

	uint16_t _maxValue = 0;
	uint16_t** _data=nullptr;
};

