#include "greeting.hpp"

namespace edu {

std::string make_greeting(std::string_view name) {
  if (name.empty()) {
    name = "world";
  }
  std::string result = "Hello, ";
  result += name;
  result += '!';
  return result;
}

}  // namespace edu
