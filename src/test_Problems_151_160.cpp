#include "gtest/gtest.h"

#include "problems_151_160/Problem_151.hpp"
#include "problems_151_160/Problem_152.hpp"
#include "problems_151_160/Problem_153.hpp"
#include "problems_151_160/Problem_154.hpp"
#include "problems_151_160/Problem_155.hpp"
#include "problems_151_160/Problem_156.hpp"
#include "problems_151_160/Problem_157.hpp"
#include "problems_151_160/Problem_158.hpp"
#include "problems_151_160/Problem_159.hpp"
#include "problems_151_160/Problem_160.hpp"

// Problem 151
TEST( Problem_151, Given_Case )
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
TEST( Problem_152, Given_Case )
{
  // given the numbers [1, 2, 3, 4] and probabilities [0.1, 0.5, 0.2, 0.2], your function should return 1 10% of the
  // time, 2 50% of the time, and 3 and 4 20% of the time.
  int result = randomProb( { 1, 2, 3, 4 }, { 0.1, 0.5, 0.2, 0.2 } );

  EXPECT_TRUE( result == 1 || result == 2 || result == 3 || result == 4 );
}

// Problem 153
TEST( Problem_153, Given_Case )
{
  // given words "hello", and "world" and a text content of "dog cat hello cat dog dog hello cat world", return 1

  EXPECT_EQ(
      smallestWordDistance( "hello", "world", { "dog", "cat", "hello", "cat", "dog", "dog", "hello", "cat", "world" } ),
      1 );
}

// Problem 154


// Problem 155
TEST( Problem_155, Given_Case )
{
  // given [1, 2, 1, 1, 3, 4, 0], return 1

  int result = majority( { 1, 2, 1, 1, 3, 4, 0 } );

  EXPECT_EQ( result, 1 );
}

// Problem 156
TEST( Problem_156, Given_Case_1 )
{
  // For example, given n = 13, return 2 since 13 = 32 + 22 = 9 + 4.
  EXPECT_EQ( num_squares( 13 ), 2 );
}

TEST( Problem_156, Given_Case_2 )
{
  // Given n = 27, return 3 since 27 = 32 + 32 + 32 = 9 + 9 + 9.
  EXPECT_EQ( num_squares( 27 ), 3 );
}

// Problem 157
TEST( Problem_157, Given_Case_1 )
{
  // carrace should return true
  EXPECT_TRUE( permPalindrome( "carrace" ) );
}

TEST( Problem_157, Given_Case_2 )
{
  // daily should return false
  EXPECT_FALSE( permPalindrome( "daily" ) );
}

// Problem 158
TEST( Problem_158, Given_Case )
{
  /*
    [[0, 0, 1],
     [0, 0, 1],
     [1, 0, 0]]

     return 2
  */

  std::vector<std::vector<int>> matrix = { { 0, 0, 1 }, { 0, 0, 1 }, { 1, 0, 0 } };
  int                           result = num_ways( matrix );
  EXPECT_EQ( result, 2 );
}

// Problem 159
TEST( Problem_159, Given_Case_1 )
{
  // given the string "acbbac", return "b".
  char result = firstRepeat( "acbbac" );
  EXPECT_EQ( result, 'b' );
}

TEST( Problem_159, Given_Case_2 )
{
  // Given the string "abcdef", return null.
  char result = firstRepeat( "abcdef" );
  EXPECT_EQ( result, '\0' );
}

// Problem 160
TEST( Problem_160, Given_Case )
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
  Node * b = new Node { 'b', {} };
  Node * c = new Node { 'c', {} };
  Node * f = new Node { 'f', {} };
  Node * g = new Node { 'g', {} };
  Node * h = new Node { 'h', {} };
  Node * e = new Node { 'e', { { 1, g }, { 1, h } } };
  Node * d = new Node { 'd', { { 2, e }, { 4, f } } };
  Node * a = new Node { 'a', { { 3, b }, { 5, c }, { 8, d } } };

  int longestPath = longest_path( a );

  EXPECT_EQ( longestPath, 17 );
}