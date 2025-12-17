#include <gtest/gtest.h>
#include "unique_array.hpp"

TEST(UniqueArrayTest, ConstructorAllocatesSize) {
    UniqueArray arr(5);
    EXPECT_EQ(arr.size(), 5);
}

TEST(UniqueArrayTest, AccessAndModify) {
    UniqueArray arr(3);
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;

    EXPECT_EQ(arr[0], 10);

    arr[1] = arr[0];
    EXPECT_EQ(arr[1], 10);
    EXPECT_EQ(arr[2], 30);
    
    // Test bounds checking
    EXPECT_THROW(arr[3], std::out_of_range);
}

TEST(UniqueArrayTest, MoveConstructorTransfersOwnership) {
    // 1. Create source
    UniqueArray source(10);
    source[0] = 99;

    // 2. Move construct destination from source
    // std::move casts 'source' to an r-value, triggering the move constructor.
    UniqueArray dest(std::move(source));

    // 3. Verify Destination has the resources
    EXPECT_EQ(dest.size(), 10);
    EXPECT_EQ(dest[0], 99);

    // 4. Verify Source is now empty (valid but empty state)
    EXPECT_EQ(source.size(), 0);
    // Accessing source[0] should now throw or be invalid depending on implementation,
    // but since size is 0, our bounds check handles it.
    EXPECT_THROW(source[0], std::out_of_range);
}

TEST(UniqueArrayTest, MoveAssignmentTransfersOwnership) {
    UniqueArray source(5);
    source[0] = 42;

    UniqueArray dest(2); // dest has its own memory initially
    
    // Move assignment: dest's original memory is freed, and it takes source's memory.
    dest = std::move(source);

    // Verify Dest
    EXPECT_EQ(dest.size(), 5);
    EXPECT_EQ(dest[0], 42);

    // Verify Source
    EXPECT_EQ(source.size(), 0);
}
