cmake_minimum_required(VERSION 3.10)

# Define the executable for the smart pointers tests
add_executable(smart_pointers_test
    tests/smart_pointer_test.cpp
    src/unique_array.cpp
)

# Link the executable against GTest
target_link_libraries(smart_pointers_test PRIVATE GTest::gtest_main)

# Include directories
target_include_directories(smart_pointers_test PRIVATE
    include
    src
)