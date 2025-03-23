#ifndef IO_HANDLER_HPP
#define IO_HANDLER_HPP

#include <vector>
#include <string>
#include <memory>
#include "Frame/FrameBase.hpp"  // Updated to use the polymorphic base class
class IOHandler {
public:
    bool validateInput(const std::string& input); // Validates user input
    std::vector<int> parseInput(const std::string& input); // Parses input into roll scores
    void displayFrameScores(const std::vector<std::shared_ptr<FrameBase>>& frames) const; // Displays polymorphic frame scores
    void displayTotalScore(int totalScore) const; // Displays the total score
};

#endif // IO_HANDLER_HPP
