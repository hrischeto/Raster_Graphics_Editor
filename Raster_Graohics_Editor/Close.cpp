#include "Close.h"

Close::Close(unsigned session) :_session(session) {}

void Close::execute(Vector<Session>& openedSessions)
{
	openedSessions.erase(_session-1);
}