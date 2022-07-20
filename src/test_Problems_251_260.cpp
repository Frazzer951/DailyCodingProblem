#include "gtest/gtest.h"

#include "problems_251_260/Problem_251.hpp"
#include "problems_251_260/Problem_252.hpp"
#include "problems_251_260/Problem_253.hpp"
#include "problems_251_260/Problem_254.hpp"
#include "problems_251_260/Problem_255.hpp"
#include "problems_251_260/Problem_256.hpp"
#include "problems_251_260/Problem_257.hpp"
#include "problems_251_260/Problem_258.hpp"
#include "problems_251_260/Problem_259.hpp"
#include "problems_251_260/Problem_260.hpp"


// Problem 251


// Problem 252
TEST( Problem_252, Given_Case )
{
  // For example, 4 / 13 can be represented as 1 / 4 + 1 / 18 + 1 / 468
  std::vector<int> result   = egyptianFraction( 4, 13 );
  std::vector<int> expected = { 4, 18, 468 };

  EXPECT_EQ( expected, result );
}

// Problem 253
TEST( Problem_253, Given_Case )
{
  /*
   For example, given the sentence "thisisazigzag" and k = 4, you should print:

    t     a     g
     h   s z   a
      i i   i z
       s     g
   */
  std::string result   = zigzag( "thisisazigzag", 4 );
  std::string expected = "t     a     g\n h   s z   a \n  i i   i z  \n   s     g   \n";
  EXPECT_EQ( expected, result );
}

// Problem 254
TEST( Problem_254, Given_Case )
{
  /*
   For example, given the following tree:

           0
        /     \
      1         2
    /            \
  3                 4
    \             /   \
      5          6     7


   You should convert it to:

        0
     /     \
   5         4
           /   \
          6     7
  */

  btNode<int> * root = new btNode<int>(
      0, new btNode<int>( 1, new btNode<int>( 3, nullptr, new btNode<int>( 5 ) ) ),
      new btNode<int>( 2, nullptr, new btNode<int>( 4, new btNode<int>( 6 ), new btNode<int>( 7 ) ) ) );

  btNode<int> * result = trim_tree( root );
  btNode<int> * expected =
      new btNode<int>( 0, new btNode<int>( 5 ), new btNode<int>( 4, new btNode<int>( 6 ), new btNode<int>( 7 ) ) );
  EXPECT_EQ( *expected, *result );
}

// Problem 255


// Problem 256


// Problem 257


// Problem 258


// Problem 259


// Problem 260
