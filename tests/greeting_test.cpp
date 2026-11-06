#include "greeting.hpp"

#include <gtest/gtest.h>

TEST(MakeGreeting, UsesGivenName) {
  EXPECT_EQ(edu::make_greeting("Ada"), "Hello, Ada!");
}

TEST(MakeGreeting, FallsBackToWorldWhenEmpty) {
  EXPECT_EQ(edu::make_greeting(""), "Hello, world!");
}
