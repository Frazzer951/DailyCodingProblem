#ifndef PROBLEMS_091_100_PROBLEM_100_HPP
#define PROBLEMS_091_100_PROBLEM_100_HPP

#pragma once

/* EASY
You are in an infinite 2D grid where you can move in any of the 8 directions:

 (x,y) to
    (x+1, y),
    (x - 1, y),
    (x, y+1),
    (x, y-1),
    (x-1, y-1),
    (x+1,y+1),
    (x-1,y+1),
    (x+1,y-1)


You are given a sequence of points and the order in which you need to cover the
points. Give the minimum number of steps in which you can achieve it. You start
from the first point.

Example:

Input: [(0, 0), (1, 1), (1, 2)]
Output: 2


It takes 1 step to move from (0, 0) to (1, 1). It takes one more step to move
from (1, 1) to (1, 2).
*/
#include <vector>

inline int minSteps( std::vector<std::pair<int, int>> points ) {
  int totalSteps = 0;

  for ( std::size_t i = 1; i < points.size(); i++ ) {
    int const xChange = std::abs( points[i].first - points[i - 1].first );
    int const yChange = std::abs( points[i].second - points[i - 1].second );

    totalSteps += std::max( xChange, yChange );
  }

  return totalSteps;
}
#endif
