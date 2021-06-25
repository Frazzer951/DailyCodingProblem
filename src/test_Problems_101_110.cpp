#include "Problem_101.hpp"

#include "gtest/gtest.h"


// Problem 101
TEST( Problem_101, Given_Case )
{
  // Input: 4
  // Output: 2 + 2 = 4

  std::pair<int, int> result = primeSum( 4 );
  std::pair<int, int> expected( 2, 2 );

  EXPECT_EQ( expected, result );
}