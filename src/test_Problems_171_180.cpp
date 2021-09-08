#include "Problem_171.hpp"
#include "Problem_172.hpp"
#include "Problem_173.hpp"
#include "Problem_174.hpp"
#include "Problem_175.hpp"
#include "Problem_176.hpp"
#include "Problem_177.hpp"

#include "gtest/gtest.h"

// Problem 171
TEST( Problem_171, Test_Case )
{
  std::vector<Timelog> entries = { { 0, 3, Type::enter }, { 10, 6, Type::exit },  { 3, 15, Type::enter },
                                   { 99, 2, Type::exit }, { 100, 4, Type::exit }, { 18, 5, Type::exit },
                                   { 5, 1, Type::enter }, { 6, 2, Type::exit } };

  std::pair<long, long> result = busiest_period( entries );
  std::pair<long, long> expected( 5, 6 );

  EXPECT_EQ( result, expected );
}

// Problem 172
TEST( Problem_172, Given_Case_1 )
{
  // Given s = "dogcatcatcodecatdog" and words = ["cat", "dog"], return [0, 13]
  std::vector<int> result   = indiciesOfSubstrings( "dogcatcatcodecatdog", { "cat", "dog" } );
  std::vector<int> expected = { 0, 13 };

  EXPECT_EQ( result, expected );
}

TEST( Problem_172, Given_Case_2 )
{
  // Given s = "barfoobazbitbyte" and words = ["dog", "cat"], return []
  std::vector<int> result   = indiciesOfSubstrings( "barfoobazbitbyte", { "dog", "cat" } );
  std::vector<int> expected = {};

  EXPECT_EQ( result, expected );
}