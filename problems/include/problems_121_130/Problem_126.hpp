#ifndef PROBLEMS_121_130_PROBLEM_126_HPP
#define PROBLEMS_121_130_PROBLEM_126_HPP

#pragma once

/* MEDIUM
Write a function that rotates a list by k elements. For example, [1, 2, 3, 4, 5,
6] rotated by two becomes [3, 4, 5, 6, 1, 2]. Try solving this without creating
a copy of the list. How many swap or move operations do you need?
*/
#include <vector>

inline void vSwap( std::vector<int> &v, std::size_t x, std::size_t y ) {
  int const temp = v[x];
  v[x]     = v[y];
  v[y]     = temp;
}

inline std::vector<int> rotateVector( std::vector<int> v, int k ) {
  for ( std::size_t i = 0; i < v.size() - k; i++ ) { vSwap( v, i, ( v.size() - k + i ) % v.size() ); }
  return v;
}
#endif
