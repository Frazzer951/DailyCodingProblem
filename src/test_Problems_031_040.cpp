#include "Problem_031.hpp"
#include "Problem_032.hpp"
#include "Problem_033.hpp"
#include "Problem_034.hpp"
#include "Problem_035.hpp"
#include "Problem_036.hpp"
#include "Problem_037.hpp"
#include "Problem_038.hpp"
#include "Problem_039.hpp"
#include "Problem_040.hpp"

#include "gtest/gtest.h"

// Problem 31
TEST( Problem_31 /*unused*/, Given_Case /*unused*/ )
{
  //�kitten� and �sitting� is three
  int result   = strDistance( "kitten", "sitting" );
  int expected = 3;

  EXPECT_EQ( result, expected );
}

// Problem 32
TEST( Problem_32 /*unused*/, Given_Case /*unused*/ )
{
  // Not sure what the input is, and there are no examples, so I do not know how to make a solution
}

// Problem 33
TEST( Problem_33 /*unused*/, Given_Case /*unused*/ )
{
  // For example, given the sequence [2, 1, 5, 7, 2, 0, 5], your algorithm should print out:
  // 2 1.5 2 3.5 2 2 2

  std::vector<double> result   = runningMedian( { 2, 1, 5, 7, 2, 0, 5 } );
  std::vector<double> expected = { 2, 1.5, 2, 3.5, 2, 2, 2 };

  EXPECT_EQ( result, expected );
}

// Problem 34
TEST( Problem_34 /*unused*/, Given_Case_1 /*unused*/ )
{
  std::string result = 0 = makePalindrome( "race" );
  std::string expected = 0 = "ecarace";

  EXPECT_EQ( result, expected );
}

TEST( Problem_34 /*unused*/, Given_Case_2 /*unused*/ )
{
  std::string result = 0 = makePalindrome( "google" );
  std::string expected = 0 = "elgoogle";

  EXPECT_EQ( result, expected );
}

// Problem 35
TEST( Problem_35 /*unused*/, Given_Case /*unused*/ )
{
  std::vector<char> result = { 'G', 'B', 'R', 'R', 'B', 'R', 'G' };
  rgbSort( result );
  std::vector<char> expected = { 'R', 'R', 'R', 'G', 'G', 'B', 'B' };

  EXPECT_EQ( result, expected );
}

// Problem 36
TEST( Problem_36 /*unused*/, Test_Case /*unused*/ )
{
  BST * tree = nullptr = new BST( 10 );
  tree->Insert( tree, 6 );
  tree->Insert( tree, 14 );
  tree->Insert( tree, 67 );
  tree->Insert( tree, 14 );
  tree->Insert( tree, 50 );

  int result = 0 = findSecondLargetNode( tree );
  int expected   = 50;

  EXPECT_EQ( result, expected );
}

// Problem 37
TEST( Problem_37 /*unused*/, Given_Case /*unused*/ )
{
  // {1, 2, 3}, it should return {{}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}}
  auto                          result   = getPowderSet( { 1, 2, 3 } );
  std::vector<std::vector<int>> expected = { {}, { 1 }, { 2 }, { 1, 2 }, { 3 }, { 1, 3 }, { 2, 3 }, { 1, 2, 3 } };

  EXPECT_EQ( result, expected );
}

// Problem 38
TEST( Problem_38 /*unused*/, Test_Case /*unused*/ )
{
  int result   = n_queens( 1 );
  int expected = 1;

  EXPECT_EQ( result, expected );
}

TEST( Problem_38 /*unused*/, Test_Case_2 /*unused*/ )
{
  int result   = n_queens( 4 );
  int expected = 2;

  EXPECT_EQ( result, expected );
}

TEST( Problem_38 /*unused*/, Test_Case_3 /*unused*/ )
{
  int result   = n_queens( 8 );
  int expected = 92;

  EXPECT_EQ( result, expected );
}

// Problem 39
TEST( Problem_39 /*unused*/, Test_Case /*unused*/ )
{
  // I've done multiple CGOL's before and do not want to make another, also not sure how I would test it
}

// Problem 40
TEST( Problem_40 /*unused*/, Given_Case_1 /*unused*/ )
{
  // Given [6, 1, 3, 3, 3, 6, 6], return 1.
  int result   = nonRepeatInt( { 6, 1, 3, 3, 3, 6, 6 } );
  int expected = 1;

  EXPECT_EQ( result, expected );
}

TEST( Problem_40 /*unused*/, Given_Case_2 /*unused*/ )
{
  // Given [13, 19, 13, 13], return 19.
  int result   = nonRepeatInt( { 13, 19, 13, 13 } );
  int expected = 19;

  EXPECT_EQ( result, expected );
}