#include <iostream>
#include <sstream>
#include "Engine.h"
#include "CommandFactory.h"

constexpr int BUFFER_SIZE = 100;

bool processInput(std::stringstream& ss, Engine& engine)
{
	char buffer[BUFFER_SIZE];
	ss.getline(buffer, BUFFER_SIZE, '/n');
	MyString command(buffer);//to use ==
	
	if (command == "exit")
	{
		//might ask to save
		return 0;
	}
	if (command == "help")
	{
		//print all commands
		return 1;
	}
	else
	{
		engine.addCommand(CommandFactory(command, ss));
		engine.getMessege();
		return 1;
	}
}
int main()
{
	Engine engine;

	bool run = 1;
	MyString input;

	while (run)
	{
		std::cin >> input;
		std::stringstream ss(input.c_str());
		run=processInput(ss,engine);
	}
}