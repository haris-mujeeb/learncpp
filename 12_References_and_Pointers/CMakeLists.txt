cmake_minimum_required(VERSION 3.10)
project(LearnCppChapter12)

# Find GTest
find_package(GTest REQUIRED)

# Enable GTest discovery for tests in subdirectories
include(GoogleTest)

# Add subdirectories for each concept
# The first concept is smart_pointers
add_subdirectory(smart_pointers)