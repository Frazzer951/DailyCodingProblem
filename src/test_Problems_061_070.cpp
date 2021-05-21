#include "Problem_061.hpp"
#include "Problem_062.hpp"
#include "Problem_063.hpp"
#include "Problem_064.hpp"
#include "Problem_065.hpp"

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