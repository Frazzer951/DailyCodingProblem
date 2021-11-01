#pragma once

/* MEDIUM
Given an array of integers in which two elements appear exactly once and all
other elements appear exactly twice, find the two elements that appear only
once.

For example, given the array [2, 4, 6, 8, 10, 2, 6, 10], return 4 and 8. The
order does not matter.

Follow-up: Can you do this in linear time and constant space?
*/

#include <vector>

inline std::pair<int, int> array_two_elements( const std::vector<int> & arr )
{
  int val = 0;
  for( int num : arr ) val = val ^ num;

  // Get rightmost set bit
  val = val & -val;

  std::pair<int, int> rets = std::make_pair( 0, 0 );
  for( int num : arr )
  {
    if( ( num & val ) != 0 ) rets.first = rets.first ^ num;
    else
      rets.second = rets.second ^ num;
  }
  return rets;
}