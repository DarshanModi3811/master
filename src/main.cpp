#include <iostream>
#include "GameController.hpp"

using namespace std;
int main() {
    // Welcome Message
    cout << "Welcome to the Bowling Score Calculator!\n";

    GameController gameController;
    gameController.startGame();

    // Input Loop for 10 Frames in a Bowling Game
    for (int frame = 1; frame <= 10; ++frame) {
        string input;
        cout << "Enter rolls for frame " << frame << ": ";
        getline(cin, input);

        gameController.processInput(input);
    }

    // Display Scores
    gameController.displayScores();

    cout << "Thanks for playing!\n";
    return 0;
}
