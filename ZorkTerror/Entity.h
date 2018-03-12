#pragma once
#include <string>
#include <list>
#include "globals.h"
using namespace std;

class Entity
{
public:
	Entity();
	Entity(string name, string description, Entity *parent);
	~Entity();
	
	Entitytype type;
	string name;
	string description;
	list<Entity*> contains;
	Entity *parent;
	Entitytype getType();

	virtual void Look() const;
	void ChangeParent(Entity* newParent);
	Entity* findByName(const string &name) const;
	virtual void Update();
private:


protected:

};

