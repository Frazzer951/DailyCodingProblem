#pragma once

/* HARD
Let A be an N by M matrix in which every row and every column is sorted.

Given i1, j1, i2, and j2, compute the number of elements of M smaller than M[i1, j1] and larger than M[i2, j2].

For example, given the following matrix:

[[1, 3, 7, 10, 15, 20],
 [2, 6, 9, 14, 22, 25],
 [3, 8, 10, 15, 25, 30],
 [10, 11, 12, 23, 30, 35],
 [20, 25, 30, 35, 40, 45]]
And i1 = 1, j1 = 1, i2 = 3, j2 = 3, return 15 as there are 15 numbers in the matrix smaller than 6 or greater than 23.
*/

#include <vector>

inline int matrix_count_edge( std::vector<std::vector<int>> matrix, int i1, int j1, int i2, int j2 )
{
  int m     = (int) matrix.size();
  int n     = (int) matrix[0].size();
  int count = 0;

  // Count numbers smaller than m[i1][j1]
  int a = matrix[i1][j1];
  int i = 0;
  int j = n;

  for( j = n - 1; j >= 0; j-- )
  {
    while( i < m && matrix[i][j] < a ) i++;
    count += i;
  }

  // Count numbers greater than m[i2][j2]
  int b = matrix[i2][j2];
  i     = 0;

  for( j = n - 1; j >= 0; j-- )
  {
    while( i < m && matrix[i][j] < b ) i++;
    count += m - i;
  }
  return count;
}