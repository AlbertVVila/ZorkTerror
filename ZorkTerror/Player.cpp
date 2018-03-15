#include "stdafx.h"
#include "Player.h"




Player::Player(const string & name, const string & description, Room * room):
	Creature(name,description,room)
{
	type = PLAYER;
}


Player::~Player()
{
}

void Player::Look(const vector<string>& args) const
{
	switch (args.size())
	{
	case 1:
		parent->Look();
		break;
	default:
		break;
	}
}

void Player::Go(const vector<string>& args)
{
	Exit *exit = GetRoom()->GetExit(args[1]);

	if(exit == NULL)
	{
		cout << WRONG_DIRECTION << endl;
	}
	else if (exit->isHidden || exit->isLocked)
	{
		cout << WRONG_DIRECTION << endl;
		cout << exit->hint << endl;
	}
	else if (exit->exitState == CLOSED)
	{
		cout << EXIT_ISCLOSED << endl;
	}
	else
	{
		ChangeParent(exit->getDestination((Room*)parent));
		parent->Look();
	}
}

void Player::Take(const vector<string>& args)
{
	Item * item;
	Entity * p;
	switch(args.size())
	{
	case 2:
		item = (Item*) GetRoom()->findEveryWhere(args[1]);
		if (item == NULL)
		{
			cout << ITEM_NOTFOUND << endl;
		}
		else if (item->parent == this)
		{
			cout << ITEM_ALREADY_TAKEN << endl;
		}
		else if (((Item*)item->parent)->itemtype != NULL && ((Item*)item->parent)->itemstate == CLOSED)
		{
			cout << CONTAINER_CLOSED << endl;
		}
		else if ( item->type != ITEM
			||item->itemtype == CONTAINER || item->itemtype == STATIC || item->itemtype == FIX
			|| (item->itemtype == LIGHTABLE && item->name!= "linterna") //la linterna es el único lightable que se puede coger
			|| (item->itemtype == READABLE && item->name == "libros"))  //los libros en general son readable pero no se pueden coger
		{
			cout << ITEM_NOTTAKEABLE << endl;
		}
		else
		{
			item->ChangeParent(this);
			cout << ITEM_TAKEN << endl;
			if (item->trigger != NULL &&
				(args[0] == item->triggerCommand || item->triggerCommand == "move"))
			{
				cout << item->triggerAction << endl;
				if (item->trigger->type == EXIT)
				{
					Exit * exit = (Exit*)item->trigger;
					exit->isHidden = false; 
				}
			}
		}
		break;
	default:
		break;
	}
}

void Player::Drop(const vector<string>& args)
{
	Entity * entity;
	switch (args.size())
	{
	case 2:
		entity = this->findByName(args[1]);
		if (entity == NULL)
		{
			entity = GetRoom()->findEveryWhere(args[1]);
			if (entity != NULL)
			{
				cout << ITEM_NOTFOUND_ININVENTORY << endl;
			}
			else
			{
				cout << ITEM_NOTFOUND << endl;
			}
		}
		else if (entity->type == ITEM)
		{
			entity->ChangeParent(GetRoom());
			cout << ITEM_DROPPED << endl;
		}
		break;
	default:
		break;
	}
}

void Player::Put(const vector<string>& args)
{
	Item *containee, *container;
	switch (args.size())
	{
	case 4:
		containee = (Item*)this->findByName(args[1]);
		if (containee == NULL) cout << ITEM_NOTFOUND_ININVENTORY << endl;
		else if(args[2] == "in")
		{
			container = (Container*)GetRoom()->findByName(args[3]);
			if (container == NULL) cout << CONTAINER_NOTFOUND << endl;
			else if (container->itemtype != CONTAINER) cout << ITEM_NOTCONTAINABLE << endl;
			else if (container->itemstate == CLOSED) cout << ITEM_ISCLOSED << endl;
			else
			{
				containee->ChangeParent(container);
				cout << ITEM_PUT << endl;
			}
		}
		break;
	default:
		break;
	}
}

void Player::Read(const vector<string>& args) const
{
	Readable *item;
	switch (args.size())
	{
	case 2:
		item = (Readable *)GetRoom()->findEveryWhere(args[1]);
		if (item == NULL)
		{
			cout << ITEM_NOTFOUND << endl;
		}
		else if (((Item*)parent)->itemtype != NULL && ((Item*)parent)->itemstate == CLOSED)
		{
			cout << CONTAINER_CLOSED << endl;
		}
		else if (item->itemtype != READABLE)
		{
			cout << ITEM_NOTREADABLE << endl;
		}
		else
		{
			cout << item->text << endl;
		}
		break;
	}
}

void Player::Open(const vector<string>& args) const
{
	Entity *entity;
	switch (args.size())
	{
	case 2:
		entity = GetRoom()->findByName(args[1]);
		if (entity == NULL)
		{
			cout << ENTITY_NOTFOUND << endl;
		}
		else if (entity->type == EXIT)
		{ //es podria fer refactor i enviar a la clase corresponent en ves de que el player ho faci tot
			Exit *ex= (Exit *) entity;
			if (ex->exitState == OPENED)
			{
				cout << EXIT_ALREADY_OPENED << endl;
			}
			else if (ex->exitState == NONE)
			{
				cout << EXIT_NOT_OPENABLE << endl;
			}
			else if (ex->exitState == CLOSED)
			{
				ex->exitState = OPENED;
				cout << EXIT_OPENED << endl;
			}
		}
		else if (entity->type == ITEM)
		{
			Item *item = (Item *) entity;
			if (item->itemstate == OPENED)
			{
				cout << ITEM_ALREADY_OPENED << endl;
			}
			else if (item->itemstate == NONE)
			{
				cout << ITEM_NONE_STATE << endl;
			}
			else if (item->itemstate == CLOSED)
			{
				cout << ITEM_OPENED << endl;
				item->itemstate = OPENED;
			}
		}
		break;
	}
}

