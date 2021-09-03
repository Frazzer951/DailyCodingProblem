#pragma once

/* MEDIUM
Given a string s and a list of words words, where each word is the same length, find all starting indices of substrings
in s that is a concatenation of every word in words exactly once.

For example, given s = "dogcatcatcodecatdog" and words = ["cat", "dog"], return [0, 13], since "dogcat" starts at index
0 and "catdog" starts at index 13.

Given s = "barfoobazbitbyte" and words = ["dog", "cat"], return [] since there are no substrings composed of "dog" and
"cat" in s.

The order of the indices does not matter.
*/

#include <algorithm>
#include <set>
#include <string>
#include <vector>

inline bool testSubstring( std::string s, const std::vector<std::string> & words )
{
  std::vector<std::string> splitWords;

  while( !s.empty() )
  {
    splitWords.push_back( s.substr( 0, 3 ) );
    s = s.substr( 3 );
  }

  std::set<std::string> set;
  long unsigned int     size = splitWords.size();
  for( long unsigned int i = 0; i < size; ++i ) set.insert( splitWords[i] );
  splitWords.assign( set.begin(), set.end() );
  std::sort( splitWords.begin(), splitWords.end() );

  return splitWords == words;
}

inline std::vector<int> indiciesOfSubstrings( const std::string & s, std::vector<std::string> words )
{
  std::sort( words.begin(), words.end() );
  std::vector<int> indecies;

  long unsigned int lengthOfSubstr = words[0].size() * words.size();

  for( int i = 0; i <= s.size() - lengthOfSubstr; i++ )
  {
    std::string curSubstr = s.substr( i, lengthOfSubstr );
    if( testSubstring( curSubstr, words ) ) indecies.push_back( i );
  }
  return indecies;
}