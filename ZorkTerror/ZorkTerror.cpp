// ZorkTerror.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "World.h"

using namespace std;

int main()
{
	
	cout << "¡Bienvenid@ a Zork Terror\nUna versión de Zork ambientada en una casa abandonada." << endl;
	cout << "--------------------------------\n\n\n" << endl;
	string input;
	vector<string> args;
	bool playing = true;

	World house;

	//args.push_back("look");

	while (playing) //gameLoop
	{
		getline(cin,input);
		ParseInput(input,args);
		bool understand = house.GetInput(args);
		if (!understand && args.size()>0) cout << "No he entendido lo que dices" << endl;
		cout << endl;
		//if (args.size() == 1 && args[0] == "salir") playing = false;
		args.clear();
	}

	cout << "Hasta luegito!" << endl;
    return 0;
}

