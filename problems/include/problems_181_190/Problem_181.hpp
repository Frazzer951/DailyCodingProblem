#pragma once

/* HARD
Given a string, split it into as few strings as possible such that each string
is a palindrome.

For example, given the input string racecarannakayak, return ["racecar", "anna",
"kayak"].

Given the input string abc, return ["a", "b", "c"].
*/

#include <string>
#include <vector>

#include "problems_031_040/Problem_034.hpp"


inline std::vector<std::string> splitPalindrome( std::string str )
{
  std::vector<std::string> palindromes;

  while( !str.empty() )
  {
    for( size_t i = str.size(); i > 0; i-- )
    {
      std::string substr = str.substr( 0, i );
      if( isPalindrome( substr ) )
      {
        palindromes.push_back( substr );
        str = str.substr( i );
        break;
      }
    }
  }

  return palindromes;
}