#ifndef PROBLEMS_221_230_PROBLEM_224_HPP
#define PROBLEMS_221_230_PROBLEM_224_HPP

#pragma once

/* EASY
Given a sorted array, find the smallest positive integer that is not the sum of
a subset of the array.

For example, for the input [1, 2, 3, 10], you should return 7.

Do this in O(N) time.
*/
#include <vector>

inline int smallestIntNotSubset( std::vector<int> input ) {
  int result = 1;
  for ( int i = 0; i < input.size() && input[i] <= result; i++ ) { result = result + input[i]; }
  return result;
}
#endif
