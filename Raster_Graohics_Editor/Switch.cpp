#include "Switch.h"
#include <iostream>

Switch::Switch(std::stringstream& ss)
{
	ss >> newIndex;

	if (ss.fail())
		throw std::invalid_argument("Not a session number");
}
void Switch::execute(unsigned& currentSession, unsigned openedSessions)
{
	if (newIndex > openedSessions)
		throw std::invalid_argument("No such session");

	currentSession = newIndex;
}
