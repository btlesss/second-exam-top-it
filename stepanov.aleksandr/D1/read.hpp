#ifndef READ_HPP
#define READ_HPP

#include <iostream>

namespace stepanov
{
  using repeatedChar = std::pair<size_t, char>;
  repeatedChar readLine(std::istream& in, bool& badInput);
  repeatedChar* readInput(std::istream& in, size_t& size, bool& badInput);
}

#endif
