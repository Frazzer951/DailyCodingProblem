#pragma once

/* EASY
Given two strings A and B, return whether or not
A can be shifted some number of times to get B.

For example, if A is abcde and B is cdeab, return true.
If A is abc and B is acb, return false.
*/

#include <string>

inline bool isSifted( std::string A, std::string B )
{
  if( A == B ) return true;

  for( int i = 0; i < A.size(); i++ )
  {
    bool matching = true;
    for( int j = 0; j < B.size(); j++ )
    {
      if( A[( i + j ) % A.size()] != B[j] )
      {
        matching = false;
        break;
      }
    }
    if( matching ) return true;
  }
  return false;
}