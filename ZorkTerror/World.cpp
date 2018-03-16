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
#include "Grue.h"

World::World()
{
	//AddRooms
	Room *bedroom = new Room("Habitación principal", "Estás en la habitación principal."
		" Hay polvo en la cama, parece que nadie ha dormido allí en meses.", "Te escondes debajo de la cama, nadie te puede ver.");
	Room *corridor = new Room("Pasillo", "Estás en un pasillo oscuro. La madera se estremece "
		"cada vez que das un paso.");
	Room *livingRoom = new Room("Sala de estar", "Estás en la sala de estar. Todas las ventanas están bloqueadas, además casi no entra luz de fuera, "
		"parece que está anocheciendo.","Te escondes detrás del sofá, esperemos que nadie mire aquí.");
	Room *kitchen = new Room("Cocina","Estás en la cocina. Está todo desordenado. No hay ningún cuchillo ni ningún instrumento"
		" que pueda servir como arma. En el techo hay el número 6 escrito con lo que parece ser un líquido rojizo.","Te escondes dentro de la nevera.");
	Room *gameRoom = new Room("Sala de juegos", "Estás en la sala de juegos.", "Debajo del billar parece un buen sitio, te quedas allí en silencio.");
	Room *biblio = new Room("Biblioteca", "Parece una biblioteca, hay una estanteria muy grande con muchos libros, algunos estan por el suelo.");
	Room *out = new Room("out", "¡Has salido de la casa, eres libre!¡Corre Forest, corre! ¡Has Ganado!");
	Room *desvan = new Room("Desván", "Es un desván lleno de polvo. Hay un número 6 escrito con lo que parece ser sangre en el suelo.");
	Room *sotano = new Room("Sótano", "Estás en el sótano, hay un 6 escrito en una pared.");

	entities.push_back(bedroom);
	entities.push_back(corridor);
	entities.push_back(livingRoom);
	entities.push_back(kitchen);
	entities.push_back(gameRoom);
	entities.push_back(biblio);
	entities.push_back(desvan);
	entities.push_back(sotano);
	entities.push_back(out);

	//AddExits

	Exit *exit1 = new Exit("Escaleras","Las escaleras llevan al piso de arriba, estan muy oscuras.",
		"Hay unas escaleras que bajan, que llevan a la penumbra, cuidado que no te coma un grue.",
		corridor, livingRoom, DOWN, UP);
	Exit *exit2 = new Exit("puertajuegos", "","Al este hay una puerta entreabierta.",corridor, gameRoom, EAST,WEST,false,"",false, OPENED);
	Exit *exit3 = new Exit("Estanteria", "Al este hay la entrada secreta de la biblioteca.", "Al oeste hay la entrada secreta de la biblioteca.", corridor, biblio, WEST, EAST,
		true, "Al oeste del pasillo hay un armario muy grande.");
	Exit *exit4 = new Exit("puertahabitacion","Al sur de la habitación hay una puerta entreabierta.",
		"",corridor, bedroom, NORTH, SOUTH, false,"La puerta de salida está cerrada", false, OPENED);
	Exit *exit5 = new Exit("puertasalida","", "¡La puerta de salida está desbloqueada!",livingRoom, out, EAST, WEST,
		false, "Al este hay una puerta que parece la de entrada a la casa,"
		" está cerrada, se ven 4 cerraduras, parece que se necesitaran 4 llaves para abrirla.",true, CLOSED, true);
	Exit *exit6 = new Exit("Cocina", "Al oeste se puede ver una cocina.", "Al este vemos el sofá de la sala de estar.", kitchen, livingRoom, EAST, WEST);
	Exit *exit7 = new Exit("Desván", "Por las escaleras vuelves a la sala de juegos.", "Hay las escaleras que llevan al desván.", gameRoom, desvan, UP, DOWN , true,"");
	Exit *exit8 = new Exit("trampilla", "", "Hay una trampilla que no se ve muy bien donde lleva.\nParece que si se baja no se puede volver a subir por el mismo sitio.", biblio, sotano, DOWN, UP,
		true, "El suelo parece hueco, como si hubiera alguna cosa debajo.",false, CLOSED, true);
	Exit *exit9 = new Exit("puertasotano", "Las escaleras suben y vuelven a la sala de estar.", "Una puerta baja al sótano.",
		livingRoom, sotano, DOWN, UP, false, "La puerta que va al sótano está atascada.", true,CLOSED);

	entities.push_back(exit1);
	entities.push_back(exit2);
	entities.push_back(exit3);
	entities.push_back(exit4);
	entities.push_back(exit5);
	entities.push_back(exit6);
	entities.push_back(exit7);
	entities.push_back(exit8);
	entities.push_back(exit9);

	//AddItems

	//Bedroom items
	Readable *carta = new Readable("carta", "Hay una pequeña carta en el borde de la cama.", bedroom, "¡Bienvenido al Zork Terror!\nTendrás "
	"que intentar escapar de esta casa sin que te coma el horrible monstruo que acecha en la oscuridad...", "Hay una carta.");	
	Container *baul = new Container("baul", "En la esquina de la habitación hay un baúl.", bedroom);
	Item *cama = new Item("cama", "", bedroom, STATIC);
	Lightable *linterna = new Lightable("linterna", "Hay una linterna encima de la cama.", bedroom, "¡Una linterna! Eso siempre va bien.");

	entities.push_back(carta);
	entities.push_back(baul);
	entities.push_back(cama);
	entities.push_back(linterna);

	//Corridor items
	Item *armario = new Item("armario", "", corridor, FIX);	
	Readable *biblia = new Readable("biblia", "En el armario hay un libro, la biblia.", corridor, "¿Enserio te quieres poner a leer la biblia ahora?", "Hay una sagrada biblia." );
	biblia->setTrigger(exit3, "Al desplazar el libro, el armario se mueve y revela una entrada secreta a otra sala.","coger");

	entities.push_back(armario);
	entities.push_back(biblia);

	//Biblio items

	Lightable *lampara = new Lightable("lampara", "Hay una lámpara en la mesita al lado de la cama.", biblio);
	Readable *libros = new Readable("libros", "Hay muchos libros en esta biblioteca, la mayoria muy antiguos.", biblio, "Demasiados libros y demasiada pereza...");
	Item *estanteria = new Item("estanteria", "", biblio, FIX);
	Item *mesa = new Item("mesa", "Hay una mesa muy grande en el centro de la sala.", biblio, STATIC);
	Item *exitKey = new Item("llave", "¡Hay una llave en la mesa!", biblio, COMMON,"¡Una llave para salir! ¡Deberia estar en mi inventario!");
	exitKey->setTrigger(exit5, "¡La cerradura encaja y desbloqueas la puerta!", "desbloquear");
	Item *rug = new Item("alfombra", "Hay una alfombra en el medio de la sala.", biblio, STATIC);
	rug->setTrigger(exit8, "Al desplazar la alfombra, aparece una trampilla cerrada, ¿A dónde llevará?","mover");

	entities.push_back(lampara);
	entities.push_back(libros);
	entities.push_back(estanteria);
	entities.push_back(mesa);
	entities.push_back(exitKey);
	entities.push_back(rug);

	//Kitchen items
	Container *nevera = new Container("nevera", "Hay una nevera bastante grande en una esquina de la cocina.", kitchen);
	Item *mesa2 = new Item("mesa", "Hay una mesa muy grande en el centro de la sala.", kitchen, STATIC);
	Container *cajon = new Container("cajon", "Hay varios cajones bloqueados, pero hay uno que parece que se pueda abrir.", kitchen);
	Item *exitKey2 = new Item("llave", "¡Hay una llave en la mesa!", kitchen, COMMON, "¡Mi llave, mi tesoro...!");
	exitKey2->setTrigger(exit5, "¡La cerradura encaja y desbloqueas la puerta!", "desbloquear");
	Item *cadaver = new Item("cadaver", "¡Hay un cadáver de una mujer, descomponiéndose!", nevera, STATIC);
	Readable *nota = new Readable("nota", "Una nota está enganchada a la nevera" , kitchen, "Encienda la luz solo cuando sea estrictamente necesario, sino él te verá...", "Hay una pequeña nota.");
	Item *tornavis = new Item("destornillador", "Parece ser que hay un destornillador dentro.", cajon, COMMON, "Un destornillador, nunca se sabe cuando puede hacer falta.");
	tornavis->setTrigger(exit9, "Con el destornillador y un poco de fuerza bruta, se desbloquea la puerta.", "desbloquear");

	entities.push_back(nevera);
	entities.push_back(mesa2);
	entities.push_back(cajon);
	entities.push_back(exitKey2);
	entities.push_back(nota);
	entities.push_back(tornavis);

	//GameRoom items

	Item *painting = new Item("cuadro", "Hay un cuadro muy grande colgado en la pared, parece que de detrás del cuadro emana una corriente de aire.", gameRoom, COMMON, "¿Que hace un cuadro en el suelo? No se juega con el arte.");
	painting->setTrigger(exit7, "Al desplazar el cuadro aparecen unas escaleras sombrías.", "mover");
	Item *tablero = new Item("tablero", "Hay un tablero de ajedrez con una partida a medias.", gameRoom, COMMON, "Hay un tablero, que lástima, la partida se echó a perder...");
	Item *billar = new Item("billar", "Hay un billar pero no hay ninguna bola, que lástima, era un gran momento para echar una partidita.", gameRoom, STATIC);
	
	entities.push_back(painting);
	entities.push_back(tablero);
	entities.push_back(billar);

	//Roof items
	Container *safe = new Container("cajafuerte", "Hay una pequeña caja fuerte que requiere una combinación de 3 números para desbloquearse.", desvan, true, "666");
	Item *exitKey3 = new Item("llave", "¡Hay una llave!", safe, COMMON,"Hay una llave para dominarlos a todooos.");
	exitKey3->setTrigger(exit5, "¡La cerradura encaja y desbloqueas la puerta!", "desbloquear");
	Item *doll = new Item("muneca", "Una muñeca estrambótica nos está mirando a los ojos, espero que no se mueva.",desvan, COMMON,
		"Una muñeca parece que te esté mirando todo el rato.");
	Item *ventanal = new Item("ventanal", "Un ventanal da a la calle, la verdad es que no se ve casi nada con la oscurida que reina fuera."
		" El ventanal es demasiado pequeño como para salir.", desvan, FIX);

	entities.push_back(exitKey3);
	entities.push_back(doll);
	entities.push_back(ventanal);
	entities.push_back(safe);

	//Sótano items
	Item *exitKey4 = new Item("llave", "Hay una llave en el suelo.",sotano);
	exitKey4->setTrigger(exit5, "¡La cerradura encaja y desbloqueas la puerta!", "desbloquear");

	Item *ventana = new Item("ventana", "Hay una ventana abierta, pero está bloqueada y no tiene pinta que se vaya a abrir más.",sotano, FIX);
	Item *rata = new Item("rata", "Ahhh, que asco, hay una rata muerta en una esquina.", sotano, COMMON, "RIP rata.");
	
	entities.push_back(exitKey4);
	entities.push_back(ventana);
	entities.push_back(rata);

	//LivingRoom
	Item *sofa = new Item("sofa", "Una sofa de mimbre se encuentra en el lateral de la sala.",livingRoom, STATIC);
	Item *tv = new Item("television","En frente del sofa tenemos una televisión.",livingRoom, STATIC);
	Item *mesita = new Item("mesita","Al lado de la televisión hay una mesita llena de polvo.",livingRoom, STATIC);
	Readable *revista = new Readable("revista","Hay una revista de monstruos nocturnos sobre la mesita", livingRoom, 
		"El Grue es un monstruo que vive en la oscuridad. Con garras afiladas y unos colmillos enormes, muy poca gente ha visto un Grue y "
		"ha vivido para contarlo...", "Hay una revista.");

	entities.push_back(sofa);
	entities.push_back(tv);
	entities.push_back(mesita);
	entities.push_back(revista);

	//Add player	
	player = new Player(PLAYER_NAME, "¡Eres muy valiente y no temes la oscuridad!", bedroom);
	
	entities.push_back(player);

	//AddGrue
	grue = new Grue("Grue", "¡HAY ALGUIEN AQUI! ", sotano);
	entities.push_back(grue);
	//init
	player->Look();
}


