#ifndef UNIQUE_ARRAY_HPP
#define UNIQUE_ARRAY_HPP

#include <memory>    // For std::unique_ptr
#include <cstddef>   // For size_t
#include <stdexcept> // For std::out_of_range
#include <utility>   // For std::move

// This custom deleter is crucial. std::unique_ptr<T> calls `delete`, but for
// an array allocated with `new T[]`, we MUST call `delete[]`.
template <typename T>
struct ArrayDeleter {
  void operator()(T* ptr) const {
    delete[] ptr;
  }
};

template <typename T>
class UniqueArray {
public:
  // Default constructor: creates an empty array.
  UniqueArray() : m_size(0), m_array(nullptr, ArrayDeleter<T>()) {}

  // Constructor: allocates a dynamic array of 'size' elements.
  explicit UniqueArray(size_t size)
      : m_size(size),
        // 1. Allocate with `new T[size]`.
        // 2. Pass the raw pointer and the custom deleter to the unique_ptr.
        m_array(size > 0 ? new T[size] : nullptr, ArrayDeleter<T>()) {}

  // Destructor is defaulted. The magic of RAII and unique_ptr is that when
  // m_array is destroyed, it will automatically invoke our ArrayDeleter.
  ~UniqueArray() = default;

  // --- Move Semantics ---
  // A move-only type cannot be copied.
  UniqueArray(const UniqueArray&) = delete;
  UniqueArray& operator=(const UniqueArray&) = delete;

  // Move constructor: "steals" the resource from the other object.
  UniqueArray(UniqueArray&& other) noexcept
      : m_size(other.m_size), m_array(std::move(other.m_array)) {
    // Leave the moved-from object in a valid, empty state.
    other.m_size = 0;
  }

  // Move assignment operator.
  UniqueArray& operator=(UniqueArray&& other) noexcept {
    if (this != &other) {
      // Steal the resources. The old resource in `this->m_array` is
      // automatically released by unique_ptr's move assignment.
      m_array = std::move(other.m_array);
      m_size = other.m_size;
      // Leave the moved-from object in a valid, empty state.
      other.m_size = 0;
    }
    return *this;
  }

  // --- Accessors ---
  T& operator[](size_t index) {
    // Correct bounds check: indices are 0 to size-1.
    if (index >= m_size) {
      throw std::out_of_range("Index out of bounds");
    }
    return m_array.get()[index];
  }

  const T& operator[](size_t index) const {
    if (index >= m_size) {
      throw std::out_of_range("Index out of bounds");
    }
    return m_array.get()[index];
  }

  // size() should be const as it doesn't modify the object.
  size_t size() const { return m_size; }

private:
  size_t m_size;
  // The member should BE a unique_ptr, not a raw pointer TO a unique_ptr.
  // We also provide our custom deleter as a template argument.
  std::unique_ptr<T, ArrayDeleter<T>> m_array;
};

#endif // UNIQUE_ARRAY_HPP