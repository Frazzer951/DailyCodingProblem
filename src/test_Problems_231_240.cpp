#include "gtest/gtest.h"

#include "problems_231_240/Problem_231.hpp"
#include "problems_231_240/Problem_232.hpp"
#include "problems_231_240/Problem_233.hpp"
#include "problems_231_240/Problem_234.hpp"
#include "problems_231_240/Problem_235.hpp"
#include "problems_231_240/Problem_236.hpp"
#include "problems_231_240/Problem_237.hpp"
#include "problems_231_240/Problem_238.hpp"

// Problem 231
TEST( Problem_231, Given_Case )
{
  std::string result = noRepeatingAdjacentCharacters( "aaabbc" );
  EXPECT_EQ( result, "abacba" );

  result = noRepeatingAdjacentCharacters( "aaab" );
  EXPECT_EQ( result, "" );
}

// Problem 232
TEST( Problem_232, Given_Case )
{
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
TEST( Problem_223, Test_Case )
{
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
TEST( Problem_234, Test_Case )
{
  UndirectedGraph graph( 3 );
  graph.add_edge( 0, 1, 5 );
  graph.add_edge( 1, 2, 10 );
  graph.add_edge( 2, 0, 15 );

  auto result = max_spanning_tree( graph );

  EXPECT_EQ( result.size(), 2 );
}

// Problem 235


// Problem 236


// Problem 237


// Problem 238


// Problem 239


// Problem 240
