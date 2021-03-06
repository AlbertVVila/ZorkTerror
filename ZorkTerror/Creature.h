#pragma once
#include "Entity.h"
#include "Room.h"
#include "Item.h"
#include "Container.h"
#include "Readable.h"
#include "Lightable.h"

class Creature :
	public Entity
{
public:
	Creature(const string &name, const string &description, Room *room);
	~Creature();

	Room* GetRoom() const;
	virtual void Go(const string& direction);
private:

};

