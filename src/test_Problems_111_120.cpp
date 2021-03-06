#include "Problem_111.hpp"
#include "Problem_112.hpp"
#include "Problem_113.hpp"
#include "Problem_114.hpp"
#include "Problem_115.hpp"
#include "Problem_116.hpp"
#include "Problem_117.hpp"
#include "Problem_118.hpp"
#include "Problem_119.hpp"
#include "Problem_120.hpp"

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

// Problem 115
TEST( Problem_115, Test_Case_1 )
{
  auto * root        = new btNode( 1 );
  root->left         = new btNode( 2 );
  root->right        = new btNode( 3 );
  root->right->right = new btNode( 4 );

  EXPECT_TRUE( isSubtree( root, root ) );
  EXPECT_TRUE( isSubtree( root, root->left ) );
  EXPECT_TRUE( isSubtree( root, root->right ) );
  EXPECT_TRUE( isSubtree( root, root->right->right ) );
}

// Problem 116
TEST( Problem_116, Test_Case )
{
  auto * root = generate();

  EXPECT_TRUE( root );
}

// Problem 117
TEST( Problem_117, Given_Case_1 )
{
  /*
         1
       /  \
     -2   -3            (level 1 is the minimum)
         /  \
        4   -5
  */

  auto * root = new ibtNode( 1, new ibtNode( -2 ), new ibtNode( -3, new ibtNode( 4 ), new ibtNode( -5 ) ) );

  int min_level = minimum_level_sum( root );

  EXPECT_EQ( 1, min_level );
}

TEST( Problem_117, Given_Case_2 )
{
  /*
            1
        /       \
      2          3
    /  \          \
   4    5          6
         \       /   \
         -1   -7     -8   (level 3 is the minimum)
  */

  auto * root = new ibtNode( 1, new ibtNode( 2, new ibtNode( 4 ), new ibtNode( 5, new ibtNode( -1 ) ) ),
                             new ibtNode( 3, nullptr, new ibtNode( 6, new ibtNode( -7 ), new ibtNode( -8 ) ) ) );

  int min_level = minimum_level_sum( root );

  EXPECT_EQ( 3, min_level );
}

// Problem 118
TEST( Problem_118, Given_Case )
{
  // given [-9, -2, 0, 2, 3], return [0, 4, 4, 9, 81]
  std::vector<int> nums     = { -9, -2, 0, 2, 3 };
  std::vector<int> expected = { 0, 4, 4, 9, 81 };
  std::vector<int> result   = square_sort( nums );

  EXPECT_EQ( expected, result );
}

// Problem 119
TEST( Problem_119, Given_Case_1 )
{
  // given the intervals [0, 3], [2, 6], [3, 4], [6, 9], return {3, 6}.

  std::vector<std::vector<int>> intervals = { { 0, 3 }, { 2, 6 }, { 3, 4 }, { 6, 9 } };

  std::vector<int> expected = { 3, 9 };
  std::vector<int> result   = covering( intervals );

  EXPECT_EQ( result, expected );
}

TEST( Problem_119, Given_Case_2 )
{
  // given the intervals [[10, 20], [1, 6], [3, 8], [7, 12]], return {1, 6}.

  std::vector<std::vector<int>> intervals = { { 10, 20 }, { 1, 6 }, { 3, 8 }, { 7, 12 } };

  std::vector<int> expected = { 6, 12 };
  std::vector<int> result   = covering( intervals );

  EXPECT_EQ( result, expected );
}
