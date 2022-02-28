#include "gtest/gtest.h"

#include "problems_121_130/Problem_121.hpp"
#include "problems_121_130/Problem_122.hpp"
#include "problems_121_130/Problem_123.hpp"
#include "problems_121_130/Problem_124.hpp"
#include "problems_121_130/Problem_125.hpp"
#include "problems_121_130/Problem_126.hpp"
#include "problems_121_130/Problem_127.hpp"
#include "problems_121_130/Problem_128.hpp"
#include "problems_121_130/Problem_129.hpp"
#include "problems_121_130/Problem_130.hpp"


// Problem 121
TEST( Problem_121, Given_Case ) { EXPECT_TRUE( k_palindrome( "waterrfetawx", 2 ) ); }

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

  auto * root = new btNode( 10, new btNode( 5 ), new btNode( 15, new btNode( 11 ), new btNode( 15 ) ) );

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

  auto * root = new btNode( 10, new btNode( 5 ), new btNode( 15, new btNode( 11 ), new btNode( 15 ) ) );

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

// Problem 127
TEST( Problem_127, Given_Case )
{
  /*
  For example, given:
  9 -> 9
  5 -> 2
  return 124 (99 + 25) as:
  4 -> 2 -> 1
  */

  auto *      x      = new slNode<int>( { 9, 9 } );
  auto *      y      = new slNode<int>( { 5, 2 } );
  slNode<int> result = *sum( x, y );
  slNode<int> expected( { 4, 2, 1 } );

  EXPECT_EQ( result, expected );
}

TEST( Problem_127, Test_Case )
{
  /*
  For example, given:
  9 -> 9
  9 -> 9 -> 9
  return 1098 (99 + 999) as:
  8 -> 9 -> 0 -> 1
  */

  auto *      x      = new slNode<int>( { 9, 9 } );
  auto *      y      = new slNode<int>( { 9, 9, 9 } );
  slNode<int> result = *sum( x, y );
  slNode<int> expected( { 8, 9, 0, 1 } );

  EXPECT_EQ( result, expected );
}

// Problem 128
TEST( Problem_128, Given_Case )
{
  /*
    For example, with n = 3, we can do this in 7 moves:

    Move 1 to 3
    Move 1 to 2
    Move 3 to 2
    Move 1 to 3
    Move 2 to 1
    Move 2 to 3
    Move 1 to 3
  */

  std::vector<std::pair<int, int>> expected = { std::make_pair( 1, 3 ), std::make_pair( 1, 2 ), std::make_pair( 3, 2 ),
                                                std::make_pair( 1, 3 ), std::make_pair( 2, 1 ), std::make_pair( 2, 3 ),
                                                std::make_pair( 1, 3 ) };
  std::vector<std::pair<int, int>> result   = solveHanoi( 3 );

  EXPECT_EQ( result, expected );
}

// Problem 129
TEST( Problem_129, Given_Case )
{
  double result = squareroot( 9 );

  EXPECT_DOUBLE_EQ( result, 3.0 );
}

// Problem 130
TEST( Problem_130, Given_Case )
{
  // [5, 2, 4, 0, 1] k = 2
  // Return 3

  std::vector<int> stocks = { 5, 2, 4, 0, 1 };

  int result = stonks( stocks, 2 );

  EXPECT_EQ( result, 3 );
}