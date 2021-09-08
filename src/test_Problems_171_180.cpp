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

// Problem 173
TEST( Problem_173, Given_Case )
{
  std::map<std::string, std::any> vals;
  std::map<std::string, std::any> foo;
  std::map<std::string, std::any> bar;
  bar["baz"]  = 8;
  foo["a"]    = 5;
  foo["bar"]  = bar;
  vals["key"] = 3;
  vals["foo"] = foo;

  std::map<std::string, int> expected;
  expected["key"]         = 3;
  expected["foo.a"]       = 5;
  expected["foo.bar.baz"] = 8;

  std::map<std::string, int> result = flatten( vals );

  EXPECT_EQ( result, expected );
}

// Problem 175
TEST( Problem_175, Test_Case )
{
  std::vector<transition> transitions = { { 'a', 'a', 0.9 },  { 'a', 'b', 0.075 }, { 'a', 'c', 0.025 },
                                          { 'b', 'a', 0.15 }, { 'b', 'b', 0.8 },   { 'b', 'c', 0.05 },
                                          { 'c', 'a', 0.25 }, { 'c', 'b', 0.25 },  { 'c', 'c', 0.5 } };

  auto result = markovChain( 'a', 5000, transitions );
}