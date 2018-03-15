#include "stdafx.h"
#include "Creature.h"

Creature::Creature()
{
}

Creature::Creature(const string & name, const string & description, Room * room):
	Entity(name,description, (Entity*) room)
{

}


Creature::~Creature()
{
}

Room * Creature::GetRoom() const
{
	return (Room*)parent;
}

bool Creature::Go(const string & direction)
{
	return false;
}


