#ifndef PROBLEMS_251_260_PROBLEM_253_HPP
#define PROBLEMS_251_260_PROBLEM_253_HPP


#pragma once

/* MEDIUM
Given a string and a number of lines k, print the string in zigzag form. In
zigzag, characters are printed out diagonally from top left to bottom right
until reaching the kth line, then back up to top right, and so on.

For example, given the sentence "thisisazigzag" and k = 4, you should print:

t     a     g
 h   s z   a
  i i   i z
   s     g
*/

#include <string>
#include <vector>

inline std::string zigzag( std::string str, int k )
{
  std::vector<std::vector<char>> lines = std::vector( k, std::vector<char>( str.size(), ' ' ) );
  bool                           down  = true;
  int                            line  = 0;
  for( int i = 0; i < str.size(); i++ )
  {
    lines[line][i] = str[i];
    if( line == k - 1 )
    {
      down = false;
    }
    else if( line == 0 )
    {
      down = true;
    }
    if( down )
    {
      line++;
    }
    else
    {
      line--;
    }
  }
  std::string result;
  for( const auto & line : lines )
  {
    for( auto c : line )
    {
      result += c;
    }
    result += '\n';
  }
  return result;
}

#endif
