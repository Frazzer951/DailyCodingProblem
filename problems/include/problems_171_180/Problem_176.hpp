#ifndef PROBLEMS_171_180_PROBLEM_176_HPP
#define PROBLEMS_171_180_PROBLEM_176_HPP


#pragma once

/* EASY
Determine whether there exists a one-to-one character mapping from one string s1
to another s2.

For example, given s1 = abc and s2 = bcd, return true since we can map a to b, b
to c, and c to d.

Given s1 = foo and s2 = bar, return false since the o cannot map to two
characters.
*/
#include <map>
#include <string>

inline bool canMap( std::string s1, std::string s2 )
{
  std::map<char, char> used;

  if( s1.size() != s2.size() ) return false;

  for( int i = 0; i < s1.size(); i++ )
  {
    if( used.find( s1[i] ) != used.end() )
    {
      if( used[s1[i]] != s2[i] ) return false;
    }
    else
    {
      used[s1[i]] = s2[i];
    }
  }
  return true;
}
#endif
