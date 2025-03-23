#ifndef STRIKE_FRAME_HPP
#define STRIKE_FRAME_HPP

#include "FrameBase.hpp"

class StrikeFrame : public FrameBase {
private:
    int roll1;                    // Fixed to 10 for a strike
    std::vector<int> bonuses;     // Holds up to two bonus rolls
public:
    StrikeFrame();                // Constructor initializes roll1 to 10
    int calculateScore() const override;  // Calculates score including bonuses
    void applyBonus(int bonus) override;  // Applies bonus rolls
};

#endif // STRIKE_FRAME_HPP
