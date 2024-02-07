#include <iostream>
#include <fstream>
#include "functions.h"
#include "Grid.h"
#include "Human.h"
#include "Robot.h"
#include "Ships.h"
using namespace std;
//use cheatcode 1234 for instructor mode 
int main() {

    cout << "                                                   Hello HUMAN! :D" << endl << endl;
    prettyBattleship();
    int mode = gameMode(); //could even write it into the switch.. actual different program for each mode

    int menuSelection;
    int rulesAns = printRules();
    if (rulesAns == 1) {
        cout << endl;
        cout << "                                               ==============" << endl;
        cout << "                                                 1 --> PLAY  " << endl;
        cout << "                                                             " << endl;
        cout << "                                                 2 --> EXIT  " << endl;
        cout << "                                               ==============" << endl;
        cin >> menuSelection;

        switch (menuSelection) {
        case 1: {
            Grid example;
            Grid humanShips; Grid robotShips; 
            Grid humanBoops; Grid robotBoops;
            //in beginning, user is instructed that the file MUST be called "ship_placement.csv".
            ifstream inFile("ship_placement.csv");

            cout << "We are going to have a great time XD" << endl;

            //printing each human grid

            example.printGrid();
            cout << "Here is what the grids will look like!" << endl;

            Human human;
            human.getShipsINFO();
            human.getGrid().printGrid();
            humanShips = human.getGrid();

            cout << " ====================== " << endl;
            cout << "    YOUR shoops grid    " << endl;
            cout << " ====================== " << endl;

            Robot robot;
            robot.getShipsINFO();
            robot.getGrid();
            

            if (mode == 1234) {
                robotShips = robot.getGrid();
                /*	You do not need to have 4 grids for this but if you decide to use only two grids, 
                you need to make sure you do not show the player the computer’s ship location when you display the grid after each turn.*/
                
                robotShips.printGrid();

                cout << " ====================== " << endl;
                cout << " This is MY shoops grid " << endl;
                cout << " You see it because you " << endl;
                cout << " are in instructor mode " << endl;
                cout << " ====================== " << endl;

            }
            
            
            //next up we begin booping
            bool gameOver = false;
            //Player humanPlayer; Player robotPlayer;

            while (gameOver == false) {
                Player player;//do i use this

                char fun_o_meter;//used for user quitting - if user quits gameOver
                
               
                human.attacc(robotShips);
                humanShips.printGrid();
                if (mode == 1234) { robotShips.printGrid(); }

                    
                
               
                robot.attacc(humanShips);
                
                bool someoneWon = false;//does this get used?

                do{
                cout << endl << "                   !!IMPORTANT!!                    " << endl;
                cout << "------------------------------------------------------------" << endl;
                cout << "| Are you still having fun? Would you like to keep playing? |" << endl;
                cout << "|              Enter P to keep playing                      |" << endl;
                cout << "|              Enter Q to quit.                             |" << endl;
                cout << "------------------------------------------------------------" << endl;
                //"You should also allow the user to quit the game by entering a Q when prompted for their next guess. "
                cin >> fun_o_meter;
                } while (fun_o_meter != 'P' && fun_o_meter != 'Q');
                
                if (fun_o_meter == 'Q' ) { 
                    robotShips.printGrid();
                    cout << " ====================== " << endl;
                    cout << " This is MY shoops grid " << endl;
                    cout << " You see it because you " << endl;
                    cout << " are quitting the game! " << endl;
                    cout << " ====================== " << endl;

                    human.printBoopVec();
                    cout << " ====================== " << endl;
                    cout << " These were all of the  " << endl;
                    cout << "   guesses you made!    " << endl;
                    cout << "   You were so close!   " << endl;
                    cout << " ====================== " << endl;
                    //"If a player decides to quit the game, the grid with all of their guessesand the locations of the computer’s ships should be displayed."

                    gameOver = true;
                    cout << "Wow that was fun, see you later!" << endl;
                }   
            }
            break;
        }
        case 2: {
            //EXIT
            cout << "We will try to play again another time! \nGoodbye!  <3 ";
            exit(0);
            break;
        }
        default: {
            cout << "That was not even one of the options!" << endl;
            cout << "I think what you are being is a ""goof ball"" :) " << endl;
            cout << "Please go back and enter 1 to PLAY or 2 to EXIT!" << endl;
            break;
        }
        }
    }
    else if (rulesAns == 2) {
        cout << "I guess we will try again next time!" << endl;
        cout << "See you later!  <3 " << endl;
        exit(0);
    }
    else {
        cout << "That was not really one of the choices..." << endl;
        cout << "If you did not read those, how do I know you read the rules, silly!" << endl;
        cout << "I know you will do better next time! " << endl;
        exit(0);
    }
    //end function here
}