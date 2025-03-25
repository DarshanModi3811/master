#include "StrikeFrame.hpp"
#include <iostream>

using namespace std;
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

void StrikeFrame::setThirdRoll(int roll3) {
    cout << "Setting third roll to " << roll3 << endl;
    m_roll3 = roll3;
}

// Returns the first roll
int StrikeFrame::getFirstRoll() const {
    return roll1;
}

// Returns the second roll
int StrikeFrame::getSecondRoll() const {
    return bonuses.size() > 0 ? bonuses[0] : 0;
}

// Returns the third roll
int StrikeFrame::getThirdRoll() const {
    return m_roll3;
}