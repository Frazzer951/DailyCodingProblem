#include "gtest/gtest.h"

#include "problems_191_200/Problem_191.hpp"
#include "problems_191_200/Problem_192.hpp"
#include "problems_191_200/Problem_193.hpp"
#include "problems_191_200/Problem_194.hpp"
#include "problems_191_200/Problem_195.hpp"
#include "problems_191_200/Problem_196.hpp"
#include "problems_191_200/Problem_197.hpp"
#include "problems_191_200/Problem_198.hpp"
#include "problems_191_200/Problem_199.hpp"
#include "problems_191_200/Problem_200.hpp"

// Problem 191
TEST( Problem_191, Given_Case ) {
  // given the intervals (7, 9), (2, 4), (5, 8), return 1
  int const result = non_overlapping_intervals( {
      {7, 9},
      {2, 4},
      {5, 8}
  } );

  EXPECT_EQ( result, 1 );
}

// Problem 192
TEST( Problem_192, Given_Case_1 ) {
  // For example, given the array [1, 3, 1, 2, 0, 1], we can go from indices 0 -> 1 -> 3 -> 5, so return true.

  bool const result = canReachEnd( { 1, 3, 1, 2, 0, 1 } );

  EXPECT_TRUE( result );
}

TEST( Problem_192, Given_Case_2 ) {
  // Given the array [1, 2, 1, 0, 0], we can't reach the end, so return false.

  bool const result = canReachEnd( { 1, 2, 1, 0, 0 } );

  EXPECT_FALSE( result );
}

// Problem 193
TEST( Problem_193, Given_Case ) {
  // given [1, 3, 2, 8, 4, 10] and fee = 2, you should return 9
  int const result = maxProfit( { 1, 3, 2, 8, 4, 10 }, 2 );

  EXPECT_EQ( result, 9 );
}

// Problem 194
TEST( Problem_194, Test_Case_1 ) {
  int const result = numIntersections( { 1, -3 }, { 5, 1 } );
  EXPECT_EQ( result, 0 );
}

TEST( Problem_194, Test_Case_2 ) {
  int const result = numIntersections( { 1, 5 }, { 5, 1 } );
  EXPECT_EQ( result, 1 );
}

// Problem 195
TEST( Problem_195, Given_Case ) {
  /*
  [[1, 3, 7, 10, 15, 20],
   [2, 6, 9, 14, 22, 25],
   [3, 8, 10, 15, 25, 30],
   [10, 11, 12, 23, 30, 35],
   [20, 25, 30, 35, 40, 45]]
  And i1 = 1, j1 = 1, i2 = 3, j2 = 3, return 15
  */
  std::vector<std::vector<int>> const matrix = {
    { 1,  3,  7, 10, 15, 20},
    { 2,  6,  9, 14, 22, 25},
    { 3,  8, 10, 15, 25, 30},
    {10, 11, 12, 23, 30, 35},
    {20, 25, 30, 35, 40, 45}
  };

  int const result = matrix_count_edge( matrix, 1, 1, 3, 3 );

  EXPECT_EQ( result, 15 );
}

// Problem 196
TEST( Problem_196, Given_Case ) {
  /*
  For example, given the following tree:

    5
   / \
  2  -5
  Return 2 as it occurs twice: once as the left leaf, and once as the sum of 2 + 5 - 5.
  */

  auto *root = new btNode( 5, new btNode( 2 ), new btNode( -5 ) );

  int const result = frequen_subtree_sum( root );

  EXPECT_EQ( result, 2 );
}

// Problem 197
TEST( Problem_197, Test_Case ) {
  std::vector<int> const arr      = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  std::vector<int> const result   = rotateArr( arr, 5 );
  std::vector<int> const expected = { 5, 6, 7, 8, 9, 1, 2, 3, 4 };

  EXPECT_EQ( result, expected );
}

// Problem 198

// Problem 199
TEST( Problem_199, Given_Case_1 ) {
  // For example, given "(()", you could return "(())".
  std::string const result = balanceParentheses( "(()" );

  EXPECT_EQ( result, "(())" );
}

TEST( Problem_199, Given_Case_2 ) {
  // Given "))()(", you could return "()()()()".
  std::string const result = balanceParentheses( "))()(" );

  EXPECT_EQ( result, "()()()()" );
}

// Problem 200
TEST( Problem_200, Given_Case ) {
  std::vector<int> const result   = get_points( {
      {1,  4},
      {4,  5},
      {7,  9},
      {9, 12}
  } );
  std::vector<int> const expected = { 4, 9 };

  EXPECT_EQ( result, expected );
}