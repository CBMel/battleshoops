#ifndef HUMAN_H
#define HUMAN_H
#include "Grid.h"
#include "Ships.h"
#include "Player.h"
#include "functions.h"
#include <fstream>

class Human : public Player {

private:
    int turns = 0;
    vector<string>pastBoopsH;
    int sinked = 0;

public:
   // Human() { aship = ' '; }
    void getShipsINFO();

    char orientCheck(string s);
    bool coordCheck(string s);
    string coordUpper(string s);
    char nameChange(string s);

    void attacc( Grid &robot);
    int getSinked() {
        return sinked;
    }
    void moarSinked() {
        sinked++;
    }
    void printBoopVec();//used for showing past guesses rather than using another grid
    
	
};

#endif
