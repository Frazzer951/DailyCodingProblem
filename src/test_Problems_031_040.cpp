#include "gtest/gtest.h"

#include "problems_031_040/Problem_031.hpp"
#include "problems_031_040/Problem_032.hpp"
#include "problems_031_040/Problem_033.hpp"
#include "problems_031_040/Problem_034.hpp"
#include "problems_031_040/Problem_035.hpp"
#include "problems_031_040/Problem_036.hpp"
#include "problems_031_040/Problem_037.hpp"
#include "problems_031_040/Problem_038.hpp"
#include "problems_031_040/Problem_039.hpp"
#include "problems_031_040/Problem_040.hpp"


// Problem 031
TEST( Problem_31, Given_Case )
{
  //“kitten” and “sitting” is three
  int result   = strDistance( "kitten", "sitting" );
  int expected = 3;

  EXPECT_EQ( result, expected );
}

// Problem 032


// Problem 033
TEST( Problem_33, Given_Case )
{
  // For example, given the sequence [2, 1, 5, 7, 2, 0, 5], your algorithm should print out:
  // 2 1.5 2 3.5 2 2 2

  std::vector<double> result   = runningMedian( { 2, 1, 5, 7, 2, 0, 5 } );
  std::vector<double> expected = { 2, 1.5, 2, 3.5, 2, 2, 2 };

  EXPECT_EQ( result, expected );
}

// Problem 034
TEST( Problem_34, Given_Case_1 )
{
  std::string result   = makePalindrome( "race" );
  std::string expected = "ecarace";

  EXPECT_EQ( result, expected );
}

TEST( Problem_34, Given_Case_2 )
{
  std::string result   = makePalindrome( "google" );
  std::string expected = "elgoogle";

  EXPECT_EQ( result, expected );
}
// Problem 035
TEST( Problem_35, Given_Case )
{
  std::vector<char> result = { 'G', 'B', 'R', 'R', 'B', 'R', 'G' };
  rgbSort( result );
  std::vector<char> expected = { 'R', 'R', 'R', 'G', 'G', 'B', 'B' };

  EXPECT_EQ( result, expected );
}

// Problem 036
TEST( Problem_36, Test_Case )
{
  BST * tree = new BST( 10 );
  tree->Insert( tree, 6 );
  tree->Insert( tree, 14 );
  tree->Insert( tree, 67 );
  tree->Insert( tree, 14 );
  tree->Insert( tree, 50 );

  int result   = findSecondLargetNode( tree );
  int expected = 50;

  EXPECT_EQ( result, expected );
}

// Problem 037
TEST( Problem_37, Given_Case )
{
  // {1, 2, 3}, it should return {{}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}}
  auto                          result   = getPowderSet( { 1, 2, 3 } );
  std::vector<std::vector<int>> expected = { {}, { 1 }, { 2 }, { 1, 2 }, { 3 }, { 1, 3 }, { 2, 3 }, { 1, 2, 3 } };

  EXPECT_EQ( result, expected );
}

// Problem 038

TEST( Problem_38, Test_Case )
{
  int result   = n_queens( 1 );
  int expected = 1;

  EXPECT_EQ( result, expected );
}

TEST( Problem_38, Test_Case_2 )
{
  int result   = n_queens( 4 );
  int expected = 2;

  EXPECT_EQ( result, expected );
}

TEST( Problem_38, Test_Case_3 )
{
  int result   = n_queens( 8 );
  int expected = 92;

  EXPECT_EQ( result, expected );
}

// Problem 039
TEST( Problem_39, Test_Case )
{
  std::vector<std::vector<bool>> board    = { { false, true, false }, { false, true, false }, { false, true, false } };
  std::vector<std::vector<bool>> expected = { { false, false, false }, { true, true, true }, { false, false, false } };
  game_of_life( board );

  EXPECT_EQ( board, expected );
}

// Problem 040
TEST( Problem_40, Given_Case_1 )
{
  // Given [6, 1, 3, 3, 3, 6, 6], return 1.
  int result   = nonRepeatInt( { 6, 1, 3, 3, 3, 6, 6 } );
  int expected = 1;

  EXPECT_EQ( result, expected );
}

TEST( Problem_40, Given_Case_2 )
{
  // Given [13, 19, 13, 13], return 19.
  int result   = nonRepeatInt( { 13, 19, 13, 13 } );
  int expected = 19;

  EXPECT_EQ( result, expected );
}