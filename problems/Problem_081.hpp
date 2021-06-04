#pragma once

/* EASY
Given a mapping of digits to letters (as in a phone number),
and a digit string, return all possible letters the number
could represent. You can assume each valid number in the
mapping is a single digit.

For example if {“2”: [“a”, “b”, “c”], 3: [“d”, “e”, “f”], …}
then “23” should return [“ad”, “ae”, “af”, “bd”, “be”, “bf”, “cd”, “ce”, “cf"].
*/

#include <map>
#include <string>
#include <vector>

inline std::vector<std::string> num_to_str( std::string nums, std::map<char, std::vector<std::string>> num_map )
{
  if( nums.size() == 1 ) return num_map[nums[0]];

  std::vector<std::string> possible_strs;

  std::vector<std::string> sub_strs = num_to_str( nums.substr( 1 ), num_map );

  for( const std::string & c : num_map[nums[0]] )
  {
    for( const std::string & sub_str : sub_strs )
    {
      possible_strs.push_back( c + sub_str );
    }
  }
  return possible_strs;
}