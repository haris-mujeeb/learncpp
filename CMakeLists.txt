cmake_minimum_required(VERSION 3.16)

project(learncpp LANGUAGES CXX)

# Set the C++ standard for the entire project to C++20 as per your goals.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set the build type to Debug to include debug symbols
# This is crucial for the debugger to work correctly.
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

# --- Google Test ---
# Use FetchContent to download and build GoogleTest automatically.
# This avoids needing to install it system-wide.
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
# Make GTest available to all subdirectories.
FetchContent_MakeAvailable(googletest)

# Enable testing for the project so CTest can discover and run tests.
enable_testing()

# Add the subdirectories that contain the CMakeLists.txt for each chapter.
# As you progress, you will add more lines like this.
add_subdirectory(12_References_and_Pointers)
add_subdirectory(20_Functions_Memory_Lambdas)
