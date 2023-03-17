#ifndef PROBLEMS_021_030_PROBLEM_025_HPP
#define PROBLEMS_021_030_PROBLEM_025_HPP

#pragma once

/* HARD
Implement regular expression matching with the following special characters:

 * . (period) which matches any single character
 * * (asterisk) which matches zero or more of the preceding element

That is, implement a function that takes in a string and a valid regular
expression and returns whether or not the string matches the regular expression.

For example, given the regular expression "ra." and the string "ray", your
function should return true. The same regular expression on the string "raymond"
should return false.

Given the regular expression ".*at" and the string "chat", your function should
return true. The same regular expression on the string "chats" should return
false.
*/
#include <string>

inline bool regex( std::string str, std::string exp ) {
  unsigned int str_index = 0;

  for ( unsigned int i = 0; i < exp.size(); ++i ) {
    char const cur = str[str_index];
    switch ( exp[i] ) {
    case '.':
      // Match Single Char
      str_index++;
      break;
    case '*':
      // Match zero or more of the preceding element
      if ( exp[i + 1] == cur ) break;

      while ( cur == str[str_index] ) { str_index++; }
      break;
    default:
      // Regular Char
      if ( exp[i] != cur ) return false;
      str_index++;
      break;
    }
  }
  return str_index == str.size();
}
#endif
