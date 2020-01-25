#pragma once
#include <iostream>
#include <string>


class Fleet
{
	const int row = 25;
	const int col = 25;
	int counter = 0; //returned with operator overloading and also 

public:

	Fleet() = default; //Default constructor && destructor
	int Fire();
	bool FleetSunk(char **);
	int getRow() const{ return row; }
	int getCol() const { return col; }
	int getCounter() { return counter; }
	friend std::ostream& operator<<(std::ostream&, const Fleet&); //<< Operator overloading to return counter (moves to win)
	virtual void hitOrMiss() const;
	~Fleet() = default;
};