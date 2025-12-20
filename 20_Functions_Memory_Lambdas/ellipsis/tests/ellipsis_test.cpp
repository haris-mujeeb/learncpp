#include <gtest/gtest.h>
#include <iostream>
#include "universal_logger.hpp"


class UniversalLoggerTest : public ::testing::Test {};

TEST(UniversalLoggerTest, EmptyLogItems) {
    std::ostringstream buffer;
    auto oldCoutBuf = std::cout.rdbuf(buffer.rdbuf());
    log_items(); 
    EXPECT_EQ(buffer.str(), "\n");
    std::cout.rdbuf(oldCoutBuf);
}

TEST(UniversalLoggerTest, LogItems) {
    std::ostringstream buffer;
    auto oldCoutBuf = std::cout.rdbuf(buffer.rdbuf());
    log_items("Error ", 404, " at ", 12.55, " PM"); 
    EXPECT_EQ(buffer.str(), "Error 404 at 12.55 PM\n");
    std::cout.rdbuf(oldCoutBuf);
}

TEST(UniversalLoggerTest, LogItemsWithSpecialCharacters) {
    std::ostringstream buffer;
    auto oldCoutBuf = std::cout.rdbuf(buffer.rdbuf());
    log_items("Hello\nWorld\t!", "Error ", 404, " at ", 12.55, " PM"); 

    EXPECT_EQ(buffer.str(), "Hello\nWorld\t!Error 404 at 12.55 PM\n");
    std::cout.rdbuf(oldCoutBuf);

}

class SumAllTest : public ::testing::Test {};

TEST(SumAllTest, SumAllWithNoArguments) {
    auto correct_result = 0.0;
    auto result = sum_all();
    EXPECT_DOUBLE_EQ(result, correct_result);
}

TEST(SumAllTest, SumAllWithPositiveAndNegativeValues) {
    int val1 = 2;
    double val2 = -2.3;
    float val3 = 3.9;
    
    auto correct_result = val1 + val2 + val3;

    auto result = sum_all(val1, val2, val3);
    
    EXPECT_DOUBLE_EQ(result, correct_result);
}


TEST(SumAllTest, SumAllNumericOverflow) {
    // Large numbers to check overflow
    long long val1 = 1e18; // 1 trillion
    long long val2 = 2e18; // 2 trillion

    double result = sum_all(val1, val2);
    EXPECT_EQ(result, 3e18);
}