#include "stdafx.h"
#include "Item.h"

Item::Item(const string & name, const string & description, Entity * parent, Itemtype itemtype, const string &descriptionFloor, const bool &dropped):
	Entity(name,description,parent)
{
	type = ITEM;
	if (itemstate == NULL) itemstate = NONE;
	this->itemtype = itemtype;
	this->descriptionFloor = descriptionFloor;
	this->dropped = dropped;
}


Item::~Item()
{
}

void Item::Look() const
{
	for (auto &entity : contains)
	{
		if (entity->getType() == ITEM && !entity->description.empty())
		{
			cout << entity->description << endl;
		}
	}
}

void Item::setTrigger(Entity * entity, const string &triggerAction, const string &triggerCommand)
{
	this->trigger = entity;
	this->triggerAction = triggerAction;
	this->triggerCommand = triggerCommand;
}
