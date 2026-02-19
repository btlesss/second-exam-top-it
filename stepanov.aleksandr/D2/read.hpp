#ifndef READ_HPP
#define READ_HPP

#include <iostream>

namespace stepanov
{
  using repeatedChar = std::pair<size_t, char>;
  repeatedChar* readInput(std::istream& in, size_t& size);
}

#endif
