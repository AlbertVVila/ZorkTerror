#ifndef __Globals__
#define __Globals__

#include <string>
#include <vector>
#include <iostream>

#define ITEM_NOTFOUND "¡No exite este item!"
#define ITEM_NOTCONTAINABLE "¡No puedes meter esto en este item!"
#define ITEM_NOTTAKEABLE "¡No puedes coger este ítem!"
#define ITEM_NOTFOUND_ININVENTORY "¡No tienes este ítem en tu inventario!"
#define CONTAINER_NOTFOUND "¡No existe ese contenedor!"
#define ITEM_PUT "Hecho."
#define ITEM_NOTREADABLE "¿Cómo pretendes leer este ítem?"
#define ITEM_ALREADY_OPENED "¡Este ítem ya está abierto!"
#define ITEM_ALREADY_CLOSED "¡Este ítem ya está cerrado!"
#define ITEM_NONE_STATE "No entiendo como quieres abrir esto."
#define ITEM_OPENED "Contenedor abierto."
#define ITEM_CLOSED "Contenedor cerrado."
#define INVENTORY "Inventario:"
#define EMPTY_INVENTORY "Inventario vacio."
#define ITEM_ALREADY_ON "¡Ya está encendido!"
#define ITEM_ALREADY_OFF "¡Ya está apagado!"
#define ITEM_ON "Y la luz se hizo."
#define ITEM_OFF "Y la luz se fue."
#define ITEM_NOT_LIGHTABLE "No entiendo como lo quieres hacer."
#define ITEM_TAKEN "Ítem cogido."
#define ITEM_DROPPED "Ítem tirado."
#define ITEM_ISCLOSED "Primero hay que abrir el contenedor."
#define ITEM_ALREADY_TAKEN "¡Ya llevas este ítem encima!"
#define CONTAINER_CLOSED "No puedes coger ese ítem ya que está en un contenedor cerrado."

#define WRONG_DIRECTION "No se puede ir en esa dirección."

#define CANNOT_HIDE "¡No hay ningun lugar para esconderse!"
#define ALREADY_HIDING "Shhhht, ya estás escondido."
#define ALREADY_REVEALED "No estás escondido, no se que intentas."
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


