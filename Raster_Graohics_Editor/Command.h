#pragma once
#include "OpenedSessions.h"
class Command
{
	virtual void execute(OpenedSessions& sessions)=0;
	virtual ~Command();
};

