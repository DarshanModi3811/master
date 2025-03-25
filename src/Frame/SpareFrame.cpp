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

// Returns the first roll
int SpareFrame::getFirstRoll() const {
    return roll1;
}

// Returns the second roll
int SpareFrame::getSecondRoll() const {
    return roll2;
}

void SpareFrame::setThirdRoll(int roll3) {
    bonus = roll3;
}

int SpareFrame::getThirdRoll() const {
    return bonus;
}