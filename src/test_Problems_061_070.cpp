#include "Problem_061.hpp"
#include "Problem_062.hpp"
#include "Problem_063.hpp"
#include "Problem_064.hpp"
#include "Problem_065.hpp"
#include "Problem_066.hpp"

#include "gtest/gtest.h"

// Problem 61
TEST( Problem_61, Given_Case )
{
  double result = p61::pow( 2, 10 );

  EXPECT_DOUBLE_EQ( 1024, result );
}

TEST( Problem_61, Test_Case )
{
  double result = p61::pow( 5, -5 );

  EXPECT_DOUBLE_EQ( 0.00032, result );
}

// Problem 62
TEST( Problem_62, Given_Case_1 )
{
  int result = num_ways( 2, 2 );

  EXPECT_EQ( 2, result );
}

TEST( Problem_62, Given_Case_2 )
{
  int result = num_ways( 5, 5 );

  EXPECT_EQ( 70, result );
}

TEST( Problem_62, Test_Case )
{
  int result = num_ways( 2, 8 );

  EXPECT_EQ( 8, result );
}

// Problem 63
TEST( Problem_63, Given_Case_1 )
{
  std::vector<std::vector<char>> letters = { { 'F', 'A', 'C', 'I' },
                                             { 'O', 'B', 'Q', 'P' },
                                             { 'A', 'N', 'O', 'B' },
                                             { 'M', 'A', 'S', 'S' } };

  bool result = findWord( letters, "FOAM" );

  EXPECT_TRUE( result );
}

TEST( Problem_63, Given_Case_2 )
{
  std::vector<std::vector<char>> letters = { { 'F', 'A', 'C', 'I' },
                                             { 'O', 'B', 'Q', 'P' },
                                             { 'A', 'N', 'O', 'B' },
                                             { 'M', 'A', 'S', 'S' } };

  bool result = findWord( letters, "MASS" );

  EXPECT_TRUE( result );
}

TEST( Problem_63, Test_Case_1 )
{
  std::vector<std::vector<char>> letters = { { 'F', 'A', 'C', 'I' },
                                             { 'O', 'B', 'Q', 'P' },
                                             { 'A', 'N', 'O', 'B' },
                                             { 'M', 'A', 'S', 'S' } };

  bool result = findWord( letters, "ZOOM" );

  EXPECT_FALSE( result );
}

TEST( Problem_63, Test_Case_2 )
{
  std::vector<std::vector<char>> letters = { { 'F', 'A', 'C', 'I' },
                                             { 'O', 'B', 'Q', 'P' },
                                             { 'A', 'N', 'O', 'B' },
                                             { 'M', 'A', 'S', 'S' } };

  bool result = findWord( letters, "LAUGH" );

  EXPECT_FALSE( result );
}

// Problem 64
TEST( Problem_64, Test_Case_1 )
{
  int result = knights_tours( 1 );

  EXPECT_EQ( 1, result );
}

// Problem 65
TEST( Problem_65, Given_Case )
{
  std::vector<std::vector<int>> v =
      { { 1, 2, 3, 4, 5 },
        { 6, 7, 8, 9, 10 },
        { 11, 12, 13, 14, 15 },
        { 16, 17, 18, 19, 20 } };

  std::vector<int> expected = {
      1,
      2,
      3,
      4,
      5,
      10,
      15,
      20,
      19,
      18,
      17,
      16,
      11,
      6,
      7,
      8,
      9,
      14,
      13,
      12 };

  auto result = print_spiral( v );

  EXPECT_EQ( expected, result );
}

// Problem 66
TEST( Problem_66, Test_Case )
{
  int heads = 0;
  int tails = 0;

  for( int i = 0; i < 10000; i++ )
  {
    bool flip = toss_fair();
    if( flip ) heads++;
    else
      tails++;
  }

  int difference = heads - tails;
  std::cout << "The difference is " << difference << ".\n";
  EXPECT_TRUE( ( difference >= -500 ) && ( difference <= 500 ) );
}