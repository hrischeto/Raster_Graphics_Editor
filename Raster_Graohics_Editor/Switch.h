#pragma once
#include <sstream>

class Switch
{
public:
	Switch(std::stringstream& ss);
	void execute(unsigned& currendSessions, unsigned openedSessions);
	void printMessege() const;

private:
	unsigned newIndex = 0;
};


