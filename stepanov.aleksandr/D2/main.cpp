#include <iostream>

namespace stepanov
{
  using repeatedChar = std::pair<size_t, char>;
  repeatedChar* readInput(std::istream& in, size_t& size);
}

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
      std::cout << data[size - id - 1].second << ' ' << data[size - id - 1].first << '\n';
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
