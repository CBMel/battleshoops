#ifndef ROBOT_H
#define ROBOT_H
#include "Grid.h"
#include "Ships.h"
#include "Player.h"
class Robot : public Player {


private:
	int turns = 0; //not reeeally using
	vector<string>pastBoopsR;
	int sinked = 0;
public:
	void getShipsINFO();
	//Robot() { aship = ' '; }
	
	string genCoord(); //can be used in setships and also boop
	char genRandOrient();
	int numGen(int max);
	void setShips(Ships& shipObj, char shipLet);
	void attacc(Grid& human);
	int getSinked() { return sinked; }
		
	
	void moarSinked() { sinked++; }
		
	
	
	
};

#endif
