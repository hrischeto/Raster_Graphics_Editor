#pragma once
#include <sstream>

class Switch
{
public:
	Switch(std::stringstream& ss);
	void execute(unsigned& currendSessions, unsigned openedSessions);

private:
	unsigned newIndex = 0;
};


