#ifndef PROBLEMS_021_030_PROBLEM_027_HPP
#define PROBLEMS_021_030_PROBLEM_027_HPP

#pragma once

/* EASY
Given a string of round, curly, and square open and closing brackets, return
whether the brackets are balanced (well-formed).

For example, given the string "([])[]({})", you should return true.

Given the string "([)]" or "((()", you should return false.
*/
#include <string>

inline bool isBallancedString( const std::string &str ) {
  int round  = 0;
  int square = 0;
  int curly  = 0;

  for ( char i : str ) {
    switch ( i ) {
    case '(': round++; break;
    case ')':
      if ( square == 0 && curly == 0 )
        round--;
      else
        return false;
      break;
    case '{': curly++; break;
    case '}': curly--; break;
    case '[': square++; break;
    case ']': square--; break;
    }
  }

  return square == 0 && curly == 0 && round == 0;
}
#endif
