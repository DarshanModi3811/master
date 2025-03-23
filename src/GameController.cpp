#include "GameController.hpp"
#include "FrameFactory/FrameFactory.hpp"
#include <iostream>

using namespace std;
// Default constructor
GameController::GameController() {
    scoreCalculator = make_unique<ScoreCalculator>();
    ioHandler = make_unique<IOHandler>();
}

// Starts the game
void GameController::startGame() {
    cout << "Game started! Let's play bowling.\n";
}

// Processes user input
void GameController::processInput(const string& input) {
    vector<int> rolls = ioHandler->parseInput(input);
    auto frame = FrameFactory::createFrame(rolls[0], rolls.size() > 1 ? rolls[1] : 0);
    frames.push_back(frame);
}

// Displays the scores
void GameController::displayScores() {
    scoreCalculator->applyBonuses(frames);
    ioHandler->displayFrameScores(frames);
    int totalScore = scoreCalculator->calculateTotalScore(frames);
    ioHandler->displayTotalScore(totalScore);
}
