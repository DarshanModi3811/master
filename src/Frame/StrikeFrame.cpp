#include "StrikeFrame.hpp"

// Constructor initializes roll1 to 10
StrikeFrame::StrikeFrame() : roll1(10) {}

// Calculates score including bonuses
int StrikeFrame::calculateScore() const {
    int score = roll1;
    if (bonuses.size() >= 2) {
        score += bonuses[0] + bonuses[1];
    }
    return score;
}

// Applies bonus rolls (up to two)
void StrikeFrame::applyBonus(int bonus) {
    if (bonuses.size() < 2) {
        bonuses.push_back(bonus);
    }
}
