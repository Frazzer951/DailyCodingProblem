#ifndef PROBLEMS_021_030_PROBLEM_022_HPP
#define PROBLEMS_021_030_PROBLEM_022_HPP

#pragma once

/* MEDIUM
Given a dictionary of words and a string made up of those words (no spaces),
return the original sentence in a list. If there is more than one possible
reconstruction, return any of them. If there is no possible reconstruction, then
return null.

For example, given the set of words 'quick', 'brown', 'the', 'fox', and the
string "thequickbrownfox", you should return ['the', 'quick', 'brown', 'fox'].

Given the set of words 'bed', 'bath', 'bedbath', 'and', 'beyond', and the string
"bedbathandbeyond", return either ['bed', 'bath', 'and', 'beyond] or ['bedbath',
'and', 'beyond'].
*/

#include <string>
#include <vector>

inline std::vector<std::string> decompressString( const std::vector<std::string> & wordSet, std::string str )
{
  std::vector<std::string> sentance;

  while( str.length() > 0 )
  {
    bool wordFound = false;
    for( const std::string & word : wordSet )
    {
      auto index = str.find( word );
      if( index == 0 )
      {
        sentance.push_back( str.substr( 0, word.length() ) );
        str       = str.substr( word.length() );
        wordFound = true;
      }
    }
    if( !wordFound ) break;
  }

  return sentance;
}
#endif
