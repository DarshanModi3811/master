#include "IOHandler.hpp"
#include <iostream>
#include <sstream>

using namespace std;

// Anonymous namespace for file-specific helper functions
namespace {
    bool isValidRoll(int roll) {
        return roll >= 0 && roll <= 10;
    }

    bool isSpare(int roll1, int roll2) {
        return roll1 + roll2 == 10;
    }
}

bool IOHandler::parseRolls(const string& input, int& roll1, int& roll2, int& roll3, int frameNumber) {
    stringstream ss(input);
    string token;
    vector<int> rolls;

    while (getline(ss, token, ' ')) {
        if (token == "X") { // Strike
            rolls.push_back(10);
        } else if (token == "/") { // Spare
            if (rolls.empty()) {
                cerr << "Invalid input: Spare '/' must follow a valid roll.\n";
                return false;
            }
            rolls.push_back(10 - rolls.back());
        } else {
            try {
                int roll = stoi(token);
                if (!isValidRoll(roll)) {
                    cerr << "Invalid input: Roll values must be between 0 and 10.\n";
                    return false;
                }
                rolls.push_back(roll);
            } catch (const invalid_argument&) {
                cerr << "Invalid input: Non-numeric value entered.\n";
                return false;
            }
        }
    }

    if (rolls.size() > 3 || rolls.empty()) {
        cerr << "Invalid input: Too many or too few rolls entered.\n";
        return false;
    }

    roll1 = rolls.size() > 0 ? rolls[0] : 0;
    roll2 = rolls.size() > 1 ? rolls[1] : 0;
    roll3 = rolls.size() > 2 ? rolls[2] : 0;

    // Validate total pins for frames 1–9
    if (frameNumber < 10 && !isValidRoll(roll1 + roll2)) {
        cerr << "Invalid input: Total pins in a frame cannot exceed 10.\n";
        return false;
    }

    return true;
}

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