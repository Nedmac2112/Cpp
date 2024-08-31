// Camden K., 8/22/24, cckirkpatrick@dmacc.edu
// Tic Tac Toe game

#include <iostream>
using namespace std;

// Added Function to check if there's a winner
bool checkWin(const char board[], char mark)
{
    // Check rows
    for (int i = 0; i < 9; i += 3)
    {
        if (board[i] == mark && board[i + 1] == mark && board[i + 2] == mark)
            return true;
    }

    // Check columns
    for (int i = 0; i < 3; i++)
    {
        if (board[i] == mark && board[i + 3] == mark && board[i + 6] == mark)
            return true;
    }

    // Check diagonals
    if (board[0] == mark && board[4] == mark && board[8] == mark)
        return true;
    if (board[2] == mark && board[4] == mark && board[6] == mark)
        return true;

    // No winner
    return false;
}

int main()
{
    char mark[] = {'X', 'O'};
    char board[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int move = 0;
    const int MAXMOVES = 9;

    for (int turn = 0; turn < MAXMOVES; turn++)
    {
        // draw the board
        cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
        cout << " -----------" << endl;
        cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
        cout << " -----------" << endl;
        cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;

        // get next move
        cout << endl
             << "Player " << (turn % 2) + 1 << " select cell (1 - 9)" << endl;
        cin >> move;

        if (board[move - 1] != ' ')
        {
            cout << "Sorry but that cell is taken! You lose the game." << endl;
            turn = MAXMOVES;
        }
        else
        {
            board[move - 1] = mark[turn % 2];

            // Check for a winner
            if (checkWin(board, mark[turn % 2]))
            {
                cout << "Player " << (turn % 2) + 1 << " wins!" << endl;
                cout << "Final Board:" << endl;
                cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
                cout << " -----------" << endl;
                cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
                cout << " -----------" << endl;
                cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
                return 0;
            }

            // Check for a tie
            else if (turn == MAXMOVES - 1)
            {
                cout << "It's a tie!" << endl;
            }
        }
    }

    cout << "Game Over." << endl;
    return 0;
}

/* Tests:
Checked for each type of win (column, row, and diagonal), as well as a tie game.
Each game resulted in the correct results.
*/