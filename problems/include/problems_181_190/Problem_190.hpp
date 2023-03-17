#ifndef PROBLEMS_181_190_PROBLEM_190_HPP
#define PROBLEMS_181_190_PROBLEM_190_HPP

#pragma once

/* MEDIUM
Given a circular array, compute its maximum subarray sum in O(n) time. A
subarray can be empty, and in this case the sum is 0.

For example, given [8, -1, 3, 4], return 15 as we choose the numbers 3, 4, and 8
where the 8 is obtained from wrapping around.

Given [-4, 5, 1, 0], return 6 as we choose the numbers 5 and 1.
*/
#include <numeric>
#include <vector>

inline int maxSubArraySum( const std::vector<int> &arr ) {
  int max        = 0;
  int max_so_far = 0;
  for ( int x : arr ) {
    max        = std::max( x, max + x );
    max_so_far = std::max( max_so_far, max );
  }
  return max_so_far;
}

inline int minSubArraySum( const std::vector<int> &arr ) {
  int min        = 0;
  int min_so_far = 0;
  for ( int x : arr ) {
    min        = std::min( x, min + x );
    min_so_far = std::min( min_so_far, min );
  }
  return min_so_far;
}

inline int maxCircSubArray( std::vector<int> arr ) {
  int maxSubArraySumWrap = std::accumulate( arr.begin(), arr.end(), 0 ) - minSubArraySum( arr );
  return std::max( maxSubArraySum( arr ), maxSubArraySumWrap );
}
#endif
