#pragma once

#include <string>
#include <string_view>

namespace edu {

// Returns "Hello, <name>!", or "Hello, world!" when name is empty.
std::string make_greeting(std::string_view name);

}  // namespace edu
