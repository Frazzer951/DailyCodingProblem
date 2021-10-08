#pragma once

/* MEDIUM
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand. Find the minimum element
in O(log N) time. You may assume the array does not contain duplicates.

For example, given [5, 7, 10, 3, 4], return 3
*/
/*
def helper(arr, low, high):
    if high == low:
        return arr[low]

    mid = (high + low) / 2
    if arr[mid] < arr[high]:
        high = mid
    else:
        low = mid + 1
    return helper(arr, low, high)

def find_min_element(arr):
    low, high = 0, len(arr) - 1
    return helper(arr, low, high)
    */

#include <vector>

inline int helper( std::vector<int> arr, int low, int high )
{
  if( high == low ) return arr[low];
  int mid = ( high + low ) / 2;
  if( arr[mid] < arr[high] ) high = mid;
  else
    low = mid + 1;
  return helper( arr, low, high );
}

inline int find_min_element( std::vector<int> arr )
{
  int low  = 0;
  int high = arr.size() - 1;
  return helper( arr, low, high );
}