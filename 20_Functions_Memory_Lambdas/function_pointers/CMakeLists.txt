# CMakeLists.txt for function_pointers module

cmake_minimum_required(VERSION 3.10)
project(function_pointers)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(function_pointers_test
    tests/function_pointers_test.cpp
)

target_link_libraries(function_pointers_test PRIVATE GTest::gtest_main)

target_include_directories(function_pointers_test PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

include(GoogleTest)
gtest_discover_tests(function_pointers_test)
