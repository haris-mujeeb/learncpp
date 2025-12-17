# CMakeLists.txt for recursion module

cmake_minimum_required(VERSION 3.10)
project(recursion)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(recursion_test
    tests/recursion_test.cpp
)

target_link_libraries(recursion_test PRIVATE GTest::gtest_main)

target_include_directories(recursion_test PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

include(GoogleTest)
gtest_discover_tests(recursion_test)
