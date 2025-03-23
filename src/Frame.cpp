#include "Frame.hpp"

// Frame class implementation

Frame::Frame() : score(0), roll1(0), roll2(0), isStrike(false), isSpare(false) {}

void Frame::setRolls(int r1, int r2) {
    roll1 = r1;
    roll2 = r2;
    score = roll1 + roll2;
    isStrike = (roll1 == 10);
    isSpare = (!isStrike && (score == 10));
}

int Frame::getScore() const {
    return score;
}

bool Frame::strike() const {
    return isStrike;
}

bool Frame::spare() const {
    return isSpare;
}