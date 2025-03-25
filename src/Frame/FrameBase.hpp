#ifndef FRAME_BASE_HPP
#define FRAME_BASE_HPP

#include <vector>

class FrameBase {
public:
    virtual int calculateScore() const = 0; // Pure virtual method for score calculation
    virtual void applyBonus(int bonus) = 0; // Pure virtual method to apply bonuses
    virtual int getFirstRoll() const = 0; // Pure virtual method to get the first roll
    virtual int getSecondRoll() const = 0; // Pure virtual method to get the second roll
    virtual void setThirdRoll(int roll3) = 0; // Add this line
    virtual int getThirdRoll() const = 0; // Add this line
    virtual ~FrameBase() {}
};

#endif // FRAME_BASE_HPP
