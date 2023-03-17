#ifndef PROBLEMS_081_090_PROBLEM_088_HPP
#define PROBLEMS_081_090_PROBLEM_088_HPP

#pragma once

/* MEDIUM
Implement division of two positive integers without using the division,
multiplication, or modulus operators. Return the quotient as an integer,
ignoring the remainder.
*/
inline int divide( const int &x, const int &y ) {
  int i       = 0;
  int counter = y;

  while ( counter <= x ) {
    i++;
    counter += y;
  }

  return i;
}
#endif
