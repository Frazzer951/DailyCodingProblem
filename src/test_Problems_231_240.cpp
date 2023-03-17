#include "gtest/gtest.h"

#include "problems_231_240/Problem_231.hpp"
#include "problems_231_240/Problem_232.hpp"
#include "problems_231_240/Problem_233.hpp"
#include "problems_231_240/Problem_234.hpp"
#include "problems_231_240/Problem_235.hpp"
#include "problems_231_240/Problem_236.hpp"
#include "problems_231_240/Problem_237.hpp"
#include "problems_231_240/Problem_238.hpp"
#include "problems_231_240/Problem_239.hpp"
#include "problems_231_240/Problem_240.hpp"

/// Problem 231
TEST( Problem_231, Given_Case ) {
  std::string result = noRepeatingAdjacentCharacters( "aaabbc" );
  EXPECT_EQ( result, "abacba" );

  result = noRepeatingAdjacentCharacters( "aaab" );
  EXPECT_EQ( result, "" );
}

// Problem 232
TEST( Problem_232, Given_Case ) {
  /*
  mapsum.insert("columnar", 3)
  assert mapsum.sum("col") == 3

  mapsum.insert("column", 2)
  assert mapsum.sum("col") == 5
  */

  PrefixMapSum mapsum;
  mapsum.insert( "columnar", 3 );
  EXPECT_EQ( mapsum.sum( "col" ), 3 );

  mapsum.insert( "column", 2 );
  EXPECT_EQ( mapsum.sum( "col" ), 5 );
}

// Problem 233
TEST( Problem_223, Test_Case ) {
  EXPECT_EQ( fib( 0 ), 0 );
  EXPECT_EQ( fib( 1 ), 1 );
  EXPECT_EQ( fib( 2 ), 1 );
  EXPECT_EQ( fib( 3 ), 2 );
  EXPECT_EQ( fib( 4 ), 3 );
  EXPECT_EQ( fib( 5 ), 5 );
  EXPECT_EQ( fib( 6 ), 8 );
  EXPECT_EQ( fib( 7 ), 13 );
}

// Problem 234
TEST( Problem_234, Test_Case ) {
  UndirectedGraph graph( 3 );
  graph.add_edge( 0, 1, 5 );
  graph.add_edge( 1, 2, 10 );
  graph.add_edge( 2, 0, 15 );

  auto result = max_spanning_tree( graph );

  EXPECT_EQ( result.size(), 2 );
}

// Problem 235
TEST( Problem_235, Given_Case ) {
  // [4, 2, 7, 5, -1, 3, 6]
  std::pair<int, int> const result = min_and_max( { 4, 2, 7, 5, -1, 3, 6 } );

  EXPECT_EQ( result, std::make_pair( -1, 7 ) );
}

// Problem 236
TEST( Problem_236, Test_Case ) {
  EXPECT_FALSE( isInsidePolygon(
      {
          { 0,  0},
          {10,  0},
          {10, 10},
          { 0, 10}
  },
      { 20, 20 } ) );
  EXPECT_TRUE( isInsidePolygon(
      {
          { 0,  0},
          {10,  0},
          {10, 10},
          { 0, 10}
  },
      { 5, 5 } ) );
  EXPECT_TRUE( isInsidePolygon(
      {
          {0, 0},
          {5, 5},
          {5, 0}
  },
      { 3, 3 } ) );
  EXPECT_FALSE( isInsidePolygon(
      {
          {0, 0},
          {5, 5},
          {5, 0}
  },
      { 5, 1 } ) );
  EXPECT_FALSE( isInsidePolygon(
      {
          {0, 0},
          {5, 5},
          {5, 0}
  },
      { 8, 1 } ) );
  EXPECT_FALSE( isInsidePolygon(
      {
          { 0,  0},
          {10,  0},
          {10, 10},
          { 0, 10}
  },
      { -1, 10 } ) );
}

// Problem 237
TEST( Problem_237, Given_Case ) {
  /*
        4
      /   \
     3      3
    / \    / \
   9   4  5   9
  */
  auto *root =
      new btNode( 4, new btNode( 3, new btNode( 9 ), new btNode( 4 ) ), new btNode( 3, new btNode( 5 ), new btNode( 9 ) ) );

  EXPECT_FALSE( isSymmetric( root, root ) );

  /*
        4
      /   \
     3      3
    / \    / \
   9   5  5   9
  */

  root = new btNode( 4, new btNode( 3, new btNode( 9 ), new btNode( 5 ) ), new btNode( 3, new btNode( 5 ), new btNode( 9 ) ) );

  EXPECT_TRUE( isSymmetric( root, root ) );
}

// Problem 238

// Problem 239
TEST( Problem_239, Test_Case ) {
  EXPECT_EQ( unlock_combinations( 1 ), 9 );
  EXPECT_EQ( unlock_combinations( 2 ), 56 );
  EXPECT_EQ( unlock_combinations( 3 ), 320 );
  EXPECT_EQ( unlock_combinations( 4 ), 1624 );
}

// Problem 240
TEST( Problem_240, Test_Case ) {
  std::vector<int> const arr    = { 1, 2, 3, 4, 1, 2, 3, 4 };
  std::vector<int> const exp    = { 1, 1, 3, 3, 2, 2, 4, 4 };
  std::vector<int> const result = sortPairs( arr );
  EXPECT_EQ( result, exp );
}