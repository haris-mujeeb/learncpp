# Chapter 12: Pointers and References - Advanced C++ Concepts

This directory contains the C++ code examples, notes, and tests for advanced concepts related to pointers and references, as outlined in the GEMINI.md guide.

## Learning Path

### 1. Pointers and References Basics
*   **Concept:** Fundamental understanding of raw pointers, references, and their differences. Address-of operator, dereference operator, pointer arithmetic, null pointers.
*   **Task:** Review and reinforce basic pointer and reference usage, including array manipulation with pointers.

### 2. Smart Pointers & Resource Management (RAII)
*   **Concept:** `std::unique_ptr`, `std::shared_ptr`, `std::weak_ptr`, Custom Deleters, RAII principle.
*   **Challenge:** You're managing a dynamically allocated resource (e.g., a file handle, a network connection, or an object). How can you ensure this resource is *always* properly released, even if exceptions occur, without explicit `delete` calls?
*   **Task:** Implement a class that encapsulates a dynamically allocated array. Demonstrate how to use `std::unique_ptr` with a custom deleter to manage this array, ensuring memory is freed upon object destruction. Write `gtest` cases to verify correct allocation, deallocation, and ownership transfer.

### 3. Move Semantics & Rvalue References
*   **Concept:** Rvalue references (`&&`), `std::move`, Move Constructors, Move Assignment Operators, Copy Elision.
*   **Challenge:** You have a class with expensive copy operations (e.g., managing a large buffer). How can you optimize transfers of ownership for temporary objects or when explicitly indicating that a resource can be "stolen" from another object?
*   **Task:** Create a `MyVector` class that mimics a simplified `std::vector`. Implement move constructor and move assignment operator. Write `gtest` cases to confirm that move operations are indeed performed (e.g., by checking if the source object is left in a valid, "empty" state) and that copies are avoided when appropriate.

### 4. Perfect Forwarding & Variadic Templates
*   **Concept:** `std::forward`, Universal References (`T&&`), Template Metaprogramming basics, Parameter Packs.
*   **Challenge:** You want to create a generic factory function or a wrapper that takes an arbitrary number of arguments and forwards them perfectly to the constructor of another object, preserving their value category (lvalue/rvalue). How do you achieve this without creating an explosion of overloads?
*   **Task:** Implement a generic `make_unique_object` function that takes a type `T` and arbitrary arguments, then uses perfect forwarding to construct and return a `std::unique_ptr<T>`. Write `gtest` cases to verify that both lvalues and rvalues are correctly forwarded to `T`'s constructor.

### 5. Concurrency & Threading (C++11/14/17)
*   **Concept:** `std::thread`, `std::mutex`, `std::lock_guard`, `std::unique_lock`, `std::condition_variable`, `std::async`, `std::future`, `std::promise`, Atomic Operations.
*   **Challenge:** You need to perform a computation that can be broken down into independent sub-tasks. How can you leverage multiple CPU cores to speed this up, ensuring data consistency and avoiding race conditions?
*   **Task:** Implement a simple producer-consumer pattern using `std::thread`, `std::mutex`, and `std::condition_variable`. The producer adds items to a shared queue, and the consumer processes them. Write `gtest` cases to ensure thread safety, correct item processing, and no deadlocks.

### 6. Polymorphism & Virtual Functions (Advanced)
*   **Concept:** Virtual Destructors, Pure Virtual Functions, Abstract Base Classes, Virtual Inheritance (briefly touch upon diamond problem), CRTP (Curiously Recurring Template Pattern).
*   **Challenge:** You're designing a system with a hierarchy of related types, and you need to ensure proper cleanup for derived objects through a base class pointer. Also, how can you enforce certain functions *must* be implemented by derived classes, or explore static polymorphism where appropriate?
*   **Task:** Design a simple shape hierarchy (e.g., `Shape` base class, `Circle`, `Rectangle` derived classes). Ensure `Shape` has a virtual destructor. Implement a pure virtual `area()` method. Demonstrate usage with `std::unique_ptr<Shape>` and verify correct `area()` calculations and destructor calls using `gtest`. Briefly illustrate CRTP for a non-polymorphic utility if you feel up to it.

### 7. Error Handling: Exceptions vs. Error Codes vs. `std::optional`/`std::variant`
*   **Concept:** `try-catch`, `noexcept`, `std::exception`, custom exception classes, `std::optional<T>`, `std::variant<T, Error>`.
*   **Challenge:** When should you use exceptions, and when are error codes or value-based error handling mechanisms like `std::optional` or `std::variant` more appropriate? How do you design an API to clearly communicate potential failure modes?
*   **Task:** Create a function that attempts to parse an integer from a string. Implement two versions: one that throws a custom exception for invalid input, and another that returns `std::optional<int>` (or `std::variant<int, ParseError>`). Write `gtest` cases to test both success and failure scenarios for both versions.
