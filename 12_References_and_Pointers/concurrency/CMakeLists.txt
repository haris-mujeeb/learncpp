# CMakeLists.txt for concurrency module

add_executable(concurrency_test
    tests/concurrency_test.cpp
)

target_link_libraries(concurrency_test PRIVATE GTest::gtest_main)

# Link against threads (required for std::thread on Linux/Unix)
find_package(Threads REQUIRED)
target_link_libraries(concurrency_test PRIVATE Threads::Threads)

target_include_directories(concurrency_test PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

include(GoogleTest)
gtest_discover_tests(concurrency_test)