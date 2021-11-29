#include "gtest/gtest.h"

#include "problems_241_250/Problem_241.hpp"
#include "problems_241_250/Problem_242.hpp"
#include "problems_241_250/Problem_243.hpp"
#include "problems_241_250/Problem_244.hpp"
#include "problems_241_250/Problem_245.hpp"
#include "problems_241_250/Problem_246.hpp"
#include "problems_241_250/Problem_247.hpp"
#include "problems_241_250/Problem_248.hpp"
#include "problems_241_250/Problem_249.hpp"
#include "problems_241_250/Problem_250.hpp"

// Problem 241
TEST( Problem_241, Given_Case )
{
  // N = 5, and the respective citations of each paper are [4, 3, 0, 1, 5]. Then the h-index would be 3
  int arr[]  = { 4, 3, 0, 1, 5 };
  int result = hIndex( 5, arr );
  EXPECT_EQ( 3, result );
}

// Problem 242
TEST( Problem_242, Test_Case )
{
  sub_hour_counter counter;
  EXPECT_EQ( 0, counter.query( 0, 23 ) );
  for( int i = 0; i < 24; i++ ) { counter.update( i, i * 10 ); }
  for( int i = 0; i < 24; i++ ) { EXPECT_EQ( i * 10, counter.query( i, i ) ); }
  int sum = 0;
  for( int i = 0; i < 24; i++ )
  {
    sum += i * 10;
    EXPECT_EQ( sum, counter.query( 0, i ) );
  }
}

// Problem 243


// Problem 244


// Problem 245


// Problem 246


// Problem 247


// Problem 248


// Problem 249


// Problem 250
