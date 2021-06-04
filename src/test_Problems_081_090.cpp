#include "Problem_081.hpp"

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