#include "Problem_101.hpp"
#include "Problem_102.hpp"
#include "Problem_103.hpp"
#include "Problem_104.hpp"
#include "Problem_105.hpp"
#include "Problem_106.hpp"
#include "Problem_107.hpp"
#include "Problem_108.hpp"

#include "gtest/gtest.h"


// Problem 101
TEST( Problem_101, Given_Case )
{
  // Input: 4
  // Output: 2 + 2 = 4

  std::pair<int, int> result = primeSum( 4 );
  std::pair<int, int> expected( 2, 2 );

  EXPECT_EQ( expected, result );
}

// Problem 102
TEST( Problem_102, Given_Case )
{
  // For example, if the list is [1, 2, 3, 4, 5] and K is 9,
  // then it should return [2, 3, 4], since 2 + 3 + 4 = 9.

  std::vector<int> nums     = { 1, 2, 3, 4, 5 };
  std::vector<int> expected = { 2, 3, 4 };
  std::vector<int> result   = continuousSum( nums, 9 );

  EXPECT_EQ( expected, result );
}

// Problem 103
TEST( Problem_103, Given_Case )
{
  // For example, given the string "figehaeci" and the set of characters {a, e, i}, you should return "aeci".

  int result = smallest( "figehaeci", { 'a', 'e', 'i' } );

  EXPECT_EQ( 4, result );
}

// Problem 104
TEST( Problem_104, Given_Case_1 )
{
  // For example, 1 -> 4 -> 3 -> 4 -> 1 returns True
  // while 1 -> 4 returns False.

  std::list<int> l;
  l.push_back( 1 );
  l.push_back( 4 );
  l.push_back( 3 );
  l.push_back( 4 );
  l.push_back( 1 );

  EXPECT_TRUE( palindromeList( l ) );
}

TEST( Problem_104, Given_Case_2 )
{
  // For example, 1 -> 4 -> 3 -> 4 -> 1 returns True
  // while 1 -> 4 returns False.

  std::list<int> l;
  l.push_back( 1 );
  l.push_back( 4 );

  EXPECT_FALSE( palindromeList( l ) );
}

// Problem 105
TEST( Problem_105, Test_Case )
{
  auto f1 = []() { return 1; };

  auto f2 = debunce( f1, 20 );

  f2();
}

// Problem 106
TEST( Problem_106, Given_Case_1 ) { EXPECT_TRUE( validate_hops( { 2, 0, 1, 0 } ) ); }

TEST( Problem_106, Given_Case_2 ) { EXPECT_FALSE( validate_hops( { 1, 1, 0, 1 } ) ); }

// Problem 107
TEST( Problem_107, Given_Case )
{
  /*
    1
   / \
  2   3
     / \
    4   5
  */

  auto * root        = new ibtNode( 1 );
  root->left         = new ibtNode( 2 );
  root->right        = new ibtNode( 3 );
  root->right->left  = new ibtNode( 4 );
  root->right->right = new ibtNode( 5 );

  std::vector<int> expected = { 1, 2, 3, 4, 5 };
  std::vector<int> result   = bt_traverse( root );

  EXPECT_EQ( expected, result );
}

// Problem 108
TEST( Problem_108, Given_Case_1 )
{
  // A is abcde and B is cdeab, return true.
  // A is abc and B is acb, return false.

  EXPECT_TRUE( isSifted( "abcde", "cdeab" ) );
}

TEST( Problem_108, Given_Case_2 )
{
  // A is abcde and B is cdeab, return true.
  // A is abc and B is acb, return false.

  EXPECT_FALSE( isSifted( "abc", "acb" ) );
}