#include "stdafx.h"
#include "Readable.h"


Readable::Readable(const string & name, const string & description, Entity * parent, const string &text, const string &descriptionFloor):
	Item(name,description,parent,READABLE, descriptionFloor)
{
	this->text = text;
}

Readable::~Readable()
{
}
