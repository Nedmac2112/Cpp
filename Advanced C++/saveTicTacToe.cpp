// Camden K., 8/30/24, cckirkpatrick@dmacc.edu
/*
   Updated the program to include a vector to store the moves made by each player in a tic-tac-toe game.
   The program will output the moves made by each player at the end of the game.
*/

#include <array>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    // TODO: declare a vector
    vector<int> moves;

    array<char, 2> mark = {'X', 'O'};
    array<char, 9> board = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
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
        // get the next move
        cout << endl
             << "Player " << (turn % 2) + 1 << " select a cell (1 - 9):" << endl;
        cin >> move;
        if (board[move - 1] != ' ')
        {
            cout << "Sorry but that cell is taken! You lose the game." << endl;
            turn = MAXMOVES;
        }
        else
        {
            board[move - 1] = mark[turn % 2];
        }

        // TODO: add move to vector
        moves.push_back(move);
    }
    cout << "Game Over" << endl;

    cout << "Review of player 1 moves: " << endl;
    // TODO: output all of the moves made by player 1 (and only 1)
    for (int i = 0; i < moves.size(); i++)
    {
        if (i % 2 == 0)
        {
            cout << moves[i] << " ";
        }
    }
    cout << "\nReview of player 2 moves: " << endl;
    // TODO: output all of the moves made by player 2 (and only 2)
    for (int i = 0; i < moves.size(); i++)
    {
        if (i % 2 != 0)
        {
            cout << moves[i] << " ";
        }
    }

    return 0;
}

/*
Tests:

Test 1:
Player1 moves: 1 2 3 4 5
Player2 moves: 6 7 8 9

Expected Output:
Review of player 1 moves: 1 2 3 4 5
Review of player 2 moves: 6 7 8 9

Actual Output:
Review of player 1 moves: 1 2 3 4 5
Review of player 2 moves: 6 7 8 9


Test 2:
Player1 moves: 1 3 5 7 9
Player2 moves: 2 4 6 8

Expected Output:
Review of player 1 moves: 1 3 5 7 9
Review of player 2 moves: 2 4 6 8

Actual Output:
Review of player 1 moves: 1 3 5 7 9
Review of player 2 moves: 2 4 6 8
*/
