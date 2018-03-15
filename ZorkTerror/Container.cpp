#include "stdafx.h"
#include "Container.h"


Container::Container(const string & name, const string & description, Entity * parent, const bool &isLocked, const string &unlockCode):
	Item(name,description,parent, CONTAINER)
{
	itemstate = CLOSED;
	this->isLocked = isLocked;
	this->unlockCode = unlockCode;
}

Container::~Container()
{
}
