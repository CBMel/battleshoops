#include "Ships.h"
#include "Player.h"
#include <iostream>
#include <vector>
using namespace std;




Ships::Ships(string ship_name, char ship_letter, string coord, int _x, int _y, int size, char orient) {
	shipName = ship_name;
	shipLetter = ship_letter;
	coordinate = coord;
	x = _x;
	y = _y;
	shipSize = size;
	orientation = orient;
	
}

string Ships::getShipName() { return shipName; }
void Ships::setShipName(string _shipName) {
	shipName = _shipName;
}

char Ships::getShipLetter() { return shipLetter; }
void Ships::setShipLetter(char _shipLetter) { shipLetter = _shipLetter; }
	


int Ships::getShipSize() { return shipSize; }
void Ships::setShipSize(int _shipSize) { shipSize = _shipSize; }
	


int Ships::getX() { return x; }
void Ships::setX(int _x) { x = _x; }
	


int Ships::getY() { return y; }
void Ships::setY(int _y) { y = _y; }
	


string Ships::getCoordinate() { return coordinate; }
void Ships::setCoordinate(string _coord) { coordinate = _coord; }
	


char Ships::getOrientation() { return orientation; }
void Ships::setOrientation(char _orientation) { orientation = _orientation; }
	
/*
char Ships::itThis() { return aship; }
void Ships::gimmeThis(char thing) {
	aship = thing;
}*/