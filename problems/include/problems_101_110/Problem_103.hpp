#ifndef PROBLEMS_101_110_PROBLEM_103_HPP
#define PROBLEMS_101_110_PROBLEM_103_HPP


#pragma once

/* MEDIUM
Given a string and a set of characters, return the shortest substring containing
all the characters in the set.

For example, given the string "figehaeci" and the set of characters {a, e, i},
you should return "aeci".

If there is no substring containing all the characters in the set, return null.
*/
#include <map>
#include <string>
#include <vector>

inline int smallest( std::string s1, const std::vector<char> & s2 )
{
  if( s2.empty() ) return 0;
  std::map<char, int> d;
  int                 nneg = 0;

  auto incr = [&d, &nneg]( char c ) mutable -> void
  {
    d[c]++;
    if( d[c] == 0 ) nneg--;
  };
  auto decr = [&d, &nneg]( char c ) mutable -> void
  {
    if( d[c] == 0 ) nneg++;
    d[c]--;
  };

  for( char c : s2 )
  {
    decr( c );
  }
  std::size_t minlen = s1.size() + 1;
  std::size_t j      = 0;
  for( std::size_t i = 0; i < s1.size(); i++ )
  {
    while( nneg > 0 )
    {
      if( j >= s1.size() ) return (int) minlen;
      incr( s1[j] );
      j++;
    }
    minlen = std::min( minlen, j - i );
    decr( s1[i] );
  }
  return (int) minlen;
}
#endif
