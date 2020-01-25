//<CSIS 112-002 Lab 8 Christian Saunders> -- This program allows a user to play a game of battleship using X and Y coordinates input by
//the user.
//CSIS 112-<002>
//<C++ How to Program>,<In class project>,<CSIS 111 battleship program>

//NOTE:
//aareadme.txt file is in "Resource Files" AND is in the zipped folder submitted

//Include statements
#include <iostream>
#include <iomanip>
#include <array>
#include <fstream>
#include <string>
#include "Fleet.h"
#include "HitAgain.h"
#include "Miss.h"
#include "Strike.h"

using namespace std;

//Function prototypes

template <typename T>
T victory(T); 
void results(Fleet classIn); //Function used in conjunction with counter in Fleet class

int main()
{
	cout << "Christian Saunders -- Lab 8" << endl << endl;

	//Variable declarations
	Fleet f;
	string name;
	//Program logic
	
	cout << "Enter player name:" << endl;
	cin >> name;
	cout << endl;


	
	victory(f.Fire()); //Sets fleet into motion, also returns counter to victory()
	cout << " steps to win the game!" << endl;
	cout << "Congratulations " << name << "!" << endl;

	//Closing program statements
	system("pause");
	return 0;
}
//Function definitions
void results(Fleet classIn)
{
	
	cout << endl << "Congratulations!" << endl << "It took you "; //Victory!
	//cout << classIn;
	
}

template<typename T>
T victory(T in)
{
	T test = in;
	cout << endl << "Congratulations!" << endl << "It took you "; //Victory!
	return test;
}
