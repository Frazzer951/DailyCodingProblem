#include "Problem_091.hpp"
#include "Problem_092.hpp"
#include "Problem_093.hpp"
#include "Problem_094.hpp"
#include "Problem_095.hpp"
#include "Problem_096.hpp"
#include "Problem_097.hpp"
#include "Problem_098.hpp"

#include "gtest/gtest.h"

// Problem 92
TEST( Problem_92, Given_Case )
{
  /*
  For example, given {'CSC300': ['CSC100', 'CSC200'],
                      'CSC200': ['CSC100'],
                      'CSC100': []},
  should return ['CSC100', 'CSC200', 'CSCS300'].
  */

  std::map<std::string, std::vector<std::string>> course_dependencies = { { "CSC300", { "CSC100", "CSC200" } }, { "CSC200", { "CSC100" } }, { "CSC100", {} } };

  std::vector<std::string> expected = { "CSC100", "CSC200", "CSC300" };
  std::vector<std::string> result   = course_order( course_dependencies );

  EXPECT_EQ( expected, result );
}

// Problem 93
TEST( Problem_93, Test_Case_1 )
{
  auto * root = new btNode( 'f' );

  root->left             = new btNode( 'g' );
  root->left->left       = new btNode( 'e' );
  root->left->left->left = new btNode( 'a' );
  root->left->right      = new btNode( 'i' );

  root->right               = new btNode( 'h' );
  root->right->right        = new btNode( 'k' );
  root->right->right->right = new btNode( 'l' );
  root->right->left         = new btNode( 'b' );
  root->right->right->left  = new btNode( 'c' );

  btNode * result      = largest_subBST( root );
  int      result_size = largest_subBST_size( root );

  EXPECT_EQ( root->right, result );
  EXPECT_EQ( 5, result_size );
}

// Problem 94
TEST( Problem_94, Test_Case )
{
  ibtNode * root           = new ibtNode( 10 );
  root->left               = new ibtNode( 6 );
  root->left->left         = new ibtNode( -3 );
  root->left->left->right  = new ibtNode( 3 );
  root->left->right        = new ibtNode( 5 );
  root->right              = new ibtNode( -4 );
  root->right->left        = new ibtNode( 11 );
  root->right->right       = new ibtNode( 9 );
  root->right->right->left = new ibtNode( 2 );

  int result = max_path_sum( root );

  EXPECT_EQ( 28, result );
}

// Problem 95
TEST( Problem_95, Given_Case_1 )
{
  /*
  the list [1,2,3] should return [1,3,2].
  */

  std::vector<int> nums     = { 1, 2, 3 };
  std::vector<int> expected = { 1, 3, 2 };
  nextPermutation( nums );
  EXPECT_EQ( expected, nums );
}

TEST( Problem_95, Given_Case_2 )
{
  /*
  The list [1,3,2] should return [2,1,3].
  */

  std::vector<int> nums     = { 1, 3, 2 };
  std::vector<int> expected = { 2, 1, 3 };
  nextPermutation( nums );
  EXPECT_EQ( expected, nums );
}

TEST( Problem_95, Given_Case_3 )
{
  /*
  The list [3,2,1] should return [1,2,3].
  */

  std::vector<int> nums     = { 3, 2, 1 };
  std::vector<int> expected = { 1, 2, 3 };
  nextPermutation( nums );
  EXPECT_EQ( expected, nums );
}

// Problem 96
TEST( Problem_96, Given_Case )
{
  /*
  For example, given [1,2,3], return
  [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]].
  */

  std::vector<int>              nums     = { 1, 2, 3 };
  std::vector<std::vector<int>> result   = getPermutations( nums );
  std::vector<std::vector<int>> expected = { { 1, 2, 3 }, { 1, 3, 2 }, { 2, 1, 3 }, { 2, 3, 1 }, { 3, 1, 2 }, { 3, 2, 1 } };

  EXPECT_EQ( expected, result );
}