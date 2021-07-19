#include "Problem_121.hpp"
#include "Problem_122.hpp"
#include "Problem_123.hpp"
#include "Problem_124.hpp"
#include "Problem_125.hpp"
#include "Problem_126.hpp"

#include "gtest/gtest.h"

// Problem 121
TEST(Problem_121, Given_Case){
  EXPECT_TRUE(k_palindrome("waterrfetawx", 2));
  }

// Problem 122
TEST( Problem_122, Given_Case )
{
  std::vector<std::vector<int>> coins = { { 0, 3, 1, 1 }, { 2, 0, 0, 4 }, { 1, 5, 3, 1 } };

  int result = maxCoins( coins );

  EXPECT_EQ( 12, result );
}

// Problem 123
TEST( Problem_123, Test_Case )
{
  /*
  True:
        "10", a positive integer
        "-10", a negative integer
        "10.1", a positive real number
        "-10.1", a negative real number
        "1e5", a number in scientific notation
  False:
        "a"
        "x 1"
        "a -2"
        "-"
  */
  EXPECT_TRUE( isNum( "10" ) );
  EXPECT_TRUE( isNum( "-10" ) );
  EXPECT_TRUE( isNum( "10.1" ) );
  EXPECT_TRUE( isNum( "-10.1" ) );
  EXPECT_TRUE( isNum( "1e5" ) );
  EXPECT_TRUE( isNum( "+10" ) );

  EXPECT_FALSE( isNum( "a" ) );
  EXPECT_FALSE( isNum( "x 1" ) );
  EXPECT_FALSE( isNum( "a -2" ) );
  EXPECT_FALSE( isNum( "-" ) );
  EXPECT_FALSE( isNum( "e" ) );
  EXPECT_FALSE( isNum( "e10" ) );
  EXPECT_FALSE( isNum( "5e" ) );
  EXPECT_FALSE( isNum( "5ee" ) );
  EXPECT_FALSE( isNum( "1." ) );
  EXPECT_FALSE( isNum( ".1" ) );
}

// Problem 124
TEST( Problem_124, Test_Case )
{
  EXPECT_DOUBLE_EQ( 0, expected_tosses( 1 ) );
  EXPECT_DOUBLE_EQ( 1, expected_tosses( 2 ) );
  EXPECT_DOUBLE_EQ( 2, expected_tosses( 4 ) );
}

// Problem 125
TEST( Problem_125, Given_Case )
{
  /*
  For example, given the following tree and K of 20

      10
     /   \
   5      15
         /  \
       11    15
  Return the nodes 5 and 15.
  */

  auto * root = new ibtNode( 10, new ibtNode( 5 ), new ibtNode( 15, new ibtNode( 11 ), new ibtNode( 15 ) ) );

  auto result   = two_sum( root, 20 );
  auto expected = std::make_pair( root->left, root->right );

  EXPECT_EQ( result, expected );
}

TEST( Problem_125, Test_Case )
{
  /*
  For example, given the following tree and K of 21

      10
     /   \
   5      15
         /  \
       11    15
  Return the nodes 10 and 11.
  */

  auto * root = new ibtNode( 10, new ibtNode( 5 ), new ibtNode( 15, new ibtNode( 11 ), new ibtNode( 15 ) ) );

  auto result   = two_sum( root, 21 );
  auto expected = std::make_pair( root, root->right->left );

  EXPECT_EQ( result, expected );
}

// Problem 126
TEST( Problem_126, Given_Case )
{
  // [1, 2, 3, 4, 5, 6] rotated by two becomes [3, 4, 5, 6, 1, 2].
  std::vector<int> v        = { 1, 2, 3, 4, 5, 6 };
  std::vector<int> expected = { 3, 4, 5, 6, 1, 2 };
  std::vector<int> result   = rotateVector( v, 2 );

  EXPECT_EQ( result, expected );
}