#include "Problem_151.hpp"
#include "Problem_152.hpp"
#include "Problem_153.hpp"
#include "Problem_154.hpp"
#include "Problem_155.hpp"
#include "Problem_156.hpp"
#include "Problem_157.hpp"
#include "Problem_158.hpp"

#include "gtest/gtest.h"

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