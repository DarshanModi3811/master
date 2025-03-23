#include "../Frame/StrikeFrame.hpp"
#include "../Frame/SpareFrame.hpp"
#include "../Frame/OpenFrame.hpp"
#include "FrameFactory.hpp"

// Factory method to create a Frame object
std::shared_ptr<FrameBase> FrameFactory::createFrame(int roll1, int roll2) {
    if (roll1 == 10) {
        return std::make_shared<StrikeFrame>();
    } else if (roll1 + roll2 == 10) {
        return std::make_shared<SpareFrame>(roll1, roll2);
    } else {
        return std::make_shared<OpenFrame>(roll1, roll2);
    }
}
