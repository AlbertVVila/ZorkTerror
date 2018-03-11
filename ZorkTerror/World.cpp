#include "stdafx.h"
#include "World.h"
#include "Entity.h"
#include "Room.h"
#include "Creature.h"
#include "Player.h"
#include "Exit.h"
World::World()
{
	//Create rooms
	Room *bedroom = new Room("Bedroom", "You are in a bedroom with a large bed."
		"The bed is dusty and seems that nobody has used in months.");
	Room *corridor = new Room("Corridor", "You are in a dark corridor.");
	Room *livingRoom = new Room("Living Room", "You are in the living room");
	Room *kitchen = new Room("Kitchen","You are in the kitchen");

	//AddRooms
	rooms.push_back(bedroom);
	rooms.push_back(corridor);
	rooms.push_back(livingRoom);
	rooms.push_back(kitchen);

	//AddExits

	//Create player
 	player = new Player("Player", "You are brave!", bedroom);
}


World::~World()
{
}

bool World::GetInput(const string & input)
{
	return false;
}
