#include <gtest/gtest.h>
#include <iostream>
#include "universal_logger.hpp"


class EllipsisTest : public ::testing::Test {};

TEST(EllipsisTest, RecursivePrinter) {
    std::ostringstream buffer;
    auto oldCoutBuf = std::cout.rdbuf(buffer.rdbuf());
    log_items("Error ", 404, " at ", 12.55, " PM"); 
    EXPECT_EQ(buffer.str(), "Error 404 at 12.55 PM\n");
    std::cout.rdbuf(oldCoutBuf);
}