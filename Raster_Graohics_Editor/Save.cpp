#include "Save.h"

Save::Save(unsigned session, CommandQueue* queue): _queue(queue)
{
	currentSession = session;
}

void Save::execute(Vector<Session>& openedSessions)
{
	int size = _queue->getSize();
	Command* comPtr = nullptr;

	for (int i = 0;i < size;i++)
	{
		comPtr = _queue->getCommand(i);
		if (comPtr)
		{
			if (currentSession == comPtr->getSession())
			{
				comPtr->execute(openedSessions);
				_queue->pop(i);
			}
		}
	
	}
	
	int imageCount = openedSessions[currentSession - 1].getNumberOfImages();
	for (int i = 0;i < imageCount;i++)
	{
		openedSessions[currentSession - 1][i]->serialize();
	}
}

