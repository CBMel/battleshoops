#ifndef GRID_H
#define GRID_H
#include "Ships.h"
#include <vector>
#include <string>
using namespace std;

class Grid {

protected:

public:
	vector<vector<char>>gridVec;

	static const int gridLen = 10;
	static const int gridWid = 10;
	void printGrid();
	Grid();

	bool canPlace(Ships& shipObj, char shipLetter);
	bool spotFree(Ships& shipObj, char shipLetter, int x, int y);
	bool isHit(int x, int y, string enemy, Grid& grid);
	char shipLet(int x, int y, Grid &grid);
	bool sameHit(int x, int y);
};

#endif

