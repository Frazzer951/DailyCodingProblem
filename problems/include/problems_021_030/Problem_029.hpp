#ifndef PROBLEMS_021_030_PROBLEM_029_HPP
#define PROBLEMS_021_030_PROBLEM_029_HPP


#pragma once

/* EASY
Run-length encoding is a fast and simple method of encoding strings. The basic
idea is to represent repeated successive characters as a single count and
character. For example, the string "AAAABBBCCDAA" would be encoded as
"4A3B2C1D2A".

Implement run-length encoding and decoding. You can assume the string to be
encoded have no digits and consists solely of alphabetic characters. You can
assume the string to be decoded is valid.
*/
#include <string>

inline int countChar( const std::string & str, char c )
{
  int count = 0;
  for( char i : str )
  {
    if( i == c ) count++;
    else
      break;
  }
  return count;
}

inline std::string runLengthEncode( std::string str )
{
  std::string return_str;

  while( !str.empty() )
  {
    char c     = str[0];
    int  count = countChar( str, c );
    return_str += std::to_string( count ) + c;
    str = str.substr( count );
  }

  return return_str;
}

inline std::string runLengthDecode( std::string str )
{
  std::string                       return_str;
  std::vector<std::pair<int, char>> charPairs;

  while( !str.empty() )
  {
    charPairs.emplace_back( std::stoi( std::string( 1, str[0] ) ), str[1] );
    str = str.substr( 2 );
  }

  for( auto & charPair : charPairs )
  {
    for( int j = 0; j < charPair.first; j++ ) { return_str += charPair.second; }
  }

  return return_str;
}
#endif
