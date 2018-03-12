#include "stdafx.h"
#include "Readable.h"


Readable::Readable(const string & name, const string & description, Entity * parent, const string &text):
	Item(name,description,parent)
{
	this->text = text;
	itemtype = READABLE;
}

Readable::~Readable()
{
}
