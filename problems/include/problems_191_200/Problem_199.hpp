#pragma once

/* HARD
Given a string of parentheses, find the balanced string that can be produced
from it using the minimum number of insertions and deletions. If there are
multiple solutions, return any of them.

For example, given "(()", you could return "(())". Given "))()(", you could
return "()()()()".
*/

#include <string>

inline std::string balanceParentheses( const std::string & str )
{
  std::string ret;

  int open_count = 0;

  for( char c : str )
  {
    if( c == '(' )
    {
      open_count++;
      ret += c;
    }
    else if( c == ')' )
    {
      if( open_count > 0 )
      {
        open_count--;
        ret += c;
      }
      else
      {
        ret += "()";
      }
    }
  }
  for( int i = 0; i < open_count; i++ ) { ret += ')'; }

  return ret;
}