#include "Grayscale.h"
#include "Pixel.h"

Grayscale::Grayscale(unsigned session)
{
	currentSession = session;
}

bool Grayscale::grayscalecheck(const Image* image) const //checks if the image has been already checked for grayscale, if not checks 
{
	if(image->grayscaleChecked())
		return true;
	else
	{
		return image->isGray();
	}

}

void Grayscale::execute(Vector<Session>& openedSessions)
{
	unsigned ImageCount = openedSessions[currentSession - 1].getNumberOfImages();
	for (int i = 0;i < ImageCount;i++)
	{
		if (!grayscalecheck(openedSessions[currentSession - 1][i]))// checks if it is already gray
		{
			openedSessions[currentSession - 1][i]->grayscale();
		}
	}
}
