#pragma once
/* EASY
Given a string of round, curly, and square open and closing brackets, return whether the brackets are balanced
(well-formed).

For example, given the string "([])[]({})", you should return true.

Given the string "([)]" or "((()", you should return false.
*/

#include <string>

bool isBallancedString( std::string str )
{
  int round = 0, square = 0, curly = 0;

  for( unsigned int i = 0; i < str.size(); i++ )
  {
    switch( str[i] )
    {
      case '(': round++; break;
      case ')':
        if( square == 0 && curly == 0 ) round--;
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