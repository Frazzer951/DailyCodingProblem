#pragma once

/* HARD
Given a list of integers S and a target number k, write a function that returns a subset of S that adds up to k. If such
a subset cannot be made, then return null.

Integers can appear more than once in the list. You may assume all numbers in the list are positive.

For example, given S = [12, 1, 61, 5, 9, 2] and k = 24, return [12, 9, 2, 1] since it sums up to 24.
*/

#include <vector>

inline std::vector<int> subset_sum( std::vector<int> nums, int k )
{
  std::vector<std::vector<std::vector<int> *>> A( nums.size() + 1, std::vector<std::vector<int> *>( k + 1, NULL ) );

  for( int i = 0; i < nums.size() + 1; i++ ) { A[i][0] = new std::vector<int>(); }

  for( int i = 1; i < nums.size() + 1; i++ )
  {
    for( int j = 1; j < k + 1; j++ )
    {
      int last = nums[i - 1];
      if( last > j ) A[i][j] = A[i - 1][j];
      else
      {
        if( A[i - 1][j] != NULL ) { A[i][j] = new std::vector<int>( *A[i - 1][j] ); }
        else if( A[i - 1][j - last] != NULL )
        {
          A[i][j] = new std::vector<int>( *A[i - 1][j - last] );
          A[i][j]->push_back( last );
        }
        else
        {
          A[i][j] = NULL;
        }
      }
    }
  }
  return *A[nums.size()][k];
}