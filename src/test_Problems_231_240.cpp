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


// Problem 235


// Problem 236


// Problem 237


// Problem 238


// Problem 239


// Problem 240
