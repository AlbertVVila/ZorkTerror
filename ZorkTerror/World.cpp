#include "stdafx.h"
#include "World.h"
#include "Entity.h"
#include "Room.h"
#include "Creature.h"
#include "Player.h"
#include "Exit.h"
World::World()
{
	//Create rooms
	Room *bedroom = new Room("Habitaci\242n principal", "Est\240s en la habitaci\242n principal."
		" Hay polvo en la cama, parece que nadie ha dormido all\241 en meses.");
	Room *corridor = new Room("Pasillo", "Est\240s en un pasillo oscuro. La madera se estremece "
		"cada vez que das un paso.");
	Room *livingRoom = new Room("Sala de estar", "Est\240s en la sala de estar. Entra un poco de luz por la ventana"
		"parece que est\240 anocheciendo.");
	Room *kitchen = new Room("Cocina","Est\240s en la cocina. Est\240 todo desordenado.");
	Room *gameRoom = new Room("Sala de juegos", "Est\240s en la sala de juegos, hay un billar y una mesa con dos sillas"
		", con una partida de ajedrez a medias.");
	Room *biblio = new Room("Biblioteca", "Parece una biblioteca, hay una estanteria muy grande con muchos libros, algunos estan por el suelo.");
	Room *out = new Room("Salida", "¡Has salido de la casa, eres libre!¡Corre Forest, corre!");
	//AddRooms
	entities.push_back(bedroom);
	entities.push_back(corridor);
	entities.push_back(livingRoom);
	entities.push_back(kitchen);
	entities.push_back(gameRoom);

	//AddExits

	Exit *exit1 = new Exit("Escaleras","Las escaleras llevan al piso de arriba, estan muy oscuras.",
		"Hay unas escaleras que bajan, que llevan a la penumbra, cuidado que no te coma un grue.",
		corridor, livingRoom, DOWN, UP);
	Exit *exit2 = new Exit("Puerta", "","",corridor, gameRoom, EAST,WEST);
	Exit *exit3 = new Exit("Estanteria", "", "Al oeste del pasillo hay un armario muy grande.", corridor, biblio, WEST, EAST);
	Exit *exit4 = new Exit("Puerta","Al sur de la habitaci\242n hay una puerta entreabierta.",
		"",corridor, bedroom, NORTH, SOUTH);
	Exit *exit5 = new Exit("Puerta de la casa","Al este hay una puerta que parece la de entrada a la casa", "",livingRoom, out, EAST, WEST);
	Exit *exit6 = new Exit("Cocina", "Al oeste se puede ver una cocina.", "Al este vemos el sofa de la sala de estar.", kitchen, livingRoom, EAST, WEST);


	entities.push_back(exit1);
	entities.push_back(exit2);
	entities.push_back(exit3);
	entities.push_back(exit4);
	entities.push_back(exit5);
	entities.push_back(exit6);

	//Create player
 	player = new Player("Player", "¡Eres muy valiente y no temes la oscuridad!", bedroom);
	entities.push_back(player);
}


World::~World()
{
}

bool World::GetInput(const vector<string> &args)
{
	bool understand = true;
	switch (args.size())
	{
	case 1:
		if (args[0] == "look")
		{
			player->Look(args);
		}
		else understand = false;
		break;
	case 2:
		if (args[0] == "go")
		{
			player->Go(args);
		}else understand = false;
		break;
	default:
		understand = false;
		break;
	}
	return understand;
}
