// ZorkTerror.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "World.h"
using namespace std;

int main()
{
	
	cout << "Welcome to ZorkTerror!\nA version of Zork ambiented in an abandoned house." << endl;
	cout << "--------------------------------\n\n\n" << endl;
	string input;
	World house;
	//house.GetInput("look");

	while (1)
	{
		getline(cin,input);
		if (input == "quit") break;
		if (house.GetInput(input) == false)
			cout << "Sorry, I don't understand what you said" << endl;

	}

	cout << "GG WP, Cya!" << endl;
    return 0;
}

