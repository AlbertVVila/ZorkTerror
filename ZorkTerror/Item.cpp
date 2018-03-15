#include "stdafx.h"
#include "Item.h"

Item::Item(const string & name, const string & description, Entity * parent, Itemtype itemtype):
	Entity(name,description,parent)
{
	type = ITEM;
	if (itemstate == NULL) itemstate = NONE;
	this->itemtype = itemtype;
}


Item::~Item()
{
}

void Item::setTrigger(Entity * entity, const string &triggerAction, const string &triggerCommand)
{
	this->trigger = entity;
	this->triggerAction = triggerAction;
	this->triggerCommand = triggerCommand;
}
