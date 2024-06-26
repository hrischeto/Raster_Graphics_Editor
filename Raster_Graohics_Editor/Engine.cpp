#include "Engine.h"

void Engine::addCommand(Command* newCommand)
{
	queue.push(newCommand);
}

CommandQueue* Engine::getQueue()
{
	return &queue;
}
Vector<Session>& Engine::getSessions()
{
	return openedSessions;
}
