#include "IOHandler.hpp"
#include <iostream>
#include <sstream>

using namespace std;
// Validates user input
bool IOHandler::validateInput(const string& input) {
    try {
        // Validate input for invalid characters
        for (char ch : input) {
            if (!isdigit(ch) && ch != 'X' && ch != '/' && ch != ' ') {
                throw invalid_argument("Invalid input character detected.");
            }
        }
        return true;
    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
        return false;
    }
}

// // Parses user input into scores
// vector<int> IOHandler::parseInput(const string& input) {
//     vector<int> rolls;
//     istringstream stream(input);
//     char token;
//     while (stream >> token) {
//         if (token == 'X') {
//             rolls.push_back(10); // Strike
//         } else if (token == '/') {
//             if (!rolls.empty()) {
//                 rolls.back() = 10 - rolls.back(); // Spare
//             }
//         } else {
//             rolls.push_back(token - '0'); // Convert char to int
//         }
//     }
//     return rolls;
// }

// Displays frame-by-frame scores
void IOHandler::displayFrameScores(const vector<shared_ptr<FrameBase>>& frames) const {
    for (size_t i = 0; i < frames.size(); ++i) {
        cout << "Frame " << i + 1 << ": " << frames[i]->calculateScore() << endl;
    }
}

// Displays the total score
void IOHandler::displayTotalScore(int totalScore) const {
    cout << "Total Score: " << totalScore << endl;
}
#include "IOHandler.hpp"

// ...existing code...