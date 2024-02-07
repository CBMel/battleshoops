#include "Human.h"
#include "Grid.h"
#include "Ships.h"
#include "Player.h"
#include "functions.h"
#include "Robot.h"


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <stdexcept>



void Human::getShipsINFO() {
	ifstream inFile;
	inFile.open("ship_placement.csv");
	string fileLine; //stores whole line to be separated
	string shipT, coordT, orientT;
	bool shipCheck = false; bool placed = false;
	//variables used for setting ship objects
	int size = 0; int _x = 0; int _y = 0;
	string fullShip; string fullCoord;
	char ship, orient;

	//calls .fail() to test for an error during input operation
	//if inFile fails to operate properly //error is printed //and program exits
	if (inFile.fail()) {
		cerr << "ERROR: No input file detected\n";
		exit(1);
	}
	else {
		//this area is storing the data from the file into a line, then separating those lines into separate variables. 
		while (getline(inFile, fileLine)) {
			stringstream data(fileLine);
			getline(data, shipT, ',');
			ship = nameChange(shipT);

			placementVecH.push_back(ship);

			getline(data, coordT, ',');
			coordT = coordUpper(coordT);//making sure the coordinates are uppercase
			char c1 = coordT[0];	//B 
			char c2 = coordT[1];  //2

			int numCoordinate1 = coordConvert(c1);//changed (b) to the number equivalent
			char changeChar1 = (int)(c1 - 16); // put a char version of that int into the placement vec (so that it could be tested by the goodShips function)
			int numCoord2 = (int)coordT[1] - '0';//changes (2) into int 2 

			if (coordCheck(coordT)) {
				placementVecH.push_back(changeChar1);
				placementVecH.push_back(coordT[1]);
			}

			getline(data, orientT);
			orient = orientCheck(orientT);
			orient = toupper(orient); //making orientation uppercase
			placementVecH.push_back(orient);
			placementVecH.push_back(' ');

			size = establishSize(ship);
			fullShip = shipFullName(ship);


			_x = numCoordinate1;
			_y = numCoord2 - 1;
			fullCoord = coordT;

			if (ship == 'W') {
				Ships WW(fullShip, ship, fullCoord, _x, _y, size, orient);
				water_wagon = WW;
			}
			else if (ship == 'B') {
				Ships B(fullShip, ship, fullCoord, _x, _y, size, orient);
				battleshoop = B;
			}
			else if (ship == 'Z') {
				Ships Z(fullShip, ship, fullCoord, _x, _y, size, orient);
				zoomship = Z;
			}
			else if (ship == 'S') {
				Ships S(fullShip, ship, fullCoord, _x, _y, size, orient);
				sub = S;
			}
			else if (ship == 'D') {
				Ships D(fullShip, ship, fullCoord, _x, _y, size, orient);
				destructo = D;
			}
			else { cout << "Invalid ship" << endl; }
				
		}
		placementVecH.pop_back(); //getting rid of last space

		cout << endl;
		inFile.close();

		setShips(water_wagon, 'W');
		setShips(battleshoop, 'B');
		setShips(zoomship, 'Z');
		setShips(sub, 'S');
		setShips(destructo, 'D');
	}
}
//coordinate to check the validity of a user-input orientation
char Human::orientCheck(string s) {
	//doing it this way allowed better chance to change to uppercase WHILE checking for invalid char.
	char orient;
	//EXCEPTION HANDLING FOR ORIENTATION IN FILE
	try {
		if ((s[0] == 'v') || (s[0] == 'V')) { return  'V'; }

		else if ((s[0] == 'h') || (s[0] == 'H')) { return 'H'; }

		else { cout << "Invalid Orientation" << endl; }	
	}
	//INVALID ARGUMENT EXCEPTION
	catch (const invalid_argument& ia) { cerr << "Invalid Orientation in File ERROR:" << ia.what() << "\n"; }
	//return orient;
}
//function to check the validity of a user-input coordinate
bool Human::coordCheck(string s) {
	//coord can only be 2 characters
	//EXCEPTION HANDLING
	try{
		if (s.length() > 3) {
			cout << "Invalid Coordinates : Bad Length" << endl;
			return false;	
		}
		// has to be A-J and 0-9   
		else if ((s[0] >= 'A' && s[0] <= 'J') && (s[1] >= '0' && s[1] <= '9')) { return true; }
		else {
			cout << "Invalid Coordinates" << endl;
			return false;
		}
	}
	catch (const std::out_of_range& oor) { cerr << "Input Coordinates Out of Range ERROR: " << oor.what() << '\n'; }
}
//makes sure the letter coordinate is uppercase
string Human::coordUpper(string s) {
	for (int i = 0; i < s.length(); i++) {
		char c = s[0];
		//calls toupper() to manipulate letter stores back in c
		if (islower(c) != 0) {c = toupper(c);}
		s[0] = c;
	}
	return s;
}
//changes "normal" battleship names from input file to the "battleshoops" ship letters WBZSD 
//also checks validity of the input
char Human::nameChange(string s) {
	
	char shipNames[5][11] = { "carrier", "battleship", "cruiser", "submarine", "destroyer" };
	char newName;
	//EXCEPTION HANDLING for SHIP in file
	try{
		for (int i = 0; i < s.length(); i++) {
			char c = s[i];

			//calls tolower() to manipulate letter stores back in c2
			if (isupper(c) != 0) {c = tolower(c);} //this is for consistency so i don't have to worry about what they capitalize
			s[i] = c;
		}

		//changing names to grid representations
		//counter (5 ships)
	
		for (int i = 0; i <= 5; i++) {
		
			if (s == shipNames[0]) { newName = 'W'; }// "Water Wagon"
		
			else if (s == shipNames[1]) { newName = 'B'; }// "Battleshoop"
		
			else if (s == shipNames[2]) { newName = 'Z'; }//"Zoomship" 
		
			else if (s == shipNames[3]) { newName = 'S'; }// "Submersible Vessel"
		
			else if (s == shipNames[4]) { newName = 'D'; }// "Destructo Boat"
		
		}
		//INVALID ARGUMENT exception
	} catch (const invalid_argument& ia) { cerr << "Invalid Ship Name in File ERROR:" << ia.what() << "\n"; }
	
	//function returns the letter associated with the new game-specific ship name
	return newName;
}

