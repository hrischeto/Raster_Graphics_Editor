#pragma once
#include "CommandQueue.h"
#include "vector.hpp"
#include "Session.h"

class CommandFactory;

class Engine
{
public:
	void addCommand(Command* newCommand);
	//void getMessege();
	CommandQueue* getQueue();
	Vector<Session>& getSessions();
private:

	Vector<Session> openedSessions;
	CommandQueue queue;
};