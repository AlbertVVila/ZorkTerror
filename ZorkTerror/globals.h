#ifndef __Globals__
#define __Globals__

#include <string>
#include <vector>
#include <iostream>

#define ITEM_NOTFOUND "¡No exite este item!"
#define ITEM_NOTCONTAINABLE "¡No puedes meter esto en este item!"
#define CONTAINER_NOTFOUND "¡No existe ese contenedor!"
#define ITEM_PUT "Hecho."
#define ITEM_NOTREADABLE "¿Cómo pretendes leer este ítem?"
#define ITEM_ALREADY_OPENED "¡Este ítem ya está abierto!"
#define ITEM_ALREADY_CLOSED "¡Este ítem ya está cerrado!"
#define ITEM_NONE_STATE "No entiendo como quieres abrir esto."
#define ITEM_OPENED "Item abierto."
#define ITEM_CLOSED "Item cerrado."
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
	COMMON, CONTAINER, READABLE, WEAPON, USABLE
};

enum ItemState
{
	OPENED,CLOSED,NONE
};
void ParseInput(string input, vector<string> &args);
direction ConvertToDir(const string &dir);
string ConvertToString(const direction &dir);
#endif // __Globals__


