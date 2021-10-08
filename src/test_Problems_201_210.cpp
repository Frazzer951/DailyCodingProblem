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
TEST( Problem_204, Test_Case )
{
  btNode<int> * root =
      new btNode( 1, new btNode( 2, new btNode( 4, new btNode( 8 ), new btNode( 9 ) ), new btNode( 5 ) ),
                  new btNode( 3, new btNode( 6 ), new btNode( 7 ) ) );

  int count = getCount( root );
  EXPECT_EQ( count, 9 );
}

// Problem 205
TEST( Problem_205, Given_Case )
{
  // given 48975, the next permutation would be 49578
  int result = get_next_perm( 48975 );
  EXPECT_EQ( result, 49578 );
}

// Problem 206
TEST( Problem_206, Given_Case )
{
  // given the array ["a", "b", "c"] and the permutation [2, 1, 0], return ["c", "b", "a"].
  std::vector<char> result   = genPermutation( { 'a', 'b', 'c' }, { 2, 1, 0 } );
  std::vector<char> expected = { 'c', 'b', 'a' };

  EXPECT_EQ( result, expected );
}

// Problem 207


// Problem 208


// Problem 209


// Problem 210