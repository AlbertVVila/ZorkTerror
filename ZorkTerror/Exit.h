#pragma once
#include "Entity.h"
using namespace std;
enum direction
{
	NORTH, SOUTH, WEST, EAST
};
class Room;

class Exit :
	public Entity
{
public:
	Exit();
	Exit(const string &name, const string &description, Room* source, Room* destination, direction dir);
	~Exit();

private:
	Room *source;
	Room *destination;
};

