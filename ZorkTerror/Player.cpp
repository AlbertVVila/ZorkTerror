#include "stdafx.h"
#include "Player.h"


Player::Player()
{
}

Player::Player(const string & name, const string & description, Room * room):
	Creature(name,description,room)
{
}


Player::~Player()
{
}
