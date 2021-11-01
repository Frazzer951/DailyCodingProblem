#ifndef PROBLEMS_021_030_PROBLEM_030_HPP
#define PROBLEMS_021_030_PROBLEM_030_HPP

#pragma once

/* MEDIUM
You are given an array of non-negative integers that represents a
two-dimensional elevation map where each element is unit-width wall and the
integer is the height. Suppose it will rain and all spots between two walls get
filled up.

Compute how many units of water remain trapped on the map in O(N) time and O(1)
space.

For example, given the input [2, 1, 2], we can hold 1 unit of water in the
middle.

Given the input [3, 0, 1, 3, 0, 5], we can hold 3 units in the first index, 2 in
the second, and 3 in the fourth index (we cannot hold 5 since it would run off
to the left), so we can trap 8 units of water.
*/

#include <vector>

inline int waterHeightMap( std::vector<int> v )
{
  int unitsOfWater = 0;

  int leftMax  = v[0];
  int rightMax = 0;

  for( unsigned int i = 1; i < v.size(); i++ )
  {
    if( rightMax == v[i] ) rightMax = 0;

    for( unsigned int j = i + 1; j < v.size(); j++ ) { rightMax = ( rightMax > v[j] ) ? rightMax : v[j]; }

    int tempWater = ( leftMax < rightMax ) ? leftMax : rightMax;

    unitsOfWater += ( tempWater - v[i] > 0 ) ? tempWater - v[i] : 0;
  }

  return unitsOfWater;
}
#endif
