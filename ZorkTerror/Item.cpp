#include "stdafx.h"
#include "Item.h"


Item::Item()
{
}

Item::Item(const string & name, const string & description, Entity * parent):
	Entity(name,description,parent)
{
	type = ITEM;
	if (this->itemstate == NULL) this->itemstate = NONE;
}


Item::~Item()
{
}
