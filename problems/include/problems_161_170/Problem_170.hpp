#ifndef PROBLEMS_161_170_PROBLEM_170_HPP
#define PROBLEMS_161_170_PROBLEM_170_HPP

#pragma once

/* MEDIUM
Given a start word, an end word, and a dictionary of valid words, find the
shortest transformation sequence from start to end such that only one letter is
changed at each step of the sequence, and each transformed word exists in the
dictionary. If there is no possible transformation, return null. Each word in
the dictionary have the same length as start and end and is lowercase.

For example, given start = "dog", end = "cat", and dictionary = {"dot", "dop",
"dat", "cat"}, return ["dog", "dot", "dat", "cat"].

Given start = "dog", end = "cat", and dictionary = {"dot", "tod", "dat", "dar"},
return null as there is no possible transformation from dog to cat.
*/

#include <string>
#include <vector>

inline int lettersOff( const std::string & s1, const std::string & s2 )
{
  int count = 0;
  for( int i = 0; i < s1.size(); i++ )
    if( s1[i] != s2[i] ) count++;
  return count;
}

inline std::vector<std::string> shortestTransform( const std::string & start, const std::string & end,
                                                   std::vector<std::string> dict )
{
  std::vector<std::string> transform;

  for( int i = 0; i < dict.size(); i++ )
  {
    std::string word = dict[i];

    if( lettersOff( word, start ) == 1 )
    {
      if( word == end )
      {
        transform = { start, word };
        return transform;
      }

      std::vector<std::string> newDict = dict;
      newDict.erase( newDict.begin() + i );
      std::vector<std::string> newPath = shortestTransform( word, end, newDict );
      if( !newPath.empty() && ( transform.empty() || newPath.size() < transform.size() ) )
      {
        transform = newPath;
        transform.insert( transform.begin(), start );
      }
    }
  }
  return transform;
}
#endif
