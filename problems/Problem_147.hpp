#pragma once

/* HARD
Given a list, sort it using this method: reverse(lst, i, j), which reverses lst from i to j.
*/

#include <algorithm>
#include <vector>

inline int smallestIndex( std::vector<int> arr, int i )
{
  int min = i;
  for( int j = i; j < arr.size(); j++ ) { min = ( arr[min] < arr[j] ) ? min : j; }
  return min;
}

inline std::vector<int> sortWithReverse( std::vector<int> arr )
{
  for( int i = 0; i < arr.size(); i++ )
  {
    int min_index = smallestIndex( arr, i );
    std::reverse( arr.begin() + i, arr.begin() + min_index +1);
  }
  return arr;
}