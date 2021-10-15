#include "Problem_211.hpp"
#include "Problem_212.hpp"
#include "Problem_213.hpp"
#include "Problem_214.hpp"

#include "gtest/gtest.h"

// Problem 211
TEST( Problem_211, Given_Case )
{
  // given the string "abracadabra" and the pattern "abr", you should return [0, 7]
  std::vector<int> indecies = indexOf( "abracadabra", "abr" );
  std::vector<int> expected = { 0, 7 };

  EXPECT_EQ( indecies, expected );
}

// Problem 212


// Problem 213


// Problem 214


// Problem 215


// Problem 216


// Problem 217


// Problem 218


// Problem 219


// Problem 220
