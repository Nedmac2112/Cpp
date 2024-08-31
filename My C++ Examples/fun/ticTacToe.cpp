#include <iostream>
using namespace std;

int main()
{
    // Tic Tac Toe board
    char board[3][3] = {{' ', ' ', ' '},
                        {' ', ' ', ' '},
                        {' ', ' ', ' '}};

    // variable declaration and initilization
    const char playerX = 'X';
    const char playerO = 'O';
    char curPlayer = playerX;
    char winner = ' ';
    int r = 0;
    int c = 0;
    bool isValidInput = false; // allows for user input in while loop

    // game loop (up to 9 turns)
    for (int i = 0; i < 9; i++)
    {
        // Print the Tic-Tac-Toe board
        cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
        cout << "-----------" << endl;
        cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
        cout << "-----------" << endl;
        cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;

        // if there is a winner, exit game loop
        if (winner != ' ')
        {
            break;
        }

        // while the input is invalid, prompt for user input
        while (!isValidInput)
        {
            cout << endl
                 << "Player " << curPlayer << ", enter a row and column (r c): ";
            // no error flags set
            if (cin >> r >> c)
            {
                // make sure the input is not out of bounds
                if (r > 3 || r < 1 || c > 3 || c < 1)
                {
                    cout << "Invaild input: this space is out of bounds" << endl;
                }
                // make sure the space is empty
                else if (board[r - 1][c - 1] != ' ')
                {
                    cout << "Invaild input: this space is not empty" << endl;
                }

                else
                {
                    // subtract one from the row and column, since the user types 1 for the first row/column, not 0
                    board[r - 1][c - 1] = curPlayer;
                    cout << endl;
                    isValidInput = true; // break out of input loop
                }
            }
            // runs if there was an invalid input type
            else
            {
                cout << "Invalid input: expected an integer" << endl;
                cin.clear();             // clear error flags
                cin.ignore(10000, '\n'); // clear input buffer
            }
        }

        isValidInput = false; // reset sentinel so the next player can input

        // Check for a winner
        // rows
        for (int r = 0; r < 3; r++)
        {
            if (board[r][0] != ' ' && board[r][0] == board[r][1] && board[r][1] == board[r][2])
            {
                winner = curPlayer;
                cout << "Player " << winner << " wins!" << endl;
                break; // no point in checking more possible wins, if there is atleast 1
            }
        }

        // columns
        for (int c = 0; c < 3; c++)
        {
            if (board[0][c] != ' ' && board[0][c] == board[1][c] && board[1][c] == board[2][c])
            {
                winner = curPlayer;
                cout << "Player " << winner << " wins!" << endl;
                break; // no point in checking more possible wins, if there is atleast 1
            }
        }

        // diagonals
        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        {
            winner = curPlayer;
            cout << "Player " << winner << " wins!" << endl;
        }
        else if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        {
            winner = curPlayer;
            cout << "Player " << winner << " wins!" << endl;
        }

        // change player for the next turn based on the current player
        curPlayer = (curPlayer == playerX) ? playerO : playerX;
    }

    // if the game loop runs all 9 times, and the winner hasn't been set, it's a tie game
    if (winner == ' ')
    {
        cout << "Tie game";
    }

    return 0;
}
