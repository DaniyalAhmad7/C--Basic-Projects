# Tic Tac Toe Game

## Description
This project is a console-based implementation of the classic Tic Tac Toe game for two players. The game is played on a 3x3 grid, and players take turns marking a cell with their respective symbols (X or O). The player who first gets three of their symbols in a row, column, or diagonal wins the game. If all cells are filled without a winner, the game ends in a draw.

## Code Explanation

### 1. **Class Definition**
The `TicTacToe` class encapsulates the game logic and board management. It uses a 2D array to represent the board and maintains the current player's turn.

```cpp
class TicTacToe {
private:
    char board[3][3];  // 2D array to represent the 3x3 board
    char currentPlayer;
public:
    TicTacToe();
    void displayBoard();
    bool checkWin();
    bool checkDraw();
    void switchPlayer();
    bool takeInput();
    void playGame();
};
```

### 2. **Initialization**
The constructor initializes the board with empty spaces and sets the current player to 'X'.

```cpp
TicTacToe::TicTacToe() : currentPlayer('X') {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            board[i][j] = ' ';
}
```

### 3. **Displaying the Board**
The `displayBoard` function prints the current state of the board in a user-friendly format.

```cpp
void TicTacToe::displayBoard() {
    cout << "\nCurrent Board:\n";
    for (int i = 0; i < 3; ++i) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << " \n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << endl;
}
```

### 4. **Win Condition Check**
The `checkWin` function checks rows, columns, and diagonals to determine if the current player has won.

```cpp
bool TicTacToe::checkWin() {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            return true;
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
            return true;
    }
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        return true;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        return true;
    return false;
}
```

### 5. **Draw Condition Check**
The `checkDraw` function checks if all cells are filled and there is no winner, indicating a draw.

```cpp
bool TicTacToe::checkDraw() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] == ' ') return false;
    return true;
}
```

### 6. **Player Input**
The `takeInput` function prompts the current player to select a position on the board. It validates the input to ensure the chosen cell is empty.

```cpp
bool TicTacToe::takeInput() {
    int position;
    cout << "Player " << currentPlayer << ", choose a position (1-9): ";
    cin >> position;
    position--;

    int row = position / 3;
    int col = position % 3;

    if (position < 0 || position >= 9 || board[row][col] != ' ') {
        cout << "Invalid move! Try again.\n";
        return false;
    }

    board[row][col] = currentPlayer;
    return true;
}
```

### 7. **Switching Players**
The `switchPlayer` function alternates the current player between 'X' and 'O'.

```cpp
void TicTacToe::switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}
```

### 8. **Main Game Loop**
The `playGame` function runs the main game loop, displaying the board, handling input, checking for win/draw conditions, and switching players.

```cpp
void TicTacToe::playGame() {
    while (true) {
        displayBoard();
        if (!takeInput()) continue;

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

        switchPlayer();
    }
}
```

### 9. **Main Function**
The `main` function creates an instance of `TicTacToe` and starts the game.

```cpp
int main() {
    TicTacToe game;
    game.playGame();
    return 0;
}
```

## Game Logic
- **Board Representation**: A 3x3 grid is represented using a 2D array.
- **Win Conditions**: The game checks rows, columns, and diagonals to determine if a player has won.
- **Draw Condition**: The game checks if all cells are filled without a winner.
- **Player Switching**: Players alternate turns, starting with 'X'.

## Sample Output
*(Manually add a snapshot here)*

