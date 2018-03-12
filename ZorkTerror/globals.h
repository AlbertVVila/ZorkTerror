#ifndef __Globals__
#define __Globals__

#include <string>
#include <vector>
#include <iostream>

#define ITEM_NOTFOUND "�No exite este item!"
#define ITEM_NOTCONTAINABLE "�No puedes meter esto en este item!"
#define ITEM_NOTTAKEABLE "�No puedes coger este �tem!"
#define ITEM_NOTFOUND_ININVENTORY "�No tienes este �tem en tu inventario!"
#define CONTAINER_NOTFOUND "�No existe ese contenedor!"
#define ITEM_PUT "Hecho."
#define ITEM_NOTREADABLE "�C�mo pretendes leer este �tem?"
#define ITEM_ALREADY_OPENED "�Este �tem ya est� abierto!"
#define ITEM_ALREADY_CLOSED "�Este �tem ya est� cerrado!"
#define ITEM_NONE_STATE "No entiendo como quieres abrir esto."
#define ITEM_OPENED "Contenedor abierto."
#define ITEM_CLOSED "Contenedor cerrado."
#define INVENTORY "Inventario:"
#define EMPTY_INVENTORY "Inventario vacio."
#define ITEM_ALREADY_ON "�Ya est� encendido!"
#define ITEM_ALREADY_OFF "�Ya est� apagado!"
#define ITEM_ON "Y la luz se hizo."
#define ITEM_OFF "Y la luz se fue."
#define ITEM_NOT_LIGHTABLE "No entiendo como lo quieres hacer."
#define ITEM_TAKEN "�tem cogido."
#define ITEM_DROPPED "�tem tirado."
#define ITEM_ISCLOSED "Primero hay que abrir el contenedor."
#define ITEM_ALREADY_TAKEN "�Ya llevas este �tem encima!"
#define CONTAINER_CLOSED "No puedes coger ese �tem ya que est� en un contenedor cerrado."

#define WRONG_DIRECTION "No se puede ir en esa direcci�n."

#define CANNOT_HIDE "�No hay ningun lugar para esconderse!"
#define ALREADY_HIDING "Shhhht, ya est�s escondido."
#define ALREADY_REVEALED "No est�s escondido, no se que intentas."
#define REVEALED "Has salido de tu escondite, ve con cuidado."

using namespace std;
enum direction
{
	NORTH,SOUTH,WEST,EAST,UP,DOWN,UNKNOWN
};
enum Entitytype
{
	PLAYER, EXIT, ROOM, ITEM, GRUE, ENTITY
};
enum Itemtype
{
	COMMON, CONTAINER, READABLE, WEAPON, LIGHTABLE
};

enum ItemState
{
	OPENED,CLOSED,NONE
};
enum ItemSwitch
{
	ON,OFF
};
void ParseInput(string input, vector<string> &args);
direction ConvertToDir(const string &dir);
string ConvertToString(const direction &dir);
#endif // __Globals__


