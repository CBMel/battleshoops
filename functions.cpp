#include "functions.h"

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

void prettyBattleship() {

    cout << "                                                 w e l c o m e   t o " << endl << endl;
    cout << "                                                    [#]        (o)   " << endl;
    cout << "                                                    /|\\   vs   /|\\   " << endl;
    cout << "                                                    / \\        / \\   " << endl << endl;

    cout << "                                                   BATTLESHOOPS < 3  " << endl;
}

int gameMode() {
    bool instructor_mode = false; bool hard_mode = false;
    int cheatCode;
    cout << "                                               Enter Cheat Code Here: ";
    cin >> cheatCode;
    if (cheatCode == 1234) {
        instructor_mode = true;
        cout << endl;
        cout << "                                                 Instructor Mode : ENABLED" << endl << endl;
        //this will print robot grids each round
    }
    else {
        cout << endl;
        cout << "                                                   Game Mode: Normal" << endl << endl;
    }
    return cheatCode;
}

int printRules() {
    int fileInfo;
    int rulesResponse;
    cout << "                                           I will be playing BATTLESHOOPS with you!                           " << endl;
    cout << "                                     Before we play, you must know the RULES of the game!                     " << endl << endl;
    cout << " my name is                                         R  U  L  E  S  :D                                         " << endl;
    cout << "   ROBOT     ===============================================================================================  " << endl;
    cout << "             + We each have 5 shoops:                                                                         " << endl;
    cout << "                 WATER WAGON(5), BATTLESHOOP(4), ZOOMSHIP(3), SUBMERSIBLE VESSEL(3), and DESTRUCTO BOAT(2)    " << endl;
    cout << "                                                                                                              " << endl;
    cout << "     !       + Before the game started, you uploaded a FILE to the game folder for your ship placement        " << endl;
    cout << "    [#]           - if you did not, please end the program and do that now.                                   " << endl;
    cout << "    /|\\                                                                                                      " << endl;
    cout << "    / \\      + Once our shoops are placed we will take turns guessing coordinates to BOOP each others SHOOPS " << endl;
    cout << "                                                                                                              " << endl;
    cout << "             + The last player left with SHOOPS left un-BOOPed WINS!                                          " << endl;
    cout << "             ===============================================================================================  " << endl << endl;
 
    cout << "  Do you need to know more about the input file?        " << endl;
    cout << "                 1 --> Yes please " << endl;
    cout << "                 2 --> No thanks  " << endl;
    cin >> fileInfo;
    if (fileInfo == 1) { 
        cout << "                       Here is some more information about the input file!                                            " << endl << endl;
        cout << "                               I  N  P  U  T       F  I  L  E    <3                                                   " << endl;
        cout << "      ====================================================================================                            " << endl;
        cout << "      + Your file must be named:    ship_placement.csv                                              EXAMPLE:          " << endl;
        cout << "                                                                                             ----------------------   " << endl;
        cout << "      + Your file should include:   comma-separated data with NO HEADERS about where you    |  ship_placement.csv  |  " << endl;
        cout << "                                    want your ships to be placed on the BATTLESHOOPS grid   |   no        headers  |  " << endl;
        cout << "      + What it means:                                                                      | Carrier,B2,H         |  " << endl;
        cout << "              -ship name     -->    which ship you are placing                              | Battleship,D4,V      |  " << endl;
        cout << "              -coordinate    -->    where on the grid you want the ship to start            | Cruiser,G4,H         |  " << endl;
        cout << "              -orientation   -->    whether you want the ship going H or V:                 | Submarine,G5,V       |  " << endl;
        cout << "                                     (V) Up and Down     (H) Side to Side          [#]      | Destroyer,G8,H       |  " << endl;
        cout << "                                                                                   /|\\      ----------------------   " << endl;
        cout << "      + Please use the TRADITIONAL names for battleships in your file              / \\                               " << endl;
        cout << "      ====================================================================================                            " << endl << endl;
        cout << "         Are you ready to move forward?" << endl;
        cout << "             1 --> Yes! :D" << endl;
        cout << "             2 --> No!  " << endl;
        cin >> rulesResponse;
    }
    else{ 
        cout << "         Wonderful, so you will follow the rules?" << endl;
        cout << "                 1 --> Yes! " << endl;
        cout << "                 2 --> No, maybe next time." << endl;
        cin >> rulesResponse;
    }

    return rulesResponse;
}
void goodJob() {
    cout << "      G A M E    O V E R " << endl;
    cout << "  You won!    " << endl;
 
    cout << "                  " << endl;
    cout << "    (o)                   " << endl;
    cout << "    /|\\        /|\\      " << endl;
    cout << "    / \\        / \\  [x]    " << endl;
    cout << "                  " << endl;
    cout << "      Good job, Bye!  " << endl;
   //"At the end of the game, you should indicate the game is over and who the winner was. "
    
}
 