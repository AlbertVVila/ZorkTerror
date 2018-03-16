#include "stdafx.h"
#include "Lightable.h"

Lightable::Lightable(const string & name, const string & description, Entity * parent, const string &descriptionFloor):
	Item(name,description,parent,LIGHTABLE,descriptionFloor)
{
	this->itemswitch = OFF;
}

Lightable::~Lightable()
{
}
