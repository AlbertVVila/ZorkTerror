#include "stdafx.h"
#include <iostream>
#include <string>
#include "World.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "spanish");
	cout << "¡Bienvenid@ a Zork Terror!\nUna versión de Zork ambientada en una casa abandonada." << endl;
	cout << "--------------------------------\n" << endl;
	string input;
	vector<string> args;
	bool playing = true;

	World house;


	while (playing) 
	{
		getline(cin,input);
		ParseInput(input,args);
		cout << endl;
		bool understand = house.GetInput(args);
		if (!understand && args.size()>0 && args[0] != "exit") cout << "No he entendido lo que dices" << endl;
		cout << endl;
		if (args.size() == 1 && args[0] == "exit") playing = false;
		args.clear();
	}

	cout << "Hasta luegito!" << endl;
    return 0;
}

