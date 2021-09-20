#pragma once

/* Easy
You are given given a list of rectangles represented by min and max x- and y-coordinates. Compute whether or not a pair
of rectangles overlap each other. If one rectangle completely covers another, it is considered overlapping.

For example, given the following rectangles:

{
    "top_left": (1, 4),
    "dimensions": (3, 3) # width, height
},
{
    "top_left": (-1, 3),
    "dimensions": (2, 1)
},
{
    "top_left": (0, 5),
    "dimensions": (4, 3)
}
return true as the first and third rectangle overlap each other.
*/

#include <Problem_185.hpp>
#include <vector>

inline bool is_overlapping( Rect rec1, Rect rec2 )
{
  if( rec1.top_left.first >= rec2.top_left.first + rec2.dimensions.first ) return false;

  if( rec1.top_left.first + rec1.dimensions.first <= rec2.top_left.first ) return false;

  if( rec1.top_left.second <= rec2.top_left.second - rec2.dimensions.second ) return false;

  if( rec1.top_left.second - rec1.dimensions.second >= rec2.top_left.second ) return false;

  return true;
}

inline bool overlapping( std::vector<Rect> rectangles )
{
  for( int i = 0; i < rectangles.size(); i++ )
  {
    Rect rec1 = rectangles[i];
    for( int j = i + 1; j < rectangles.size(); j++ )
    {
      Rect rec2 = rectangles[j];
      if( is_overlapping( rec1, rec2 ) ) return true;
    }
  }

  return false;
}