#ifndef PROBLEMS_141_150_PROBLEM_144_HPP
#define PROBLEMS_141_150_PROBLEM_144_HPP


#pragma once

/* MEDIUM
Given an array of numbers and an index i, return the index of the nearest larger
number of the number at index i, where distance is measured in array indices.

For example, given [4, 1, 3, 5, 6] and index 0, you should return 3.

If two distances to larger numbers are the equal, then return any one of them.
If the array at i doesn't have a nearest larger integer, then return null.

Follow-up: If you can preprocess the array, can you do this in constant time?
*/
#include <vector>

inline int nearest( std::vector<int> arr, int i )
{
  for( int j = 1; j < arr.size(); j++ )
  {
    int low  = i - j;
    int high = i + j;
    if( 0 <= low && arr[low] > arr[i] ) return low;
    if( high < arr.size() && arr[high] > arr[i] ) return high;
  }
  return -1;
}

inline std::vector<int> preprocess( std::vector<int> arr )
{
  std::vector<int> cache( arr.size(), -1 );

  for( int j = 0; j < arr.size() - 1; j++ )
  {
    if( arr[j] > arr[j + 1] ) cache[j + 1] = j;
    else if( arr[j + 1] > arr[j] )
      cache[j] = j + 1;
  }

  for( int i = 0; i < cache.size(); i++ )
    if( cache[i] == -1 ) cache[i] = nearest( arr, i );

  return cache;
}
#endif
