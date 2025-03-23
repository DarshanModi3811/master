cmake_minimum_required(VERSION 3.10)

# Set the project name
project(BowlingScoreCalculator)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the source files
set(SOURCES
    src/GameController.cpp
    src/FrameFactory/FrameFactory.cpp
    src/IOHandler.cpp
    src/ScoreCalculator.cpp
    src/main.cpp
)

# Add the header files
set(HEADERS
    src/GameController.hpp
    src/Frame/FrameBase.hpp
    src/Frame/StrikeFrame.hpp
    src/Frame/SpareFrame.hpp
    src/Frame/OpenFrame.hpp
    src/FrameFactory/FrameFactory.hpp
    src/IOHandler.hpp
    src/ScoreCalculator.hpp
)

# Add the executable
add_executable(BowlingScoreCalculator ${SOURCES} ${HEADERS})

# Add the tests
enable_testing()

add_executable(GameControllerTests tests/GameControllerTests.cpp)
add_executable(FrameBaseTests tests/FrameTests/FrameBaseTests.cpp)
add_executable(StrikeFrameTests tests/FrameTests/StrikeFrameTests.cpp)
add_executable(SpareFrameTests tests/FrameTests/SpareFrameTests.cpp)
add_executable(OpenFrameTests tests/FrameTests/OpenFrameTests.cpp)

add_test(NAME GameControllerTests COMMAND GameControllerTests)
add_test(NAME FrameBaseTests COMMAND FrameBaseTests)
add_test(NAME StrikeFrameTests COMMAND StrikeFrameTests)
add_test(NAME SpareFrameTests COMMAND SpareFrameTests)
add_test(NAME OpenFrameTests COMMAND OpenFrameTests)
