#include "Problem_111.hpp"
#include "Problem_112.hpp"

#include "gtest/gtest.h"

// Problem 111
TEST( Problem_111, Given_Case )
{
  // given that W is "ab", and S is "abxaba", return 0, 3, and 4.
  std::vector<int> expected = { 0, 3, 4 };
  std::vector<int> result   = anagramIndex( "ab", "abxaba" );

  EXPECT_EQ( expected, result );
}