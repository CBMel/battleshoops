#include "Player.h"
#include "Grid.h"
#include "Ships.h"


int Player::establishSize(char c) {
	int size = 0;
	if (c == 'W') { size = 5; }
	else if (c == 'B') { size = 4; }
	else if (c == 'Z') { size = 3; }
	else if (c == 'S') { size = 3; }
	else if (c == 'D') { size = 2; }
	return size;
}

string Player::shipFullName(char c) {
	string shipName;
	if (c == 'W') { shipName = "Water Wagon"; }
	else if (c == 'B') { shipName = "Battleshoop"; }
	else if (c == 'Z') { shipName = "Zoomship"; }
	else if (c == 'S') { shipName = "Submersible Vessel"; }
	else if (c == 'D') { shipName = "Destructo Boat"; }
	else {
		cout << " Invalid ship, please check your file." << endl;
	}

	return shipName;
}

//this replaces all those charToInt functions you see all the time with way less lines.
int Player::coordConvert(char c) {
	int num = 0;
	num = ((int)c - 65);
	return num;
}

//pass by reference to save data stored in the grid
//because player has a Grid object called grid
Grid& Player::getGrid() { return grid; }

void Player::setShips(Ships& shipObj, char shipLet) {
	//checks if it's placeable on grid
	if (grid.canPlace(shipObj, shipLet)) { cout << shipObj.getShipName() << " has been placed on the grid" << endl; }

		
	
	else { cout << shipObj.getShipName() << " cannot be placed" << endl; }
		
	
}
//reads in Char Int coordinate, converts to Int Int returns Int Int string 
string Player::convBoop(string s) {
	string booping = s; //post conversion -> grid position
	char c1 = ((int)booping[0]);
	booping[0] = (int)(c1 - 16);
	return booping;
}

//if string isnt same as vector stuff then they havent booped it
bool Player::notBooped(string s, vector<string>& XBoops) {
	bool notBooped = false;
	string numCoord = convBoop(s);
	int _x = (int)s[0] - '0';
	int _y = (int)s[1] - '0';
	for (int i = 0; i < XBoops.size(); i++) {
		//if string isnt same as vector stuff
		if (s != XBoops.at(i)) {
			XBoops.push_back(s);
			//then they havent booped it
			notBooped = true; 
		}
	}
	return notBooped;
}

//this will make sure that just 5 hits in general won't win the game but that one hit 
//at least per ship wins the game
bool Player::sinkEm(char s) {

	bool wagonSunk = false; bool battleSunk = false;
	bool zoomSunk = false; bool subSunk = false;
	bool destructoSunk = false;
	bool allSunk = false;

	if (s == 'W'){ wagonSunk = true; }
		
	else if (s == 'B'){ battleSunk = true; }
		
	else if (s == 'Z'){ zoomSunk = true; }
		

	else if (s == 'S'){ subSunk = true; }
		

	else if (s == 'D'){ destructoSunk = true; }
		

	if (wagonSunk && battleSunk && zoomSunk && subSunk && destructoSunk){ allSunk = true; }
		
	return allSunk;
}/**/

char Player::itThis() { return aship; }
void Player::gimmeThis(char thing) { aship = thing; }
	

