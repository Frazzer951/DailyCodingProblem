#ifndef PROBLEMS_061_070_PROBLEM_069_HPP
#define PROBLEMS_061_070_PROBLEM_069_HPP

#pragma once

/* EASY
Given a list of integers, return the largest product that can be made by
multiplying any three integers.

For example, if the list is [-10, -10, 5, 2], we should return 500, since that's
-10 * -10 * 5.

You can assume the list has at least three integers.
*/
#include <vector>

inline int largest_product_x3( std::vector<int> nums ) {
  int largest = nums[0] * nums[1] * nums[2];

  for ( int i = 0; i < nums.size(); i++ ) {
    for ( int j = i + 1; j < nums.size(); j++ ) {
      for ( int k = j + 1; k < nums.size(); k++ ) {
        int temp = nums[i] * nums[j] * nums[k];
        largest  = std::max( largest, temp );
      }
    }
  }
  return largest;
}
#endif
