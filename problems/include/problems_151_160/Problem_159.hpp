#ifndef PROBLEMS_151_160_PROBLEM_159_HPP
#define PROBLEMS_151_160_PROBLEM_159_HPP

#pragma once

/* EASY
Given a string, return the first recurring character in it, or null if there is
no recurring character.

For example, given the string "acbbac", return "b". Given the string "abcdef",
return null.
*/
#include <map>
#include <string>

inline char firstRepeat( const std::string &str ) {
  std::map<char, int> count;

  for ( char const c : str ) {
    count[c]++;
    if ( count[c] > 1 ) return c;
  }
  return '\0';
}
#endif
