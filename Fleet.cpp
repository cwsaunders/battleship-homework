//Most of the implementation of this program is throughout this class
//Other classes are used for polymorphism
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <array>
#include <iomanip>
#include "Fleet.h"
#include "Miss.h"
#include "Strike.h"
#include "HitAgain.h"

using namespace std;

void Fleet::hitOrMiss() const
{
	//This function is for polymorphism
}

ostream& operator<<(std::ostream& output, Fleet& fleet) //Used to return number of moves required to win game
{
	output << fleet.getCounter();
	return output;
}





bool Fleet::FleetSunk(char **myArray)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (myArray[i][j] == '#')
				return 1;
		}
	}
	return 0;
}
int Fleet::Fire()
{
	const int row = 25;
	const int col = 25;
	int x;
	int y;
	ifstream battleshipIn;
	srand(25);
	Fleet f;
	Miss m;
	Strike s;
	HitAgain h;
	//int counter = 0;
	array < array<char, col>, row> playerOcean; //Use of array class to create 2D array

	Fleet * mPtr = &m;
	Fleet * sPtr = &s;
	Fleet * hPtr = &h;



	

	for (int i = 0; i < row; i++) 
	{
		for (int j = 0; j < col; j++)
		{
			playerOcean[i][j] = '~';
			cout << playerOcean[i][j] << " ";
		}
		cout << endl;
	}
	//***********************
	//Error handling:
	try {
		battleshipIn.open("battleship.txt");
	}
	catch (...)
	{
		cerr << "Error opening file!" << endl; //Error message
	}
	//************************



	//************************************
	//Code from announcements edited to have char types
	char **myArray;
	myArray = new char*[col];

	//Error handling:
	try {
		for (int i = 0; i < row; i++)
			myArray[i] = new char[col];

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				battleshipIn >> myArray[i][j];
				//cout << myArray[i][j] << " ";
			}
			//cout << endl;
		}
		//*************************************
	}
	catch (...)
	{
		cerr << "Dynamic array failed!" << endl; //Error message
	}


	for (; FleetSunk(myArray) == 1;)
	{
		cout << endl << "Enter your Y coordinate (Enter 0 to choose randomized number):" << endl; //Prompt
		cin >> y;
		while (cin.fail() || y>25 || y<0)
		{
			cout << "Input must be an integer:" << endl; //Error message
			cin.clear();
			cin.ignore(10000, '\n');
			cin >> y;
		}
		if (y == 0)
		{
			y = rand() % 25 + 1;
		}
		cout << "Enter your Y coordinate (Enter 0 to choose randomized number):" << endl; //Prompt
		cin >> x;
		while (cin.fail() || x>25 || x<0)
		{
			cout << "Input must be an integer:" << endl; //Error message
			cin.clear();
			cin.ignore(10000, '\n');
			cin >> x;
		}
		if (x == 0)
		{
			x = rand() % 25 + 1;
		}

		x = x - 1;
		y = y - 1;

		++counter;

		//Edit player ocean
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (myArray[i][j] == '~')
				{
					playerOcean[i][j] = myArray[i][j];
				}
				if (myArray[i][j] == 'H')
				{
					myArray[i][j] = myArray[i][j];
				}
				if (myArray[i][j] == '#')
				{
					playerOcean[i][j] = '~';
				}
			}
		}

		//Response message
		if (myArray[y][x] == 'H')
		{
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					cout << playerOcean[i][j] << " ";
				}
				cout << endl;
			}
			hPtr->hitOrMiss();
			cout << endl;
		}
		if (myArray[y][x] == '~')
		{
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					cout << playerOcean[i][j] << " ";
				}
				cout << endl;
			}
			mPtr->hitOrMiss();
			cout << endl;
		}
		if (myArray[y][x] == '#')
		{
			myArray[y][x] = 'H';
			playerOcean[y][x] = 'H'; //player hit hidden && player board
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					cout << playerOcean[i][j] << " ";
				}
				cout << endl;
			}
			sPtr->hitOrMiss();
			cout << endl;
		}

	}
	if (FleetSunk(myArray) == 0)
	{
		cout << "The fleet was destroyed!" << endl; //Victory message!
		delete[] myArray; //De-allocates myArray array
		return counter;
	}


}