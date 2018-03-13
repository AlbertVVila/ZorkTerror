#include "stdafx.h"
#include "Exit.h"
#include "Room.h"

Exit::Exit(const string & name, const string &dSource, const string &dDest,Room *source, Room * destination, const direction & dirSource, const direction &dirDest,
	const bool &isHidden, const string &hint, const bool &isLocked, State exitState, const bool &isOneWay):
	Entity(name,"",(Entity*) source)
{
	this->source = source;
	this->destination = destination;
	this->dirSource = dirSource;
	this->dirDest = dirDest;
	this->descriptionSource = dSource;
	this->descriptionDest = dDest;
	this->isHidden = isHidden;
	this->isLocked = isLocked;
	this->hint = hint;
	this->exitState = exitState;
	type = EXIT;

	if (!isOneWay) this->destination->contains.push_back(this);

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

