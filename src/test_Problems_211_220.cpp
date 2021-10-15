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
TEST( Problem_212, Given_Case )
{
  // given 1, return "A". Given 27, return "AA"
  std::string col1 = colLetter( 1 );
  std::string col2 = colLetter( 27 );

  EXPECT_EQ( col1, "A" );
  EXPECT_EQ( col2, "AA" );
}

TEST( Problem_212, Test_Case )
{
  std::string col1 = colLetter( 2 );
  std::string col2 = colLetter( 25 );
  std::string col3 = colLetter( 26 );
  std::string col4 = colLetter( 52 );
  std::string col5 = colLetter( 53 );

  EXPECT_EQ( col1, "B" );
  EXPECT_EQ( col2, "Y" );
  EXPECT_EQ( col3, "Z" );
  EXPECT_EQ( col4, "ZZ" );
  EXPECT_EQ( col5, "AAA" );
}

// Problem 213


// Problem 214


// Problem 215


// Problem 216


// Problem 217


// Problem 218


// Problem 219


// Problem 220
