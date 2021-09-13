#include "Problem_181.hpp"

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