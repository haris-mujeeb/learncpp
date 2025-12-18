#ifndef UNI_LOGGER_HPP
#define UNI_LOGGER_HPP

#include <iostream>


void log_items() {
  std::cout << '\n';
}

template <typename T, typename... Args>
void log_items(T first, Args... rest) {
  std::cout << first;
  log_items(rest...);
}

#endif // UNI_LOGGER_HPP