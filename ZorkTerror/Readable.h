#pragma once
#include "Item.h"

class Readable :
	public Item
{
public:
	Readable(const string &name, const string &description, Entity* parent, const string &text, const string &descriptionFloor="");
	~Readable();
	string text;
};
