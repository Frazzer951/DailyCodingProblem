#ifndef PROBLEMS_041_050_PROBLEM_046_HPP
#define PROBLEMS_041_050_PROBLEM_046_HPP

#pragma once

/* HARD
Given a string, find the longest palindromic contiguous substring. If there are
more than one with the maximum length, return any one.

For example, the longest palindromic substring of "aabcdcb" is "bcdcb". The
longest palindromic substring of "bananas" is "anana".
*/
#include <algorithm>
#include <string>

inline bool is_palindrome( const std::string &s ) {
  std::string temp = s;
  std::reverse( temp.begin(), temp.end() );

  return s == temp;
}

inline std::string longest_palindrome( const std::string &s ) {
  std::string longest;
  for ( int i = 0; i < s.length() - 1; i++ ) {
    for ( int j = 1; j < s.length(); j++ ) {
      std::string const substring = s.substr( i, j - i );
      if ( is_palindrome( substring ) && substring.length() > longest.length() ) { longest = substring; }
    }
  }
  return longest;
}
#endif
