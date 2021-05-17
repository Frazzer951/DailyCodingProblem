#include "Problem_061.hpp"
#include "Problem_062.hpp"
#include "Problem_063.hpp"

#include "gtest/gtest.h"

// Problem 61
TEST( Problem_61, Given_Case )
{
  double result = p61::pow( 2, 10 );

  EXPECT_DOUBLE_EQ( 1024, result );
}

TEST( Problem_61, Test_Case )
{
  double result = p61::pow( 5, -5 );

  EXPECT_DOUBLE_EQ( 0.00032, result );
}