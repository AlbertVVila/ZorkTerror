#pragma once
#include "Item.h"
class Lightable :
	public Item
{
public:
	Lightable(const string & name, const string & description, Entity * parent);
	~Lightable();
	ItemSwitch itemswitch;
};

