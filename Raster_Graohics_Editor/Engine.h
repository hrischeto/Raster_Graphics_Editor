#pragma once
#include "CommandQueue.h"
#include "vector.hpp"
#include "Session.h"

class CommandFactory;

class Engine
{
public:
	void addCommand(Command* newCommand);
	void getMessege() const;

private:

	CommandQueue commands;
	Vector<Session> openedSessions;
};