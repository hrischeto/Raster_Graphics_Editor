#pragma once
#include "Command.h"
class Close : public Command
{
public:
	Close(unsigned session);
	void execute(Vector<Session>& openedSessions) override;

private:
	unsigned _session = 0;
};

