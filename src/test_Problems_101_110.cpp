#include "Problem_101.hpp"
#include "Problem_102.hpp"
#include "Problem_103.hpp"
#include "Problem_104.hpp"

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

// Problem 102
TEST( Problem_102, Given_Case )
{
  // For example, if the list is [1, 2, 3, 4, 5] and K is 9,
  // then it should return [2, 3, 4], since 2 + 3 + 4 = 9.

  std::vector<int> nums     = { 1, 2, 3, 4, 5 };
  std::vector<int> expected = { 2, 3, 4 };
  std::vector<int> result   = continuousSum( nums, 9 );

  EXPECT_EQ( expected, result );
}