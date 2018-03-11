#include "stdafx.h"
#include "Exit.h"
#include "Room.h"

Exit::Exit(const string & name, const string &dSource, const string &dDest,Room *source, Room * destination, const direction & dirSource, const direction &dirDest):
	Entity(name,"",(Entity*) source)
{
	this->source = source;
	this->destination = destination;
	this->dirSource = dirSource;
	this->dirDest = dirDest;
	this->descriptionSource = dSource;
	this->descriptionDest = dDest;
	type = EXIT;

	this->destination->contains.push_back(this);
}


Exit::~Exit()
{
}

direction Exit::getDirection(const Room * room) const
{
	if (room == parent) return dirSource;
	return dirDest;
}

Room* Exit::getDestination(const Room * room) const
{
	if (room == parent) return destination;
	return source;
}

string Exit::GetDescription(const Room* room) const
{
	if (room == parent) return descriptionDest;
	return descriptionSource;
}

