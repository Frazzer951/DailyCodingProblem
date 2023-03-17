#ifndef PROBLEMS_041_050_PROBLEM_049_HPP
#define PROBLEMS_041_050_PROBLEM_049_HPP

#pragma once

/* MEDIUM
Given an array of numbers, find the maximum sum of any contiguous subarray of
the array.

For example, given the array [34, -50, 42, 14, -5, 86], the maximum sum would be
137, since we would take elements 42, 14, -5, and 86.

Given the array [-5, -1, -8, -9], the maximum sum would be 0, since we would not
take any elements.

Do this in O(N) time.
*/
#include <vector>

inline int max_subarray_sum( const std::vector<int> &arr ) {
  int max_ending_here = 0;
  int max_so_far      = 0;
  for ( int x : arr ) {
    max_ending_here = std::max( x, max_ending_here + x );
    max_so_far      = std::max( max_so_far, max_ending_here );
  }
  return max_so_far;
}
#endif
