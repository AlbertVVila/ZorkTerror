#pragma once
#include <string>
#include <list>
#include "globals.h"

class Entity
{
public:
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
	Entity* findEveryWhere(const string &name) const;
	list<Entity*> findbyItemType(Itemtype type) const;
	list<Entity*> findAllByName(const string &name) const;

private:


protected:

};


