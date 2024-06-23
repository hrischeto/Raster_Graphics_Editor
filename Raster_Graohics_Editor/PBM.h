#pragma once
#include "Image.h"
#include "Bitset.h"

class PBM : public Image
{

public:
	PBM(const char* filepath, int magicNumber, int width, int height, DynamicSet** data);
	PBM(const PBM& other);
	PBM(PBM&& other) noexcept;
	
	PBM& operator=(const PBM& other);
	PBM& operator= (PBM&& other) noexcept;

	~PBM() noexcept;

	Image* clone() const override;
private:

	void copyFrom(const PBM& other);
	void moveFrom(PBM&& other);
	void free();

	DynamicSet** _data = nullptr;
};

