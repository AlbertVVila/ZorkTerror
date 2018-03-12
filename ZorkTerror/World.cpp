#include "stdafx.h"
#include "World.h"
#include "Entity.h"
#include "Room.h"
#include "Creature.h"
#include "Player.h"
#include "Exit.h"
#include "Item.h"
#include "Container.h"
#include "Readable.h"
World::World()
{
	//Create rooms
	Room *bedroom = new Room("Habitación principal", "Estás en la habitación principal."
		" Hay polvo en la cama, parece que nadie ha dormido allí en meses.");
	Room *corridor = new Room("Pasillo", "Estás en un pasillo oscuro. La madera se estremece "
		"cada vez que das un paso.");
	Room *livingRoom = new Room("Sala de estar", "Estás en la sala de estar. Entra un poco de luz por la ventana"
		"parece que está anocheciendo.");
	Room *kitchen = new Room("Cocina","Estás en la cocina. Está todo desordenado.");
	Room *gameRoom = new Room("Sala de juegos", "Estás en la sala de juegos, hay un billar y una mesa con dos sillas"
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
	Exit *exit4 = new Exit("Puerta","Al sur de la habitación hay una puerta entreabierta.",
		"",corridor, bedroom, NORTH, SOUTH);
	Exit *exit5 = new Exit("Puerta de la casa","Al este hay una puerta que parece la de entrada a la casa", "",livingRoom, out, EAST, WEST);
	Exit *exit6 = new Exit("Cocina", "Al oeste se puede ver una cocina.", "Al este vemos el sofa de la sala de estar.", kitchen, livingRoom, EAST, WEST);


	entities.push_back(exit1);
	entities.push_back(exit2);
	entities.push_back(exit3);
	entities.push_back(exit4);
	entities.push_back(exit5);
	entities.push_back(exit6);

	//AddItems

	Item *mailBox = new Readable("Carta", "Hay una pequeña carta en el borde de la cama.", bedroom, "¡Bienvenido al Zork Terror!\nTendrás "
	"que intentar escapar de esta casa sin que te coma el horrible monstruo que acecha en la oscuridad...");
	Item *baul = new Container("Baul", "En la esquina de la habitación hay un baúl.", bedroom);
	entities.push_back(mailBox);
	entities.push_back(baul);
	//Create player
 	player = new Player("Player", "¡Eres muy valiente y no temes la oscuridad!", bedroom);
	entities.push_back(player);
}


World::~World()
{
}

bool World::GetInput(const vector<string>& args)
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
		}
		else if (args[0] == "take")
		{
			player->Take(args);
		}
		else if (args[0] == "drop")
		{
			player->Drop(args);
		}
		else if (args[0] == "read")
		{
			player->Read(args);
		}
		else if (args[0] == "open")
		{
			player->Open(args);
		}
		else if (args[0] == "close")
		{
			player->Close(args);
		}
		else understand = false;
		break;
	case 4:
		if (args[0] == "put")
		{
			player->Put(args);
		}
		else understand = false;
		break;
	default:
		understand = false;
		break;
	}
	return understand;
}

