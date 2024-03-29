#ifndef PROBLEMS_191_200_PROBLEM_194_HPP
#define PROBLEMS_191_200_PROBLEM_194_HPP

#pragma once

/* EASY
Suppose you are given two lists of n points, one list p1, p2, ..., pnon the line
y = 0 and the other list q1, q2, ..., qn on the line y = 1. Imagine a set of n
line segments connecting each point pi to qi. Write an algorithm to determine
how many pairs of the line segments intersect.
*/
#include <vector>

struct line {
  int a, b, c;
};

inline int numIntersections( std::vector<int> ps, std::vector<int> qs ) {
  int intersections = 0;

  std::vector<line> lines;

  int const y1 = 0;
  int const y2 = 1;

  for ( int i = 0; i < ps.size(); i++ ) {
    int const x1 = ps[i];
    int const x2 = qs[i];

    int const A = y2 - y1;
    int const B = x1 - x2;
    int const C = A * x1 + B * y1;

    lines.push_back( { A, B, C } );
  }

  for ( int i = 0; i < lines.size(); i++ ) {
    for ( int j = i + 1; j < lines.size(); j++ ) {
      line const l1 = lines[i];
      line const l2 = lines[j];

      double const det = l1.a * l2.b - l2.a * l1.b;

      if ( det != 0 ) intersections++;
    }
  }
  return intersections;
}
#endif
