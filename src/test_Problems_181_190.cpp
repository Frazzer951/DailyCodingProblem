#include "Problem_181.hpp"
#include "Problem_182.hpp"

#include "gtest/gtest.h"

// Problem 181
TEST( Problem_181, Given_Case_1 )
{
  // Given the input string racecarannakayak, return ["racecar", "anna", "kayak"].

  std::vector<std::string> result   = splitPalindrome( "racecarannakayak" );
  std::vector<std::string> expected = { "racecar", "anna", "kayak" };

  EXPECT_EQ( result, expected );
}

TEST( Problem_181, Given_Case_2 )
{
  // Given the input string abc, return ["a", "b", "c"].

  std::vector<std::string> result   = splitPalindrome( "abc" );
  std::vector<std::string> expected = { "a", "b", "c" };

  EXPECT_EQ( result, expected );
}

// Problem 182
TEST( Problem_182, Test_Case_1 )
{
  auto * n1 = new gNode { 1, {} };
  auto * n2 = new gNode { 2, {} };
  auto * n3 = new gNode { 3, {} };
  auto * n4 = new gNode { 4, {} };
  n1->connections.push_back( n2 );
  n1->connections.push_back( n4 );
  n2->connections.push_back( n1 );
  n2->connections.push_back( n3 );
  n3->connections.push_back( n2 );
  n3->connections.push_back( n4 );
  n4->connections.push_back( n1 );
  n4->connections.push_back( n3 );

  EXPECT_FALSE( isMinimallyConnected( n1 ) );
}

TEST( Problem_182, Test_Case_2 )
{
  auto * n1 = new gNode { 1, {} };
  auto * n2 = new gNode { 2, {} };
  auto * n3 = new gNode { 3, {} };
  auto * n4 = new gNode { 4, {} };
  n1->connections.push_back( n2 );
  n2->connections.push_back( n1 );
  n2->connections.push_back( n3 );
  n3->connections.push_back( n2 );
  n3->connections.push_back( n4 );
  n4->connections.push_back( n3 );

  EXPECT_TRUE( isMinimallyConnected( n1 ) );
}