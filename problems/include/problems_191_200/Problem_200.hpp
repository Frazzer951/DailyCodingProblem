#ifndef PROBLEMS_191_200_PROBLEM_200_HPP
#define PROBLEMS_191_200_PROBLEM_200_HPP

#pragma once

/* HARD
Let X be a set of n intervals on the real line. We say that a set of points P
"stabs" X if every interval in X contains at least one point in P. Compute the
smallest set of points that stabs X.

For example, given the intervals [(1, 4), (4, 5), (7, 9), (9, 12)], you should
return [4, 9].
*/
#include <algorithm>
#include <vector>

inline bool sortbysec( const std::pair<int, int> &a, const std::pair<int, int> &b );

inline std::vector<int> get_points( std::vector<std::pair<int, int>> intervals ) {
  std::sort( intervals.begin(), intervals.end(), sortbysec );

  std::vector<int> points;
  int              latest_endpoint = intervals[0].first - 1;

  for ( auto &[start, end] : intervals ) {
    if ( start <= latest_endpoint ) continue;
    points.push_back( end );
    latest_endpoint = end;
  }

  return points;
}
#endif
