#ifndef PROBLEMS_061_070_PROBLEM_065_HPP
#define PROBLEMS_061_070_PROBLEM_065_HPP

#pragma once

/* EASY
Given a N by M matrix of numbers, print out the matrix in a clockwise spiral.

For example, given the following matrix:

[[1,  2,  3,  4,  5],
 [6,  7,  8,  9,  10],
 [11, 12, 13, 14, 15],
 [16, 17, 18, 19, 20]]


You should print out the following:

1
2
3
4
5
10
15
20
19
18
17
16
11
6
7
8
9
14
13
12
*/

#include <vector>

inline std::vector<int> print_spiral( std::vector<std::vector<int>> v )
{
  std::vector<int> spiral;

  int i = 0;
  int k = 0;
  int m = (int) v.size();
  int l = 0;
  int n = (int) v[0].size();

  /* k - starting row index
     m - ending row index
     l - starting column index
     n - ending column index
     i - iterator
  */

  while( k < m && l < n )
  {
    /* Print the first row from
               the remaining rows */
    for( i = l; i < n; ++i ) { spiral.push_back( v[k][i] ); }
    k++;

    /* Print the last column
         from the remaining columns */
    for( i = k; i < m; ++i ) { spiral.push_back( v[i][n - 1] ); }
    n--;

    /* Print the last row from
                the remaining rows */
    if( k < m )
    {
      for( i = n - 1; i >= l; --i ) { spiral.push_back( v[m - 1][i] ); }
      m--;
    }

    /* Print the first column from
                   the remaining columns */
    if( l < n )
    {
      for( i = m - 1; i >= k; --i ) { spiral.push_back( v[i][l] ); }
      l++;
    }
  }
  return spiral;
}
#endif
