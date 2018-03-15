#pragma once
#include "globals.h"

class Grue;
class Player;
class Entity;


class World
{

public:
	World();
	~World();
	bool GetInput(const vector<string> &args);
private:
	vector<Entity*> entities;
	Player *player;
	Grue *grue;
};


