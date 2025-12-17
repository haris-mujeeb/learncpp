#include <gtest/gtest.h>
#include "factory.hpp"
#include <string>
#include <vector>

struct Tracker
{
    std::string log;
    Tracker() { log = "Default"; };
    Tracker(int x) { log = "Int: " + std::to_string(x);}
    Tracker(int x, int y) { log = "Int, Int: " + std::to_string(x) + "," + std::to_string(y);}
    Tracker(const Tracker& other) { log = "Copy";}
    Tracker(Tracker&& other) noexcept { log = "Move";}
};



TEST(FactoryTest, ForwardsBasicArguments) {
    // Test forwarding of simple values (r-values)
    auto ptr = make_unique_object<Tracker>(10);
    EXPECT_EQ(ptr->log, "Int: 10");
}

TEST(FactoryTest, ForwardsLValueAsCopy) {
    Tracker original; // log is "Default"
    
    // Pass 'original' (an L-value) to the factory.
    // Expectation: It should call Tracker(const Tracker&) -> "Copy"
    auto ptr = make_unique_object<Tracker>(original);
    EXPECT_EQ(ptr->log, "Copy");
}

TEST(FactoryTest, ForwardsRValueAsMove) {
    Tracker original;
    
    // Pass 'std::move(original)' (an R-value) to the factory.
    // Expectation: It should call Tracker(Tracker&&) -> "Move"
    auto ptr = make_unique_object<Tracker>(std::move(original));

    EXPECT_EQ(ptr->log, "Move");
}

TEST(FactoryTest, WorksWithStandardContainers) {
    // Real world usage check
    auto vecPtr = make_unique_object<std::vector<int>>(3, 100); // size 3, value 100

    ASSERT_EQ(vecPtr->size(), 3);
    EXPECT_EQ(vecPtr->at(0), 100);
    EXPECT_EQ((*vecPtr)[1], 100);
    EXPECT_EQ(vecPtr->at(2), 100);
}