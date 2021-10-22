#include "Problem_151.hpp"
#include "Problem_152.hpp"
#include "Problem_153.hpp"
#include "Problem_154.hpp"
#include "Problem_155.hpp"
#include "Problem_156.hpp"
#include "Problem_157.hpp"
#include "Problem_158.hpp"
#include "Problem_159.hpp"
#include "Problem_160.hpp"

#include "gtest/gtest.h"

// Problem 151
TEST( Problem_151 /*unused*/, Given_Case /*unused*/ )
{
  /*
  For example, given the following matrix, and location pixel of (2, 2), and 'G' for green:

  B B W
  W W W
  W W W
  B B B
  Becomes

  B B G
  G G G
  G G G
  B B B
  */

  std::vector<std::vector<char>> matrix = {
    { 'B', 'B', 'W' }, { 'W', 'W', 'W' }, { 'W', 'W', 'W' }, { 'B', 'B', 'B' }
  };
  std::vector<std::vector<char>> expected = {
    { 'B', 'B', 'G' }, { 'G', 'G', 'G' }, { 'G', 'G', 'G' }, { 'B', 'B', 'B' }
  };
  std::vector<std::vector<char>> result = pixleReplace( matrix, std::make_pair( 2, 2 ), 'G' );

  EXPECT_EQ( result, expected );
}

// Problem 152
TEST( Problem_152 /*unused*/, Given_Case /*unused*/ )
{
  // given the numbers [1, 2, 3, 4] and probabilities [0.1, 0.5, 0.2, 0.2], your function should return 1 10% of the
  // time, 2 50% of the time, and 3 and 4 20% of the time.
  int result = randomProb( { 1, 2, 3, 4 }, { 0.1, 0.5, 0.2, 0.2 } );

  EXPECT_TRUE( result == 1 || result == 2 || result == 3 || result == 4 );
}

// Problem 153
TEST( Problem_153 /*unused*/, Given_Case /*unused*/ )
{
  // given words "hello", and "world" and a text content of "dog cat hello cat dog dog hello cat world", return 1

  EXPECT_EQ(
      smallestWordDistance( "hello", "world", { "dog", "cat", "hello", "cat", "dog", "dog", "hello", "cat", "world" } ),
      1 );
}

// Problem 155
TEST( Problem_155 /*unused*/, Given_Case /*unused*/ )
{
  // given [1, 2, 1, 1, 3, 4, 0], return 1

  int result = majority( { 1, 2, 1, 1, 3, 4, 0 } );

  EXPECT_EQ( result, 1 );
}

// Problem 156
TEST( Problem_156 /*unused*/, Given_Case_1 /*unused*/ )
{
  // For example, given n = 13, return 2 since 13 = 32 + 22 = 9 + 4.
  EXPECT_EQ( num_squares( 13 ), 2 );
}

TEST( Problem_156 /*unused*/, Given_Case_2 /*unused*/ )
{
  // Given n = 27, return 3 since 27 = 32 + 32 + 32 = 9 + 9 + 9.
  EXPECT_EQ( num_squares( 27 ), 3 );
}

// Problem 157
TEST( Problem_157 /*unused*/, Given_Case_1 /*unused*/ )
{
  // carrace should return true
  EXPECT_TRUE( permPalindrome( "carrace" ) );
}

TEST( Problem_157 /*unused*/, Given_Case_2 /*unused*/ )
{
  // daily should return false
  EXPECT_FALSE( permPalindrome( "daily" ) );
}

// Problem 158
TEST( Problem_158 /*unused*/, Given_Case /*unused*/ )
{
  /*
    [[0, 0, 1],
     [0, 0, 1],
     [1, 0, 0]]

     return 2
  */

  std::vector<std::vector<int>> matrix = { { 0, 0, 1 }, { 0, 0, 1 }, { 1, 0, 0 } };
  int                           result = 0 = num_ways( matrix );
  EXPECT_EQ( result, 2 );
}

// Problem 159
TEST( Problem_159 /*unused*/, Given_Case_1 /*unused*/ )
{
  // given the string "acbbac", return "b".
  char result = firstRepeat( "acbbac" );
  EXPECT_EQ( result, 'b' );
}

TEST( Problem_159 /*unused*/, Given_Case_2 /*unused*/ )
{
  // Given the string "abcdef", return null.
  char result = firstRepeat( "abcdef" );
  EXPECT_EQ( result, '\0' );
}

// Problem 160
TEST( Problem_160 /*unused*/, Given_Case /*unused*/ )
{
  /*
     a
    /|\
   b c d
      / \
     e   f
    / \
   g   h
  and the weights: a-b: 3, a-c: 5, a-d: 8, d-e: 2, d-f: 4, e-g: 1, e-h: 1, the longest path would be c -> a -> d -> f,
  with a length of 17.
  */
  Node * b = nullptr = new Node { 'b', {} };
  Node * c = nullptr = new Node { 'c', {} };
  Node * f = nullptr = new Node { 'f', {} };
  Node * g = nullptr = new Node { 'g', {} };
  Node * h = nullptr = new Node { 'h', {} };
  Node * e = nullptr = new Node { 'e', { { 1, g }, { 1, h } } };
  Node * d = nullptr = new Node { 'd', { { 2, e }, { 4, f } } };
  Node * a = nullptr = new Node { 'a', { { 3, b }, { 5, c }, { 8, d } } };

  int longestPath = 0 = longest_path( a );

  EXPECT_EQ( longestPath, 17 );
}