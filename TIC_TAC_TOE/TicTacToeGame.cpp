#include "TicTacToeGame.h"
#include <iostream>

using namespace std;

//Constructor, ours does nothing :P
TicTacToeGame::TicTacToeGame()
{
}

//The game!
void TicTacToeGame::playGame()
{
    clearBoard();

    char player1 = 'X';
    char player2 = 'O';

    char currentPlayer = player1;
    bool isDone = false;

    int x, y;

    int turn = 0;

    //Inner game loop
    while (isDone == false) {

        //Print out the board each time we loop
        printBoard();

        //Get the coordinates of where the user wants to place a marker
        x = getXCoord();
        y = getYCoord();

        //Try to place a marker
        if (placeMarker(x, y, currentPlayer) == false) {
            //If we failed to place a marker, tell him he failed!
            cout << "That spot is occupied!\n";
        } else {
            //Otherwise, we successfully did this turn!
            turn++;
            //See if the player won!
            if (checkForVictory(currentPlayer) == true) {
                //He won!
                cout << "The game is over! Player " << currentPlayer << " has won!\n";
                isDone = true;
            } else if (turn == 9) {
                //Tie game!
                cout << "Its a tie game!\n";
                isDone = true;
            }

            // Switch players
            if (currentPlayer == player1) {
                currentPlayer = player2;
            } else {
                currentPlayer = player1;
            }
        }
    }
}



int TicTacToeGame::getXCoord()
{
    bool isInputBad = true;

    int x;

    while (isInputBad == true) {
        cout << "Enter the X coordinate: ";
        cin >> x;

        if (x < 1 || x > 3) {
            cout << "Invalid Coordinate!\n";
        } else {
            isInputBad = false;
        }
    }
    return x - 1;
}

int TicTacToeGame::getYCoord()
{
    bool isInputBad = true;

    int y;

    while (isInputBad == true) {
        cout << "Enter the Y coordinate: ";
        cin >> y;

        if (y < 1 || y > 3) {
            cout << "Invalid Coordinate!\n";
        } else {
            isInputBad = false;
        }
    }
    return y - 1;
}

bool TicTacToeGame::placeMarker(int x, int y, char currentPlayer)
{
    if (board[y][x] != ' ') {
        return false;
    }

    board[y][x] = currentPlayer;
    return true;
}

bool TicTacToeGame::checkForVictory(char currentPlayer)
{
    //Check the rows
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == currentPlayer) && (board[i][0] == board[i][1]) && (board[i][1] == board[i][2])) {
            return true; //We won!
        }
    }

    //Check the columns
    for (int i = 0; i < 3; i++) {
        if ((board[0][i] == currentPlayer) && (board[0][i] == board[1][i]) && (board[1][i] == board[2][i])) {
            return true; //We won!
        }
    }

    //Check top left diagonal
    if ((board[0][0] == currentPlayer) && (board[0][0] == board[1][1]) && (board[1][1] == board[2][2])) {
        return true; //We won!
    }

    //Check top right diagonal
    if ((board[2][0] == currentPlayer) && (board[2][0] == board[1][1]) && (board[1][1] == board[0][2])) {
        return true; //We won!
    }

    return false;
}

void TicTacToeGame::clearBoard()
{
    //Empties the board
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void TicTacToeGame::printBoard()
{
    //ugly formatting yay
    cout << endl;
    cout << " |1 2 3|\n";
    for (int i = 0; i < 3; i++) {
        cout << " -------\n";
        cout << i+1 << "|" << board[i][0] << "|" << board[i][1] << "|" << board[i][2] << "|\n";
    }
    cout << " -------\n";
}
