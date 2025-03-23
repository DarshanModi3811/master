#include <iostream>
#include "GameController.hpp"

using namespace std;
// Display the welcome message
void displayWelcomeMessage() {
    cout << "🎳 Welcome to the Bowling Score Calculator! 🎳\n";
    cout << "Rules:\n";
    cout << " - Enter rolls for each frame (e.g., 'X', '7 2', '5 /').\n";
    cout << " - Strikes ('X') end the frame early.\n";
    cout << " - Spares ('/') require one bonus roll.\n";
    cout << " - The 10th frame allows bonus rolls for strikes and spares.\n";
    cout << "Let's begin!\n\n";
}

int main() {
    try {
        displayWelcomeMessage(); // Display the game introduction message
        
        GameController gameController;
        gameController.startGame();

        for (int frame = 1; frame <= 10; ++frame) {
            gameController.processInput(frame); // Process roll-by-roll input
        }

        gameController.displayScores(); // Display the final scores
        cout << "🎉 Thanks for playing! 🎉\n";
    } catch (const exception& e) {
        cerr << "An unexpected error occurred: " << e.what() << "\n";
    }

    return 0;
}

