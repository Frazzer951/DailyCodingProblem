#ifndef PROBLEMS_001_010_PROBLEM_004_HPP
#define PROBLEMS_001_010_PROBLEM_004_HPP

#pragma once

/* HARD
Given an array of integers, find the first missing positive integer in linear
time and constant space. In other words, find the lowest positive integer that
does not exist in the array. The array can contain duplicates and negative
numbers as well.

For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should
give 3.

You can modify the input array in-place.
*/
#include <algorithm>
#include <iostream>
#include <vector>

inline int findMissingPositive( std::vector<int> arr ) {
  std::sort( arr.begin(), arr.end() );

  int missing = 1;

  for ( int const i : arr ) {
    if ( i > 0 && i == missing ) { missing++; }
  }
  return missing;
}

inline void testArray( const std::vector<int> &arr ) {
  std::cout << "For the array: ";
  for ( int const i : arr ) { std::cout << i << ' '; }
  int const missing = findMissingPositive( arr );
  std::cout << " the missing number is " << missing << '\n';
}

inline int prob_4() {
  std::cout << "\nProblem 4:\n";

  std::vector<int> const arr = { 3, 4, -1, 1 };
  testArray( arr );

  std::vector<int> const arr2 = { 1, 2, 0 };
  testArray( arr2 );

  return 0;
}
#endif
