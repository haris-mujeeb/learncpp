add_executable(perfect_forwarding_test
  tests/perfect_forwarding_test.cpp
)

target_link_libraries(perfect_forwarding_test PRIVATE GTest::gtest_main)

target_include_directories(perfect_forwarding_test PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

include(GoogleTest)
gtest_discover_tests(perfect_forwarding_test)