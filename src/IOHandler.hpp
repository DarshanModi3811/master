#ifndef IO_HANDLER_HPP
#define IO_HANDLER_HPP

#include <vector>
#include <string>
#include <memory>
#include "Frame/FrameBase.hpp"  // Updated to use the polymorphic base class
class IOHandler {
public:
    bool parseRolls(const std::string& input, int& roll1, int& roll2, int& roll3, int frameNumber); // Parses and validates rolls from a string
    void displayFrameScores(const std::vector<std::shared_ptr<FrameBase>>& frames) const; // Displays polymorphic frame scores
    void displayTotalScore(int totalScore) const; // Displays the total score
};

#endif // IO_HANDLER_HPP
