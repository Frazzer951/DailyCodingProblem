#pragma once

/* EASY
Given a sorted list of integers, square the elements and give the output in
sorted order.

For example, given [-9, -2, 0, 2, 3], return [0, 4, 4, 9, 81].
*/

#include <algorithm>
#include <vector>

inline std::vector<int> square_sort( std::vector<int> nums )
{
  for( int & num : nums ) { num = num * num; }

  std::sort( nums.begin(), nums.end() );

  return nums;
}