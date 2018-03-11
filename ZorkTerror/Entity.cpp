#include "stdafx.h"
#include "Entity.h"


Entity::Entity()
{
}

Entity::Entity(string name, string description, Entity *parent)
{
	type = ENTITY;
	this->name = name;
	this->description = description;
	this->parent = parent;
	if (parent != NULL)
	{
		this->parent->contains.push_back(this);
	}
}


Entity::~Entity()
{
}

Entitytype Entity::getType()
{
	return this->type;
}


void Entity::Look() const
{
	cout << name << endl;
	cout << description << endl;
}

void Entity::ChangeParent(Entity* newParent)
{
	if (parent != NULL)
	{
		parent->contains.remove(this);
	}
	parent = newParent;
	if (parent != NULL)
	{
		parent->contains.push_back(this);
	}

}

void Entity::Update()
{
}
