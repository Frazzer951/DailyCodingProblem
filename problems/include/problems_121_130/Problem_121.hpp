#ifndef PROBLEMS_121_130_PROBLEM_121_HPP
#define PROBLEMS_121_130_PROBLEM_121_HPP

#pragma once

/* HARD
Given a string which we can delete at most k, return whether you can make a
palindrome.

For example, given 'waterrfetawx' and a k of 2, you could delete f and x to get
'waterretaw'.
*/
#include <algorithm>
#include <string>
#include <vector>

inline int longest_palindromic_subsequence( std::string s ) {
  std::string rs = s;
  std::reverse( rs.begin(), rs.end() );
  if ( s == rs ) return (int) s.size();

  int                           n = (int) s.size();
  std::vector<std::vector<int>> A( n, std::vector( n, 0 ) );

  for ( int i = n - 1; i >= 0; i-- ) {
    A[i][i] = 1;
    for ( int j = i + 1; j < n; j++ ) {
      if ( s[i] == s[j] )
        A[i][j] = 2 + A[i + 1][j - 1];
      else
        A[i][j] = std::max( A[i + 1][j], A[i][j - 1] );
    }
  }
  return A[0][n - 1];
}

inline bool k_palindrome( const std::string &s, int k ) { return s.size() - longest_palindromic_subsequence( s ) <= k; }
#endif
