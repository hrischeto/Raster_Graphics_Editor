#include "load.h"
#include "ImageFactory.h"
#include <sstream>

Load::Load(std::stringstream& ss)
{
	if (ss.eof())
		throw std::invalid_argument("No image provided");

	MyString filepath;
	while (!(ss.eof()))
	{
		ss >> filepath;
		newSession.addImage(filepath.c_str());
	}
}
void Load::execute(Vector<Session>& openedSessions)
{
	newSession.setID(openedSessions.getSize());
	openedSessions.push_back(std::move(newSession));
}
