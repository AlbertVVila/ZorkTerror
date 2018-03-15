#pragma once
#include "Entity.h"
#include "Exit.h"
#include "globals.h"

class Room :
	public Entity
{
public:
	Room(const string &name, const string &description, const string &hidingSpot= "", const bool &isLighted = false);

	void Look() const;
	Exit* GetExit(const string &dir) const;
	list<Exit*> GetPassableExits() const;

	bool LightsOn() const;

	string hidingSpot;
	bool isLighted;

private:

};


