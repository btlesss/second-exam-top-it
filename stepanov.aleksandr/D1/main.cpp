#include <iostream>
#include "read.hpp"

int main()
{
  size_t size = 0;
  stepanov::repeatedChar* data = nullptr;
  bool wasBadInput = false;
  try {
    data = stepanov::readInput(std::cin, size, wasBadInput);
  } catch (const std::bad_alloc& e) {
    std::cout << '\n';
    std::cerr << "bad alloc\n";
    return 2;
  }

  for (size_t id = size; id > 0; id--) {
    for (size_t rpt = 0; rpt < data[id - 1].first; rpt++) {
      std::cout << data[id - 1].second;
    }
  }
  std::cout << '\n';
  delete[] data;

  if (wasBadInput) {
    std::cerr << "bad input\n";
    return 1;
  }

  return 0;
}
