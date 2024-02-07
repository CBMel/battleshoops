#include "Grid.h"
#include "Player.h"
#include "Ships.h"
#include <iostream>
#include <iomanip>
using namespace std;


Grid::Grid() { gridVec.resize(gridWid, vector<char>(gridLen, '~'));}

void Grid::printGrid() {

    cout << endl;
    int num = 0;
    cout << "   A B C D E F G H I J" << endl;
    //prints side labels and starts counter for i index of grid vector
    for (int i = 0; i < gridWid; i++) {
        num++;
        cout << left << setw(3) << num;
        //starts counter for j index of grid vector and prints grid 
        for (int j = 0; j < gridLen; j++) { cout << gridVec[i][j] << " "; }
          
        cout << endl;
    }
        /* for (int j = 0; j < gridLen; j++) {//don't think i need. 
             if (gridVec[i][j] == '~') { cout << "~" << " "; }//empty
             else if (gridVec[i][j] == 'W') { cout << "W" << " "; }//water wagon
             else if (gridVec[i][j] == 'B') { cout << "B" << " "; }//battleshoop
             else if (gridVec[i][j] == 'Z') { cout << "Z" << " "; }//zoomship
             else if (gridVec[i][j] == 'S') { cout << "S" << " "; }//sub
             else if (gridVec[i][j] == 'D') { cout << "D" << " "; }//doomship
             else if (gridVec[i][j] == '#') { cout << "#" << " "; }//miss
             else if (gridVec[i][j] == 'X') { cout << "X" << " "; }//hit
             else { cout << "~" << " "; }
        }cout << endl;}*/
}


bool Grid::spotFree(Ships& shipObject, char shipLetter, int x, int y) {
    bool emptySpot = false;
    //goes through the grid to check what the current character is. if it is anything but ~ then it
    //already has a ship placed in it and so another one can not be placed there. 
    if (shipObject.getOrientation() == 'H') {
        for (int i = 0; i < shipObject.getShipSize(); i++) {
            if ((x >= 0) && (x <= 9) && (y >= 0) && (y <= 9)) {
                //LEARNED GOING THROUGH [y][x] WAS THE ONLY WAY IT WOULD DO IT PROPERLY funfact
                if (gridVec[y][x] != '~') {//if the symbol is anything but ~
                    emptySpot = false;//means something is there, so not empty
                    return emptySpot;
                }
                else {
                    emptySpot = true;
                    y++;
                }
            }
        }
    }
    else if (shipObject.getOrientation() == 'V') {
        for (int i = 0; i < shipObject.getShipSize(); i++) {
            if ((x >= 0) && (y >= 0) && (x < 10) && (y < 10)) {
                if (gridVec[y][x] != '~') {//if the symbol is anything but ~
                    emptySpot = false;//means something is there, so not empty
                    return emptySpot;
                }
                else {
                    emptySpot = true;
                    x++;
                }
            }
        }
    }
    return emptySpot;
}

/**/
bool Grid::canPlace(Ships& shipObj, char shipLetter) {
    bool placeable = false;
    int size = shipObj.getShipSize();
    int x = shipObj.getX();
    int y = shipObj.getY();
    int endX = x + size;
    int endY = y + size;
    if ((endX <= 10) && (endY <= 10)) {
        if (shipObj.getOrientation() == 'H') {
            if (spotFree(shipObj, shipLetter, x, y)) {
                while (size > 0) {
                    gridVec[y][x] = shipLetter;
                    x++;
                    size--;
                }
                placeable = true;
            }
        }
        else if (shipObj.getOrientation() == 'V') {
            if (spotFree(shipObj, shipLetter, x, y)) {
                while (size > 0) {
                    gridVec[y][x] = shipLetter;
                    y++;
                    size--;
                }
                placeable = true;
            }
        }
    }
    return placeable;
}

bool Grid::isHit(int x, int y, string enemy,  Grid &grid) {
    Player player;
   
    
    //string shipLetters = "WBZSD";
    bool isHit = false;
    if ((gridVec[y][x] == 'W' || gridVec[y][x] == 'B' || gridVec[y][x] == 'Z' || gridVec[y][x] == 'S' || gridVec[y][x] == 'D' )
            && gridVec[y][x] != 'X' && gridVec[y][x] != '#'){
            isHit = true;
            char spot = shipLet(x, y, grid);
            cout << enemy << player.shipFullName(spot) << " got booped!" << endl;  //I AM ABLE TO USE THE FORBIDDEN VARIABLE HERE WHY NOT ANYWHERE ELSE D:
             /*if (gridVec[y][x] == 'W') {
                
            }*/
            
           
            player.gimmeThis(grid.gridVec[y][x]); //I WANT IT JUST GIMME
            cout << "THA PLAYAA GITS THE :" << player.itThis();
            //cout << "THA PLAYAA GITS THE :" << shipLet(x, y, grid) << endl;
            gridVec[y][x] = 'X';// x marks the spot
    }
    else {
        gridVec[y][x] = '#';// # means miss cause it looks like a splash
        isHit = false;
    }
    return isHit;
}

char Grid::shipLet(int x, int y, Grid &grid) { //returns the shipLetter of the grid index
    //TODO added grid object 
    char shipLetter = grid.gridVec[y][x];
    return shipLetter;
}

bool Grid::sameHit(int x, int y) {
    if (gridVec[y][x] == 'X' || gridVec[y][x] == '#')
        return true;
    else
        return false;
}
