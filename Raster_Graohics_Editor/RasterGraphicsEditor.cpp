#include <iostream>
#include <sstream>
#include "Engine.h"
#include "CommandFactory.h"
#include "Save.h"

constexpr int BUFFER_SIZE = 100;

bool processInput(std::stringstream& ss, Engine& engine)
{
	char buffer[BUFFER_SIZE];
	ss.getline(buffer, BUFFER_SIZE, '/n');
	MyString command(buffer);//to use ==
	CommandFactory factory;

	if (command == "exit")
	{
		//might ask to save
		return 0;
	}
	else if (command == "save")
	{
		Save newCommand(factory.currentSession, engine.getQueue());
		newCommand.execute(engine.getSessions());
	}
	else if (command == "help")
	{
		//print all commands
	}
	else
	{
		engine.addCommand(factory(command, ss));
		//engine.getMessege();
		return 1;
	}
}

void application()
{
	Engine engine;

	bool run = 1;
	MyString input;

	while (run)
	{
		std::cin >> input;
		std::stringstream ss(input.c_str());
		run = processInput(ss, engine);
	}
}
int main()
{
	application();
}