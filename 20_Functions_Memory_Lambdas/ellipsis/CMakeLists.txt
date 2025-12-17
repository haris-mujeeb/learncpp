# CMakeLists.txt for ellipsis module

cmake_minimum_required(VERSION 3.10)
project(ellipsis)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(ellipsis_test
    tests/ellipsis_test.cpp
)

target_link_libraries(ellipsis_test PRIVATE GTest::gtest_main)

target_include_directories(ellipsis_test PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

include(GoogleTest)
gtest_discover_tests(ellipsis_test)
