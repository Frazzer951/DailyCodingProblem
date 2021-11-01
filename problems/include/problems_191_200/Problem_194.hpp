#pragma once

/* EASY
Suppose you are given two lists of n points, one list p1, p2, ..., pnon the line
y = 0 and the other list q1, q2, ..., qn on the line y = 1. Imagine a set of n
line segments connecting each point pi to qi. Write an algorithm to determine
how many pairs of the line segments intersect.
*/

#include <vector>

struct line
{
  int a, b, c;
};

inline int numIntersections( std::vector<int> ps, std::vector<int> qs )
{
  int intersections = 0;

  std::vector<line> lines;

  int y1 = 0;
  int y2 = 1;

  for( int i = 0; i < ps.size(); i++ )
  {
    int x1 = ps[i];
    int x2 = qs[i];

    int A = y2 - y1;
    int B = x1 - x2;
    int C = A * x1 + B * y1;

    lines.push_back( { A, B, C } );
  }

  for( int i = 0; i < lines.size(); i++ )
  {
    for( int j = i + 1; j < lines.size(); j++ )
    {
      line l1 = lines[i];
      line l2 = lines[j];

      double det = l1.a * l2.b - l2.a * l1.b;

      if( det != 0 ) intersections++;
    }
  }
  return intersections;
}