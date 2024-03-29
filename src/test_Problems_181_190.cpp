#include "gtest/gtest.h"

#include "problems_181_190/Problem_181.hpp"
#include "problems_181_190/Problem_182.hpp"
#include "problems_181_190/Problem_183.hpp"
#include "problems_181_190/Problem_184.hpp"
#include "problems_181_190/Problem_185.hpp"
#include "problems_181_190/Problem_186.hpp"
#include "problems_181_190/Problem_187.hpp"
#include "problems_181_190/Problem_188.hpp"
#include "problems_181_190/Problem_189.hpp"
#include "problems_181_190/Problem_190.hpp"

// Problem 181
TEST( Problem_181, Given_Case_1 ) {
  // Given the input string racecarannakayak, return ["racecar", "anna", "kayak"].

  std::vector<std::string> const result   = splitPalindrome( "racecarannakayak" );
  std::vector<std::string> const expected = { "racecar", "anna", "kayak" };

  EXPECT_EQ( result, expected );
}

TEST( Problem_181, Given_Case_2 ) {
  // Given the input string abc, return ["a", "b", "c"].

  std::vector<std::string> const result   = splitPalindrome( "abc" );
  std::vector<std::string> const expected = { "a", "b", "c" };

  EXPECT_EQ( result, expected );
}

// Problem 182
TEST( Problem_182, Test_Case_1 ) {
  auto *n1 = new gNode { 1, {} };
  auto *n2 = new gNode { 2, {} };
  auto *n3 = new gNode { 3, {} };
  auto *n4 = new gNode { 4, {} };
  n1->connections.push_back( n2 );
  n1->connections.push_back( n4 );
  n2->connections.push_back( n1 );
  n2->connections.push_back( n3 );
  n3->connections.push_back( n2 );
  n3->connections.push_back( n4 );
  n4->connections.push_back( n1 );
  n4->connections.push_back( n3 );

  EXPECT_FALSE( isMinimallyConnected( n1 ) );
}

TEST( Problem_182, Test_Case_2 ) {
  auto *n1 = new gNode { 1, {} };
  auto *n2 = new gNode { 2, {} };
  auto *n3 = new gNode { 3, {} };
  auto *n4 = new gNode { 4, {} };
  n1->connections.push_back( n2 );
  n2->connections.push_back( n1 );
  n2->connections.push_back( n3 );
  n3->connections.push_back( n2 );
  n3->connections.push_back( n4 );
  n4->connections.push_back( n3 );

  EXPECT_TRUE( isMinimallyConnected( n1 ) );
}

// Problem 183

// Problem 184
TEST( Problem_184, Given_Case ) {
  // Given [42, 56, 14], return 14
  int const result = greatestCommonDenominator( { 42, 56, 14 } );

  EXPECT_EQ( result, 14 );
}

TEST( Problem_184, Test_Case ) {
  int const result = greatestCommonDenominator( { 8, 12, 20 } );

  EXPECT_EQ( result, 4 );
}

// Problem 185
TEST( Problem_185, Given_Case ) {
  /*
  {
    "top_left": (1, 4),
    "dimensions": (3, 3) # width, height
  }
  and

  {
      "top_left": (0, 5),
      "dimensions": (4, 3) # width, height
  }
  return 6.
  */

  Rect const r1 = {
    {1, 4},
    {3, 3}
  };
  Rect const r2 = {
    {0, 5},
    {4, 3}
  };

  int const area = intersectArea( r1, r2 );

  EXPECT_EQ( area, 6 );
}

TEST( Problem_185, Test_Case ) {
  Rect const r1 = {
    {0, 0},
    {2, 2}
  };
  Rect const r2 = {
    {2, 5},
    {4, 3}
  };

  int const area = intersectArea( r1, r2 );

  EXPECT_EQ( area, 0 );
}

// Problem 186

// Problem 187
TEST( Problem_187, Given_Case ) {
  /*
  Given:
  {
    "top_left": (1, 4),
    "dimensions": (3, 3) # width, height
  },
  {
      "top_left": (-1, 3),
      "dimensions": (2, 1)
  },
  {
      "top_left": (0, 5),
      "dimensions": (4, 3)
  }
  Return true
  */

  std::vector<Rect> const rectangles = {
    { { 1, 4 }, { 3, 3 }},
    {{ -1, 3 }, { 2, 1 }},
    { { 0, 5 }, { 4, 3 }}
  };

  EXPECT_TRUE( overlapping( rectangles ) );
}

// Problem 188

// Problem 189
TEST( Problem_189, Test_Case ) {
  // Given [5, 1, 3, 5, 2, 3, 4, 1] return 5

  std::vector<int> const arr = { 5, 1, 3, 5, 2, 3, 4, 1 };

  EXPECT_EQ( longestSubArray( arr ), 5 );
}

// Problem 190
TEST( Problem_190, Given_Case_1 ) {
  std::vector<int> const arr = { 8, -1, 3, 4 };
  EXPECT_EQ( maxCircSubArray( arr ), 15 );
}

TEST( Problem_190, Given_Case_2 ) {
  std::vector<int> const arr = { -4, 5, 1, 0 };
  EXPECT_EQ( maxCircSubArray( arr ), 6 );
}