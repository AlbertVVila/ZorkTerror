#include "stdafx.h"
#include "Exit.h"


Exit::Exit()
{
}


Exit::Exit(const string & name, const string & description, Room * source, Room * destination):
	Entity(name,description)
{
	this->source = source;
	this->destination = destination;
}


Exit::~Exit()
{
}
