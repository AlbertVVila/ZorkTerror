#pragma once
#include "Entity.h"
#include "Room.h"
class Creature :
	public Entity
{
public:
	Creature();
	Creature(const string &name, const string &description, Room *room);
	~Creature();

	virtual bool Go(const string& direction);

private:
		Room *location;
};

