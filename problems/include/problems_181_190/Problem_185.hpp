#ifndef PROBLEMS_181_190_PROBLEM_185_HPP
#define PROBLEMS_181_190_PROBLEM_185_HPP


#pragma once

/* EASY
Given two rectangles on a 2D graph, return the area of their intersection. If
the rectangles don't intersect, return 0.

For example, given the following rectangles:

{
    "top_left": (1, 4),
    "dimensions": (3, 3) # width, height
}


and

{
    "top_left": (0, 5),
    "dimensions": (4, 3) # width, height
}


return 6.
*/
#include <vector>

struct Rect
{
  std::pair<int, int> top_left;
  std::pair<int, int> dimensions;
};

inline bool inRect( Rect r, std::pair<int, int> point )
{
  int x = point.first;
  int y = point.second;
  if( x < r.top_left.first || x > r.top_left.first + r.dimensions.first ) return false;
  if( y < r.top_left.second || y > r.top_left.second + r.dimensions.second ) return false;
  return true;
}

inline int intersectArea( Rect r1, Rect r2 )
{
  int x_shift = std::min( r1.top_left.first, r2.top_left.first );
  int y_shift = std::min( r1.top_left.second, r2.top_left.second );
  int x_size  = std::max( r1.top_left.first + r1.dimensions.first, r2.top_left.first + r2.dimensions.first );
  int y_size  = std::max( r1.top_left.second + r1.dimensions.second, r2.top_left.second + r2.dimensions.second );

  std::vector<std::vector<bool>> board( x_size, std::vector( y_size, false ) );

  for( int i = r1.top_left.first - x_shift; i < r1.top_left.first + r1.dimensions.first - x_shift; i++ )
  {
    for( int j = r1.top_left.second - y_shift; j < r1.top_left.second + r1.dimensions.second - y_shift; j++ )
    {
      board[i][j] = true;
    }
  }
  int count = 0;
  for( int i = r2.top_left.first - x_shift; i < r2.top_left.first + r2.dimensions.first - x_shift; i++ )
  {
    for( int j = r2.top_left.second - y_shift; j < r2.top_left.second + r2.dimensions.second - y_shift; j++ )
    {
      if( board[i][j] ) count++;
    }
  }
  return count;
}
#endif
