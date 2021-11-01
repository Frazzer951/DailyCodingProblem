#ifndef PROBLEMS_081_090_PROBLEM_085_HPP
#define PROBLEMS_081_090_PROBLEM_085_HPP

#pragma once

/* MEDIUM
Given three 32-bit integers x, y, and b, return x if b is 1 and y if b is 0,
using only mathematical or bit operations. You can assume b can only be 1 or 0.
*/

inline int math_if( int x, int y, int b )
{
  b = -b;
  x = x & b;
  y = y & ~b;
  return x | y;
}
#endif
