# CMakeLists.txt for lambdas module

cmake_minimum_required(VERSION 3.10)
project(lambdas)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(lambdas_test
    tests/lambdas_test.cpp
)

target_link_libraries(lambdas_test PRIVATE GTest::gtest_main)

target_include_directories(lambdas_test PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

include(GoogleTest)
gtest_discover_tests(lambdas_test)
