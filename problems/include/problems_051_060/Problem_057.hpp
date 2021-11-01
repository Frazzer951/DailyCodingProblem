#pragma once

/* MEDIUM
Given a string s and an integer k, break up the string into multiple lines such
that each line has a length of k or less. You must break it up so that words
don't break across lines. Each line has to have the maximum possible amount of
words. If there's no way to break the text up, then return null.

You can assume that there are no spaces at the ends of the string and that there
is exactly one space between each word.

For example, given the string "the quick brown fox jumps over the lazy dog" and
k = 10, you should return: ["the quick", "brown fox", "jumps over", "the lazy",
"dog"]. No string in the list has a length of more than 10.
*/

#include <string>
#include <utility>
#include <vector>

#include "Futils.hpp"

inline std::vector<std::string> splitString( std::string str, int k )
{
  std::vector<std::string> multi_string;

  auto split_string = split( std::move( str ) );

  int         count = 0;
  std::string cur_str;
  for( const auto & word : split_string )
  {
    if( count == 0 )
    {
      cur_str += word;
      count = (int) word.size();
    }
    else if( count + word.size() + 1 <= k )
    {
      cur_str += " " + word;
      count += (int) word.size() + 1;
    }
    else
    {
      multi_string.push_back( cur_str );
      cur_str = word;
      count   = (int) word.size();
    }
  }
  multi_string.push_back( cur_str );

  return multi_string;
}