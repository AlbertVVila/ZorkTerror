#include "stdafx.h"
#include "Grue.h"
#include <stdlib.h> 
Grue::Grue(const string & name, const string & description, Room *room):
	Creature(name,description,room)
{

}

Grue::~Grue()
{
}

void Grue::Look()
{
	Entity *entity = GetRoom()->findByName(PLAYER_NAME);
	if (entity != NULL && entity->type == PLAYER)
	{
		Player *player = (Player *)entity;
		if (GetRoom()->isLighted)
		{
			EatPlayer(player); //Con la luz encendida siempre te come
		}
		else
		{
			bool seen = rand() % 4;
			if (seen)
			{
				EatPlayer(player); //Con la luz apagada 1/4 de posibilidades de que te coma
			}
		}
	}
}

void Grue::Go()
{
	if (rand() % 3 == 0) //CADA TURNO HAY UN 33,3% DE PROBABILIDADES DE QUE SE MUEVA
	{
		list<Exit *> l = GetRoom()->GetPassableExits();
		vector<Exit *> exits{ make_move_iterator(begin(l)),
			make_move_iterator(end(l)) };
		if (exits.size() > 0)
		{
			int r = exits.size() == 1 ? 0 : rand() % (exits.size() - 1);
			if (exits[r]->exitState = CLOSED) exits[r]->exitState = OPENED;
			ChangeParent(exits[r]->getDestination((Room*)parent));
		}
	}

	cout << "GRUE est� en " << this->GetRoom()->name << endl;
}

void Grue::EatPlayer(Player * player)
{
	player->isDead = true;
	cout << GRUE_ATE_PLAYER << endl;
}
