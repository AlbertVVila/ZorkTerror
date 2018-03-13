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
		" Hay polvo en la cama, parece que nadie ha dormido allí en meses.", "Te escondes debajo de la cama, nadie te puede ver.");
	Room *corridor = new Room("Pasillo", "Estás en un pasillo oscuro. La madera se estremece "
		"cada vez que das un paso.");
	Room *livingRoom = new Room("Sala de estar", "Estás en la sala de estar. Entra un poco de luz por la ventana"
		"parece que está anocheciendo.","Te escondes detrás del sofá, esperemos que nadie mire aquí.");
	Room *kitchen = new Room("Cocina","Estás en la cocina. Está todo desordenado.","Te escondes dentro de un armario.");
	Room *gameRoom = new Room("Sala de juegos", "Estás en la sala de juegos, hay un billar y una mesa con dos sillas"
		", con una partida de ajedrez a medias.", "Debajo del billar parece un buen sitio, te quedas allí en silencio.");
	Room *biblio = new Room("Biblioteca", "Parece una biblioteca, hay una estanteria muy grande con muchos libros, algunos estan por el suelo.");
	Room *out = new Room("Salida", "¡Has salido de la casa, eres libre!¡Corre Forest, corre!");
	Room *desvan = new Room("Desván", "Es un desván lleno de polvo.");

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
	Exit *exit2 = new Exit("Puerta", "","Al este hay una puerta entreabierta.",corridor, gameRoom, EAST,WEST);
	Exit *exit3 = new Exit("Estanteria", "Al este hay la entrada secreta de la biblioteca.", "Al oeste hay la entrada secreta de la biblioteca.", corridor, biblio, WEST, EAST,
		true, "Al oeste del pasillo hay un armario muy grande.");
	Exit *exit4 = new Exit("Puerta","Al sur de la habitación hay una puerta entreabierta.",
		"",corridor, bedroom, NORTH, SOUTH);
	Exit *exit5 = new Exit("puerta","", "¡La puerta de salida está desbloqueada!",livingRoom, out, EAST, WEST,
		false, "Al este hay una puerta que parece la de entrada a la casa, está cerrada con llave.",true);
	Exit *exit6 = new Exit("Cocina", "Al oeste se puede ver una cocina.", "Al este vemos el sofa de la sala de estar.", kitchen, livingRoom, EAST, WEST);
	Exit *exit7 = new Exit("Desván", "Por las escaleras vuelves a la sala de juegos.", "Hay las escaleras que llevan al desvan.", gameRoom, desvan, UP, DOWN , true,"");

	entities.push_back(exit1);
	entities.push_back(exit2);
	entities.push_back(exit3);
	entities.push_back(exit4);
	entities.push_back(exit5);
	entities.push_back(exit6);

	//AddItems

	Readable *mailBox = new Readable("carta", "Hay una pequeña carta en el borde de la cama.", bedroom, "¡Bienvenido al Zork Terror!\nTendrás "
	"que intentar escapar de esta casa sin que te coma el horrible monstruo que acecha en la oscuridad...");
	Readable *book = new Readable("book", "En el armario hay un libro, la biblia.", corridor, "¿Enserio te quieres poner a leer la biblia ahora?");
	book->setTrigger(exit3, "Al coger el libro, el armario se mueve y revela una entrada secreta a otra sala.","take");

	Item *exitKey = new Item("key", "Hay una llave en el suelo.",livingRoom);
	exitKey->setTrigger(exit5, "¡La cerradura encaja y desbloqueas la puerta!", "unlock");

	Item *painting = new Item("cuadro", "Hay un cuadro muy grande colgado en la pared, parece que de detrás del cuadro emana una corriente de aire.", gameRoom);
	painting->setTrigger(exit7, "Mueves el cuadro y aparecen unas escaleras sombrías.", "move");

	Container *baul = new Container("baul", "En la esquina de la habitación hay un baúl.", bedroom);
	Lightable *lamp = new Lightable("lamp", "Hay una lámpara en la mesita al lado de la cama.", bedroom);
	
	Item *rug = new Item("alfombra", "Hay una alfombra en el medio de la sala.", biblio);

	entities.push_back(mailBox);
	entities.push_back(book);
	entities.push_back(baul);
	entities.push_back(lamp);
	entities.push_back(exitKey);
	entities.push_back(rug);

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
		else if (args[0] == "inventory")
		{
			player->Inventory();
		}
		else if (args[0] == "hide")
		{
			player->Hide();
		}
		else if (args[0] == "reveal")
		{
			player->Reveal();
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
		else if (args[0] == "move")
		{
			player->Move(args);
		}
		else understand = false;
		break;
	case 3:
		if (args[0] == "turn")
		{
			player->Turn(args);
		}
		else understand = false;
		break;
	case 4:
		if (args[0] == "put")
		{
			player->Put(args);
		}
		else if(args[0] == "unlock")
		{
			player->Unlock(args);
		}
		else understand = false;
		break;
	default:
		understand = false;
		break;
	}
	return understand;
}