void Player::Close(const vector<string>& args) const
{
	Entity *entity;
	switch (args.size())
	{
	case 2:
		entity = GetRoom()->findByName(args[1]);
		if (entity == NULL)
		{
			cout << ENTITY_NOTFOUND << endl;
		}
		else if (entity->type == EXIT)
		{
			Exit *ex = (Exit *)entity;
			if (ex->exitState == CLOSED)
			{
				cout << EXIT_ALREADY_CLOSED << endl;
			}
			else if (ex->exitState == NONE)
			{
				cout << EXIT_NOT_CLOSABLE << endl;
			}
			else if (ex->exitState == OPENED)
			{
				ex->exitState = CLOSED;
				cout << EXIT_OPENED << endl;
			}
		}
		else if (entity->type == ITEM)
		{
			Item *item = (Item *)entity;
			if (item->itemstate == CLOSED)
			{
				cout << ITEM_ALREADY_CLOSED << endl;
			}
			else if (item->itemstate == NONE)
			{
				cout << ITEM_NONE_STATE << endl;
			}
			else if (item->itemstate == OPENED)
			{
				cout << ITEM_CLOSED << endl;
				item->itemstate = CLOSED;
			}
		}
		break;
	}
}

void Player::Inventory() const
{
	if (contains.size() > 0)
	{
		cout << INVENTORY << endl;
		for (auto &entity : contains)
		{
			cout << entity->name << endl;
		}
	}
	else
	{
		cout << EMPTY_INVENTORY << endl;
	}
}

void Player::Turn(const vector<string>& args) const
{
	Lightable *item;
	switch (args.size())
	{
	case 3:
		if (args[1] == "on")
		{
			item = (Lightable*)GetRoom()->findEveryWhere(args[2]);
			if (item == NULL)
			{
				cout << ITEM_NOTFOUND << endl;
			}
			else if (item->itemtype != LIGHTABLE)
			{
				cout << ITEM_NOT_LIGHTABLE << endl;
			}
			else if (item->itemswitch == ON)
			{
				cout << ITEM_ALREADY_ON << endl;
			}
			else if (item->itemswitch == OFF)
			{
				item->itemswitch = ON;
				cout << ITEM_ON << endl;
			}
		}
		else if (args[1] == "off")
		{
			item = (Lightable *)GetRoom()->findEveryWhere(args[2]); //mirar a zork com funciona
			if (item == NULL)
			{
				cout << ITEM_NOTFOUND << endl;
			}
			else if (item->itemtype != LIGHTABLE)
			{
				cout << ITEM_NOT_LIGHTABLE << endl;
			}
			else if (item->itemswitch == OFF)
			{
				cout << ITEM_ALREADY_OFF << endl;
			}
			else if (item->itemswitch == ON)
			{
				item->itemswitch = OFF;
				cout << ITEM_OFF << endl;
			}
		}
		break;
	}
}

void Player::Hide()
{
	Room *room = GetRoom();
	if (this->isHiding)
	{
		cout << ALREADY_HIDING << endl;
	}
	else if (room->hidingSpot.empty())
	{
		cout << CANNOT_HIDE << endl;
	}
	else
	{
		this->isHiding = true;
		cout << room->hidingSpot << endl;
	}
}

void Player::Reveal()
{
	Room *room = GetRoom();
	if (!this->isHiding)
	{
		cout << ALREADY_REVEALED << endl;
	}
	else
	{
		this->isHiding = false;
		cout << REVEALED << endl;
	}
}

void Player::Unlock(const vector<string>& args) const
{
	switch (args.size())
	{
	case 4:
		Exit *lockedExit = (Exit*)GetRoom()->findByName(args[1]);
		if (lockedExit == NULL)
		{
			cout << EXIT_LOCKED_NOTFOUND << endl;
		}
		else if (lockedExit->type != EXIT)
		{
			cout << ENTITY_NOTUNLOCKABLE << endl;
		}
		else if (!lockedExit->isLocked)
		{
			cout << EXIT_NOTLOCKED << endl;
		}
		else
		{
			if (args[2] == "with")
			{
				Item *unlocker = (Item*)this->findByName(args[3]);
				if (unlocker == NULL || unlocker->trigger != lockedExit) cout << UNLOCKER_NOTFOUND << endl;
				else
				{
					lockedExit->isLocked = false;
					cout << unlocker->triggerAction << endl;
				}
			}
		}
		break;
	}
}

void Player::Move(const vector<string>& args) const
{
	Item *item = (Item*)GetRoom()->findEveryWhere(args[1]);
	if (item == NULL) cout << ITEM_NOTFOUND << endl;
	else if (item->type!= ITEM || item->itemtype == FIX)
	{
		cout << ENTITY_NOTMOVABLE << endl;
	}
	else if (item->trigger == NULL && item->parent != this)
	{
		cout << MOVING_HAS_NOEFFECT << endl;
	}
	else if (item->triggerCommand == args[0] || item->triggerCommand == "take")
	{
		if ((item->trigger)->type == EXIT)
		{
			Exit * exit = (Exit*)item->trigger;
			exit->isHidden = false;
		}
		cout << item->triggerAction << endl;
	}
	else if (item->parent == this)
	{
		cout << MOVING_NOEFFECT_INVENTORY << endl;
	}
} 
