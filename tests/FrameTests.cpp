#include "Frame.hpp"
#include <gtest/gtest.h>

TEST(FrameTest, TestFrameInitialization) {
    Frame frame;
    EXPECT_EQ(frame.getScore(), 0);
    EXPECT_EQ(frame.isStrike(), false);
    EXPECT_EQ(frame.isSpare(), false);
}

TEST(FrameTest, TestFrameAddRoll) {
    Frame frame;
    frame.addRoll(5);
    EXPECT_EQ(frame.getScore(), 5);
    frame.addRoll(4);
    EXPECT_EQ(frame.getScore(), 9);
}

TEST(FrameTest, TestFrameStrike) {
    Frame frame;
    frame.addRoll(10);
    EXPECT_EQ(frame.isStrike(), true);
}

TEST(FrameTest, TestFrameSpare) {
    Frame frame;
    frame.addRoll(5);
    frame.addRoll(5);
    EXPECT_EQ(frame.isSpare(), true);
}