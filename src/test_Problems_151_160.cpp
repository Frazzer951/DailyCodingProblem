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