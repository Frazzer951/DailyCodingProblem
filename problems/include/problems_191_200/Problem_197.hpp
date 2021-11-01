#ifndef PROBLEMS_191_200_PROBLEM_197_HPP
#define PROBLEMS_191_200_PROBLEM_197_HPP

#pragma once

/* EASY
Given an array and a number k that's smaller than the length of the array,
rotate the array to the right k elements in-place.
*/

#include <vector>

inline std::vector<int> rotateArr( std::vector<int> arr, int k )
{
  std::vector<int> rotated( arr.size() );

  for( int i = 0; i < arr.size(); i++ ) { rotated[( i + k ) % arr.size()] = arr[i]; }
  return rotated;
}
#endif
