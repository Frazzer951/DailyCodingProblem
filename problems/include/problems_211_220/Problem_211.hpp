#ifndef PROBLEMS_211_220_PROBLEM_211_HPP
#define PROBLEMS_211_220_PROBLEM_211_HPP

#pragma once

/* MEDIUM
Given a string and a pattern, find the starting indices of all occurrences of
the pattern in the string. For example, given the string "abracadabra" and the
pattern "abr", you should return [0, 7].
*/
#include <string>
#include <vector>

inline std::vector<int> indexOf( const std::string & str, const std::string & pattern )
{
  std::vector<int> indecies;

  for( int i = 0; i < str.size() - pattern.size(); i++ )
  {
    std::string tmp = str.substr( i, pattern.size() );
    if( tmp == pattern ) indecies.push_back( i );
  }

  return indecies;
}
#endif
