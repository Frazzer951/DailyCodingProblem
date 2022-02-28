#ifndef PROBLEMS_151_160_PROBLEM_158_HPP
#define PROBLEMS_151_160_PROBLEM_158_HPP


#pragma once

/* MEDIUM
You are given an N by M matrix of 0s and 1s. Starting from the top left corner,
how many ways are there to reach the bottom right corner?

You can only move right and down. 0 represents an empty space while 1 represents
a wall you cannot walk through.

For example, given the following matrix:

[[0, 0, 1],
 [0, 0, 1],
 [1, 0, 0]]


Return two, as there are only two ways to get to the bottom right:

 * Right, down, down, right
 * Down, right, down, right

The top left corner and bottom right corner will always be 0.
*/
#include <vector>

inline int num_ways( std::vector<std::vector<int>> matrix )
{
  const int                     WALL = 1;
  size_t                        m    = matrix.size();
  size_t                        n    = matrix[0].size();
  std::vector<std::vector<int>> num_ways_matrix( m, std::vector<int>( n, 0 ) );

  // Fill first row
  for( int j = 0; j < n; j++ )
  {
    if( matrix[0][j] == WALL ) break;
    num_ways_matrix[0][j] = 1;
  }
  // Fill first col
  for( int i = 0; i < m; i++ )
  {
    if( matrix[i][0] == WALL ) break;
    num_ways_matrix[i][0] = 1;
  }

  for( int i = 1; i < m; i++ )
  {
    for( int j = 1; j < n; j++ )
    {
      int from_top  = ( matrix[i - 1][j] != WALL ) ? num_ways_matrix[i - 1][j] : 0;
      int from_left = ( matrix[i][j - 1] != WALL ) ? num_ways_matrix[i][j - 1] : 0;

      num_ways_matrix[i][j] = from_top + from_left;
    }
  }

  return num_ways_matrix[m - 1][n - 1];
}
#endif
