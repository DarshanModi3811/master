#include "../Frame/StrikeFrame.hpp"
#include "../Frame/SpareFrame.hpp"
#include "../Frame/OpenFrame.hpp"
#include "FrameFactory.hpp"
#include <stdexcept>
#include <iostream>

using namespace std;
// Factory method to create a Frame object
std::shared_ptr<FrameBase> FrameFactory::createFrame(int roll1, int roll2) {
    try {
        if (roll1 < 0 || roll1 > 10 || roll2 < 0 || roll2 > 10 || (roll1 + roll2 > 10 && roll1 != 10)) {
            throw std::out_of_range("Invalid roll values detected.");
        }

        if (roll1 == 10) {
            return std::make_shared<StrikeFrame>();
        } else if (roll1 + roll2 == 10) {
            return std::make_shared<SpareFrame>(roll1, roll2);
        } else {
            return std::make_shared<OpenFrame>(roll1, roll2);
        }
    } catch (const std::exception& e) {
        std::cerr << "Error in FrameFactory: " << e.what() << std::endl;
        return nullptr;
    }
}