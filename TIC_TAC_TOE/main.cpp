#include <iostream>
#include "TicTacToeGame.h"

using namespace std;

int main()
{
    char input;
    bool isDone = false;
    //here is our game object
    TicTacToeGame game;

    //Outer Game Loop
    while (isDone == false) {
        //this plays a game of tic tac toe!
        game.playGame();
        // We have to see if they want to play again!
        cout << "Would you like to play again? (Y/N): ";
        cin >> input;
        if (input == 'N' || input == 'n') {
            isDone = true;
        }
    }

    system("PAUSE");
    return 0;
}
