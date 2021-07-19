#include "Problem_121.hpp"
#include "Problem_122.hpp"
#include "Problem_123.hpp"
#include "Problem_124.hpp"
#include "Problem_125.hpp"
#include "Problem_126.hpp"

#include "gtest/gtest.h"

// Problem 122
TEST( Problem_122, Given_Case )
{
  std::vector<std::vector<int>> coins = { { 0, 3, 1, 1 }, { 2, 0, 0, 4 }, { 1, 5, 3, 1 } };

  int result = maxCoins( coins );

  EXPECT_EQ( 12, result );
}

// Problem 123
TEST( Problem_123, Test_Case )
{
  /*
  True:
        "10", a positive integer
        "-10", a negative integer
        "10.1", a positive real number
        "-10.1", a negative real number
        "1e5", a number in scientific notation
  False:
        "a"
        "x 1"
        "a -2"
        "-"
  */
  EXPECT_TRUE( isNum( "10" ) );
  EXPECT_TRUE( isNum( "-10" ) );
  EXPECT_TRUE( isNum( "10.1" ) );
  EXPECT_TRUE( isNum( "-10.1" ) );
  EXPECT_TRUE( isNum( "1e5" ) );
  EXPECT_TRUE( isNum( "+10" ) );

  EXPECT_FALSE( isNum( "a" ) );
  EXPECT_FALSE( isNum( "x 1" ) );
  EXPECT_FALSE( isNum( "a -2" ) );
  EXPECT_FALSE( isNum( "-" ) );
  EXPECT_FALSE( isNum( "e" ) );
  EXPECT_FALSE( isNum( "e10" ) );
  EXPECT_FALSE( isNum( "5e" ) );
  EXPECT_FALSE( isNum( "5ee" ) );
  EXPECT_FALSE( isNum( "1." ) );
  EXPECT_FALSE( isNum( ".1" ) );
}