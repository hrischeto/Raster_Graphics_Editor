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

void Load::printMessege() const
{
	std::cout << "New session with id " << id << " started." << std::endl;
	std::cout << "Added images: ";

	for (int i = 0;i < newSession.getNumberOfImages();i++)
	{
		std::cout << newSession[i].getName() << " ";
	}
	
	std::cout << std::endl;
}
