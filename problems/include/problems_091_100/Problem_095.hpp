#ifndef PROBLEMS_091_100_PROBLEM_095_HPP
#define PROBLEMS_091_100_PROBLEM_095_HPP

#pragma once

/* HARD
Given a number represented by a list of digits, find the next greater
permutation of a number, in terms of lexicographic ordering. If there is not
greater permutation possible, return the permutation with the lowest
value/ordering.

For example, the list [1,2,3] should return [1,3,2]. The list [1,3,2] should
return [2,1,3]. The list [3,2,1] should return [1,2,3].

Can you perform the operation without allocating extra memory (disregarding the
input memory)?
*/
#include <vector>

inline void swap( std::vector<int> &nums, int a, int b ) {
  // Perform an in-place swap
  int temp = nums[a];
  nums[a]  = nums[b];
  nums[b]  = temp;
}

inline void reverse( std::vector<int> &nums, int a, int b ) {
  // Reverses elements at index a to b (inclusive) in-place
  std::reverse( nums.begin() + a, nums.begin() + b + 1 );
}

inline void nextPermutation( std::vector<int> &nums ) {
  // Find first index where nums[idx] < nums[idx + 1]
  int pivot = (int) nums.size() - 2;
  while ( pivot >= 0 && nums[pivot] >= nums[pivot + 1] ) pivot -= 1;

  if ( pivot >= 0 ) {
    // Find the next-largest number to swap with
    int successor = (int) nums.size() - 1;
    while ( successor > 0 && nums[successor] <= nums[pivot] ) successor -= 1;
    swap( nums, pivot, successor );
  }
  reverse( nums, pivot + 1, (int) nums.size() - 1 );
}
#endif
