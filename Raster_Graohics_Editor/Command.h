#pragma once
#include "vector.hpp"
#include "Session.h"

class Command
{
public:
	virtual void execute(Vector<Session>& openedSessions)=0;
	virtual ~Command();
	virtual void printMessege() const = 0;
};

