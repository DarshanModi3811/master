#ifndef SPARE_FRAME_HPP
#define SPARE_FRAME_HPP

#include "FrameBase.hpp"

class SpareFrame : public FrameBase {
private:
    int roll1, roll2;  // Rolls that make up the spare
    int bonus;         // Holds the single bonus roll
public:
    SpareFrame(int roll1, int roll2);  // Constructor initializes rolls
    int calculateScore() const override;  // Calculates score including bonus
    void applyBonus(int bonus) override;  // Applies the bonus roll
};

#endif // SPARE_FRAME_HPP
