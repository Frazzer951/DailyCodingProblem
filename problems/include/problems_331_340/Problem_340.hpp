#ifndef PROBLEMS_331_340_PROBLEM_340_HPP
#define PROBLEMS_331_340_PROBLEM_340_HPP



#pragma once

/* EASY
Given a set of points (x, y) on a 2D cartesian plane, find the two closest
points. For example, given the points [(1, 1), (-1, -1), (3, 4), (6, 1), (-1,
-6), (-4, -3)], return [(-1, -1), (1, 1)].
*/
#include <cmath>
#include <map>
#include <vector>

double distance( const std::pair<int, int> & p1, const std::pair<int, int> & p2 )
{
  return std::sqrt( std::pow( p1.first - p2.first, 2 ) + std::pow( p1.second - p2.second, 2 ) );
}

std::pair<std::pair<int, int>, std::pair<int, int>> findClosestPair( const std::vector<std::pair<int, int>> & points )
{
  std::map<double, std::pair<std::pair<int, int>, std::pair<int, int>>> distances;
  for( int i = 0; i < points.size(); ++i )
  {
    for( int j = i + 1; j < points.size(); ++j )
    {
      distances[distance( points[i], points[j] )] = std::make_pair( points[i], points[j] );
    }
  }
  return distances.begin()->second;
}
#endif
