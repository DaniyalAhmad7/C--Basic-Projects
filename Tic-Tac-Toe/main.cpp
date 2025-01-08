#include <iostream>
#include <windows.h> // For Sleep()
using namespace std;

class TicTacToe {
private:
    char board[3][3];  // 2D array to represent the 3x3 board
    char currentPlayer;

public:
    TicTacToe() : currentPlayer('X') {
        // Initialize the board with empty spaces
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                board[i][j] = ' ';
    }

    // Function to display the current board
    void displayBoard() {
        
        cout << "\nCurrent Board:\n";
        for (int i = 0; i < 3; ++i) {
            cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << " \n";
            if (i < 2) cout << "---+---+---\n";
        }
        cout << endl;
        
    }

    // Function to check if the current player has won
    bool checkWin() {
        // Check rows, columns, and diagonals for a win
        for (int i = 0; i < 3; ++i) {
            // Check rows
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
                return true;
            // Check columns
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
                return true;
        }
        // Check diagonals
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
            return true;
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
            return true;
        return false;
    }

    // Function to check if the game is a draw
    bool checkDraw() {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (board[i][j] == ' ') return false;
        return true;
    }

    // Function to switch the current player
    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    // Function to take input and update the board
    bool takeInput() {
        int position;
        cout << "Player " << currentPlayer << ", choose a position (1-9): ";
        cin >> position;
        position--; // Convert to 0-based index

        int row = position / 3;
        int col = position % 3;

        if (position < 0 || position >= 9 || board[row][col] != ' ') {
            cout << "Invalid move! Try again.\n";
            return false;
        }

        board[row][col] = currentPlayer;
        return true;
    }

    // Function to run the game
    void playGame() {
        while (true) {
            displayBoard();
            if (!takeInput()) continue; // Take input until it's valid

            // Check for win or draw
            if (checkWin()) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!\n";
                break;
            }
            if (checkDraw()) {
                displayBoard();
                cout << "It's a draw!\n";
                break;
            }

            // Switch players
            switchPlayer();
        }
    }
};

// Main function
int main() {
    TicTacToe game;
    game.playGame();
    return 0;
}

