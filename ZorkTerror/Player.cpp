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
		cout << "No se puede ir en esa dirección" << endl;
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
	switch(args.size())
	{
	case 2:
		item = (Item*) GetRoom()->findByName(args[1]);
		if (item != NULL)
		{
			item->ChangeParent(this);
			cout << "Elemento cogido" << endl;
		}
		else
		{
			cout << ITEM_NOTFOUND << endl;
		}
		break;
	default:
		break;
	}
}

void Player::Drop(const vector<string>& args)
{
	Item * item;
	switch (args.size())
	{
	case 2:
		item = (Item*)this->findByName(args[1]);
		if (item != NULL)
		{
			item->ChangeParent(GetRoom());
			cout << "Elemento tirado." << endl;
		}
		else
		{
			cout << ITEM_NOTFOUND << endl;
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
		if (containee == NULL) cout << ITEM_NOTFOUND << endl;
		else if(args[2] == "in")
		{
			container = (Container*)GetRoom()->findByName(args[3]);
			if (container == NULL) cout << CONTAINER_NOTFOUND << endl;
			else if (container->itemtype != CONTAINER) cout << ITEM_NOTCONTAINABLE << endl;
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
		item = (Readable *)GetRoom()->findByName(args[1]);
		if (item == NULL) cout << ITEM_NOTFOUND << endl;
		else if (item->itemtype != READABLE) cout << ITEM_NOTREADABLE << endl;
		else cout << item->text << endl;
		break;
	}
}

void Player::Open(const vector<string>& args) const
{
	Item *item;
	switch (args.size())
	{
	case 2:
		item = (Item *)GetRoom()->findByName(args[1]);
		if (item == NULL) cout << ITEM_NOTFOUND << endl;
		else if (item->itemstate == OPENED) cout << ITEM_ALREADY_OPENED << endl;
		else if (item->itemstate == NONE) cout << ITEM_NONE_STATE << endl;
		else if (item->itemstate == CLOSED)
		{
			cout << ITEM_OPENED << endl;
			item->itemstate = OPENED;
		}

		break;
	}
}

void Player::Close(const vector<string>& args) const
{
	Item *item;
	switch (args.size())
	{
	case 2:
		item = (Item *)GetRoom()->findByName(args[1]);
		if (item == NULL) cout << ITEM_NOTFOUND << endl;
		else if (item->itemstate == CLOSED) cout << ITEM_ALREADY_CLOSED << endl;
		else if (item->itemstate == NONE) cout << ITEM_NONE_STATE << endl;
		else if (item->itemstate == OPENED)
		{
			cout << ITEM_CLOSED << endl;
			item->itemstate = CLOSED;
		}

		break;
	}
}
