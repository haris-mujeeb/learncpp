# Recursion & Tree Structures

## Project: Virtual File System (VFS) Analyzer
This project implements a mock file system structure to demonstrate the power of recursion in handling hierarchical data (Trees).

## Core Concepts Learned

### 1. Recursion Mechanics
*   **The Stack:** Learned that every recursive call creates a new stack frame with its own local variables.
*   **Base Case:** The critical condition (e.g., `node == nullptr` or a leaf node) that stops the recursion to prevent Stack Overflow.
*   **Recursive Step:** The logic where the function calls itself with a smaller part of the problem (e.g., iterating through a directory's children).

### 2. Tree Traversal (DFS)
*   Implemented **Depth-First Search** to navigate the file system.
*   The algorithm dives deep into nested directories before backtracking, which is natural for calculating total sizes or finding file paths.

### 3. Smart Pointers in Recursive Structures
*   Used `std::unique_ptr` to manage the lifecycle of tree nodes automatically.
*   When a parent node is destroyed, the recursive destructor chain ensures all children are freed without memory leaks.

## Key Functions
*   `getTotalSize(Node*)`: Recursively sums the size of files in a directory and its sub-directories.
*   `findPath(Node*, target)`: Searches the tree for a specific file name and reconstructs the full path string as the recursion unwinds.

## Common Pitfalls Avoided
*   **Infinite Recursion:** Ensuring the base case is always reachable.
*   **Cycles:** Understanding that tree structures (unlike general graphs) are acyclic, making simple recursion safe without visited-node tracking.