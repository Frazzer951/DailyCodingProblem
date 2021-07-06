#pragma once

/* HARD
Given a word W and a string S, find all starting indices in S which are anagrams of W.

For example, given that W is "ab", and S is "abxaba", return 0, 3, and 4.
*/

#include <map>
#include <set>
#include <string>
#include <vector>

inline bool isAnagram( const std::string& s1, const std::string& s2 )
{
  std::map<char, int> count1;
  std::map<char, int> count2;
  std::set<char>      chars1;
  std::set<char>      chars2;
  for( char c : s1 )
  {
    count1[c]++;
    chars1.insert( c );
  }
  for( char c : s2 )
  {
    count2[c]++;
    chars2.insert( c );
  }
  if( chars1 != chars2 ) return false;
  return count1 == count2;
}

inline std::vector<int> anagramIndex( const std::string& w, const std::string& s )
{
  std::vector<int> indecies;
  for( int i = 0; i <= s.size() - w.size(); i++ )
  {
    if( isAnagram( w, s.substr( i, w.size() ) ) ) indecies.push_back( i );
  }
  return indecies;
}