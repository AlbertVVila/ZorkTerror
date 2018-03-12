#pragma once
#include "Item.h"
class Container :
	public Item
{
public:
	Container(const string &name, const string &description, Entity* parent);
	~Container();
};

