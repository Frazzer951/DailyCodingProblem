#ifndef PROBLEMS_191_200_PROBLEM_191_HPP
#define PROBLEMS_191_200_PROBLEM_191_HPP


#pragma once

/* EASY
Given a collection of intervals, find the minimum number of intervals you need
to remove to make the rest of the intervals non-overlapping.

Intervals can "touch", such as [0, 1] and [1, 2], but they won't be considered
overlapping.

For example, given the intervals (7, 9), (2, 4), (5, 8), return 1 as the last
interval can be removed and the first two won't overlap.

The intervals are not necessarily sorted in any order.
*/
#include <algorithm>
#include <limits>
#include <vector>

inline bool sortbysec( const std::pair<int, int> & a, const std::pair<int, int> & b )
{
  return ( a.second < b.second );
}

inline int non_overlapping_intervals( std::vector<std::pair<int, int>> intervals )
{
  int current_end = std::numeric_limits<int>::min();
  int overlapping = 0;

  std::sort( intervals.begin(), intervals.end(), sortbysec );

  for( auto & [start, end] : intervals )
  {
    if( start >= current_end ) current_end = end;
    else
      overlapping += 1;
  }
  return overlapping;
}
#endif
