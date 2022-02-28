#ifndef PROBLEMS_141_150_PROBLEM_150_HPP
#define PROBLEMS_141_150_PROBLEM_150_HPP


#pragma once

/* HARD
Given a list of points, a central point, and an integer k, find the nearest k
points from the central point.

For example, given the list of points [(0, 0), (5, 4), (3, 1)], the central
point (1, 2), and k = 2, return[(0, 0), (3, 1)].
*/
#include <cmath>
#include <map>
#include <vector>

inline std::vector<std::pair<int, int>> nearestPoints( const std::vector<std::pair<int, int>> & points,
                                                       std::pair<int, int>                      central )
{
  std::map<std::pair<int, int>, double> pointDistance;

  for( auto p : points )
  {
    double xLeng    = p.first - central.first;
    double yLeng    = p.second - central.second;
    double distance = sqrt( ( xLeng * xLeng ) + ( yLeng * yLeng ) );

    pointDistance[p] = distance;
  }

  std::vector<std::pair<int, int>> nearest;
  nearest.push_back( pointDistance.begin()->first );
  nearest.push_back( ( ++pointDistance.begin() )->first );

  return nearest;
}
#endif
