#include "read.hpp"

stepanov::repeatedChar stepanov::readLine(std::istream& in, bool& badInput)
{
  repeatedChar line = {0, '\0'};
  if (!(in >> line.first)) {
    if (!in.eof()) {
      badInput = true;
    }
    return line;
  }
  if (!(in >> line.second)) {
    badInput = true;
  }
  return line;
}

stepanov::repeatedChar* stepanov::readInput(std::istream& in, size_t& size, bool& badInput)
{
  const size_t step = 10;
  size_t capacity = 10;
  auto* mem = new stepanov::repeatedChar[capacity];

  auto c = readLine(in, badInput);
  while (!in.eof() && !badInput) {
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
    mem[size] = c;
    size++;
    c = readLine(in, badInput);
  }
  return mem;
}
