#ifndef PROBLEMS_181_190_PROBLEM_184_HPP
#define PROBLEMS_181_190_PROBLEM_184_HPP

#pragma once

/* EASY
Given n numbers, find the greatest common denominator between them.

For example, given the numbers [42, 56, 14], return 14.
*/
#include <vector>

inline int greatestCommonDenominator( std::vector<int> nums ) {
  int i = nums[0];
  for ( int const num : nums ) i = std::min( i, num );

  while ( i > 0 ) {
    bool divisable = true;
    for ( int const num : nums )
      if ( num % i != 0 ) divisable = false;
    if ( divisable ) break;
    i--;
  }

  return i;
}
#endif
