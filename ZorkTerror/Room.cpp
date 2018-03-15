#include "stdafx.h"
#include "Room.h"
#include "Lightable.h"

Room::Room(const string & name, const string & description, const string &hidingSpot, const bool &isLighted) :
	Entity(name,description,NULL)
{
	this->hidingSpot = hidingSpot;
	this->isLighted = isLighted;
	type = ROOM;
}


void Room::Look() const
{
	if (this->isLighted || this->name == "Habitación principal")
	{
		cout << "\n" << name << endl;
		cout << description << endl;

		//Exits
		for (auto &entity : contains)
		{
			if (entity->getType() == EXIT)
			{
				Exit *ex = (Exit*)entity;
				if (ex->isHidden || ex->isLocked)
				{
					if (!ex->hint.empty()) cout << ex->hint << endl;
				}
				else
				{
					string descrip = ex->GetDescription(this);
					if (!descrip.empty()) cout << descrip << endl;
				}
			}
		}
		for (auto &entity : contains)
		{
			if (entity->getType() == ITEM && !entity->description.empty())
			{
				cout << entity->description << endl;
			}
		}
	}
	else
	{
		cout << BLACK_ROOM << endl;
	}
}

Exit* Room::GetExit(const string & dir) const
{
	for(auto &entity : contains)
	{
		if (entity->getType() == EXIT)
		{
			Exit *ex = (Exit*) entity;
			if (ConvertToDir(dir) == ex->getDirection(this))
			{
				return ex;
			}
		}
	}
	return NULL;
}

bool Room::LightsOn() const
{
	list<Entity *> lights = this->findbyItemType(LIGHTABLE);
	for (auto &light : lights)
	{
		if (((Lightable *)light)->itemswitch == ON)
		{
			return true;
		}
	}
	return false;
}

