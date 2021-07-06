#include "Problem_111.hpp"
#include "Problem_112.hpp"
#include "Problem_113.hpp"

#include "gtest/gtest.h"

// Problem 111
TEST( Problem_111, Given_Case )
{
  // given that W is "ab", and S is "abxaba", return 0, 3, and 4.
  std::vector<int> expected = { 0, 3, 4 };
  std::vector<int> result   = anagramIndex( "ab", "abxaba" );

  EXPECT_EQ( expected, result );
}

// Problem 112
TEST( Problem_112, Test_Case )
{
  auto * root = new pbtNode( 1 );
  auto * n1   = new pbtNode( 2, root );
  auto * n2   = new pbtNode( 3, root );
  auto * n3   = new pbtNode( 4, n1 );
  auto * n4   = new pbtNode( 5, n1 );
  auto * n5   = new pbtNode( 6, n2 );
  root->left  = n1;
  root->right = n2;
  n1->left    = n3;
  n1->right   = n4;
  n2->right   = n5;

  EXPECT_EQ( root, pbtLCA( n1, n2 ) );
  EXPECT_EQ( root, pbtLCA( n4, n5 ) );
  EXPECT_EQ( n1, pbtLCA( n3, n4 ) );
}

// Problem 113
TEST( Problem_113, Given_Case )
{
  std::string result = reverseSentance( "hello world here" );

  EXPECT_EQ( "here world hello", result );
}