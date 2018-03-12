#include "stdafx.h"
#include "Container.h"


Container::Container(const string & name, const string & description, Entity * parent):
	Item(name,description,parent)
{
	itemtype = CONTAINER;
	itemstate = CLOSED;
}

Container::~Container()
{
}
