#include "Problem_141.hpp"
#include "Problem_142.hpp"
#include "Problem_143.hpp"
#include "Problem_144.hpp"

#include "gtest/gtest.h"

// Problem 143
TEST( Problem_143, Given_Case )
{
  // For example, given x = 10 and lst = [9, 12, 3, 5, 14, 10, 10], one partition may be [9, 3, 5, 10, 10, 12, 14].

  std::vector<int> given    = { 9, 12, 3, 5, 14, 10, 10 };
  std::vector<int> expected = { 9, 3, 5, 10, 10, 12, 14 };
  std::vector<int> result   = partition( given, 10 );

  EXPECT_EQ( result, expected );
}