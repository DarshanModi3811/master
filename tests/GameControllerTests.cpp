#include "GameController.hpp"
#include <gtest/gtest.h>

TEST(GameControllerTest, TestInitialization) {
    GameController gameController;
    ASSERT_EQ(gameController.getScore(), 0);
}

TEST(GameControllerTest, TestAddFrame) {
    GameController gameController;
    Frame frame;
    gameController.addFrame(frame);
    ASSERT_EQ(gameController.getFrames().size(), 1);
}

TEST(GameControllerTest, TestCalculateScore) {
    GameController gameController;
    Frame frame1;
    frame1.addRoll(5);
    frame1.addRoll(4);
    gameController.addFrame(frame1);

    Frame frame2;
    frame2.addRoll(3);
    frame2.addRoll(6);
    gameController.addFrame(frame2);

    ASSERT_EQ(gameController.calculateScore(), 18);
}