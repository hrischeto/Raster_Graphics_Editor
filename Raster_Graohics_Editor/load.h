#pragma once
#include "Command.h"
#include "Session.h"
class Load : public Command
{
public:
	Load(std::stringstream& ss);
	void execute(Vector<Session>& openedSessions) override;
private:
	Session newSession;
};

