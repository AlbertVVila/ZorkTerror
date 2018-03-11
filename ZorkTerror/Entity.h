#pragma once
#include <string>
#include <list>
using namespace std;

class Entity
{
public:
	Entity();
	Entity(string name, string description);
	~Entity();

private:
	enum type
	{
		CREATURE,EXIT,ROOM,ITEM
	};
	string name;
	string description;
	list<Entity*> contains;

	virtual void Update();
};

