#pragma once
#include "vector.hpp"
#include "Session.h"

class Command
{
public:
	virtual void execute(Vector<Session>& openedSessions)=0;
	virtual void printMessege() const;
	virtual ~Command();
};

