#pragma once
#include "stdafx.h"
#include "Item.h"

class Container :
	public Item
{
public:
	Container(const string &name, const string &description, Entity* parent, const bool &isLocked= false, const string &unlockCode="");
	~Container();

	bool isLocked;
	string unlockCode;
};
