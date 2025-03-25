#ifndef FRAME_FACTORY_HPP
#define FRAME_FACTORY_HPP

#include <memory>
#include "../Frame/FrameBase.hpp"

class FrameFactory {
public:
    static std::shared_ptr<FrameBase> createFrame(int roll1, int roll2); // Factory method
    // static std::shared_ptr<FrameBase> createFrame(int roll1, int roll2); // Add this line
};

#endif // FRAME_FACTORY_HPP
