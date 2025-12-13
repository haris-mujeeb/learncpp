add_executable(linked_list_test
    tests/linked_list_test.cpp
)

# Link the test executable against GTest.
target_link_libraries(linked_list_test PRIVATE GTest::gtest_main)

# Make headers available to the test executable
target_include_directories(linked_list_test PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

# Register the executable as a test with CTest.
include(GoogleTest)
gtest_add_tests(TARGET linked_list_test)