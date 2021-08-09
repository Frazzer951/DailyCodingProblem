#include "Problem_141.hpp"
#include "Problem_142.hpp"
#include "Problem_143.hpp"
#include "Problem_144.hpp"
#include "Problem_145.hpp"
#include "Problem_146.hpp"

#include "gtest/gtest.h"

// Problem 141
TEST( Problem_141, Test_Case )
{
  Stack s;
  s.push( 1, 0 );
  s.push( 2, 0 );
  s.push( 3, 0 );
  s.push( 1, 1 );
  s.push( 2, 1 );
  s.push( 3, 1 );
  s.push( 1, 2 );
  s.push( 2, 2 );
  s.push( 3, 2 );

  EXPECT_EQ( s.pop( 0 ), 3 );
  EXPECT_EQ( s.pop( 1 ), 3 );
  EXPECT_EQ( s.pop( 2 ), 3 );
  EXPECT_EQ( s.pop( 0 ), 2 );
  EXPECT_EQ( s.pop( 1 ), 2 );
  EXPECT_EQ( s.pop( 2 ), 2 );
  EXPECT_EQ( s.pop( 0 ), 1 );
  EXPECT_EQ( s.pop( 1 ), 1 );
  EXPECT_EQ( s.pop( 2 ), 1 );
}

// Problem 142
TEST( Problem_142, Given_Case )
{
  // For example, (()* and (*) are balanced. )*( is not balanced.

  EXPECT_TRUE( balanced( "(()*" ) );
  EXPECT_TRUE( balanced( "(*)" ) );
  EXPECT_FALSE( balanced( ")*(" ) );
}

// Problem 143
TEST( Problem_143, Given_Case )
{
  // For example, given x = 10 and lst = [9, 12, 3, 5, 14, 10, 10], one partition may be [9, 3, 5, 10, 10, 12, 14].

  std::vector<int> given    = { 9, 12, 3, 5, 14, 10, 10 };
  std::vector<int> expected = { 9, 3, 5, 10, 10, 12, 14 };
  std::vector<int> result   = partition( given, 10 );

  EXPECT_EQ( result, expected );
}

// Problem 145
TEST( Problem_145, Given_Case )
{
  // given 1 -> 2 -> 3 -> 4, return 2 -> 1 -> 4 -> 3
  auto *   root   = new slNode( 1, new slNode( 2, new slNode( 3, new slNode( 4 ) ) ) );
  slNode * result = swapEveryTwo( root );

  EXPECT_EQ( result->value, 2 );
  EXPECT_EQ( result->next->value, 1 );
  EXPECT_EQ( result->next->next->value, 4 );
  EXPECT_EQ( result->next->next->next->value, 3 );
}

// Problem 146
TEST( Problem_146, Given_Case )
{
  /*
     0
    / \
   1   0
      / \
     1   0
    / \
   0   0
  should be pruned to:

     0
    / \
   1   0
      /
     1
  */

  auto * root   = new ibtNode( 0, new ibtNode( 1 ),
                             new ibtNode( 0, new ibtNode( 1, new ibtNode( 0 ), new ibtNode( 0 ) ), new ibtNode( 0 ) ) );
  auto * result = pruneZeroBranches( root );

  EXPECT_EQ( result->value, 0 );
  EXPECT_EQ( result->left->value, 1 );
  EXPECT_EQ( result->right->value, 0 );
  EXPECT_EQ( result->right->left->value, 1 );
}