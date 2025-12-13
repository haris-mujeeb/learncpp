cmake_minimum_required(VERSION 3.16)
project(move_semantics_project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(GoogleTest)

add_executable(ascii_art_test
  tests/ascii_art_tests.cpp
)

# Define a preprocessor macro that holds the path to the source directory
# target_compile_definitions(ascii_art_test PRIVATE IMAGE_FILE_PATH=${CMAKE_CURRENT_SOURCE_DIR}/images/capybara.jpeg)
# target_compile_definitions(ascii_art_test PRIVATE IMAGE_FILE_PATH=${CMAKE_CURRENT_SOURCE_DIR}/images/sunglasses.png)
target_compile_definitions(ascii_art_test PRIVATE IMAGE_FILE_PATH=${CMAKE_CURRENT_SOURCE_DIR}/images/light.png)
# target_compile_definitions(ascii_art_test PRIVATE IMAGE_FILE_PATH=${CMAKE_CURRENT_SOURCE_DIR}/images/haris.jpg)
# target_compile_definitions(ascii_art_test PRIVATE IMAGE_FILE_PATH=${CMAKE_CURRENT_SOURCE_DIR}/images/uni_siegen.jpg)
target_compile_definitions(ascii_art_test PRIVATE OUTPUT_TXT_FILE_PATH=${CMAKE_CURRENT_SOURCE_DIR}/output/output.txt)

target_link_libraries(ascii_art_test PRIVATE GTest::gtest_main)

target_include_directories(ascii_art_test PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

# Register the executable as a test with CTest.
gtest_add_tests(TARGET ascii_art_test)