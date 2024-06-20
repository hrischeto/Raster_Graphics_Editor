#pragma once
#include "CommandQueue.h"
#include "OpenedSessions.h"

class RasterGraphicsEditor
{
	CommandQueue commands;
	OpenedSessions openedSessions;
};