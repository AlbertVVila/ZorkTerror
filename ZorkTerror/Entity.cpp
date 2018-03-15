#include "stdafx.h"
#include "Entity.h"
#include "Item.h"

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

Entity* Entity::findByName(const string & name) const
{
	for (auto &entity : contains)
	{
		if (entity->name == name)
		{
			return entity;
		}
	}
	return NULL;
}

Entity * Entity::findEveryWhere(const string & name) const //recursivament busca 
{
	for (auto &entity : contains)
	{
		Entity *child = entity->findEveryWhere(name);
		if (child != NULL) return child;

		if (entity->name == name)
		{
			return entity;
		}
	}
	return NULL;
}

list<Entity *> Entity::findbyItemType(Itemtype type) const
{
	list<Entity*> items;
	for (auto &entity : contains)
	{
		if (entity->type == ITEM && ((Item *)entity)->itemtype == type)
		{
			items.push_front(entity);
		}
		list<Entity*> childItems = entity->findbyItemType(type);
		items.merge(childItems);
	}
	return items;
}

void Entity::Update()
{
}
