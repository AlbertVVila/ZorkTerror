#ifndef __Globals__
#define __Globals__

#include <string>
#include <vector>
#include <iostream>

#define ITEM_NOTFOUND "�No exite este item!"
#define ITEM_NOTCONTAINABLE "�No puedes meter esto en este item!"
#define ITEM_NOTTAKEABLE "�No puedes coger este �tem!"
#define ITEM_NOTFOUND_ININVENTORY "�No tienes este �tem en tu inventario!"
#define ITEM_PUT "Hecho."
#define ITEM_NOTREADABLE "�C�mo pretendes leer este �tem?"
#define ITEM_ALREADY_OPENED "�Este �tem ya est� abierto!"
#define ITEM_ALREADY_CLOSED "�Este �tem ya est� cerrado!"
#define ITEM_NONE_STATE "Ya me dir�s t� como lo haces."
#define ITEM_OPENED "Contenedor abierto."
#define ITEM_CLOSED "Contenedor cerrado."
#define ITEM_ALREADY_ON "�Ya est� encendido!"
#define ITEM_ALREADY_OFF "�Ya est� apagado!"
#define ITEM_ON "Y la luz se hizo."
#define ITEM_OFF "Y la luz se fue."
#define ITEM_NOT_LIGHTABLE "No entiendo como lo quieres hacer."
#define ITEM_TAKEN "�tem cogido."
#define ITEM_DROPPED "�tem tirado."
#define ITEM_ISCLOSED "Primero hay que abrir el contenedor."
#define ITEM_ALREADY_TAKEN "�Ya llevas este �tem encima!"

#define EXIT_LOCKED_NOTFOUND "No encuentro lo que quieres desbloquear."
#define EXIT_ISCLOSED "La salida est� cerrada, tienes que abrirla primero."
#define EXIT_NOTLOCKED "�Esta salida no est� bloqueada!"
#define EXIT_ALREADY_CLOSED "�La salida ya est� cerrada!"
#define EXIT_ALREADY_OPENED "�La salida ya est� abierta!"
#define EXIT_NOT_CLOSABLE "�Esto no se puede cerrar!"
#define EXIT_NOT_OPENABLE "�Esto no se puede abrir!"
#define EXIT_CLOSED "�Hecho!"
#define EXIT_OPENED "�Hecho!"
#define EXIT_LOCKED "No puedes abrir esta salida ya que est� bloqueada."
#define EXIT_DOOR_OPENED "�Has desbloqueado la puerta principal! ��Huye!!"

#define ENTITY_NOTUNLOCKABLE "�A que te refieres con desbloquear esto?"
#define ENTITY_NOTMOVABLE "�C�mo lo pretendes mover?"
#define ENTITY_NOTFOUND "No se a que te refieres."

#define UNLOCKER_NOTFOUND "�No tienes el �tem necesario para desbloquear!"

#define CONTAINER_NOTFOUND "�No existe ese contenedor!"
#define CONTAINER_CLOSED "No puedes coger ese �tem ya que est� en un contenedor cerrado."
#define CONTAINER_NOTLOCKED "No est� bloqueado."
#define CONTAINER_UNLOCKED "�Y se abri�!"
#define CONTAINER_LOCKED "Est� bloqueado con c�digo."
#define WRONG_CODE "Este c�digo no funciona."

#define WRONG_DIRECTION "No se puede ir en esa direcci�n."

#define CANNOT_HIDE "�No hay ningun lugar para esconderse!"
#define ALREADY_HIDING "Shhhht, ya est�s escondido."
#define ALREADY_REVEALED "No est�s escondido, no se que intentas."
#define REVEALED "Has salido de tu escondite, ve con cuidado."

#define INVENTORY "Inventario:"
#define EMPTY_INVENTORY "Inventario vacio."

#define MOVING_HAS_NOEFFECT "Movido."
#define MOVING_NOEFFECT_INVENTORY "�Cu�l es el objetivo de mover algo que llevas encima?"

#define PLAYER_HIDING "Est�s escondido y no puedes realizar esta acci�n."
#define PLAYER_NAME "player"
#define PLAYER_DEAD "Lo siento, est�s muerto. �Gracias por jugar! Para salir escribe exit."

#define BLACK_ROOM "No ves absolutamente nada, est� muy oscuro."

#define GRUE_ATE_PLAYER "��Se te comi� el Grue!!"
#define GRUE_NOTSEEN_PLAYER "�Vaya suerte! �El Grue no te ha visto!"
#define GRUE_IN_PLAYERROOM "�Cuidado! �El Grue est� en la misma sala que tu!"
#define NB_KEYS 4
#define NOT_ENOUGH_KEYS "No tienes todas las llaves necesarias para desbloquear la puerta."

#define WAITING "El tiempo pasa.."
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
	COMMON, CONTAINER, READABLE, WEAPON, LIGHTABLE, STATIC, FIX
};

enum State
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
