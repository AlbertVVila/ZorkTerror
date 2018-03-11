#include "stdafx.h"
#include "Entity.h"


Entity::Entity()
{
}

Entity::Entity(string name, string description)
{
	this->name = name;
	this->description = description;
}


Entity::~Entity()
{
}

void Entity::Update()
{
}
