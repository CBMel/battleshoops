#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <iostream>

using namespace std;

#include "Ships.h"
#include "Grid.h"

class Player : public Ships, public Grid {

protected:

    Ships water_wagon;
    Ships battleshoop;
    Ships zoomship;
    Ships sub;
    Ships destructo;

    Grid grid;

    vector<char>placementVecR;
    vector<char>placementVecH;
    vector<string>HBoops;
    vector<string>RBoops;// do i use?
    char aship = ' '; //GET THIS TO WORK

public:
    Player() {}
    Player(char thing) { aship = thing ; }
    //PASSING BY REFERENCE HERE MIGHT HELP SAVE THE DATA TO THE ACTUAL VECTOR
    int establishSize(char c);
    string shipFullName(char c);
    int coordConvert(char c);
    Grid& getGrid();
    void setShips(Ships& shipObj, char shipLet);
    string convBoop(string s);
    bool notBooped(string s, vector<string> &pastBoopsX);
    void boopCounting(Grid& grid, char ship);

    char itThis();// {return aship; }
    void gimmeThis(char thing);/* {
        aship = thing;
    }*/
    bool sinkEm(char s);
};


#endif
