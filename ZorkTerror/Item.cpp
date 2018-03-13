#include "stdafx.h"
#include "Item.h"


Item::Item()
{
}

Item::Item(const string & name, const string & description, Entity * parent):
	Entity(name,description,parent)
{
	type = ITEM;
	if (itemstate == NULL) itemstate = NONE;
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
