#include "stdafx.h"
#include "Creature.h"


Creature::Creature()
{
}

Creature::Creature(const string & name, const string & description, Room * room):
	Entity(name,description)
{
	this->location = room;
}


Creature::~Creature()
{
}

bool Creature::Go(const string & direction)
{
	return false;
}


