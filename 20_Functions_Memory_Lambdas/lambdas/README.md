# Lambdas & Higher-Order Functions

## Project: Banking Transaction Analyzer
This project builds a flexible data processing engine to demonstrate how Lambdas allow passing "behavior" as data, enabling dynamic filtering and processing of transactions.

## Core Concepts Learned

### 1. Lambda Mechanics
*   **Closures:** Lambdas are objects that can "capture" local variables from their surrounding scope.
*   **Capture Lists:**
    *   `[=]`: Captures everything by value (copy). Read-only by default.
    *   `[&]`: Captures everything by reference. Allows modifying the original variable.
    *   `[var]`: Captures a specific variable.
*   **Mutable:** The `mutable` keyword allows a lambda to modify its *own copy* of a value-captured variable.

### 2. Higher-Order Functions
*   **Passing Lambdas:** Implemented a generic `process_transactions` function. Used **Templates** (`typename Predicate`) instead of `std::function` to allow the compiler to inline the lambda code for maximum performance.
*   **Returning Lambdas:** Implemented a "Factory" (`make_currency_converter`) that generates and returns a new function configured with specific parameters (like exchange rate).

### 3. Type Theory
*   Learned that every lambda has a unique, compiler-generated type (Closure Type).
*   Used `auto` to handle these types since they cannot be named explicitly.

## Key Functions
*   `process_transactions`: A generic engine that accepts any logic for filtering (Predicate) and processing (Consumer).
*   `make_currency_converter`: Demonstrates how to create functions dynamically based on runtime data.

## Common Pitfalls
*   **Dangling References:** Capturing a local variable by reference (`[&]`) in a lambda that outlives the function scope leads to crashes (accessing destroyed stack memory).
*   **Performance:** `std::function` has runtime overhead (virtual calls/heap alloc); Templates are preferred for tight loops.