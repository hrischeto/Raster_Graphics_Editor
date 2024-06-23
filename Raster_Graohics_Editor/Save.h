#pragma once
#include "Command.h"
#include "CommandQueue.h"

class Save : public Command
{
public:
	Save(unsigned session, CommandQueue* queue);
	void execute(Vector<Session>& openedSessions) override;
private:
	CommandQueue* _queue = nullptr;
};

