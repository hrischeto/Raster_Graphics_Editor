#include "Close.h"

Close::Close(unsigned session) 
{
	currentSession = session;
}

void Close::execute(Vector<Session>& openedSessions)
{
	openedSessions.erase(currentSession-1);
}