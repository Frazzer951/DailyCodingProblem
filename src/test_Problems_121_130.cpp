#include "Problem_121.hpp"
#include "Problem_122.hpp"
#include "Problem_123.hpp"

#include "gtest/gtest.h"

// Problem 122
TEST( Problem_122, Given_Case )
{
  std::vector<std::vector<int>> coins = { { 0, 3, 1, 1 }, { 2, 0, 0, 4 }, { 1, 5, 3, 1 } };

  int result = maxCoins( coins );

  EXPECT_EQ( 12, result );
}