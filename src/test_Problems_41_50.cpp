#include "Problem_41.hpp"
#include "Problem_42.hpp"
#include "Problem_43.hpp"
#include "Problem_44.hpp"
#include "Problem_45.hpp"
#include "Problem_46.hpp"
#include "Problem_47.hpp"
#include "Problem_48.hpp"
#include "Problem_49.hpp"
#include "Problem_50.hpp"

#include "gtest/gtest.h"

// Problem 41
TEST( Problem_41, Given_Case_1 )
{
  // Given [('SFO', 'HKO'), ('YYZ', 'SFO'), ('YUL', 'YYZ'), ('HKO', 'ORD')] and starting airport 'YUL',
  // return ['YUL', 'YYZ', 'SFO', 'HKO', 'ORD'].

  std::vector<std::pair<std::string, std::string>> flights = { std::make_pair( "SFO", "HKO" ),
                                                               std::make_pair( "YYZ", "SFO" ),
                                                               std::make_pair( "YUL", "YYZ" ),
                                                               std::make_pair( "HKO", "ORD" ) };

  std::vector<std::string> result   = getItinerary( flights, "YUL" );
  std::vector<std::string> expected = { "YUL", "YYZ", "SFO", "HKO", "ORD" };

  EXPECT_EQ( result, expected );
}

TEST( Problem_41, Given_Case_2 )
{
  // Given [('SFO', 'COM'), ('COM', 'YYZ')] and starting airport 'COM', return null.

  std::vector<std::pair<std::string, std::string>> flights = { std::make_pair( "SFO", "COM" ),
                                                               std::make_pair( "COM", "YYZ" ) };

  std::vector<std::string> result   = getItinerary( flights, "COM" );
  std::vector<std::string> expected = {};

  EXPECT_EQ( result, expected );
}

TEST( Problem_41, Given_Case_3 )
{
  // Given [('A', 'B'), ('A', 'C'), ('B', 'C'), ('C', 'A')] and starting airport 'A', return ['A', 'B', 'C', 'A', 'C']

  std::vector<std::pair<std::string, std::string>> flights = { std::make_pair( "A", "B" ),
                                                               std::make_pair( "A", "C" ),
                                                               std::make_pair( "B", "C" ),
                                                               std::make_pair( "C", "A" ) };

  std::vector<std::string> result   = getItinerary( flights, "A" );
  std::vector<std::string> expected = { "A", "B", "C", "A", "C" };

  EXPECT_EQ( result, expected );
}

// Problem 42
TEST( Problem_42, Given_Case )
{
  // given S = [12, 1, 61, 5, 9, 2] and k = 24, return [12, 9, 2, 1] since it sums up to 24
  auto             result   = subset_sum( { 12, 1, 61, 5, 9, 2 }, 24 );
  std::vector<int> expected = { 12, 1, 9, 2 };

  EXPECT_EQ( result, expected );
}

// Problem 43
TEST( Problem_43, Test_Push )
{
  stack testStack;
  testStack.push( 10 );

  EXPECT_EQ( testStack.top->val, 10 );
}

TEST( Problem_43, Test_Pop )
{
  stack testStack;
  testStack.push( 15 );

  int result   = testStack.pop();
  int expected = 15;

  EXPECT_EQ( result, expected );
}

TEST( Problem_43, Test_Pop_Exception )
{
  stack testStack;

  EXPECT_ANY_THROW( testStack.pop() );
}

TEST( Problem_43, Test_getMax )
{
  stack testStack;
  testStack.push( 15 );
  testStack.push( 18 );
  testStack.push( 2 );

  int result   = testStack.getMax();
  int expected = 18;

  EXPECT_EQ( result, expected );
}

TEST( Problem_43, Test_getMax_Exception )
{
  stack testStack;

  EXPECT_ANY_THROW( testStack.getMax() );
}

// Problem 44
TEST( Problem_44, Given_Case_1 )
{
  // The array [2, 4, 1, 3, 5] has three inversions: (2, 1), (4, 1), and (4,3).
  int result   = outOfOrder( { 2, 4, 1, 3, 5 } );
  int expected = 3;

  EXPECT_EQ( result, expected );
}

TEST( Problem_44, Given_Case_2 )
{
  // The array [5, 4, 3, 2, 1] has ten inversions: every distinct pair forms an inversion.

  int result   = outOfOrder( { 5, 4, 3, 2, 1 } );
  int expected = 10;

  EXPECT_EQ( result, expected );
}