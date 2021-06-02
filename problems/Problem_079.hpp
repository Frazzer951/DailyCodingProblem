#pragma once

/* MEDIUM
Given an array of integers, write a function to determine
whether the array could become non-decreasing by modifying
at most 1 element.

For example, given the array [10, 5, 7], you should return
true, since we can modify the 10 into a 1 to make the array
non-decreasing.

Given the array [10, 5, 1], you should return false, since
we can't modify any one element to get a non-decreasing array.
*/

#include <vector>

bool remove_one_non_decrease( std::vector<int> nums )
{
  for( int i = 0; i < nums.size(); i++ )
  {
    bool increasing = true;
    for( int j = 0; j < nums.size() - 1; j++ )
    {
      if( j == i ) continue;
      if( j + 1 == i && j + 2 < nums.size() )
      {
        if( nums[j] > nums[j + 2] ) increasing = false;
      }
      else
      {
        if( nums[j] > nums[j + 1] ) increasing = false;
      }
    }
    if( increasing ) return true;
  }
  return false;
}