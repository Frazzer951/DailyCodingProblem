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
TEST( Problem_194, Test_Case_1 )
{
  int result = numIntersections( { 1, -3 }, { 5, 1 } );
  EXPECT_EQ( result, 0 );
}

TEST( Problem_194, Test_Case_2 )
{
  int result = numIntersections( { 1, 5 }, { 5, 1 } );
  EXPECT_EQ( result, 1 );
}

// Problem 195
TEST( Problem_195, Given_Case )
{
  /*
  [[1, 3, 7, 10, 15, 20],
   [2, 6, 9, 14, 22, 25],
   [3, 8, 10, 15, 25, 30],
   [10, 11, 12, 23, 30, 35],
   [20, 25, 30, 35, 40, 45]]
  And i1 = 1, j1 = 1, i2 = 3, j2 = 3, return 15
  */
  std::vector<std::vector<int>> matrix = { { 1, 3, 7, 10, 15, 20 },
                                           { 2, 6, 9, 14, 22, 25 },
                                           { 3, 8, 10, 15, 25, 30 },
                                           { 10, 11, 12, 23, 30, 35 },
                                           { 20, 25, 30, 35, 40, 45 } };

  int result = matrix_count_edge( matrix, 1, 1, 3, 3 );

  EXPECT_EQ( result, 15 );
}

// Problem 196

// Problem 197

// Problem 198