#pragma once
#include "Creature.h"


class Player :
	public Creature
{
public:
	Player();
	Player(const string &name, const string &description, Room *room);
	~Player();

	void Look(const vector<string> &args) const;
	void Go(const vector<string> &args);
};

