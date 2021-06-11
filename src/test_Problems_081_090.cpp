#include "Problem_081.hpp"
#include "Problem_082.hpp"
#include "Problem_083.hpp"
#include "Problem_084.hpp"
#include "Problem_085.hpp"
#include "Problem_086.hpp"
#include "Problem_088.hpp"

#include "gtest/gtest.h"

// Problem 81
TEST( Problem_81, Given_Case )
{
  /*
  For example if {“2”: [“a”, “b”, “c”], 3: [“d”, “e”, “f”], …}
  then “23” should return [“ad”, “ae”, “af”, “bd”, “be”, “bf”, “cd”, “ce”, “cf"].
  */

  std::map<char, std::vector<std::string>> num_map;
  num_map['2'] = { "a", "b", "c" };
  num_map['3'] = { "d", "e", "f" };

  std::vector<std::string> expected = { "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" };
  std::vector<std::string> result   = num_to_str( "23", num_map );

  EXPECT_EQ( expected, result );
}

// Problem 82
TEST( Problem_82, Test_read7 )
{
  filereader filereader( "Problem_082.txt" );

  std::string one   = filereader.read7();
  std::string two   = filereader.read7();
  std::string three = filereader.read7();

  EXPECT_EQ( "Hello w", one );
  EXPECT_EQ( "orld", two );
  EXPECT_EQ( "", three );
}

TEST( Problem_82, Test_Case_1 )
{
  std::string result = readN( 5 );

  EXPECT_EQ( "Hello", result );
}

TEST( Problem_82, Test_Case_2 )
{
  std::string result = readN( 11 );

  EXPECT_EQ( "Hello world", result );
}

// Problem 83
TEST( Problem_83, Given_Case )
{
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

  auto * a       = new btNode( 'a' );
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

// Problem 84
TEST( Problem_84, Given_Case )
{
  /*
  For example, this matrix has 4 islands.

  1 0 0 0 0
  0 0 1 1 0
  0 1 1 0 0
  0 0 0 0 0
  1 1 0 0 1
  1 1 0 0 1
  */
  std::vector<std::vector<int>> island_map = { { 1, 0, 0, 0, 0 },
                                               { 0, 0, 1, 1, 0 },
                                               { 0, 1, 1, 0, 0 },
                                               { 0, 0, 0, 0, 0 },
                                               { 1, 1, 0, 0, 1 },
                                               { 1, 1, 0, 0, 1 } };

  int result = num_islands( island_map );

  EXPECT_EQ( 4, result );
}

// Problem 85
TEST( Problem_85, Test_Case_1 )
{
  int result = math_if( 10, 20, 1 );

  EXPECT_EQ( 10, result );
}

TEST( Problem_85, Test_Case_2 )
{
  int result = math_if( 10, 20, 0 );

  EXPECT_EQ( 20, result );
}

// Problem 86
TEST( Problem_86, Give_Case_1 )
{
  int result = parentheses_to_remove( "()())()" );

  EXPECT_EQ( 1, result );
}

TEST( Problem_86, Give_Case_2 )
{
  int result = parentheses_to_remove( ")(" );

  EXPECT_EQ( 2, result );
}

// Problem 88
TEST( Problem_88, Test_Case_1 )
{
  int result = divide( 10, 2 );

  EXPECT_EQ( 5, result );
}

TEST( Problem_88, Test_Case_2 )
{
  int result = divide( 10, 10 );

  EXPECT_EQ( 1, result );
}

TEST( Problem_88, Test_Case_3 )
{
  int result = divide( 10, 15 );

  EXPECT_EQ( 0, result );
}

TEST( Problem_88, Test_Case_4 )
{
  int result = divide( 13, 4 );

  EXPECT_EQ( 3, result );
}