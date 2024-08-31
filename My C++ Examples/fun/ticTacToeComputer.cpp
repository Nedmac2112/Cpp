// Tic Tac Toe game with a computer opponent

#include <iostream>
using namespace std;

void printBoard(char board[3][3]);
void rowWin(char board[3][3], char &winner, char &curPlayer);
void columnWin(char board[3][3], char &winner, char &curPlayer);
void diagonalWin(char board[3][3], char &winner, char &curPlayer);

const int ROW_NUMS = 3;
const int COL_NUMS = 3;
const int TILE_NUMS = 9;
int main()
{
    // Tic Tac Toe board
    char board[3][3] = {{' ', ' ', ' '},
                        {' ', ' ', ' '},
                        {' ', ' ', ' '}};

    // variable declaration and initilization
    const char playerX = 'X';
    const char computer = 'O';
    char curPlayer = playerX;
    char winner = ' ';
    int row = 0;
    int col = 0;
    bool isValidInput = false; // allows for user input in while loop

    // game loop (up to 9 turns)
    for (int i = 0; i < TILE_NUMS; i++)
    {

        // if there is a winner, exit game loop
        if (winner != ' ')
        {
            break;
        }

        // Player's turn
        if (curPlayer == playerX)
        {
            printBoard(board);
            // while the input is invalid, prompt for user input
            while (!isValidInput)
            {
                cout << endl
                     << "Player " << curPlayer << ", enter a row and column (r c): ";
                // no error flags set
                if (cin >> row >> col)
                {
                    // make sure the input is not out of bounds
                    if (row > ROW_NUMS || row < 1 || col > COL_NUMS || col < 1)
                    {
                        cout << "Invaild input: this space is out of bounds" << endl;
                    }
                    // make sure the space is empty
                    else if (board[row - 1][col - 1] != ' ')
                    {
                        cout << "Invaild input: this space is not empty" << endl;
                    }

                    else
                    {
                        // subtract one from the row and column, since the user types 1 for the first row/column, not 0
                        board[row - 1][col - 1] = curPlayer;
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
        }

        // Computer's turn
        else
        {
            cout << "Computer's turn" << endl;
            srand(time(0));
            int choice1;
            int choice2;
            do
            {
                choice1 = rand() % 3; // creates numbers between 0 and 2
                choice2 = rand() % 3;
            } while (board[choice1][choice2] != ' ');
            board[choice1][choice2] = curPlayer;
        }

        isValidInput = false; // reset sentinel so the next player can input

        // Check for a winner
        rowWin(board, winner, curPlayer);
        columnWin(board, winner, curPlayer);
        diagonalWin(board, winner, curPlayer);
        // change player for the next turn based on the current player
        curPlayer = (curPlayer == playerX) ? computer : playerX;
    }

    // if the game loop runs all 9 times, and the winner hasn't been set, it's a tie game
    if (winner == ' ')
    {
        cout << "Tie game";
        printBoard(board);
    }

    return 0;
}

void printBoard(char board[3][3])
{
    // Print the Tic-Tac-Toe board
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

// Check possible row wins
void rowWin(char board[3][3], char &winner, char &curPlayer)
{
    for (int r = 0; r < ROW_NUMS; r++)
    {
        if (board[r][0] != ' ' && board[r][0] == board[r][1] && board[r][1] == board[r][2])
        {
            winner = curPlayer;
            cout << "Player " << winner << " wins!" << endl;
            printBoard(board);
            break; // no point in checking more possible wins, if there is atleast 1
        }
    }
}

// Check possible column wins
void columnWin(char board[3][3], char &winner, char &curPlayer)
{

    for (int c = 0; c < COL_NUMS; c++)
    {
        if (board[0][c] != ' ' && board[0][c] == board[1][c] && board[1][c] == board[2][c])
        {
            winner = curPlayer;
            cout << "Player " << winner << " wins!" << endl;
            printBoard(board);
            break; // no point in checking more possible wins, if there is atleast 1
        }
    }
}

// Check possible diagonal wins
void diagonalWin(char board[3][3], char &winner, char &curPlayer)
{
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        winner = curPlayer;
        cout << "Player " << winner << " wins!" << endl;
        printBoard(board);
    }
    else if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        winner = curPlayer;
        cout << "Player " << winner << " wins!" << endl;
        printBoard(board);
    }
}