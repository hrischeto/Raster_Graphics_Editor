#include "Command.h"

Command::~Command() = default;

unsigned Command::getSession() const
{
	return currentSession;
}
