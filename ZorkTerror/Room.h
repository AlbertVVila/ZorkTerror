#pragma once
#include "Entity.h"
#include "Exit.h"
#include "globals.h"
class Room :
	public Entity
{
public:
	Room();
	Room(const string &name, const string &description);
	~Room();

	void Look() const;
	Exit* GetExit(const string &dir) const;
private:

};

