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

	Room* GetRoom() const;
	virtual bool Go(const string& direction);
private:

};

