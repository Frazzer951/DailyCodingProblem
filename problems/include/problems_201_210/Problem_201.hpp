#ifndef PROBLEMS_201_210_PROBLEM_201_HPP
#define PROBLEMS_201_210_PROBLEM_201_HPP


#pragma once

/* EASY
You are given an array of arrays of integers, where each array corresponds to a
row in a triangle of numbers. For example, [[1], [2, 3], [1, 5, 1]] represents
the triangle:

  1
 2 3
1 5 1


We define a path in the triangle to start at the top and go down one row at a
time to an adjacent value, eventually ending with an entry on the bottom row.
For example, 1 -> 3 -> 5. The weight of the path is the sum of the entries.

Write a program that returns the weight of the maximum weight path.
*/
#include <vector>

inline int longestPath( std::vector<std::vector<int>> arrays )
{
  for( int level = (int) arrays.size() - 2; level > -1; level-- )
  {
    for( int index = 0; index < level + 1; index++ )
    {
      arrays[level][index] += std::max( arrays[level + 1][index], arrays[level + 1][index + 1] );
    }
  }
  return arrays[0][0];
}
#endif
