#include "Problem_191.hpp"
#include "Problem_192.hpp"
#include "Problem_193.hpp"
#include "Problem_194.hpp"
#include "Problem_195.hpp"
#include "Problem_196.hpp"
#include "Problem_197.hpp"
#include "Problem_198.hpp"

#include "gtest/gtest.h"

// Problem 191
TEST( Problem_191, Given_Case )
{
  // given the intervals (7, 9), (2, 4), (5, 8), return 1
  int result = non_overlapping_intervals( { { 7, 9 }, { 2, 4 }, { 5, 8 } } );

  EXPECT_EQ( result, 1 );
}

// Problem 192
TEST( Problem_192, Given_Case_1 )
{
  // For example, given the array [1, 3, 1, 2, 0, 1], we can go from indices 0 -> 1 -> 3 -> 5, so return true.

  bool result = canReachEnd( { 1, 3, 1, 2, 0, 1 } );

  EXPECT_TRUE( result );
}

TEST( Problem_192, Given_Case_2 )
{
  // Given the array [1, 2, 1, 0, 0], we can't reach the end, so return false.

  bool result = canReachEnd( { 1, 2, 1, 0, 0 } );

  EXPECT_FALSE( result );
}

// Problem 193

// Problem 194

// Problem 195

// Problem 196

// Problem 197

// Problem 198