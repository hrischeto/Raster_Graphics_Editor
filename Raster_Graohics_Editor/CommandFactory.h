#pragma once
#include "Command.h"
#include <sstream>

Command* CommandFactory(MyString command, std::stringstream& ss);

