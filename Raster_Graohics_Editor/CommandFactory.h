#pragma once
#include "Command.h"
#include <sstream>

class CommandFactory {
public:
	unsigned currentSession = 0;
	unsigned openedSessions = 0;
	Command* operator()(MyString command, std::stringstream& ss);
};


