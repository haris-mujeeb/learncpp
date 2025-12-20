#ifndef UNI_LOGGER_HPP
#define UNI_LOGGER_HPP

#include <iostream>

#if __cplusplus < 201703L
void log_items() {
  std::cout << '\n';
}

template <typename T, typename... Args>
void log_items(T first, Args... rest) {
  std::cout << first;
  log_items(rest...);
}
#else

template <typename... Args>
void log_items(Args... args) {
  (std::cout << ... << args) << '\n'; // Expands to: ((cout << arg1) << arg2) << arg3
}

#endif //  __cplusplus < 201703L

#if __cplusplus < 201703L
double sum_all() {
  return 0.0;
}

template <typename T, typename... Args>
auto sum_all(T first, Args... rest) {
  return first + sum_all(rest...);
}
# else

template <typename... Args>
auto sum_all(Args... args) {
  return (0.0 + ... + args); // Binary fold: 0.0 + arg1 + arg2 + ...
}
#endif //  __cplusplus < 201703L

#endif // UNI_LOGGER_HPP