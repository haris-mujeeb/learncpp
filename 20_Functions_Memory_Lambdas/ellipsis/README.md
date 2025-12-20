# Variadic Templates (Modern Ellipsis)

## Project: Universal Logger
This project implements a type-safe logging utility that can accept any number of arguments of mixed types, replacing the unsafe C-style `printf`.

## Core Concepts Learned

### 1. Parameter Packs
*   **Template Pack:** `template <typename... Args>` defines a pack of types.
*   **Function Pack:** `Args... rest` defines a pack of values.
*   **Expansion:** Using `...` to unpack arguments.

### 2. Compile-Time Recursion
*   **Head & Tail Pattern:** The function processes the first argument (`first`) and recursively calls itself with the remaining arguments (`rest...`).
*   **Base Case:** A non-variadic overload (or empty function) is required to handle the end of the recursion when the parameter pack is empty.

### 3. Type Safety
*   Unlike C-style ellipsis (`...`), Variadic Templates preserve type information at compile time.
*   This allows passing objects like `std::string` or custom classes without undefined behavior.

## Key Functions
*   `log_items(T first, Args... rest)`: The recursive template that prints one item and forwards the rest.
*   `log_items()`: The base case function that terminates the recursion (e.g., printing a newline).

## Future Optimizations (C++17)
*   **Fold Expressions:** In C++17, the recursive syntax can often be simplified to a single line like `(std::cout << ... << args);`.