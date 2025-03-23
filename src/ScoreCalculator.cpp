#include "ScoreCalculator.hpp"
#include "Frame/StrikeFrame.hpp"

// Adds bonuses for strikes/spares
void ScoreCalculator::applyBonuses(std::vector<std::shared_ptr<FrameBase>>& frames) {
    for (size_t i = 0; i < frames.size(); ++i) {
        if (i + 1 < frames.size()) {
            frames[i]->applyBonus(frames[i + 1]->calculateScore());
        }
        if (i + 2 < frames.size() && dynamic_cast<StrikeFrame*>(frames[i].get())) {
            frames[i]->applyBonus(frames[i + 2]->calculateScore());
        }
    }
}

// Calculates the total score
int ScoreCalculator::calculateTotalScore(const std::vector<std::shared_ptr<FrameBase>>& frames) const {
    int totalScore = 0;
    for (const auto& frame : frames) {
        totalScore += frame->calculateScore();
    }
    return totalScore;
}
