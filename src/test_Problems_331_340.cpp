#include "gtest/gtest.h"

#include "problems_331_340/Problem_331.hpp"
#include "problems_331_340/Problem_332.hpp"
#include "problems_331_340/Problem_333.hpp"
#include "problems_331_340/Problem_334.hpp"
#include "problems_331_340/Problem_335.hpp"
#include "problems_331_340/Problem_336.hpp"
#include "problems_331_340/Problem_337.hpp"
#include "problems_331_340/Problem_338.hpp"
#include "problems_331_340/Problem_339.hpp"
#include "problems_331_340/Problem_340.hpp"


// Problem 331


// Problem 332


// Problem 333


// Problem 334


// Problem 335


// Problem 336


// Problem 337


// Problem 338


// Problem 339


// Problem 340
TEST( Problem_340, Given_Case )
{
  std::pair<std::pair<int, int>, std::pair<int, int>> result =
      findClosestPair( { { 1, 1 }, { -1, -1 }, { 3, 4 }, { 6, 1 }, { -1, -6 }, { -4, -3 } } );
  std::pair<std::pair<int, int>, std::pair<int, int>> expected = { { 1, 1 }, { -1, -1 } };
  EXPECT_EQ( result, expected );
}