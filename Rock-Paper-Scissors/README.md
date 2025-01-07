# Rock Paper Scissors Game

## Table of Contents
- [Introduction](#introduction)
- [Game Logic](#game-logic)
- [Code Explanation](#code-explanation)
- [Sample Output](#sample-output)
- [About Me](#about-me)

---

## Introduction

The **Rock Paper Scissors** game is a classic two-player game where each player simultaneously chooses one of the three options: Rock, Paper, or Scissors. The game follows simple rules:

- Rock beats Scissors.
- Scissors beats Paper.
- Paper beats Rock.

In this implementation, you can play the game either **against the computer** or **with another player**. The game keeps track of the score for each player and continues until the user decides to exit.

---

## Game Logic

The core logic of the game is based on comparing the choices made by the players. The rules are as follows:

1. **Rock** beats **Scissors**.
2. **Scissors** beats **Paper**.
3. **Paper** beats **Rock**.
4. If both players select the same option, it results in a **tie**.

### Steps:
1. Player 1 makes their choice.
2. Player 2 (or the computer) makes their choice.
3. The winner is determined based on the above rules.
4. The score is updated, and the game continues until the player opts to exit.

---

## Code Explanation

### 1. **RockPaperScissors Class**

The `RockPaperScissors` class handles all the gameplay mechanics, player input, game rules, and score tracking. Here's a breakdown of its key functions:

#### - `getUserChoiceConcealed()`
This function allows the player to input their choice of Rock, Paper, or Scissors without displaying it on the screen. It uses the `getch()` function from the `conio.h` library to capture the input as a character and immediately converts it to uppercase using `toupper()`. If the input is invalid (anything other than 'R', 'P', or 'S'), the function will repeatedly prompt the user until a valid choice is entered.

#### - `getComputerChoice()`
This function generates the computer's move randomly. It uses an array `options[]` that stores the possible choices (Rock, Paper, Scissors). The `rand()` function is used to generate a random number between 0 and 2, which corresponds to one of the three options.

#### - `determineWinner()`
This function compares the two players' choices (either Player 1 vs Player 2 or Player 1 vs Computer) and determines the winner based on the game rules:
- If both players choose the same option, it results in a tie.
- If Player 1's choice beats Player 2's (or the computer's), Player 1 wins. 
- Otherwise, Player 2 (or the computer) wins.
The function updates the win counters for each player.

#### - `displayScore()`
This function prints out the current score, showing how many wins each player has accumulated. It's displayed after every round of the game.

#### - `playWithPlayer()`
This method handles the two-player mode of the game. Player 1 and Player 2 take turns making their choices, and the game compares the two inputs. The winner of each round is announced, and the score is updated. The function continues to loop until the user decides to exit or return to the main menu.

#### - `playWithComputer()`
This method allows the player to play against the computer. The player selects their choice, and the computer generates a random choice. The game then compares the two choices and determines the winner, updating the score after each round. The user can choose to continue playing or exit after each round.

#### - `choiceToString()`
This helper function converts the choice character ('R', 'P', 'S') into a human-readable string: "Rock", "Paper", or "Scissors". This is helpful for displaying the result to the user in a clear and understandable way.

#### - `checkExit()`
After each round, the game prompts the user if they want to continue playing or return to the main menu. If the user enters `0`, the program exits the loop and returns to the main menu. If the user enters `1`, the game continues.

---

### 2. **Main Function**

The `main()` function serves as the entry point of the game. It displays a menu where the user can choose to:
- Play against the computer (Option 1)
- Play against another player (Option 2)
- Exit the game (Option 0)

Based on the user's selection, the appropriate game mode is launched. The game will continue to run in a loop, allowing the user to play multiple rounds. When the user decides to exit the game by selecting Option 0, the program thanks the user and terminates.

The `main()` function also seeds the random number generator using `srand()` and the current time with `time(0)` to ensure that the computer's moves are unpredictable and not repeated across multiple runs.

---

## Sample Output

*(Add a snapshot of the game output here)*

---

## About Me

I am a Computer Science student who enjoys working on coding projects and improving my programming skills. You can reach out to me through the following channels:

- **Email**: [your-email@example.com](mailto:your-email@example.com)
- **WhatsApp**: [Click here](https://wa.me/1234567890)
- **LinkedIn**: [Your LinkedIn](https://www.linkedin.com/in/your-profile)

---

Thank you for checking out my Rock Paper Scissors game!

