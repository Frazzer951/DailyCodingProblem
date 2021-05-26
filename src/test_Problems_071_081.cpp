#include "Problem_071.hpp"
#include "Problem_072.hpp"

#include "gtest/gtest.h"

// Problem 71
TEST( Problem_71, Test_Case )
{
  int result = rand5();

  EXPECT_TRUE( ( result >= 1 ) && ( result <= 5 ) );
}