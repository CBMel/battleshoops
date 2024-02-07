#ifndef SHIPS_H
#define SHIPS_H
//#include "Player.h"
#include <string>
#include <iostream>
using namespace std;

class Ships { 
protected:

	string shipName;
	char shipLetter;
	int shipSize = 0;
	string coordinate;
	int x, y;
	char orientation = ' ';

	int boopCounter = 0;

	//char aship = ' ';

public:
	//bool isSunk(); //not using yet

	//gets and sets
	Ships() {}//default
	Ships(string ship_name, char ship_letter, string coord, int _x, int _y, int size, char orient);

	string getShipName();
	void setShipName(string _shipName);

	char getShipLetter();
	void setShipLetter(char _shipLetter);

	int getShipSize();
	void setShipSize(int _shipSize);

	int getX();
	void setX(int _x);

	int getY();
	void setY(int _y);

	string getCoordinate();
	void setCoordinate(string _coord);

	char getOrientation();
	void setOrientation(char _orientation);
	/*
	char itThis();
	void gimmeThis(char thing);
	*/


};

#endif