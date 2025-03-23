#include "IOHandler.hpp"
#include <gtest/gtest.h>

class IOHandlerTests : public ::testing::Test {
protected:
    IOHandler ioHandler;

    void SetUp() override {
        // Code here will be called immediately after the constructor (right before each test).
    }

    void TearDown() override {
        // Code here will be called immediately after each test (right before the destructor).
    }
};

TEST_F(IOHandlerTests, TestReadInput) {
    // Add your test code here
}

TEST_F(IOHandlerTests, TestWriteOutput) {
    // Add your test code here
}