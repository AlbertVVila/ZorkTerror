#pragma once
#include "Entity.h"

class Room;
class Exit :
	public Entity
{
public:
	Exit(const string &name, const string &descrip1, const string &descrip2, Room *source, Room *destination, const direction &dirSource, const direction &dirDest,
		const bool &isHidden = false, const string &hint= "", const bool &isLocked = false, const bool &isOneWay = false);
	~Exit();
	Room *source;
	Room *destination;
	string descriptionSource, descriptionDest, hint;
	direction dirSource, dirDest;
	bool isHidden, isLocked, isOneWay;

	direction getDirection(const Room* room) const;
	Room* getDestination(const Room* room) const;
	string GetDescription(const Room* room) const;

private:

};

