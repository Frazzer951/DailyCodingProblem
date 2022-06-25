#ifndef PROBLEMS_151_160_PROBLEM_157_HPP
#define PROBLEMS_151_160_PROBLEM_157_HPP


#pragma once

/* EASY
Given a string, determine whether any permutation of it is a palindrome.

For example, carrace should return true, since it can be rearranged to form
racecar, which is a palindrome. daily should return false, since there's no
rearrangement that can form a palindrome.
*/
#include <map>
#include <string>

inline bool permPalindrome( const std::string & word )
{
  std::map<char, int> letterCount;

  for( char c : word )
  {
    letterCount[c]++;
  }

  bool oneOdd = false;

  for( auto & [c, n] : letterCount )
  {
    if( n % 2 != 0 )
    {
      if( oneOdd ) return false;
      oneOdd = true;
    }
  }
  return true;
}
#endif
