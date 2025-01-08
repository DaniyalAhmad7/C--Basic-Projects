# Tic Tac Toe Game

This is a simple C++ implementation of the classic Tic Tac Toe game. The game allows two players to play against each other on a 3x3 grid, aiming to be the first to align three of their marks in a row, column, or diagonal.

## Features

- Two-player game mode.
- Dynamic board display after each move.
- Input validation to ensure valid moves.
- Detection of win, draw, or invalid moves.
- Allows players to restart or exit after a game ends.

## Table of Contents
1. [Game Logic](#game-logic)
2. [Code Explanation](#code-explanation)
    - [TicTacToe Class](#tictactoe-class)
    - [Main Function](#main-function)
3. [Sample Output](#sample-output)
4. [About Me](#about-me)

## Game Logic

Tic Tac Toe is played on a 3x3 grid. Players take turns marking a spot on the grid with their respective symbols ('X' or 'O'). The game ends when:

- A player successfully marks three spots in a row, column, or diagonal.
- All spots are filled without any player achieving the above condition, resulting in a draw.

## Code Explanation

### TicTacToe Class

The `TicTacToe` class encapsulates the game logic and handles the game board, player turns, and checking win/draw conditions.

#### Attributes:
- `board[3][3]`: A 3x3 array representing the game board.
- `currentPlayer`: Character representing the current player ('X' or 'O').

#### Methods:

- **Constructor**: Initializes the board with empty spaces and sets the first player to 'X'.
  
- **displayBoard()**: Displays the current state of the board. The grid is formatted with clear lines separating the cells.

- **checkWin()**: Checks all rows, columns, and diagonals to see if the current player has won the game. Returns `true` if a win condition is met.

- **checkDraw()**: Checks if the board is full without any player winning, indicating a draw. Returns `true` if the game is a draw.

- **switchPlayer()**: Switches the current player from 'X' to 'O' or vice versa after each turn.

- **takeInput()**: Prompts the current player to choose a position on the board. It validates the input to ensure it is within the range (1-9) and that the selected cell is not already occupied.

- **playGame()**: The main game loop. It handles the game flow, displaying the board, taking input, checking win/draw conditions, and switching players.

### Main Function

The main function creates an instance of the `TicTacToe` class and starts the game by calling the `playGame()` method.

## Sample Output

(Add a snapshot of the game output here)

## About Me

A passionate Computer Science student with an interest in software development, open-source projects, and learning new technologies.

### Contact Me
[![GitHub](https://img.shields.io/badge/GitHub-181717?style=for-the-badge&logo=github&logoColor=white)](https://github.com/yourusername)
[![Email](https://img.shields.io/badge/Email-D14836?style=for-the-badge&logo=gmail&logoColor=white)](mailto:your-email@example.com)
[![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/yourprofile)
[![WhatsApp](https://img.shields.io/badge/WhatsApp-25D366?style=for-the-badge&logo=whatsapp&logoColor=white)](https://wa.me/yourphonenumber)
