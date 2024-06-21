#pragma once
#include "MyQueue.hpp"
#include "Command.h"
#include "vector.hpp"
#include "Session.h"

class Engine
{
	MyQueue<Command> commands;
	Vector<Session> openedSessions;
};