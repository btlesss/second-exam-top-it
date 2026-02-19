#include <iostream>

namespace stepanov
{
  using repeatedChar = std::pair<size_t, char>;
  repeatedChar readLine(std::istream& in, bool& success);
  repeatedChar* readInput(std::istream& in, size_t& size);
}

int main()
{
  size_t size = 0;
  stepanov::repeatedChar* data = nullptr;
  try {
    data = stepanov::readInput(std::cin, size);
  } catch (const std::bad_alloc& e) {
    std::cerr << "bad alloc\n";
    return 2;
  } catch (const std::runtime_error& e) {
    std::cerr << e.what() << '\n';
    return 1;
  }
  return 0;
}

stepanov::repeatedChar stepanov::readLine(std::istream& in, bool& success)
{
  repeatedChar line = { 0, '\0' };
  in >> line.first >> line.second;
  if (in.fail() && !in.eof()) {
    success = false;
    return line;
  }
  return line;
}

stepanov::repeatedChar* stepanov::readInput(std::istream& in, size_t& size)
{
  const size_t step = 10;
  size_t capacity = 10;
  auto* mem = new stepanov::repeatedChar[capacity];

  bool success = true;
  auto c = readLine(in, success);
  while (!in.eof() && success) {
    if (size + 1 >= capacity) {
      stepanov::repeatedChar* new_mem = nullptr;
      try {
        new_mem = new stepanov::repeatedChar[capacity + step];
      } catch (const std::bad_alloc& e) {
        delete[] mem;
        throw;
      }
      capacity += step;
      for (size_t i = 0; i < size; i++) {
        new_mem[i] = mem[i];
      }
      delete[] mem;
      mem = new_mem;
    }
    mem[size] = c;
    size++;
    c = readLine(in, success);
  }

  if (!success) {
    delete[] mem;
    throw std::runtime_error("bad input");
  }
  return mem;
}
