#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <windows.h> // For Sleep()
#include <conio.h> // For getch()
using namespace std;

// Class to handle the game logic
class RockPaperScissors {
private:
    int player1Wins;
    int player2Wins;

public:
    RockPaperScissors() : player1Wins(0), player2Wins(0) {}

    // Function to get user choice (Rock, Paper, Scissors) with concealed input
    char getUserChoiceConcealed(string playerName) {
        char choice;
        cout << playerName << ", make your choice (R for Rock, P for Paper, S for Scissors): ";
        choice = toupper(getch()); // Get input without displaying it
        cout << "\n"; // Move to the next line after input
        Sleep(500);
        while (choice != 'R' && choice != 'P' && choice != 'S') {
            cout << "Invalid input. Please try again.\n";
            cout << playerName << ", make your choice (R for Rock, P for Paper, S for Scissors): ";
            choice = toupper(getch());
            cout << "\n"; // Move to the next line after input
            Sleep(500);
        }
        return choice;
    }

    // Function to get computer choice
    char getComputerChoice() {
        char options[] = {'R', 'P', 'S'};
        return options[rand() % 3];
    }

    // Function to determine the winner
    string determineWinner(char choice1, char choice2) {
        if (choice1 == choice2) {
            return "It's a tie!";
        }
        if ((choice1 == 'R' && choice2 == 'S') ||
            (choice1 == 'P' && choice2 == 'R') ||
            (choice1 == 'S' && choice2 == 'P')) {
            player1Wins++;
            return "Player 1 wins!";
        }
        player2Wins++;
        return "Player 2 wins!";
    }

    // Function to display the score
    void displayScore() const {
        cout << "\nCurrent Score:\n";
        cout << "Player 1 Wins: " << player1Wins << endl;
        cout << "Player 2 Wins: " << player2Wins << endl;
    }

    // Function to play against another player
    void playWithPlayer() {
        while (true) {
            cout << "\n--- Player vs Player ---\n";
            char choice1 = getUserChoiceConcealed("Player 1");
            Sleep(250);
            char choice2 = getUserChoiceConcealed("Player 2");
            Sleep(500);
            cout << "Player 1 chose " << choiceToString(choice1) << endl;
            
            cout << "Player 2 chose " << choiceToString(choice2) << endl;

            cout << determineWinner(choice1, choice2) << endl;
            displayScore();

            if (checkExit()) {
                break;
            }
        }
    }

    // Function to play against the computer
    void playWithComputer() {
        while (true) {
            cout << "\n--- Player vs Computer ---\n";
            char playerChoice = getUserChoiceConcealed("Player");
            char computerChoice = getComputerChoice();

            cout << "Player chose " << choiceToString(playerChoice) << endl;
            cout << "Computer chose " << choiceToString(computerChoice) << endl;

            cout << determineWinner(playerChoice, computerChoice) << endl;
            displayScore();

            if (checkExit()) {
                break;
            }
        }
    }

    // Helper function to convert choice to string
    string choiceToString(char choice) const {
        switch (choice) {
            case 'R': return "Rock";
            case 'P': return "Paper";
            case 'S': return "Scissors";
            default: return "Invalid";
        }
    }

    // Function to check if the user wants to exit or return to the main menu
    bool checkExit() {
        int input;
        cout << "\nEnter 0 to return to main menu, or 1 to continue: ";
        cin >> input;
        return input == 0;
    }
};

// Main function
int main() {
    srand(static_cast<unsigned>(time(0))); // Seed random number generator
    RockPaperScissors game;

    while (true) {
        cout << "\n--- Rock Paper Scissors Game ---\n";
        cout << "1. Play with Computer\n";
        cout << "2. Play with Another Player\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                game.playWithComputer();
                break;
            case 2:
                game.playWithPlayer();
                break;
            case 0:
                cout << "Thanks for playing! Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

