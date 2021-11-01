#ifndef PROBLEMS_061_070_PROBLEM_062_HPP
#define PROBLEMS_061_070_PROBLEM_062_HPP

#pragma once

/* MEDIUM
There is an N by M matrix of zeroes. Given N and M, write a function to count
the number of ways of starting at the top-left corner and getting to the
bottom-right corner. You can only move right or down.

For example, given a 2 by 2 matrix, you should return 2, since there are two
ways to get to the bottom-right:

 * Right, then down
 * Down, then right

Given a 5 by 5 matrix, there are 70 ways to get to the bottom-right.
*/

#include <vector>

inline int num_ways( int n, int m )
{
  std::vector<std::vector<int>> A( n, std::vector<int>( m, 0 ) );
  for( int i = 0; i < n; i++ ) A[i][0] = 1;
  for( int j = 0; j < m; j++ ) A[0][j] = 1;

  for( int i = 1; i < n; i++ )
  {
    for( int j = 1; j < m; j++ ) { A[i][j] = A[i - 1][j] + A[i][j - 1]; }
  }
  return A[n - 1][m - 1];
}
#endif
