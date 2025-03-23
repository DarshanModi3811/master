#ifndef OPEN_FRAME_HPP
#define OPEN_FRAME_HPP

#include "FrameBase.hpp"

class OpenFrame : public FrameBase {
private:
    int roll1, roll2;  // Rolls in an open frame
public:
    OpenFrame(int roll1, int roll2);  // Constructor initializes rolls
    int calculateScore() const override;  // Calculates score (no bonuses)
    void applyBonus(int bonus) override;  // Does nothing, as open frames have no bonuses
};

#endif // OPEN_FRAME_HPP
