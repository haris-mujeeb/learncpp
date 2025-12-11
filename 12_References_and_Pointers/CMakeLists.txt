# This CMakeLists.txt file manages all build targets for the "References and Pointers" chapter.

# To keep things organized, we'll handle each concept (smart_pointers, move_semantics, etc.) here.

add_subdirectory(pointers_and_references_basics)
add_subdirectory(smart_pointers)
add_subdirectory(linked_list)
add_subdirectory(move_semantics)
add_subdirectory(perfect_forwarding)
add_subdirectory(concurrency)
add_subdirectory(polymorphism_advanced)
add_subdirectory(error_handling)