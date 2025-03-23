#include "SpareFrame.hpp"

// Constructor initializes rolls
SpareFrame::SpareFrame(int roll1, int roll2) : roll1(roll1), roll2(roll2), bonus(0) {}

// Calculates score including bonus
int SpareFrame::calculateScore() const {
    return roll1 + roll2 + bonus;
}

// Applies the bonus roll
void SpareFrame::applyBonus(int bonusValue) {
    bonus = bonusValue;
}
