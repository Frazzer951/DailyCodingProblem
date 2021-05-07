#pragma once

#include <string>
#include <vector>

/* EASY
The edit distance between two strings refers to the minimum number of character insertions, deletions, and substitutions
required to change one string to the other. For example, the edit distance between �kitten� and �sitting� is three:
substitute the �k� for �s�, substitute the �e� for �i�, and append a �g�.

Given two strings, compute the edit distance between them.
*/

int strDistance( std::string s1, std::string s2 )
{
  size_t x = s1.size() + 1;
  size_t y = s2.size() + 1;

  std::vector<std::vector<int>> A( y, std::vector<int>( x, -1 ) );

  for( int i = 0; i < x; i++ ) { A[0][i] = i; }
  for( int j = 0; j < y; j++ ) { A[j][0] = j; }

  for( int i = 1; i < y; i++ )
  {
    for( int j = 1; j < x; j++ )
    {
      if( s1[j - 1] == s2[i - 1] ) A[i][j] = A[i - 1][j - 1];
      else
      {
        A[i][j] = std::min( std::min( A[i - 1][j] + 1, A[i][j - 1] + 1 ), A[i - 1][j - 1] + 1 );
      }
    }
  }
  return A[y - 1][x - 1];
}