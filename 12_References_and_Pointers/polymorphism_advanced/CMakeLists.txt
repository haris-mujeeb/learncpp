# Executable for tests
add_executable(polymorphism_advanced_test 
  tests/polymorphism_advanced_test.cpp)

target_link_libraries(polymorphism_advanced_test PRIVATE GTest::gtest_main)

target_include_directories(polymorphism_advanced_test PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

include(GoogleTest)
gtest_discover_tests(polymorphism_advanced_test)