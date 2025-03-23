#ifndef GAME_CONTROLLER_HPP
#define GAME_CONTROLLER_HPP

#include <vector>
#include <memory>
#include "../src/Frame/FrameBase.hpp"
#include "ScoreCalculator.hpp"
#include "IOHandler.hpp"

class GameController {
private:
    std::vector<std::shared_ptr<FrameBase>> frames;    // Polymorphic collection of frames
    std::unique_ptr<ScoreCalculator> scoreCalculator; // Scoring logic
    std::unique_ptr<IOHandler> ioHandler;             // Input/output handler

public:
    GameController();                                  // Default constructor
    void startGame();                                  // Starts the game
    void processInput(const std::string& input);      // Processes user input
    void displayScores();                              // Displays the scores
};

#endif // GAME_CONTROLLER_HPP
