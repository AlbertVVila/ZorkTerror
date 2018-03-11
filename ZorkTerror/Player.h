#pragma once
#include "Creature.h"


class Player :
	public Creature
{
public:
	Player();
	Player(const string &name, const string &description, Room *room);
	~Player();
};

