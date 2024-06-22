#include "CommandFactory.h"
#include "load.h"

Command* CommandFactory(MyString command, std::stringstream& ss)
	{
	if (command == "load")
	{
		return new Load(ss);
	}
	else if ()
	{
	}