//function for user (human) to take shots at computer (robot)'s shoops
void Human::attacc(Grid& robot) {
	Human human;//DO I USE THIS?
	Player player;//DO I USE THIS?
	Ships shop;
	bool coordGood = false;
	bool emptySpot = false;
	string shoot; string shootT;
	Robot rObot;

	//prints list of the human's previous guesses rather than on the grid
	//when in 1234 mode, they can see past guesses just on the robot grid though
	printBoopVec(); 

	cout << "Where would you like to boop?" << endl;
	cout << "Example: A1" << endl;
	cin >> shootT;;
	
	shoot = coordUpper(shootT);
	coordGood = coordCheck(shoot);
	

	if (coordGood) {
		if (HBoops.size() == 0) {
			emptySpot = true;
			//makes sure that the pop_back down there doesn't get rid of this one
			HBoops.push_back(shoot); HBoops.push_back(shoot);
			
		}
		for (int i = 0; i < HBoops.size(); i++) {
			//if string isnt same as vector stuff
			if (shoot != HBoops.at(i)) {
				HBoops.push_back(shoot);
				//then they havent booped it
				emptySpot = true;
			}
			//keeps previous guesses list from adding random duplicates
			if (HBoops.size() > turns && HBoops.size() != 0) { HBoops.pop_back();}
				
			
		}
		if (emptySpot) {
			//same converty stuff as everywhere else
			char c1 = shoot[0]; char c2 = shoot[1];
			int numCoord2 = (int)shoot[1] - '0';
			int _x = coordConvert(c1);
			int _y = numCoord2 - 1;
			//if they boop the same spot as they've booped before
			if (robot.sameHit(_x, _y)) {
				cout << "You booped there already.. try to not do that next time!" << endl;
				cin.clear();
				attacc(robot);
			}
			if (robot.isHit(_x, _y, "ROBOT ", robot)) {//checks if ship is hit
				moarSinked();

				char letter = human.itThis(); //THIS DOESN'T WORK YET
				cout << "this is player.itThis" << player.itThis()<< endl;
				cout <<"this is aship in human" << aship << endl;
				cout << "this is shop.itThis" << rObot.itThis() << endl;
				cout << "H: it this  " << letter << itThis();//for deleting

				if (sinkEm(letter)) {//human wins
					goodJob();//prints cute you win thing to screen
					exit(0);//goodbye
				}
			}
			else if (!robot.isHit(_x, _y, "ROBOT ", robot)) { cout << "You Missed! You will get it next time!" << endl; }
		}
		turns++;
	}
}
void Human::printBoopVec() {
	if (HBoops.size() > 0) {
		cout << "\n ==================================== " << endl;
		cout << "Here is a list of your past guesses:" << endl;
		for (int i = 0; i < HBoops.size(); i++) {
			cout << HBoops.at(i) << endl;
		}
		cout << " ==================================== " << endl;
	}
}



