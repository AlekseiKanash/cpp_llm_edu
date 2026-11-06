#include <iostream>
#include <string_view>

#include "greeting.hpp"

int main(int argc, char** argv) {
  std::string_view name = argc > 1 ? argv[1] : "";
  std::cout << edu::make_greeting(name) << '\n';
  return 0;
}
