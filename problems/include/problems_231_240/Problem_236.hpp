#ifndef PROBLEMS_231_240_PROBLEM_236_HPP
#define PROBLEMS_231_240_PROBLEM_236_HPP


#pragma once

/* MEDIUM
You are given a list of N points (x1, y1), (x2, y2), ..., (xN, yN) representing
a polygon. You can assume these points are given in order; that is, you can
construct the polygon by connecting point 1 to point 2, point 2 to point 3, and
so on, finally looping around to connect point N to point 1.

Determine if a new point p lies inside this polygon. (If p is on the boundary of
the polygon, you should return False).
*/
#include <limits>
#include <vector>

struct Point
{
  int x;
  int y;
};

inline bool isInsidePolygon( const std::vector<Point> & polygon, const Point & p )
{
  if( polygon.size() < 3 ) return false;

  int Xmin = std::numeric_limits<int>::max();
  int Xmax = std::numeric_limits<int>::min();
  int Ymin = std::numeric_limits<int>::max();
  int Ymax = std::numeric_limits<int>::min();
  for( const auto & point : polygon )
  {
    Xmin = std::min( Xmin, point.x );
    Xmax = std::max( Xmax, point.x );
    Ymin = std::min( Ymin, point.y );
    Ymax = std::max( Ymax, point.y );
  }

  if( p.x < Xmin || p.x > Xmax || p.y < Ymin || p.y > Ymax ) return false;

  bool c = false;
  for( int i = 0, j = polygon.size() - 1; i < polygon.size(); j = i++ )
  {
    if( ( polygon[i].y > p.y ) != ( polygon[j].y > p.y )
        && p.x < ( polygon[j].x - polygon[i].x ) * ( p.y - polygon[i].y ) / ( polygon[j].y - polygon[i].y )
                     + polygon[i].x )
    {
      c = !c;
    }
  }

  return c;
}
#endif
