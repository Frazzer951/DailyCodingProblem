#pragma once

/* MEDIUM
You are given an array of nonnegative integers. Let's say you start at the beginning of the array and are trying to
advance to the end. You can advance at most, the number of steps that you're currently on. Determine whether you can get
to the end of the array.

For example, given the array [1, 3, 1, 2, 0, 1], we can go from indices 0 -> 1 -> 3 -> 5, so return true.

Given the array [1, 2, 1, 0, 0], we can't reach the end, so return false.
*/

#include <vector>

// def can_reach_end(arr):
//    furthest_so_far = 0
//    for i in range(len(arr)):
//        if i > furthest_so_far:
//            break
//        furthest_so_far = max(furthest_so_far, i + arr[i])
//    return furthest_so_far >= len(arr) - 1

inline bool canReachEnd( std::vector<int> arr )
{
  int furthest_so_far = 0;

  for( int i = 0; i < arr.size(); i++ )
  {
    if( i > furthest_so_far ) break;
    furthest_so_far = std::max( furthest_so_far, i + arr[i] );
  }
  return furthest_so_far >= arr.size() - 1;
}
