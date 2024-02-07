#include "Robot.h"
#include "Grid.h"
#include "Ships.h"
#include "Player.h"
#include "functions.h"
#include "Human.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

/**/
void Robot::getShipsINFO() {
	srand(time(NULL)); //KEEP THIS HERE. 

	bool shipCheck = false;
	string fullCoord;
	char c1 = ' ';
	char c2 = ' ';
	int n1 = 0;
	int n2 = 0;

	fullCoord = genCoord();
	c1 = fullCoord[0]; c2 = fullCoord[1];
	n1 = (coordConvert(c1));
	n2 = (int)c2 - '0';

	Ships WW("Water Wagon", 'W', fullCoord, n1, n2, 5, genRandOrient());
	water_wagon = WW;
	setShips(water_wagon, 'W');

	fullCoord = genCoord();
	c1 = fullCoord[0]; c2 = fullCoord[1];
	n1 = (coordConvert(c1));
	n2 = (int)c2 - '0';

	Ships B("Battleshoop", 'B', fullCoord, n1, n2, 4, genRandOrient());
	battleshoop = B;
	setShips(battleshoop, 'B');

	fullCoord = genCoord();
	c1 = fullCoord[0]; c2 = fullCoord[1];
	n1 = (coordConvert(c1));
	n2 = (int)c2 - '0';

	Ships Z("Zoomship", 'Z', fullCoord, n1, n2, 3, genRandOrient());
	zoomship = Z;
	setShips(zoomship, 'Z');

	fullCoord = genCoord();
	c1 = fullCoord[0]; c2 = fullCoord[1];
	n1 = (coordConvert(c1));
	n2 = (int)c2 - '0';

	Ships S("Submersible Vessel", 'S', fullCoord, n1, n2, 3, genRandOrient());
	sub = S;
	setShips(sub, 'S');

	fullCoord = genCoord();
	c1 = fullCoord[0]; c2 = fullCoord[1];
	n1 = (coordConvert(c1));
	n2 = (int)c2 - '0';

	Ships D("Destructo Boat", 'D', fullCoord, n1, n2, 2, genRandOrient());
	destructo = D;
	setShips(destructo, 'D');
}

char Robot::genRandOrient() {
	char orient = ' ';

	int num = numGen(4);//changing to 4 just made it a little more random.. better output
	if (num == 0 || num == 2) { orient = 'H'; }
	else if (num == 1 || num == 3) { orient = 'V'; }

	return orient;
}

string Robot::genCoord() {

	string validLCoords = "ABCDEFGHIJ";
	string validNCoords = "123456789";
	string coord = "  ";

	// pick a random letter and set as first char in string
	coord[0] = validLCoords[numGen(9)];
	coord[1] = validNCoords[numGen(9)];

	return coord;
}

int Robot::numGen(int max) {
	//generates random number bt 1 and 10
	int num;

	num = (rand() % (max + 0));
	return num;
}

void Robot::setShips(Ships& shipObj, char shipLet) {
	
	if (!grid.canPlace(shipObj, shipLet)) {
		shipObj.setX(numGen(10));
		shipObj.setY(numGen(10));
		setShips(shipObj, shipLet);
	}
}

/**/
void Robot::attacc(Grid& human) {
	Human hUman; //NEED???
	Ships shop; //NEED???
	Player player; //NEED???
	int _x = numGen(9);
	int _y = numGen(9);

	if (human.isHit(_x, _y, "HUMAN ", human)) {//checks if ship is hit
		//TODO changed shipLet funcs to gridvec for char calls//DELETE @CLEANUP
		//moarSinked();//DELETE @CLEANUP
		//cout << "ROBOT'S SINKED " << sinked << endl;//DELETE @CLEANUP
		char letter = player.itThis();
		//cout << "R: it this  " << letter << itThis();//DELETE @CLEANUP
		if(sinkEm(letter)){
			cout << endl << endl << endl << endl;
			cout << "  G A M E      O V E R  " << endl;
			cout << "        lol i win\n          GG EZ  " << endl;
			//"At the end of the game, you should indicate the game is over and who the winner was. "
			exit(0);
		}
	}
	else { cout << "Aww, I missed! XD " << endl; }
		
	
	turns++;//DELETE @CLEANUP if dont need
}

