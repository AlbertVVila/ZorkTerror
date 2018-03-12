#pragma once
#include "Entity.h"
#include "Exit.h"
#include "globals.h"
class Room :
	public Entity
{
public:
	Room();
	Room(const string &name, const string &description, const string &hidingSpot= "");
	~Room();

	void Look() const;
	Exit* GetExit(const string &dir) const;

	string hidingSpot;
private:

};

