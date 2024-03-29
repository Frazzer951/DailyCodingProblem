#ifndef PROBLEMS_201_210_PROBLEM_203_HPP
#define PROBLEMS_201_210_PROBLEM_203_HPP

#pragma once

/* MEDIUM
Suppose an array sorted in ascending order is rotated at some pivot unknown to
you beforehand. Find the minimum element in O(log N) time. You may assume the
array does not contain duplicates.

For example, given [5, 7, 10, 3, 4], return 3.
*/
#include <vector>

inline int helper( std::vector<int> arr, int low, int high ) {
  if ( high == low ) return arr[low];
  int const mid = ( high + low ) / 2;
  if ( arr[mid] < arr[high] )
    high = mid;
  else
    low = mid + 1;
  return helper( arr, low, high );
}

inline int find_min_element( const std::vector<int> &arr ) {
  int const low  = 0;
  int const high = (int) arr.size() - 1;
  return helper( arr, low, high );
}
#endif
