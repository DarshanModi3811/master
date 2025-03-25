#ifndef STRIKE_FRAME_HPP
#define STRIKE_FRAME_HPP

#include "FrameBase.hpp"

class StrikeFrame : public FrameBase {
private:
    int roll1;                    // Fixed to 10 for a strike
    int m_roll3;                  // for 3rd roll
    std::vector<int> bonuses;     // Holds up to two bonus rolls
public:
    StrikeFrame();                // Constructor initializes roll1 to 10
    int calculateScore() const override;  // Calculates score including bonuses
    void applyBonus(int bonus) override;  // Applies bonus rolls
    int getFirstRoll() const override;  // Returns the first roll
    int getSecondRoll() const override;  // Returns the second roll
    void setThirdRoll(int roll3) override; // to cater for 3rd roll
    int getThirdRoll() const override;  // Returns the third roll
    // int getThirdRoll() const override; // Add this line
};

#endif // STRIKE_FRAME_HPP
