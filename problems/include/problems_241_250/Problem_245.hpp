#ifndef PROBLEMS_241_250_PROBLEM_245_HPP
#define PROBLEMS_241_250_PROBLEM_245_HPP

#pragma once

/* MEDIUM
You are given an array of integers, where each element represents the maximum
number of steps that can be jumped going forward from that element. Write a
function to return the minimum number of jumps you must take in order to get
from the start to the end of the array.

For example, given [6, 2, 4, 0, 5, 1, 1, 4, 2, 9], you should return 2, as the
optimal solution involves jumping from 6 to 5, and then from 5 to 9.
*/

#include <limits>
#include <vector>

inline int minJumps( std::vector<int> & jumps )
{
  int              n = jumps.size();
  std::vector<int> dp( n, std::numeric_limits<int>::max() );
  dp[0] = 0;

  for( int i = 1; i < n; ++i )
  {
    for( int j = 0; j < i; ++j )
    {
      if( jumps[j] >= i - j ) { dp[i] = std::min( dp[i], dp[j] + 1 ); }
    }
  }

  return dp[n - 1];
}

#endif
