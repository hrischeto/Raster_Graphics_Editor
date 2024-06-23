#pragma once
#include "Command.h"
class Grayscale : public Command
{
public:
	Grayscale(unsigned session);
	void execute(Vector<Session>& openedSessions) override;

private:

	bool grayscalecheck(const Image* image) const;
};

