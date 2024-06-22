#include "CommandFactory.h"
#include "load.h"
#include "Close.h"
#include "Switch.h"

Command* CommandFactory::operator()(MyString command, std::stringstream& ss)
{
	if (command == "load")
	{
		Load* newCommand = new Load(ss);
		currentSession = newCommand->getId();
		openedSessions++;
		return newCommand;
	}
	else if (command == "close")
	{
		openedSessions--;
		return new Close(currentSession++);
	}

	else if (command == "switch")
	{
		 Switch newCommand(ss);

		 newCommand.execute(currentSession, openedSessions);
		 newCommand.printMessege();
		return nullptr;
	}

	else if (command == "grayscale")
	{

	}
}