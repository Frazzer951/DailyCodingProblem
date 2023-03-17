#include "gtest/gtest.h"

#include "problems_201_210/Problem_201.hpp"
#include "problems_201_210/Problem_202.hpp"
#include "problems_201_210/Problem_203.hpp"
#include "problems_201_210/Problem_204.hpp"
#include "problems_201_210/Problem_205.hpp"
#include "problems_201_210/Problem_206.hpp"
#include "problems_201_210/Problem_207.hpp"
#include "problems_201_210/Problem_208.hpp"
#include "problems_201_210/Problem_209.hpp"
#include "problems_201_210/Problem_210.hpp"

// Problem 201
TEST( Problem_201, Given_Case ) {
  std::vector<std::vector<int>> const arrays = {
    { 1 },
    { 2, 3 },
    { 1, 5, 1 }
  };
  int const result = longestPath( arrays );
  EXPECT_EQ( result, 9 );
}

// Problem 202
TEST( Problem_202, Given_Case ) {
  // For example, 121 is a palindrome, as well as 888. 678 is not a palindrome
  EXPECT_TRUE( isPalindrome( 121 ) );
  EXPECT_TRUE( isPalindrome( 888 ) );
  EXPECT_FALSE( isPalindrome( 678 ) );
}

// Problem 203
TEST( Problem_203, Given_Case ) {
  // given [5, 7, 10, 3, 4], return 3
  int const result = find_min_element( { 5, 7, 10, 3, 4 } );
  EXPECT_EQ( result, 3 );
}

// Problem 204
TEST( Problem_204, Test_Case ) {
  auto *root = new btNode( 1, new btNode( 2, new btNode( 4, new btNode( 8 ), new btNode( 9 ) ), new btNode( 5 ) ),
                           new btNode( 3, new btNode( 6 ), new btNode( 7 ) ) );

  int const count = getCount( root );
  EXPECT_EQ( count, 9 );
}

// Problem 205
TEST( Problem_205, Given_Case ) {
  // given 48975, the next permutation would be 49578
  int const result = get_next_perm( 48975 );
  EXPECT_EQ( result, 49578 );
}

// Problem 206
TEST( Problem_206, Given_Case ) {
  // given the array ["a", "b", "c"] and the permutation [2, 1, 0], return ["c", "b", "a"].
  std::vector<char> const result   = genPermutation( { 'a', 'b', 'c' }, { 2, 1, 0 } );
  std::vector<char> const expected = { 'c', 'b', 'a' };

  EXPECT_EQ( result, expected );
}

// Problem 207
TEST( Problem_207, Given_Case ) {
  std::map<int, std::vector<int>> const graph = {
    {0,    { 1, 2 }},
    {1,    { 0, 2 }},
    {2, { 0, 1, 3 }},
    {3,       { 2 }}
  };

  EXPECT_FALSE( is_bipartite( graph ) );
}

// Problem 208
TEST( Problem_208, Given_Case ) {
  // given the linked list 5 -> 1 -> 8 -> 0 -> 3 and k = 3, the solution could be 1 -> 0 -> 5 -> 8 -> 3.
  auto             *head   = new slNode<int>( { 5, 1, 8, 0, 3 } );
  slList<int> const result = partition( head, 3 );
  slList<int> const expected( { 0, 1, 5, 8, 3 } );

  EXPECT_EQ( result, expected );
}

// Problem 209
TEST( Problem_209, Given_Case ) {
  int const length = lcs( "epidemiologist", "refrigeration", "supercalifragilisticexpialodocious" );

  EXPECT_EQ( length, 5 );
}

// Problem 210
TEST( Problem_210, Test_Case ) {
  int const testTo  = 100;
  long int  longest = -1;
  for ( long int i = 1; i <= testTo; i++ ) {
    long int const result = collatz( i );
    if ( i == -1 ) testing::AssertionFailure() << "Collatz Returned -1";
    longest = std::max( longest, result );
  }
  std::cout << "Longest Collatz sequence in " << testTo << " is " << longest << "\n";
  testing::AssertionSuccess() << "Longest Collatz sequence in " << testTo << " is " << longest;
}