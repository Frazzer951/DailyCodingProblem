#ifndef PROBLEMS_131_140_PROBLEM_136_HPP
#define PROBLEMS_131_140_PROBLEM_136_HPP

#pragma once

/* MEDIUM
Given an N by M matrix consisting only of 1's and 0's, find the largest
rectangle containing only 1's and return its area.

For example, given the following matrix:

[[1, 0, 0, 0],
 [1, 0, 1, 1],
 [1, 0, 1, 1],
 [0, 1, 0, 0]]


Return 4.
*/
#include <map>
#include <vector>

inline int explore( std::vector<std::vector<int>> v, std::vector<std::vector<bool>> &seen, int x, int y ) {
  int width  = 0;
  int height = 0;

  for ( int i = x; i < v.size(); i++ ) {
    for ( int j = y; j < v[0].size(); j++ ) {
      seen[i][j] = true;
      if ( v[i][j] != 1 ) break;
      if ( ( i - x ) > width ) width = i - x;
      if ( ( j - y ) > height ) height = j - y;
    }
  }
  return ( width + 1 ) * ( height + 1 );
}

inline int largestRectangle( std::vector<std::vector<int>> v ) {
  std::vector<std::vector<bool>> seen( v.size(), std::vector( v[0].size(), false ) );
  int                            largest = 0;
  for ( int i = 0; i < v.size(); i++ ) {
    for ( int j = 0; j < v[0].size(); j++ ) {
      if ( !seen[i][j] ) {
        seen[i][j] = true;
        if ( v[i][j] == 1 ) largest = std::max( largest, explore( v, seen, i, j ) );
      }
    }
  }
  return largest;
}
#endif
