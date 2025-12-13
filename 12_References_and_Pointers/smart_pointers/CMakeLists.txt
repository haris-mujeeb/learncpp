# CMakeLists.txt for smart_pointers module

# Define the executable for the smart pointers tests.
# The source paths are relative to this file's location.
add_executable(smart_pointers_test
    tests/smart_pointer_test.cpp
)

# Link the test executable against GTest.
# The GTest::gtest_main target is available from the top-level CMakeLists.txt.
target_link_libraries(smart_pointers_test PRIVATE GTest::gtest_main)

# Add the 'src' directory for smart_pointers to its include path.
# This allows #include "unique_array.hpp" to work from both the .cpp and the test file.
target_include_directories(smart_pointers_test PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

# Register the executable as a test with CTest.
include(GoogleTest)
gtest_add_tests(TARGET smart_pointers_test)