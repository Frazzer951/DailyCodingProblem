#ifndef PROBLEMS_121_130_PROBLEM_123_HPP
#define PROBLEMS_121_130_PROBLEM_123_HPP

#pragma once

/* HARD
Given a string, return whether it represents a number. Here are the different
kinds of numbers:

 * "10", a positive integer
 * "-10", a negative integer
 * "10.1", a positive real number
 * "-10.1", a negative real number
 * "1e5", a number in scientific notation

And here are examples of non-numbers:

 * "a"
 * "x 1"
 * "a -2"
 * "-"
*/
#include <map>
#include <string>
#include <vector>

inline bool isNum( std::string s ) {
  bool hasNum       = false;
  bool hasE         = false;
  bool hasDecimal   = false;
  int  eCount       = 0;
  int  decimalCount = 0;

  char const           numbers[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };
  char const           allowed[] = { '+', '-', 'e', '.' };
  std::map<char, bool> allowedChars;
  std::map<char, bool> nums;
  for ( char const c : allowed ) allowedChars[c] = true;
  for ( char const c : numbers ) {
    allowedChars[c] = true;
    nums[c]         = true;
  }

  for ( char const c : s ) {
    if ( !allowedChars[c] ) return false;
    if ( !hasNum && nums[c] ) hasNum = true;
    if ( c == 'e' ) {
      hasE = true;
      eCount++;
    }
    if ( c == '.' ) {
      hasDecimal = true;
      decimalCount++;
    }
  }
  if ( !hasNum ) return false;
  if ( !nums[s[0]] && s[0] != '+' && s[0] != '-' ) return false;

  if ( hasE ) {
    if ( eCount > 1 ) return false;
    std::size_t const index = s.find( 'e' );
    if ( !nums[s[index - 1]] || !nums[s[index + 1]] ) return false;
  }

  if ( hasDecimal ) {
    if ( decimalCount > 1 ) return false;
    std::size_t const index = s.find( '.' );
    if ( !nums[s[index - 1]] || !nums[s[index + 1]] ) return false;
  }

  return true;
}
#endif
