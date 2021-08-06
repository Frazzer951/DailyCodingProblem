#include "Problem_141.hpp"
#include "Problem_142.hpp"
#include "Problem_143.hpp"
#include "Problem_144.hpp"

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