#include "gtest/gtest.h"

#include "problems_081_090/Problem_081.hpp"
#include "problems_081_090/Problem_082.hpp"
#include "problems_081_090/Problem_083.hpp"
#include "problems_081_090/Problem_084.hpp"
#include "problems_081_090/Problem_085.hpp"
#include "problems_081_090/Problem_086.hpp"
#include "problems_081_090/Problem_087.hpp"
#include "problems_081_090/Problem_088.hpp"
#include "problems_081_090/Problem_089.hpp"
#include "problems_081_090/Problem_090.hpp"

// Problem 081
TEST( Problem_81, Given_Case ) {
  /*
  For example if {“2”: [“a”, “b”, “c”], 3: [“d”, “e”, “f”], …} then “23” should
  return [“ad”, “ae”, “af”, “bd”, “be”, “bf”, “cd”, “ce”, “cf"].
  */

  std::map<char, std::vector<std::string>> num_map;
  num_map['2'] = { "a", "b", "c" };
  num_map['3'] = { "d", "e", "f" };

  std::vector<std::string> const expected = { "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" };
  std::vector<std::string> const result   = num_to_str( "23", num_map );

  EXPECT_EQ( expected, result );
}

// Problem 082
TEST( Problem_82, Test_read7 ) {
  filereader filereader( "Problem_082.txt" );

  std::string const one   = filereader.read7();
  std::string const two   = filereader.read7();
  std::string const three = filereader.read7();

  EXPECT_EQ( "Hello w", one );
  EXPECT_EQ( "orld", two );
  EXPECT_EQ( "", three );
}

TEST( Problem_82, Test_Case_1 ) {
  std::string const result = readN( 5 );

  EXPECT_EQ( "Hello", result );
}

TEST( Problem_82, Test_Case_2 ) {
  std::string const result = readN( 11 );

  EXPECT_EQ( "Hello world", result );
}

// Problem 083
TEST( Problem_83, Given_Case ) {
  /*
  For example, given the following tree:

  a
      / \
      b   c
      / \  /
      d   e f
          should become:

    a
    / \
    c   b
  \  / \
    f e  d

        */

  auto *a        = new btNode( 'a' );
  a->left        = new btNode( 'b' );
  a->left->left  = new btNode( 'd' );
  a->left->right = new btNode( 'e' );
  a->right       = new btNode( 'c' );
  a->right->left = new btNode( 'f' );

  invert_B_Tree( a );

  EXPECT_EQ( 'a', a->value );
  EXPECT_EQ( 'c', a->left->value );
  EXPECT_EQ( 'f', a->left->right->value );
  EXPECT_EQ( 'b', a->right->value );
  EXPECT_EQ( 'e', a->right->left->value );
  EXPECT_EQ( 'd', a->right->right->value );
}

// Problem 084
TEST( Problem_84, Given_Case ) {
  /*
  For example, this matrix has 4 islands.

  1 0 0 0 0
      0 0 1 1 0
      0 1 1 0 0
      0 0 0 0 0
      1 1 0 0 1
      1 1 0 0 1
      */
  std::vector<std::vector<int>> const island_map = {
    {1, 0, 0, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0},
    {1, 1, 0, 0, 1},
    {1, 1, 0, 0, 1}
  };

  int const result = num_islands( island_map );

  EXPECT_EQ( 4, result );
}

// Problem 085
TEST( Problem_85, Test_Case_1 ) {
  int const result = math_if( 10, 20, 1 );

  EXPECT_EQ( 10, result );
}

TEST( Problem_85, Test_Case_2 ) {
  int const result = math_if( 10, 20, 0 );

  EXPECT_EQ( 20, result );
}

// Problem 086
TEST( Problem_86, Give_Case_1 ) {
  int const result = parentheses_to_remove( "()())()" );

  EXPECT_EQ( 1, result );
}

TEST( Problem_86, Give_Case_2 ) {
  int const result = parentheses_to_remove( ")(" );

  EXPECT_EQ( 2, result );
}

// Problem 087
TEST( Problem_87, Given_Case_1 ) {
  std::vector<std::string> const rules = { "A N B", "C SE B", "C N A" };

  bool const result = validate( rules );
  EXPECT_FALSE( result );
}

TEST( Problem_87, Given_Case_2 ) {
  std::vector<std::string> const rules = { "A NW B", "A N B" };

  bool const result = validate( rules );
  EXPECT_TRUE( result );
}

TEST( Problem_87, Given_Case_3 ) {
  std::vector<std::string> const rules = { "A N B", "C N B" };

  bool const result = validate( rules );
  EXPECT_TRUE( result );
}

TEST( Problem_87, Given_Case_4 ) {
  std::vector<std::string> const rules = { "A NW B", "A N B" };

  bool const result = validate( rules );
  EXPECT_TRUE( result );
}

TEST( Problem_87, Test_Case ) {
  std::vector<std::string> const rules = { "A N B", "B N A" };

  bool const result = validate( rules );
  EXPECT_FALSE( result );
}

// Problem 088
TEST( Problem_88, Test_Case_1 ) {
  int const result = divide( 10, 2 );

  EXPECT_EQ( 5, result );
}

TEST( Problem_88, Test_Case_2 ) {
  int const result = divide( 10, 10 );

  EXPECT_EQ( 1, result );
}

TEST( Problem_88, Test_Case_3 ) {
  int const result = divide( 10, 15 );

  EXPECT_EQ( 0, result );
}

TEST( Problem_88, Test_Case_4 ) {
  int const result = divide( 13, 4 );

  EXPECT_EQ( 3, result );
}

// Problem 089
TEST( Problem_89, Test_Case_1 ) {
  auto *root        = new btNode( 'd' );
  root->left        = new btNode( 'c' );
  root->left->left  = new btNode( 'a' );
  root->left->right = new btNode( 'f' );
  root->right       = new btNode( 'z' );

  bool const result = validateBST( root );

  EXPECT_TRUE( result );
}

TEST( Problem_89, Test_Case_2 ) {
  auto *root        = new btNode( 'd' );
  root->left        = new btNode( 'c' );
  root->left->left  = new btNode( 'a' );
  root->left->right = new btNode( 'f' );
  root->right       = new btNode( 'b' );

  bool const result = validateBST( root );

  EXPECT_FALSE( result );
}

// Problem 090
TEST( Problem_90, Test_Case ) {
  std::vector<int> const l = { 1, 3, 4, 8, 9 };

  int const result = randNotInL( 10, l );

  EXPECT_TRUE( result >= 0 );
  EXPECT_TRUE( result <= 10 );

  EXPECT_NE( result, 1 );
  EXPECT_NE( result, 3 );
  EXPECT_NE( result, 4 );
  EXPECT_NE( result, 8 );
  EXPECT_NE( result, 9 );
}