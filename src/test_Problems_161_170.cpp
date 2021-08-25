#include "Problem_161.hpp"
#include "Problem_162.hpp"
#include "Problem_163.hpp"

#include "gtest/gtest.h"

// Problem 161
TEST( Problem_161, Given_Case )
{
  // given 1111 0000 1111 0000 1111 0000 1111 0000, return 0000 1111 0000 1111 0000 1111 0000 1111
  long int x      = 0xF0F0F0F0;
  long int result = reverse( x );

  EXPECT_EQ( result, 0x0F0F0F0F );
}

// Problem 162
TEST( Problem_162, Given_Case )
{
  /*
  given the list:
    dog
    cat
    apple
    apricot
    fish

  Return the list:
    d
    c
    app
    apr
    f
  */

  std::vector<std::string> lst      = { "dog", "cat", "apple", "apricot", "fish" };
  std::vector<std::string> expected = { "d", "c", "app", "apr", "f" };
  std::vector<std::string> result   = shortest_unique_prefix( lst );

  EXPECT_EQ( result, expected );
}