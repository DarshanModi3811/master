#ifndef FRAME_HPP
#define FRAME_HPP

#include <vector>
#include <numeric>

class Frame {
public:
    int roll1; // First roll score
    int roll2; // Second roll score
    std::vector<int> bonusRolls; // Bonus rolls for strikes/spares
    bool isStrike; // True if frame is a strike
    bool isSpare;  // True if frame is a spare

    Frame(int roll1, int roll2);        // Constructor
    int calculateFrameScore() const;   // Calculate score for the frame
};

#endif // FRAME_HPP
