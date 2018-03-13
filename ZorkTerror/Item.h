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

	Entity *trigger=NULL;
	string triggerAction="", triggerCommand = "";
	Itemtype itemtype;
	State itemstate;

	void setTrigger(Entity* entity, const string &triggerAction, const string &triggerCommand);
};

