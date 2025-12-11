add_executable(pointer_test
    src/pointer_sorter.cpp
    tests/pointer_test.cpp
)

# Link the test executable against GTest.
# The GTest::gtest_main target is available from the top-level CMakeLists.txt.
target_link_libraries(pointer_test PRIVATE GTest::gtest_main)

target_include_directories(pointer_test PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

# Register the executable as a test with CTest.
include(GoogleTest)
gtest_add_tests(TARGET pointer_test)