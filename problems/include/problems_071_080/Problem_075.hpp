#ifndef PROBLEMS_071_080_PROBLEM_075_HPP
#define PROBLEMS_071_080_PROBLEM_075_HPP

#pragma once

/* HARD
Given an array of numbers, find the length of the longest increasing subsequence
in the array. The subsequence does not necessarily have to be contiguous.

For example, given the array [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7,
15], the longest increasing subsequence has length 6: it is 0, 2, 6, 9, 11, 15.
*/
#include <vector>

#include "Futils.hpp"

inline int longest_increasing_subsequence( std::vector<int> arr ) {
  if ( arr.empty() ) return 0;

  std::vector<int> cache( arr.size(), 1 );
  for ( int i = 1; i < arr.size(); i++ ) {
    for ( int j = 0; j < i; j++ ) {
      if ( arr[i] > arr[j] ) cache[i] = std::max( cache[i], cache[j] + 1 );
    }
  }
  return getIntVecMax( cache );
}
#endif
