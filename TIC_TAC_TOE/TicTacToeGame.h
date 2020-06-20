#pragma once
class TicTacToeGame
{
public:
    //Constructor
    TicTacToeGame();

    //This plays the game
    void playGame();

private:

    //Gets input from the user
    int getXCoord();
    int getYCoord();
    //Places a marker. If it returns false, it couldnt place!
    bool placeMarker(int x, int y, char currentPlayer);

    //Returns true if the current player won!
    bool checkForVictory(char currentPlayer);

    //Empties the board
    void clearBoard();
    // Prints the board
    void printBoard();

    //This stores the board state
    char board[3][3];
};
