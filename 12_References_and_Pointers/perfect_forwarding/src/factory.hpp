#ifndef FACTORY_HPP
#define FACTORY_HPP

#include <memory>
#include <utility> // Required for std::forward

// T: The type of object to create
// Args: A parameter pack representing the types of the arguments
template <typename T, typename... Args>
std::unique_ptr<T> make_unique_object(Args&&... args){
// std::forward<Args>(args)... 
    // 1. Unpacks the arguments.
    // 2. Casts each one to R-value ONLY if it was passed as an R-value.
    // 3. Passes them to T's constructor.

    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

#endif // FACTORY_HPP