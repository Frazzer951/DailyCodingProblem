#include "Problem_201.hpp"
#include "Problem_202.hpp"
#include "Problem_203.hpp"
#include "Problem_204.hpp"
#include "Problem_205.hpp"
#include "Problem_206.hpp"

#include "gtest/gtest.h"

// Problem 201
TEST( Problem_201, Given_Case )
{
  std::vector<std::vector<int>> arrays = { { 1 }, { 2, 3 }, { 1, 5, 1 } };
  int                           result = longestPath( arrays );
  EXPECT_EQ( result, 9 );
}

// Problem 202
TEST( Problem_202, Given_Case )
{
  // For example, 121 is a palindrome, as well as 888. 678 is not a palindrome
  EXPECT_TRUE( isPalindrome( 121 ) );
  EXPECT_TRUE( isPalindrome( 888 ) );
  EXPECT_FALSE( isPalindrome( 678 ) );
}

// Problem 203
TEST( Problem_203, Given_Case )
{
  // given [5, 7, 10, 3, 4], return 3
  int result = find_min_element( { 5, 7, 10, 3, 4 } );
  EXPECT_EQ( result, 3 );
}

// Problem 204


// Problem 205


// Problem 206


// Problem 207


// Problem 208


// Problem 209


// Problem 210