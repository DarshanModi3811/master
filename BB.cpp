// #include <iostream>
// #include <vector>

// class Frame {
// public:
//     int roll1;      // First roll score
//     int roll2;      // Second roll score
//     int bonus;      // Bonus score (for strikes and spares)
//     int frameScore; // Total score for this frame

//     Frame() : roll1(0), roll2(0), bonus(0), frameScore(0) {}

//     // Method to calculate the frame score
//     void calculateFrameScore() {
//         frameScore = roll1 + roll2 + bonus;
//     }

//     // Check if the frame is a strike
//     bool isStrike() const {
//         return roll1 == 10;
//     }

//     // Check if the frame is a spare
//     bool isSpare() const {
//         return (roll1 + roll2 == 10) && !isStrike();
//     }
// };

// class Game {
// private:
//     std::vector<Frame> frames; // List of frames
//     int currentFrame;          // Index of the current frame
//     int totalScore;            // Total score of the game

// public:
//     Game() : currentFrame(0), totalScore(0) {
//         frames.resize(10); // Initialize 10 frames for a standard bowling game
//     }

//     // Method to start a new game
//     void startGame() {
//         currentFrame = 0;
//         totalScore = 0;
//         frames.clear();
//         frames.resize(10); // Reset frames
//     }

//     // Method to input rolls for the current frame
//     void inputRolls(int roll1, int roll2) {
//         if (currentFrame < 10) {
//             frames[currentFrame].roll1 = roll1;
//             frames[currentFrame].roll2 = roll2;
//             frames[currentFrame].calculateFrameScore();
//             totalScore += frames[currentFrame].frameScore;
//             currentFrame++;
//         }
//     }

//     // Method to calculate bonuses for strikes and spares
//     void calculateBonuses() {
//         for (int i = 0; i < frames.size(); ++i) {
//             if (frames[i].isStrike() && i < 9) { // Strike bonus
//                 frames[i].bonus += frames[i + 1].roll1; // Next frame's first roll
//                 if (i + 1 < frames.size() && frames[i + 1].isStrike() && i + 2 < frames.size()) {
//                     frames[i].bonus += frames[i + 2].roll1; // Next frame's second roll
//                 } else {
//                     frames[i].bonus += frames[i + 1].roll2; // Next frame's second roll
//                 }
//             } else if (frames[i].isSpare() && i < 9) { // Spare bonus
//                 frames[i].bonus += frames[i + 1].roll1; // Next frame's first roll
//             }
//         }
//     }

//     // Method to display the final score
//     void displayFinalScore() const {
//         std::cout << "Final Score: " << totalScore << std::endl;
//     }
// };

// int main() {
//     Game bowlingGame;
//     bowlingGame.startGame();

//     for (int i = 0; i < 10; ++i) {
//         int roll1, roll2;
//         std::cout << "Enter scores for Frame " << (i + 1) << " (Roll 1 and Roll 2): ";
//         std::cin >> roll1 >> roll2;

//         // Input validation can be added here

//         bowlingGame.inputRolls(roll1, roll2);
//     }

//     bowlingGame.calculateBonuses(); // Calculate bonuses after all frames are input
//     bowlingGame.displayFinalScore(); // Display the final score

//     return 0;
// }