#include "Problem_071.hpp"
#include "Problem_072.hpp"

#include "gtest/gtest.h"

// Problem 71
TEST( Problem_71, Test_Case )
{
  int result = prob71::rand5();

  EXPECT_TRUE( ( result >= 1 ) && ( result <= 5 ) );
}

// Problem 72
TEST( Problem_72, Given_Case_1 )
{
  std::vector<std::pair<int, int>> edges = { std::make_pair( 0, 1 ), std::make_pair( 0, 2 ), std::make_pair( 2, 3 ), std::make_pair( 3, 4 ) };

  int result = pathValue( "ABACA", edges );

  EXPECT_EQ( 3, result );
}

TEST( Problem_72, Given_Case_2 )
{
  std::vector<std::pair<int, int>> edges = { std::make_pair( 0, 0 ) };

  int result = pathValue( "A", edges );

  EXPECT_EQ( -1, result );
}

TEST( Problem_72, Test_Case )
{
  std::vector<std::pair<int, int>> edges = { std::make_pair( 0, 1 ), std::make_pair( 1, 0 ) };

  int result = pathValue( "AB", edges );

  EXPECT_EQ( -1, result );
}