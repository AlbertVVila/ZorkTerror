#include "stdafx.h"
#include "globals.h"
#include <iostream>

using namespace std;


void ParseInput(string input, vector<string> &args)
{
	size_t pos=0;
	while (pos!=string::npos)
	{
		pos = input.find(" ");
		args.push_back(input.substr(0,pos));
		input.erase(0,pos+1);
	}
	/*for (auto &arg : args)
	{
		cout << arg << endl;
	}*/

}

direction ConvertToDir(const string & dir)
{
	if (dir == "north")
	{
		return NORTH;
	}
	if (dir == "south")
	{
		return SOUTH;
	}
	if (dir == "west")
	{
		return WEST;
	}
	if (dir == "east")
	{
		return EAST;
	}
	if (dir == "up")
	{
		return UP;
	}
	if (dir == "down")
	{
		return DOWN;
	}
	return UNKNOWN;
}

string ConvertToString(const direction & dir)
{
	switch (dir)
	{
	case NORTH:
		return "norte";
	case SOUTH:
		return "sur";
	case WEST:
		return "oeste";
	case EAST:
		return "este";
	case UP:
		return "arriba";
	case DOWN:
		return "abajo";
	}
	return NULL;
}
