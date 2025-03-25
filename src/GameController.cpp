#include "GameController.hpp"
#include "FrameFactory/FrameFactory.hpp"
#include <iostream>
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

        // First Roll
        while (true) {
            cout << "Enter the first roll for frame " << frameNumber << ": ";
            cin >> roll1;

            // Validate roll1 (must be between 0 and 10)
            if (roll1 < 0 || roll1 > 10) {
                cerr << "Invalid input: Roll values must be between 0 and 10. Please try again.\n";
                continue;
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
            break; // Valid input, exit loop
        }

        // Second Roll (for non-strike frames)
        if (frameNumber < 10) {
            while (true) {
                cout << "Enter the second roll for frame " << frameNumber << ": ";
                cin >> roll2;

                // Validate roll2 and ensure total pins do not exceed 10
                if (roll2 < 0 || roll2 > 10 || roll1 + roll2 > 10) {
                    cerr << "Invalid input: Total pins in a frame cannot exceed 10. Please try again.\n";
                    continue;
                }

                auto frame = FrameFactory::createFrame(roll1, roll2); // Create Frame
                if (!frame) {
                    throw runtime_error("Failed to create frame.");
                }
                m_frames.push_back(frame); // Add the frame
                return; // Move to the next frame
            }
        }

        // Special Handling for 10th Frame
        if (frameNumber == 10) {
            // Second Roll
            cout << "Enter the second roll for frame " << frameNumber << ": ";
            cin >> roll2;

            // Third Roll (if Strike or Spare)
            if (roll1 == 10 || roll1 + roll2 == 10) {
                cout << "Enter the third roll for frame " << frameNumber << ": ";
                cin >> roll3;

                // Validate bonus roll
                if (roll3 < 0 || roll3 > 10) {
                    cerr << "Invalid input: Bonus roll must be between 0 and 10. Please try again.\n";
                    return processInput(frameNumber); // Restart the 10th frame input
                }
            }

            auto frame = FrameFactory::createFrame(roll1, roll2); // Create the frame
            if (!frame) {
                throw runtime_error("Failed to create frame.");
            }
            frame->applyBonus(roll3); // Apply the bonus roll
            frame->setThirdRoll(roll3); // Set the third roll
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
