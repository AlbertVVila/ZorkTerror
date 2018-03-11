#include "stdafx.h"
#include "Room.h"


Room::Room()
{
}

Room::Room(const string & name, const string & description) :
	Entity(name,description)
{

}


Room::~Room()
{
}
