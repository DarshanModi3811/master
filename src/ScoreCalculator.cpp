#include "ScoreCalculator.hpp"
#include "Frame/StrikeFrame.hpp"
#include "Frame/SpareFrame.hpp"
#include <stdexcept>
#include <iostream>

using namespace std;

// Adds bonuses for strikes/spares
void ScoreCalculator::applyBonuses(vector<shared_ptr<FrameBase>>& frames) {
    lock_guard<mutex> lock(mtx);
    try {
        for (size_t i = 0; i < frames.size(); ++i) {
            if (!frames[i]) {
                throw logic_error("Null frame detected in applyBonuses.");
            }

            // For frames 0–8, apply usual bonus rules
            if (i < 9) {
                if (dynamic_cast<StrikeFrame*>(frames[i].get())) {
                    if (i + 1 < frames.size()) {
                        // First bonus: First roll of the next frame
                        frames[i]->applyBonus(frames[i + 1]->getFirstRoll());
                
                        // Second bonus: Either the second roll of the next frame or the first roll of the frame after that
                        if (dynamic_cast<StrikeFrame*>(frames[i + 1].get()) && i + 2 < frames.size()) {
                            // If the next frame is a strike, take the first roll of the frame after that
                            frames[i]->applyBonus(frames[i + 2]->getFirstRoll());
                        } else {
                            // Otherwise, take the second roll of the next frame
                            frames[i]->applyBonus(frames[i + 1]->getSecondRoll());
                        }
                    }
                }
                else if (dynamic_cast<SpareFrame*>(frames[i].get())) {
                    if (i + 1 < frames.size()) {
                        frames[i]->applyBonus(frames[i + 1]->getFirstRoll());
                    }
                }
            } else if (i == 9) { // 10th Frame (special handling)
                // No extra handling needed; bonuses are already processed in the frame itself.
                // Ensure the 10th frame is self-contained
                if (dynamic_cast<StrikeFrame*>(frames[i].get())) {
                    frames[i]->applyBonus(frames[i]->getSecondRoll());
                    frames[i]->applyBonus(frames[i]->getThirdRoll());
                } else if (dynamic_cast<SpareFrame*>(frames[i].get())) {
                    frames[i]->applyBonus(frames[i]->getThirdRoll());
                }
            }
        }
    } catch (const exception& e) {
        cerr << "Error in applyBonuses: " << e.what() << endl;
    }
}

// Calculates the total score
int ScoreCalculator::calculateTotalScore(const vector<shared_ptr<FrameBase>>& frames) const {
    lock_guard<mutex> lock(mtx);
    int totalScore = 0;
    for (const auto& frame : frames) {
        totalScore += frame->calculateScore();
    }
    return totalScore;
}
