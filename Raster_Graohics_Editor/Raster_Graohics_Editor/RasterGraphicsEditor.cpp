#pragma once
#include <iostream>
#include <sstream>
#include "Engine.h"
#include "CommandFactory.h"

constexpr int BUFFER_SIZE = 100;

bool processInput(std::stringstream& ss)
{
	char buffer[BUFFER_SIZE];
	ss.getline(buffer, BUFFER_SIZE, '/n');
	MyString command(buffer);//to use ==
	//return 0 when exit
	//for help print all commands
	//print a messege after every command
	//for commands with contex give the ss in the constuctor
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
		run=processInput(ss);
	}
}