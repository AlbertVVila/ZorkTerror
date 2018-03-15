#include "stdafx.h"
#include "Container.h"


Container::Container(const string & name, const string & description, Entity * parent):
	Item(name,description,parent, CONTAINER)
{
	itemstate = CLOSED;
}

Container::~Container()
{
}
