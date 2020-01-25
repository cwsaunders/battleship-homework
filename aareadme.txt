Christian Saunders battleship program information:

how program works:
This program uses user input of a Y and X input to strike hits on a board. The original board shown to the user is a blank (all ~'s) version.
As the user takes hits at the ~'s it will either display "Miss" or "hit" depending on whether they hit a boat (#) or not. Once a user gets a
hit on a boat the wave (~) turns into an "H". If a user hits an "H" it displays "hit again" You also have the option of selecting "0" for 
the Y and/or X coordinate which will use the rand() function to select a random integer between 1 and 25

how to use it:
the program will ask you first to input a Y coordinate, and then an X coordinate. Once you input those two integers (or use the random
integer) it will strike the player board. Once you hit all the boats the program will tell you how many hits it took you to win the game.


how it behaves (technical specs):
The program uses all of the lab requirements:
1.	Classes: Fleet, HitAgain, Miss, and Strike.
2.	Inheritance: All derived classes inherit from Fleet.
3.	Polymorphism: hitOrMiss() function in all classes is virtual (polymorphic)
4.	Random number generators: Fire() function in the Fleet class gives the user an option to choose a random integer between 1 and 25.
5.	Pointers: Used in polymorphism in Fleet class Fire() function.
6.	Double pointers: Used to create behind-the-scenes array in Fleet class.
7.	The array class: Used to create player board in Fleet class.
8.	Operator overloading: Overloaded "<<" operator in Fleet. 
9.	Templates: Used in BattleShipDriver file to accept and return counter from Fleet class.
10.	File processing: Used in Fleet class to recieve information for the board to place boats or waves.
11.	Exception handling: Used throughout Fire() function

Summary:
Fleet is called from driver program which uses a two dimensional array from the array class to constantly update the user as each strike takes
place. The behind-the-scenes dynamic array is used to keep track of all boats and waves from the battleship.txt file. As the user slowly
hits each boat (#) the player board shows "H" where the hit boat is. At the end the counter shows how many moves it took to win the game.

