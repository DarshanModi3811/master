#ifndef SCORE_CALCULATOR_HPP
#define SCORE_CALCULATOR_HPP

#include <vector>
#include <memory>
#include "../src/Frame/FrameBase.hpp" // Polymorphic base class

class ScoreCalculator {
public:
    // Updates bonuses for strikes and spares dynamically
    void applyBonuses(std::vector<std::shared_ptr<FrameBase>>& frames);

    // Calculates the total score of all frames
    int calculateTotalScore(const std::vector<std::shared_ptr<FrameBase>>& frames) const;
};

#endif // SCORE_CALCULATOR_HPP
