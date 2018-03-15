#pragma once
#include "Creature.h"
class Grue :
	public Creature
{
public:
	Grue(const string &name, const string &description, Room *room);
	~Grue();
};

