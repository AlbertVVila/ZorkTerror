#pragma once
#include "Entity.h"
#include "Room.h"
class Item :
	public Entity
{
public:
	Item();
	Item(const string &name, const string &description, Entity* parent);
	~Item();

	Itemtype itemtype;
	ItemState itemstate;
};

