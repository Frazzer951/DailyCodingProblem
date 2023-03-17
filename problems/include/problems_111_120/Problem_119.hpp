#ifndef PROBLEMS_111_120_PROBLEM_119_HPP
#define PROBLEMS_111_120_PROBLEM_119_HPP

#pragma once

/* MEDIUM
Given a set of closed intervals, find the smallest set of numbers that covers
all the intervals. If there are multiple smallest sets, return any of them.

For example, given the intervals [0, 3], [2, 6], [3, 4], [6, 9], one set of
numbers that covers all these intervals is {3, 6}.
*/
#include <vector>

inline bool intersecting( std::vector<int> x, std::vector<int> y ) { return x[0] <= y[1] && y[0] <= x[1]; }

inline std::vector<int> covering( std::vector<std::vector<int>> intervals ) {
  std::sort( intervals.begin(), intervals.end() );

  std::vector<int> result;
  int              i = 0;

  while ( i < intervals.size() ) {
    auto interval = intervals[i];

    while ( i < intervals.size() && intersecting( intervals[i], interval ) ) {
      interval = { std::max( intervals[i][0], interval[0] ), std::min( intervals[i][1], interval[1] ) };
      i++;
    }
    result.push_back( interval[1] );
  }
  return result;
}
#endif
