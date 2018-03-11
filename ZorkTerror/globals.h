#ifndef __Globals__
#define __Globals__

#include <string>
#include <vector>
#include <iostream>
using namespace std;
enum direction
{
	NORTH,SOUTH,WEST,EAST,UP,DOWN,UNKNOWN
};
enum Entitytype
{
	PLAYER, EXIT, ROOM, ITEM, GRUE, ENTITY
};

void ParseInput(string input, vector<string> &args);
direction ConvertToDir(const string &dir);
string ConvertToString(const direction &dir);
#endif // __Globals__


