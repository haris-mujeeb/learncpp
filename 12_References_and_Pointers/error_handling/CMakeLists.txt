add_executable(error_handling_test tests/error_handling_test.cpp)

target_link_libraries(error_handling_test PRIVATE GTest::gtest_main)

target_include_directories(error_handling_test PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

include(GoogleTest)
gtest_discover_tests(error_handling_test)