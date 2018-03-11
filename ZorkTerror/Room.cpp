#include "stdafx.h"
#include "Room.h"


Room::Room()
{
}

Room::Room(const string & name, const string & description) :
	Entity(name,description,NULL)
{
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
			Exit *ex = static_cast<Exit*>(entity);
			string descrip = ex->GetDescription(this);
			if(!descrip.empty()) cout <<descrip<< endl;
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

