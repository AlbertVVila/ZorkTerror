#pragma once
#include "Creature.h"
#include "Player.h"

class Grue :
	public Creature
{
public:
	Grue(const string &name, const string &description, Room *room);
	~Grue();

	void Look();
	void Go();
	void EatPlayer(Player *player);
};

