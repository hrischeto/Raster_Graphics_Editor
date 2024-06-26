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
	id++;
	newSession.setID(id);

	currentSession = id;
}

void Load::execute(Vector<Session>& openedSessions)
{
	openedSessions.push_back(std::move(newSession));
}

unsigned Load::getId() const
{
	return id;
}

