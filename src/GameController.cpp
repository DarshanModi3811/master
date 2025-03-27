#include "GameController.hpp"
#include "FrameFactory/FrameFactory.hpp"
#include <iostream>
#include <sstream> // For stringstream
#include "../src/Frame/StrikeFrame.hpp"
#include "../src/Frame/OpenFrame.hpp"
#include "../src/Frame/SpareFrame.hpp"

using namespace std;

// Default constructor
GameController::GameController() {
    m_scoreCalculator = make_unique<ScoreCalculator>();
    m_ioHandler = make_unique<IOHandler>();
}

// Starts the game
void GameController::startGame() {
    cout << "Game started! Let's play bowling.\n";
}

// Processes user input
void GameController::processInput(int frameNumber) {
    try {
        int roll1 = -1, roll2 = -1, roll3 = -1;
        string input;

        // Get input for the frame
        while (true) {
            cout << "Enter rolls for frame " << frameNumber << ": ";
            getline(cin, input);

            if (m_ioHandler->parseRolls(input, roll1, roll2, roll3, frameNumber)) {
                break; // Valid input
            }
        }

        // Handle Strike in Frames 1–9
        if (roll1 == 10 && frameNumber < 10) {
            auto frame = FrameFactory::createFrame(roll1, 0); // Create StrikeFrame
            if (!frame) {
                throw runtime_error("Failed to create StrikeFrame.");
            }
            m_frames.push_back(frame); // Add StrikeFrame
            cout << "Strike! Moving to the next frame...\n";
            return; // Move to the next frame
        }

        // Handle non-strike frames (Frames 1–9)
        if (frameNumber < 10) {
            auto frame = FrameFactory::createFrame(roll1, roll2); // Create Frame
            if (!frame) {
                throw runtime_error("Failed to create frame.");
            }
            m_frames.push_back(frame); // Add the frame
            return; // Move to the next frame
        }

        // Special Handling for 10th Frame
        if (frameNumber == 10) {
            auto frame = FrameFactory::createFrame(roll1, roll2); // Create the frame
            if (!frame) {
                throw runtime_error("Failed to create frame.");
            }
            if (roll1 == 10 || roll1 + roll2 == 10) {
                frame->applyBonus(roll3); // Apply the bonus roll
                frame->setThirdRoll(roll3); // Set the third roll
            }
            m_frames.push_back(frame); // Add the 10th frame
            return; // End the game
        }
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << ". Please try again.\n";
        processInput(frameNumber); // Retry the input for the same frame
    }
}

// Displays the scores
void GameController::displayScores() {
    m_scoreCalculator->applyBonuses(m_frames);
    m_ioHandler->displayFrameScores(m_frames);
    int totalScore = m_scoreCalculator->calculateTotalScore(m_frames);
    m_ioHandler->displayTotalScore(totalScore);
}
