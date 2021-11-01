#include "gtest/gtest.h"

#include "problems_221_230/Problem_221.hpp"
#include "problems_221_230/Problem_222.hpp"
#include "problems_221_230/Problem_223.hpp"
#include "problems_221_230/Problem_224.hpp"
#include "problems_221_230/Problem_225.hpp"
#include "problems_221_230/Problem_226.hpp"
#include "problems_221_230/Problem_227.hpp"
#include "problems_221_230/Problem_228.hpp"
#include "problems_221_230/Problem_229.hpp"
#include "problems_221_230/Problem_230.hpp"

// Problem 221
TEST( Problem_221, Given_Case )
{
  EXPECT_EQ( nthSevenish( 1 ), 1 );
  EXPECT_EQ( nthSevenish( 2 ), 7 );
  EXPECT_EQ( nthSevenish( 3 ), 8 );
  EXPECT_EQ( nthSevenish( 4 ), 49 );
}

// Problem 222
TEST( Problem_222, Given_Case )
{
  // given "/usr/bin/../bin/./scripts/../", return "/usr/bin/"
  std::string result = shortestAbsolutePath( "/usr/bin/../bin/./scripts/../" );
  EXPECT_EQ( result, "/usr/bin/" );
}

// Problem 223
TEST( Problem_223, Given_Case )
{
  auto * root =
      new btNode( 5, new btNode( 4, new btNode<int>( 1, nullptr, new btNode<int>( 2, nullptr, new btNode( 3 ) ) ) ),
                  new btNode( 8 ) );

  std::string result = inOrderTraversal( root );
  EXPECT_EQ( result, "1 2 3 4 5 8 " );
}

// Problem 224
TEST( Problem_224, Given_Case )
{
  // for the input [1, 2, 3, 10], you should return 7.
  int result = smallestIntNotSubset( { 1, 2, 3, 10 } );

  EXPECT_EQ( result, 7 );
}

// Problem 225
TEST( Problem_225, Given_Case )
{
  // if N = 5 and k = 2, the order of executions would be [2, 4, 1, 5, 3], so you should return 3.
  int result = last_prisoner( 5, 2 );
  EXPECT_EQ( result, 3 );
}

// Problem 226


// Problem 227


// Problem 228


// Problem 229


// Problem 230