bool World::GetInput(const vector<string>& args)
{
	bool understand = true;
	if (player->isDead)
	{
		cout << PLAYER_DEAD << endl;
	}
	else if (player->won)
	{
		cout << PLAYER_WON << endl;
	}
	else if (player->isHiding && 
		(args[0] == "coger"
		|| args[0] == "ir"
		|| args[0] == "mover"
		|| args[0] == "abrir"
		|| args[0] == "cerrar"
		|| args[0] == "poner"
		|| args[0] == "desbloquear"
		|| args[0] == "leer"
		|| args[0] == "encender"
		|| args[0] == "apagar"))
	{
		cout << PLAYER_HIDING << endl;
	}
	else
	{
		switch (args.size())
		{
		case 1:
			if (args[0] == "mirar")
			{
				player->Look();
			}
			else if (args[0] == "inventario")
			{
				player->Inventory();
			}
			else if (args[0] == "esconder")
			{
				player->Hide();
			}
			else if (args[0] == "revelar")
			{
				player->Reveal();
			}
			else if (args[0] == "esperar")
			{
				cout << WAITING << endl;
			}
			else if (args[0] == "suicidarme")
			{
				player->isDead = true;
				cout << PLAYER_SUICIDE << endl;
			}
			else understand = false;
			break;
		case 2:
			if (args[0] == "ir")
			{
				player->Go(args);
			}
			else if (args[0] == "coger")
			{
				player->Take(args);
			}
			else if (args[0] == "tirar")
			{
				player->Drop(args);
			}
			else if (args[0] == "leer")
			{
				player->Read(args);
			}
			else if (args[0] == "abrir")
			{
				player->Open(args);
			}
			else if (args[0] == "cerrar")
			{
				player->Close(args);
			}
			else if (args[0] == "mover")
			{
				player->Move(args);
			}
			else if (args[0] == "encender")
			{
				player->Encender(args);
			}
			else if (args[0] == "apagar")
			{
				player->Apagar(args);
			}
			else understand = false;
			break;
		case 3:
			if(args[0] == "desbloquear")
			{
				player->Unlock(args);
			}
			else understand = false;
			break;
		case 4:
			if (args[0] == "poner")
			{
				player->Put(args);
			}
			else if (args[0] == "desbloquear")
			{
				player->Unlock(args);
			}
			else understand = false;
			break;
		default:
			understand = false;
			break;
		}
	}
	//turno para Grue
	if (!player->isDead || player->won)
	{
		grue->Look();
		grue->Go();
	}

	return understand;
}

