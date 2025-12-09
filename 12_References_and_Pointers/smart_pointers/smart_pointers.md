# Smart Pointers & Resource Management (RAII)

## The Challenge: Managing Dynamic Resources Safely

When we allocate memory or acquire resources (like file handles, network connections, etc.) dynamically using `new` or C-style functions, we take on the responsibility of releasing them with `delete` or corresponding release functions. What happens if an exception is thrown between allocation and deallocation? What if we simply forget to deallocate?

**Question:** How can C++ help us ensure that dynamically acquired resources are *always* released, even in the face of exceptions or complex control flows, without manual `delete` calls?

## The Principle: RAII (Resource Acquisition Is Initialization)

RAII is a C++ programming idiom that ties the lifecycle of a resource to the lifecycle of an object. The resource is acquired in the constructor and released in the destructor.

**Question:** Why is the destructor the perfect place for resource release in this context? What guarantees does C++ provide about destructor execution?

## `std::unique_ptr`: Exclusive Ownership

`std::unique_ptr` is a smart pointer that owns an object exclusively. When the `unique_ptr` goes out of scope, the owned object is automatically deleted.

**Question:** What are the key characteristics of `std::unique_ptr` that enforce exclusive ownership? How does it prevent common ownership-related bugs?

**Task:** Implement a class that encapsulates a dynamically allocated array. Demonstrate how to use `std::unique_ptr` with a custom deleter to manage this array, ensuring memory is freed upon object destruction. Write `gtest` cases to verify correct allocation, deallocation, and ownership transfer.

## `std::shared_ptr`: Shared Ownership

`std::shared_ptr` is a smart pointer that manages an object shared by multiple owners through a reference count. The object is deleted when the last `shared_ptr` goes out of scope.

**Question:** What problem does `std::shared_ptr` solve that `std::unique_ptr` does not address? What are the potential overheads or considerations when using `std::shared_ptr`?

## `std::weak_ptr`: Non-Owning Reference

`std::weak_ptr` is a non-owning smart pointer that holds a non-owning reference to an object managed by `std::shared_ptr`. It's used to break circular references that would prevent objects from being destroyed.

**Question:** When would `std::shared_ptr` create a circular dependency, and how does `std::weak_ptr` resolve this issue? How do you safely access the managed object through a `std::weak_ptr`?

## Custom Deleters

Both `std::unique_ptr` and `std::shared_ptr` can be supplied with custom deleters, allowing them to manage resources that are not allocated with `new` (e.g., C-style `malloc`, file handles, custom factories).

**Question:** Why are custom deleters important for integrating smart pointers with existing C APIs or custom resource management schemes? How do you define and pass a custom deleter to a smart pointer?
