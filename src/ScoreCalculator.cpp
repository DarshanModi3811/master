#include "ScoreCalculator.hpp"
#include "Frame/StrikeFrame.hpp"
#include <stdexcept>
#include <iostream>
#include "../src/Frame/SpareFrame.hpp"

using namespace std;
// Adds bonuses for strikes/spares
void ScoreCalculator::applyBonuses(vector<shared_ptr<FrameBase>>& frames) {
    try {
        for (size_t i = 0; i < frames.size(); ++i) {
            if (!frames[i]) {
                throw logic_error("Null frame detected in applyBonuses.");
            }

            // For frames 1–9, apply usual bonus rules
            if (i < 9) {
                if (i + 1 < frames.size()) {
                    frames[i]->applyBonus(frames[i + 1]->calculateScore());
                }
                if (i + 2 < frames.size() && dynamic_cast<StrikeFrame*>(frames[i].get())) {
                    frames[i]->applyBonus(frames[i + 2]->calculateScore());
                }
            } 
	    else if (i == 9) { // 10th Frame (special handling)
                // No extra handling needed; bonuses are already processed in the frame itself.
            }
        }
    } catch (const exception& e) {
        cerr << "Error in applyBonuses: " << e.what() << endl;
    }
}

// Calculates the total score
int ScoreCalculator::calculateTotalScore(const vector<shared_ptr<FrameBase>>& frames) const {
    int totalScore = 0;
    for (const auto& frame : frames) {
        totalScore += frame->calculateScore();
    }
    return totalScore;
}
