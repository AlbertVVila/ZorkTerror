#include "stdafx.h"
#include "Lightable.h"


Lightable::Lightable(const string & name, const string & description, Entity * parent):
	Item(name,description,parent)
{
	itemtype = LIGHTABLE;
	this->itemswitch = OFF;
}

Lightable::~Lightable()
{
}
