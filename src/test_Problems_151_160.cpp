#include "Problem_151.hpp"
#include "Problem_152.hpp"
#include "Problem_153.hpp"

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