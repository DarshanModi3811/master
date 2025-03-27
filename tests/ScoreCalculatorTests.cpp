// #include "ScoreCalculator.hpp"
// #include <gtest/gtest.h>

// TEST(ScoreCalculatorTests, CalculateScoreForStrike) {
//     ScoreCalculator calculator;
//     std::vector<int> rolls = {10, 3, 4};
//     int score = calculator.calculateScore(rolls);
//     EXPECT_EQ(score, 24);
// }

// TEST(ScoreCalculatorTests, CalculateScoreForSpare) {
//     ScoreCalculator calculator;
//     std::vector<int> rolls = {5, 5, 3, 4};
//     int score = calculator.calculateScore(rolls);
//     EXPECT_EQ(score, 20);
// }

// TEST(ScoreCalculatorTests, CalculateScoreForOpenFrame) {
//     ScoreCalculator calculator;
//     std::vector<int> rolls = {3, 4, 5, 2};
//     int score = calculator.calculateScore(rolls);
//     EXPECT_EQ(score, 14);
// }

// TEST(ScoreCalculatorTests, CalculateScoreForPerfectGame) {
//     ScoreCalculator calculator;
//     std::vector<int> rolls(12, 10);
//     int score = calculator.calculateScore(rolls);
//     EXPECT_EQ(score, 300);
// }

// TEST(ScoreCalculatorTests, CalculateScoreForGutterGame) {
//     ScoreCalculator calculator;
//     std::vector<int> rolls(20, 0);
//     int score = calculator.calculateScore(rolls);
//     EXPECT_EQ(score, 0);
// }