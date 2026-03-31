#include "read.hpp"

stepanov::repeatedChar* stepanov::readInput(std::istream& in, size_t& size)
{
  const size_t step = 10;
  size_t capacity = 10;
  auto* mem = new stepanov::repeatedChar[capacity];

  char next = '\0';
  in >> next;
  mem[0] = {0, next};
  while (!in.eof()) {
    if (size + 1 > capacity) {
      stepanov::repeatedChar* newMem = nullptr;
      try {
        newMem = new stepanov::repeatedChar[capacity + step];
      } catch (const std::bad_alloc& e) {
        delete[] mem;
        throw;
      }
      capacity += step;
      for (size_t i = 0; i < size; i++) {
        newMem[i] = mem[i];
      }
      delete[] mem;
      mem = newMem;
    }
    while (mem[size].second == next && !in.eof()) {
      mem[size].first++;
      in >> std::ws >> next;
    }
    size++;
    mem[size] = {0, next};
  }
  return mem;
}

