#pragma once
#include "Entity.h"
#include "Room.h"

class Item :
	public Entity
{
public:
	Item(const string &name, const string &description, Entity* parent, Itemtype itemtype = COMMON, const string &descriptionFloor="", const bool &dropped=false);
	~Item();

	Entity *trigger=NULL;
	string triggerAction="", triggerCommand = "";
	Itemtype itemtype;
	State itemstate;
	string descriptionFloor;
	bool dropped;
	void Look() const;
	void setTrigger(Entity* entity, const string &triggerAction, const string &triggerCommand);
};
