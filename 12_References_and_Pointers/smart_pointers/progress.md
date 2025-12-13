## Smart Pointers: `UniqueArray` Challenge

*   **Status:** Initial implementation of `UniqueArray` attempted.
*   **Findings:** Code review revealed fundamental issues with `std::unique_ptr` usage (using a pointer-to-a-pointer), incorrect move semantics syntax, and flawed bounds checking.
*   **Next Step:** Refactor `UniqueArray` based on review feedback. Then, implement the `gtest` suite in `smart_pointer_test.cpp` to verify all functionality, especially resource deallocation and move operations.