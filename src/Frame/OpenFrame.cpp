#include "OpenFrame.hpp"

// Constructor initializes rolls
OpenFrame::OpenFrame(int roll1, int roll2) : roll1(roll1), roll2(roll2) {}

// Calculates score (no bonuses)
int OpenFrame::calculateScore() const {
    return roll1 + roll2;
}

// Does nothing, as open frames have no bonuses
void OpenFrame::applyBonus(int bonus) {
    // No bonus for open frames
}
