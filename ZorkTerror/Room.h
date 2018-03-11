#pragma once
#include "Entity.h"
class Room :
	public Entity
{
public:
	Room();
	Room(const string &name, const string &description);
	~Room();
};

