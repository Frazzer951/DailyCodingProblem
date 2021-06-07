#include "Problem_081.hpp"
#include "Problem_082.hpp"
#include "Problem_083.hpp"
#include "Problem_084.hpp"

#include "gtest/gtest.h"

// Problem 81
TEST( Problem_81, Given_Case )
{
  /*
  For example if {“2”: [“a”, “b”, “c”], 3: [“d”, “e”, “f”], …}
  then “23” should return [“ad”, “ae”, “af”, “bd”, “be”, “bf”, “cd”, “ce”, “cf"].
  */

  std::map<char, std::vector<std::string>> num_map;
  num_map['2'] = { "a", "b", "c" };
  num_map['3'] = { "d", "e", "f" };

  std::vector<std::string> expected = { "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" };
  std::vector<std::string> result   = num_to_str( "23", num_map );

  EXPECT_EQ( expected, result );
}

// Problem 82
TEST( Problem_82, Test_read7 )
{
  filereader filereader( "Problem_082.txt" );

  std::string one   = filereader.read7();
  std::string two   = filereader.read7();
  std::string three = filereader.read7();

  EXPECT_EQ( "Hello w", one );
  EXPECT_EQ( "orld", two );
  EXPECT_EQ( "", three );
}

TEST( Problem_82, Test_Case_1 )
{
  std::string result = readN( 5 );

  EXPECT_EQ( "Hello", result );
}

TEST( Problem_82, Test_Case_2 )
{
  std::string result = readN( 11 );

  EXPECT_EQ( "Hello world", result );
}