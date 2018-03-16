#include "stdafx.h"
#include "globals.h"
#include <iostream>
#include <algorithm>
using namespace std;


void ParseInput(string input, vector<string> &args)
{
	const char specialChar[] = { '\xA0','\xA4','\x82','\xA1','\xA2','\xA3' };
	const char replaceChar[] = { 'a','n','e','i','o','u'};
	size_t pos=0;
	while (pos!=string::npos)
	{
		pos = input.find(" ");
		string word = input.substr(0, pos);
		for (size_t i=0; i<strlen(specialChar); i++) //eliminar caracteres especiales
		{
			replace(word.begin(), word.end(), specialChar[i], replaceChar[i]);
		}
		args.push_back(input.substr(0,pos));
		input.erase(0,pos+1);
	}
}

direction ConvertToDir(const string & dir)
{
	if (dir == "norte")
	{
		return NORTH;
	}
	if (dir == "sur")
	{
		return SOUTH;
	}
	if (dir == "oeste")
	{
		return WEST;
	}
	if (dir == "este")
	{
		return EAST;
	}
	if (dir == "arriba")
	{
		return UP;
	}
	if (dir == "abajo")
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
