# CMakeLists.txt for lambdas_captures module

cmake_minimum_required(VERSION 3.10)
project(lambdas_captures)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(lambdas_captures_test
    tests/lambdas_captures_test.cpp
)

target_link_libraries(lambdas_captures_test PRIVATE GTest::gtest_main)

target_include_directories(lambdas_captures_test PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

include(GoogleTest)
gtest_discover_tests(lambdas_captures_test)
