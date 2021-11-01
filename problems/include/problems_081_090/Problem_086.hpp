#ifndef PROBLEMS_081_090_PROBLEM_086_HPP
#define PROBLEMS_081_090_PROBLEM_086_HPP

#pragma once

/* MEDIUM
Given a string of parentheses, write a function to compute the minimum number of
parentheses to be removed to make the string valid (i.e. each open parenthesis
is eventually closed).

For example, given the string "()())()", you should return 1. Given the string
")(", you should return 2, since we must remove all of them.
*/

#include <string>
#include <vector>

inline int parentheses_to_remove( std::string parens_str )
{
  int               counter = 0;
  std::vector<bool> used( parens_str.size() );

  for( int i = 0; i < parens_str.size(); i++ )
  {
    if( used[i] ) continue;
    if( parens_str[i] == ')' )
    {
      used[i] = true;
      counter++;
      continue;
    }
    if( parens_str[i] == '(' )
    {
      used[i]        = true;
      bool completed = false;
      for( int j = i + 1; j < parens_str.size(); j++ )
      {
        if( !used[j] && parens_str[j] == ')' )
        {
          used[j]   = true;
          completed = true;
          break;
        }
      }
      if( !completed ) counter++;
    }
  }
  return counter;
}
#endif
