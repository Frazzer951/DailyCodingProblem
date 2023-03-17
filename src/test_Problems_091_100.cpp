#include "gtest/gtest.h"

#include "problems_091_100/Problem_091.hpp"
#include "problems_091_100/Problem_092.hpp"
#include "problems_091_100/Problem_093.hpp"
#include "problems_091_100/Problem_094.hpp"
#include "problems_091_100/Problem_095.hpp"
#include "problems_091_100/Problem_096.hpp"
#include "problems_091_100/Problem_097.hpp"
#include "problems_091_100/Problem_098.hpp"
#include "problems_091_100/Problem_099.hpp"
#include "problems_091_100/Problem_100.hpp"

// Problem 091

// Problem 092
TEST( Problem_92, Given_Case ) {
  /*
  For example, given {'CSC300': ['CSC100', 'CSC200'],
                      'CSC200': ['CSC100'],
                      'CSC100': []},
  should return ['CSC100', 'CSC200', 'CSCS300'].
  */

  std::map<std::string, std::vector<std::string>> const course_dependencies = {
    {"CSC300", { "CSC100", "CSC200" }},
    {"CSC200",           { "CSC100" }},
    {"CSC100",                     {}}
  };

  std::vector<std::string> const expected = { "CSC100", "CSC200", "CSC300" };
  std::vector<std::string> const result   = course_order( course_dependencies );

  EXPECT_EQ( expected, result );
}

// Problem 093
TEST( Problem_93, Test_Case_1 ) {
  auto *root = new btNode( 'f' );

  root->left             = new btNode( 'g' );
  root->left->left       = new btNode( 'e' );
  root->left->left->left = new btNode( 'a' );
  root->left->right      = new btNode( 'i' );

  root->right               = new btNode( 'h' );
  root->right->right        = new btNode( 'k' );
  root->right->right->right = new btNode( 'l' );
  root->right->left         = new btNode( 'b' );
  root->right->right->left  = new btNode( 'c' );

  btNode<char> *result      = largest_subBST( root );
  int           const result_size = largest_subBST_size( root );

  EXPECT_EQ( root->right, result );
  EXPECT_EQ( 5, result_size );
}

// Problem 094
TEST( Problem_94, Test_Case ) {
  auto *root               = new btNode( 10 );
  root->left               = new btNode( 6 );
  root->left->left         = new btNode( -3 );
  root->left->left->right  = new btNode( 3 );
  root->left->right        = new btNode( 5 );
  root->right              = new btNode( -4 );
  root->right->left        = new btNode( 11 );
  root->right->right       = new btNode( 9 );
  root->right->right->left = new btNode( 2 );

  int const result = max_path_sum( root );

  EXPECT_EQ( 28, result );
}

// Problem 095
TEST( Problem_95, Given_Case_1 ) {
  /*
  the list [1,2,3] should return [1,3,2].
  */

  std::vector<int> nums     = { 1, 2, 3 };
  std::vector<int> const expected = { 1, 3, 2 };
  nextPermutation( nums );
  EXPECT_EQ( expected, nums );
}
TEST( Problem_95, Given_Case_2 ) {
  /*
  The list [1,3,2] should return [2,1,3].
  */

  std::vector<int> nums     = { 1, 3, 2 };
  std::vector<int> const expected = { 2, 1, 3 };
  nextPermutation( nums );
  EXPECT_EQ( expected, nums );
}
TEST( Problem_95, Given_Case_3 ) {
  /*
  The list [3,2,1] should return [1,2,3].
  */

  std::vector<int> nums     = { 3, 2, 1 };
  std::vector<int> const expected = { 1, 2, 3 };
  nextPermutation( nums );
  EXPECT_EQ( expected, nums );
}

// Problem 096
TEST( Problem_96, Given_Case ) {
  /*
  For example, given [1,2,3], return
  [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]].
  */

  std::vector<int>              const nums     = { 1, 2, 3 };
  std::vector<std::vector<int>> const result   = getPermutations( nums );
  std::vector<std::vector<int>> const expected = {
    {1, 2, 3},
    {1, 3, 2},
    {2, 1, 3},
    {2, 3, 1},
    {3, 1, 2},
    {3, 2, 1}
  };

  EXPECT_EQ( expected, result );
}

// Problem 097
TEST( Problem_97, Given_Case ) {
  /*
  d.set(1, 1, 0) # set key 1 to value 1 at time 0
  d.set(1, 2, 2) # set key 1 to value 2 at time 2
  d.get(1, 1) # get key 1 at time 1 should be 1
  d.get(1, 3) # get key 1 at time 3 should be 2
  d.set(1, 1, 5) # set key 1 to value 1 at time 5
  d.get(1, 0) # get key 1 at time 0 should be null
  d.get(1, 10) # get key 1 at time 10 should be 1
  d.set(1, 1, 0) # set key 1 to value 1 at time 0
  d.set(1, 2, 0) # set key 1 to value 2 at time 0
  d.get(1, 0) # get key 1 at time 0 should be 2
  */

  MultiTimeMap d;

  d.set( 1, 1, 0 );                  // set key 1 to value 1 at time 0
  d.set( 1, 2, 2 );                  // set key 1 to value 2 at time 2
  EXPECT_EQ( 1, d.get( 1, 1 ) );     // get key 1 at time 1 should be 1
  EXPECT_EQ( 2, d.get( 1, 3 ) );     // get key 1 at time 3 should be 2
  d.set( 1, 1, 5 );                  // set key 1 to value 1 at time 5
  EXPECT_EQ( 1, d.get( 1, 0 ) );     // get key 1 at time 0 should be 1
  EXPECT_EQ( 1, d.get( 1, 10 ) );    // get key 1 at time 10 should be 1
  d.set( 1, 1, 0 );                  // set key 1 to value 1 at time 0
  d.set( 1, 2, 0 );                  // set key 1 to value 2 at time 0
  EXPECT_EQ( 2, d.get( 1, 0 ) );     // get key 1 at time 0 should be 2
}

// Problem 098
TEST( Problem_98, Given_Case ) {
  /*
  [
    ['A','B','C','E'],
    ['S','F','C','S'],
    ['A','D','E','E']
  ]
  exists(board, "ABCCED") returns true,
  exists(board, "SEE") returns true,
  exists(board, "ABCB") returns false.
  */

  std::vector<std::vector<char>> const board = {
    {'A', 'B', 'C', 'E'},
    {'S', 'F', 'C', 'S'},
    {'A', 'D', 'E', 'E'}
  };

  EXPECT_TRUE( find_word( board, "ABCCED" ) );
  EXPECT_TRUE( find_word( board, "SEE" ) );
  EXPECT_FALSE( find_word( board, "ABCB" ) );
}

// Problem 099
TEST( Problem_99, Given_Case ) {
  /*
  For example, given [100, 4, 200, 1, 3, 2],
  the longest consecutive element sequence is [1, 2, 3, 4].
  Return its length: 4.
  */

  std::vector<int> const arr    = { 100, 4, 200, 1, 3, 2 };
  int              const result = findLongestConseqSubseq( arr );
  EXPECT_EQ( 4, result );
}

// Problem 100
TEST( Problem_100, Given_Case ) {
  /*
  Input: [(0, 0), (1, 1), (1, 2)]
  Output: 2
  */

  std::vector<std::pair<int, int>> const points = { std::make_pair( 0, 0 ), std::make_pair( 1, 1 ), std::make_pair( 1, 2 ) };

  int const result = minSteps( points );

  EXPECT_EQ( 2, result );
}