#include "stdafx.h"
#include "Room.h"


Room::Room()
{
}

Room::Room(const string & name, const string & description, const string &hidingSpot) :
	Entity(name,description,NULL)
{
	this->hidingSpot = hidingSpot;
	type = ROOM;
}


Room::~Room()
{
}

void Room::Look() const
{
	cout << "\n" << name << endl;
	cout << description <<endl;

	//Exits
	for (auto &entity : contains)
	{
		if (entity->getType() == EXIT)
		{
			Exit *ex = (Exit*) entity;
			if (ex->isHidden || ex->isLocked)
			{
				if(!ex->hint.empty()) cout << ex->hint << endl;
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
		if (entity->getType() == ITEM)
		{
			cout<< entity->description << endl;
		}
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

