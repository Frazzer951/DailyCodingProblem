#ifndef PROBLEMS_151_160_PROBLEM_156_HPP
#define PROBLEMS_151_160_PROBLEM_156_HPP


#pragma once

/* MEDIUM
Given a positive integer n, find the smallest number of squared integers which
sum to n.

For example, given n = 13, return 2 since 13 = 32 + 22 = 9 + 4.

Given n = 27, return 3 since 27 = 32 + 32 + 32 = 9 + 9 + 9.
*/
#include <limits>
#include <vector>


inline int num_squares( int n )
{
  if( n == 0 ) return 0;

  std::vector<int> cache( n + 1, std::numeric_limits<int>::max() );
  cache[0] = 0;

  for( int i = 1; i < n + 1; i++ )
  {
    int j = 1;
    while( j * j <= i )
    {
      cache[i] = std::min( cache[i], cache[i - j * j] + 1 );
      j += 1;
    }
  }
  return cache[n];
}
#endif
