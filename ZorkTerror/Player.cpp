#include "stdafx.h"
#include "Player.h"


Player::Player()
{
}

Player::Player(const string & name, const string & description, Room * room):
	Creature(name,description,room)
{
	type = PLAYER;
}


Player::~Player()
{
}

void Player::Look(const vector<string>& args) const
{
	switch (args.size())
	{
	case 1:
		parent->Look();
		break;
	default:
		break;
	}
}

void Player::Go(const vector<string>& args)
{
	Exit *exit = GetRoom()->GetExit(args[1]);

	if(exit == NULL)
	{
		cout << "No se puede ir en esa dirección" << endl;
	}
	else
	{
		ChangeParent(exit->getDestination((Room*)parent));
		parent->Look();
	}
}
