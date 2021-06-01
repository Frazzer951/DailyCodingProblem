#include "Problem_071.hpp"
#include "Problem_072.hpp"
#include "Problem_073.hpp"
#include "Problem_074.hpp"
#include "Problem_075.hpp"
#include "Problem_076.hpp"
#include "Problem_077.hpp"

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

// Problem 73
TEST( Problem_73, Test_Case )
{
  slList list;
  list.add( new slNode( 1 ) );
  list.add( new slNode( 2 ) );
  list.add( new slNode( 3 ) );

  reverse_slList( list );

  EXPECT_EQ( 3, *list.get( 0 ) );
  EXPECT_EQ( 2, *list.get( 1 ) );
  EXPECT_EQ( 1, *list.get( 2 ) );
}

// Problem 74
TEST( Problem_74, Given_Case )
{
  int result = countMultiples( 6, 12 );

  EXPECT_EQ( 4, result );
}

TEST( Problem_74, Test_Case )
{
  int result = countMultiples( 10, 100 );

  EXPECT_EQ( 1, result );
}

// Problem 75
TEST( Problem_75, Given_Case )
{
  std::vector<int> arr = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };

  int result = longest_increasing_subsequence( arr );

  EXPECT_EQ( 6, result );
}