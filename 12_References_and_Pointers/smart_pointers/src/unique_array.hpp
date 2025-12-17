#ifndef UNIQUE_ARRAY_HPP
#define UNIQUE_ARRAY_HPP

#include <memory>
#include <cstdlib>
#include <stdexcept>
#include <utility>

// TODO: 1. Define a custom deleter struct (functor) named 'FreeDeleter'.
// It should overload operator() to take an int* and call std::free(ptr).
struct FreeDeleter {
  void operator()(int* ptr) const {
    std::free(ptr);
  }
};


class UniqueArray {
private:
    size_t m_size;
    std::unique_ptr<int[], FreeDeleter> m_data;
    // TODO: 2. Declare a std::unique_ptr member named 'm_data'.
    // It must hold an array of ints (int[]) and use your FreeDeleter.
    
public:
    // TODO: 3. Implement the Constructor.
    // - Take 'size' as an argument.
    // - Allocate memory using std::malloc(size * sizeof(int)).
    // - If malloc returns null, throw std::bad_alloc().
    // - Initialize m_data with this raw pointer.
    UniqueArray(size_t size) : m_size(size) {
      
      void* data_ptr = std::malloc(size * sizeof(int));
      
      if (data_ptr == nullptr){
        throw std::bad_alloc();
      }

      m_data.reset(static_cast<int*>(data_ptr));
    }

    int& operator[] (size_t index) {
      if (index >= m_size) {
        throw std::out_of_range("Index out of bounds");
      }
      return m_data[index];
    }

    size_t size() const {
      return m_size;
    }
    // TODO: 4. Implement Destructor (if needed) or rely on default?
    // Hint: If m_data is a unique_ptr, do you need a manual destructor? Answer: NO
    ~UniqueArray() = default;

    // Rule of Five: Explicitly allow moving, because destructor prevented implicit generation
    UniqueArray(UniqueArray&& other) noexcept
    : m_size(other.m_size), m_data(std::move(other.m_data)) {
      other.m_size = 0; // so that when bounds check are checked (e.g.  if (0 >= 0) becomes true),
                        //  the exception is thrown, 
    };

    UniqueArray& operator=(UniqueArray&& other) noexcept {
      if (this != &other) {
        m_size = other.m_size;
        m_data = std::move(other.m_data);
        other.m_size = 0; 
      }
      return *this;
    }

    // TODO: 5. Implement set/get for array access
    void setValue(size_t index, int value) {
      m_data[index] = value;
    }
    int getValue(size_t index) const {
      return m_data[index];
    }
    
    size_t getSize() const { return m_size; }
};

#endif // UNIQUE_ARRAY_HPP