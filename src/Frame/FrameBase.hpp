#ifndef FRAME_BASE_HPP
#define FRAME_BASE_HPP

#include <vector>

class FrameBase {
public:
    virtual int calculateScore() const = 0; // Pure virtual method for score calculation
    virtual void applyBonus(int bonus) = 0; // Pure virtual method to apply bonuses
    virtual ~FrameBase() {}
};

#endif // FRAME_BASE_HPP
