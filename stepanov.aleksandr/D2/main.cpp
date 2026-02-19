#include <iostream>
#include <cstring>

#include "read.hpp"

int main(int argc, char* argv[])
{
  bool reverse = false;
  if (argc > 2) {
    std::cerr << "too many arguments\n";
    return 1;
  } else if (argc == 2) {
    if (std::strcmp(argv[1], "reverse") == 0) {
      reverse = true;
    } else {
      std::cerr << "invalid argument\n";
      return 1;
    }
  }

  size_t size = 0;
  stepanov::repeatedChar* data = nullptr;
  try {
    data = stepanov::readInput(std::cin, size);
  } catch (const std::bad_alloc& e) {
    std::cout << '\n';
    std::cerr << "bad alloc\n";
    return 2;
  }

  for (size_t id = 0; id < size; id++) {
    if (reverse) {
      std::cout << data[size - id - 1].first << ' ' << data[size - id - 1].second << '\n';
    } else {
      std::cout << data[id].first << ' ' << data[id].second << '\n';
    }
  }
  if (size == 0) {
    std::cout << '\n';
  }
  delete[] data;
  return 0;
}
