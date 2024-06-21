#pragma once
#include "vector.hpp"
#include "Session.h"

class Command
{
	virtual void execute(Vector<Session>& openedSessions)=0;
	virtual ~Command();
};

